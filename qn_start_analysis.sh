#!/bin/bash

#
#SBATCH -D /mnt/pool/nica/8/trshinvv/STAR_Qn/TMP
#SBATCH -J run_qn
#SBATCH -p fast
#SBATCH -a 1-547

#
#SBATCH -o /mnt/pool/nica/8/trshinvv/STAR_Qn/TMP/slurm_%A_%a.out
#SBATCH -e /mnt/pool/nica/8/trshinvv/STAR_Qn/TMP/slurm_%A_%a.err
#



export ecm=27
export sys=AuAu
export model=STAR

export JOB_ID=${SLURM_ARRAY_JOB_ID}
export TASK_ID=${SLURM_ARRAY_TASK_ID}

export MAIN_DIR=/mnt/pool/nica/8/trshinvv/STAR_Qn
export LIST_DIR=$MAIN_DIR/lists/
export INPUT_FILELIST=$MAIN_DIR/STAR27GevAuAu_list.txt
split -l 20 -d -a 4 --additional-suffix=.list "$INPUT_FILELIST" $LIST_DIR
export CURRENT_FILE=`sed "${TASK_ID}q;d" $INPUT_FILELIST`
job_num=$((SLURM_ARRAY_TASK_ID))
filelist=$LIST_DIR/$(ls $LIST_DIR | sed "${job_num}q;d")
export COMMIT=${model}_${sys}_${ecm}gev_${job_num}
export START_POSITION=$PWD
cd $MAIN_DIR/output_dir/
export OUT_LOG=$MAIN_DIR/log
export LOG=${OUT_LOG}/JOB_${JOB_ID}_${TASK_ID}.log
export TMPALL=$MAIN_DIR/TMP
export TMPDIR=$TMPALL/TMP_${JOB_ID}_${TASK_ID}

mkdir -pv $OUT_LOG
#source /mnt/pool/nica/8/trshinvv/StFemtoToAnalysisTreeConverter/SetEnv.sh &>> $LOG
source /mnt/pool/nica/8/parfenovpeter/Soft/Unicluster/ROOT/build-cxx17/bin/thisroot.sh
export ANALYSISTREE_INC=/mnt/pool/nica/8/trshinvv/AnalysisTree/install/include
export ANALYSISTREE_LIB=/mnt/pool/nica/8/trshinvv/AnalysisTree/install/lib


#export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/mnt/pool/nica/8/trshinvv/AnalysisTree/install/lib/
_log() {

echo  "input file: $input_file" &>>$LOG
local format='+%Y/%m/%d-%H:%M:%S'
echo [`date $format`] "$@"

}

echo "Node host name: $HOSTNAME" &>> $LOG
echo "Node architecture name: $ARC" &>> $LOG
echo "Filelist: $filelist" &>> $LOG

echo "Current file: $CURRENT_FILE" &>>$LOG
cd /mnt/pool/nica/8/trshinvv/STAR_Qn/output_dir/preprocess_dir/
/mnt/pool/nica/8/trshinvv/bmn_preprocessing/build/src/pre_process -i $filelist -o output_${TASK_ID}.root -t aTree --output-tree-name bTree -N -1 &>>$LOG
find `pwd` -name "output_${TASK_ID}.root" > output_${TASK_ID}.txt

cd /mnt/pool/nica/8/trshinvv/STAR_Qn/output_dir/correction/
mkdir correction${job_num}
cd correction${job_num}
rm -rf *
cor_dir=correction${job_num}
/mnt/pool/nica/8/trshinvv/QnAnalysis/build/src/QnAnalysisCorrect/QnAnalysisCorrect -i $filelist /mnt/pool/nica/8/trshinvv/STAR_Qn/output_dir/preprocess_dir/output_${TASK_ID}.txt \
														-t aTree bTree\
														--yaml-config-file=/mnt/pool/nica/8/trshinvv/STAR_Qn/correction_config.yml \
														--yaml-config-name=STAR \
														--output-file correction_out.root \
														-n -1
mv /mnt/pool/nica/8/trshinvv/STAR_Qn/output_dir/correction/$cor_dir/correction_out.root /mnt/pool/nica/8/trshinvv/STAR_Qn/output_dir/correction/$cor_dir/correction_in.root
/mnt/pool/nica/8/trshinvv/QnAnalysis/build/src/QnAnalysisCorrect/QnAnalysisCorrect -i $filelist /mnt/pool/nica/8/trshinvv/STAR_Qn/output_dir/preprocess_dir/output_${TASK_ID}.txt \
														-t aTree bTree\
														--yaml-config-file=/mnt/pool/nica/8/trshinvv/STAR_Qn/correction_config.yml \
														--yaml-config-name=STAR \
														--output-file correction_out.root \
														-n -1
#mv /mnt/pool/nica/8/trshinvv/STAR_Qn/output_dir/correction/$cor_dir/correction_out.root /mnt/pool/nica/8/trshinvv/STAR_Qn/output_dir/correction/$cor_dir/correction_in.root
#/mnt/pool/nica/8/trshinvv/QnAnalysis/build/src/QnAnalysisCorrect/QnAnalysisCorrect -i $filelist /mnt/pool/nica/8/trshinvv/STAR_Qn/output_dir/preprocess_dir/output_${TASK_ID}.txt \
#														-t aTree bTree \
#														--yaml-config-file=/mnt/pool/nica/8/trshinvv/STAR_Qn/correction_config.yml \
#														--yaml-config-name=STAR \
#														--output-file correction_out.root \
#														-n -1

/mnt/pool/nica/8/trshinvv/QnAnalysis/build/src/QnAnalysisCorrelate/QnAnalysisCorrelate \
 --configuration-file /mnt/pool/nica/8/trshinvv/STAR_Qn/correlation_config.yml \
 --configuration-name _tasks --input-file /mnt/pool/nica/8/trshinvv/STAR_Qn/output_dir/correction/$cor_dir/correction_out.root --input-tree=tree --output-file /mnt/pool/nica/8/trshinvv/STAR_Qn/output_dir/correlation_outSTARprobe${job_num}.root

cd $START_POSITION
_log "Job is done!" &>> $LOG
