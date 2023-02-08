
// Created by mikhail on 5/6/21.
//

void Meanv2Draw(){
  gROOT->Macro( "/home/valeriy/flow_drawing_tools/example/style.cc" );
    auto leg1 = new TLegend( 0.7, 0.6, 0.9, 0.8 );
    auto leg2 = new TLegend( 0.7, 0.6, 0.9, 0.8 );
    auto leg3 = new TLegend( 0.7, 0.6, 0.9, 0.8 );
  TH1F* histo_axis;



    auto R1_qnqs_xx1 = new Correlation( "/home/valeriy/flow_calculator/build/STAR_27_D_weightone.root",
                                       {
                                               "v2_protons/v2w.hadronsE_RECENTERED(hadronsW_RECENTERED.hadronsE_RECENTERED).x2x2","v2_protons/v2w.hadronsE_RECENTERED(hadronsW_RECENTERED.hadronsE_RECENTERED).y2y2"
                                       },"protons_centrality" );
    R1_qnqs_xx1->SetCalculateSystematicsFromVariation(false);
    R1_qnqs_xx1->SetStyle( kBlue, kFullCircle );
    R1_qnqs_xx1->Scale(1);
    R1_qnqs_xx1->Rebin({
                               {"TpcTracks_pT", 1, 0.2, 2.0},
                               {"TpcTracks_eta", 1, -1, 0}
                       });
    R1_qnqs_xx1->Project({"RecoEventExt_centrality"});

    auto R1_qnqs_true_xx1 = new Correlation( "/home/valeriy/flow_calculator/build/STAR_27_D_weightone.root",
                                            {
                                                    "v2_protons/v2w.hadronsE_RECENTERED(hadronsW_RECENTERED.hadronsE_RECENTERED).x2x2","v2_protons/v2w.hadronsE_RECENTERED(hadronsW_RECENTERED.hadronsE_RECENTERED).y2y2"
                                            },"protons_eta_negative" );
    R1_qnqs_true_xx1->SetCalculateSystematicsFromVariation(false);
    R1_qnqs_true_xx1->SetStyle( kBlue, kFullCircle );
    R1_qnqs_true_xx1->Scale(1);
    R1_qnqs_true_xx1->Select({{"RecoEventExt_centrality", {10,20,30,40}},
                             {"TpcTracks_pT",{0.2,0.4,0.6,0.8,1.0,1.2,1.4,1.6,1.8,2.0}}});
    R1_qnqs_true_xx1->Project({"TpcTracks_eta"});



    auto R1_qnqs_res_xx1 = new Correlation( "/home/valeriy/flow_calculator/build/STAR_27_D_weightone.root",
                                           {
                                                   "v2_protons/v2w.hadronsE_RECENTERED(hadronsW_RECENTERED.hadronsE_RECENTERED).x2x2","v2_protons/v2w.hadronsE_RECENTERED(hadronsW_RECENTERED.hadronsE_RECENTERED).y2y2"
                                           },"40<cent<60 %" );
    R1_qnqs_res_xx1->SetCalculateSystematicsFromVariation(false);
    R1_qnqs_res_xx1->SetStyle( kGreen, kFullCircle );
    R1_qnqs_res_xx1->Scale(1);
    R1_qnqs_res_xx1->Select({{"RecoEventExt_centrality", {40.,50.,60.}},
                            {"TpcTracks_pT",{0.2,0.4,0.6,0.8,1.0,1.2,1.4,1.6,1.8,2.0}}});
    R1_qnqs_res_xx1->Project({"TpcTracks_eta"});

    auto R1_qnqs_xx2 = new Correlation( "/home/valeriy/flow_calculator/build/STAR_27_D_weightone.root",
                                       {
                                               "v2_protons/v2e.hadronsW_RECENTERED(hadronsW_RECENTERED.hadronsE_RECENTERED).x2x2","v2_protons/v2e.hadronsW_RECENTERED(hadronsW_RECENTERED.hadronsE_RECENTERED).y2y2"

                                       }," eW" );
    R1_qnqs_xx2->SetCalculateSystematicsFromVariation(false);
    R1_qnqs_xx2->SetStyle( kRed, kFullCircle );
    R1_qnqs_xx2->Scale(1);
    R1_qnqs_xx2->Select({{"RecoEventExt_centrality", {0,5.,10.} },
                        {"TpcTracks_pT",{0.2,0.4,0.6,0.8,1.0,1.2,1.4,1.6,1.8,2.0}}});
    R1_qnqs_xx2->Project({"TpcTracks_eta"});

    auto R1_qnqs_true_xx2 = new Correlation( "/home/valeriy/flow_calculator/build/STAR_27_D_weightone.root",
                                            {
                                                    "v2_protons/v2e.hadronsW_RECENTERED(hadronsW_RECENTERED.hadronsE_RECENTERED).x2x2","v2_protons/v2e.hadronsW_RECENTERED(hadronsW_RECENTERED.hadronsE_RECENTERED).y2y2"

                                            },"protons_eta_positive" );
    R1_qnqs_true_xx2->SetCalculateSystematicsFromVariation(false);
    R1_qnqs_true_xx2->SetStyle( kBlue, kFullCircle );
    R1_qnqs_true_xx2->Scale(1);
    R1_qnqs_true_xx2->Select({{"RecoEventExt_centrality", {10,20,30,40}},
                             {"TpcTracks_pT",{0.2,0.4,0.6,0.8,1.0,1.2,1.4,1.6,1.8,2.0}}});
    R1_qnqs_true_xx2->Project({"TpcTracks_eta"});



    auto R1_qnqs_res_xx2 = new Correlation( "/home/valeriy/flow_calculator/build/STAR_27_D_weightone.root",
                                           {
                                                   "v2_protons/v2e.hadronsW_RECENTERED(hadronsW_RECENTERED.hadronsE_RECENTERED).x2x2","v2_protons/v2e.hadronsW_RECENTERED(hadronsW_RECENTERED.hadronsE_RECENTERED).y2y2"
                                           },"40<cent<60 %" );
    R1_qnqs_res_xx2->SetCalculateSystematicsFromVariation(false);
    R1_qnqs_res_xx2->SetStyle( kGreen, kFullCircle );
    R1_qnqs_res_xx2->Scale(1);
    R1_qnqs_res_xx2->Select({{"RecoEventExt_centrality", {40.,50.,60.}},
                            {"TpcTracks_pT",{0.2,0.4,0.6,0.8,1.0,1.2,1.4,1.6,1.8,2.0}}});
    R1_qnqs_res_xx2->Project({"TpcTracks_eta"});








  HeapPicture pic( "v2_au123_y_slices_pT", {1000, 1000});
    pic.AddText({0.42, 0.9, "Reco #pi^{+} 0.2<p_{T}<2.0 #frac{GeV}{c}"}, 0.04);
   // pic.AddText({0.5, 0.85, "0-10 % "}, 0.04);

    pic.AddDrawable(R1_qnqs_xx1);
 //   pic.AddDrawable(R1_qnqs_xx2);



  //  leg1->AddEntry( R1_qnqs_xx1->GetPoints(), R1_qnqs_xx1->GetTitle().c_str(), "P" );

  pic.SetAxisTitles({"centrality", "v_{2}"});
  pic.AddLegend(leg1);

  pic.SetXRange({0,80});
  pic.SetYRange({0,0.2});
  pic.Draw();
    pic.Save("/home/valeriy/STAR_Qn/27_D/v2_Reco_protons_centrality_West","png");
 // pic.Save("/home/valeriy/STAR_Qn/27_D/v2_Reco_protons_eta_centrality_010","png");
    pic.SavePoints("/home/valeriy/TVV_STAR_points_protons_centrality","root");

    HeapPicture pic2( "v2_au123_y_slices_pT2", {1000, 1000});
    pic2.AddText({0.42, 0.9, "Reco #pi^{+} 0.2<p_{T}<2.0 #frac{GeV}{c}"}, 0.04);
    pic2.AddText({0.7, 0.85, "10-40 % "}, 0.04);

    pic2.AddDrawable(R1_qnqs_true_xx1);
    pic2.AddDrawable(R1_qnqs_true_xx2);
  //  leg2->AddEntry( R1_qnqs_xx1->GetPoints(), R1_qnqs_xx1->GetTitle().c_str(), "P" );


    pic2.SetAxisTitles({"eta ", "v_{2}"});
    pic2.AddLegend(leg2);

    pic2.SetXRange({-1,1});
    pic2.SetYRange({0,0.3});
    pic2.Draw();
    pic2.Save("/home/valeriy/STAR_Qn/27_D/v2_Reco_protons_eta_centrality_1040","png");
    pic2.SavePoints("/home/valeriy/TVV_STAR_points_protons_eta","root");

    HeapPicture pic3( "v2_au123_y_slices_pT3", {1000, 1000});
    pic3.AddText({0.7, 0.85, "40-60 % "}, 0.04);

    pic3.AddDrawable(R1_qnqs_res_xx1);
    pic3.AddDrawable(R1_qnqs_res_xx2);
  //  leg3->AddEntry( R1_qnqs_xx1->GetPoints(), R1_qnqs_xx1->GetTitle().c_str(), "P" );


    pic3.SetAxisTitles({"eta ", "v_{2}"});
    pic3.AddLegend(leg3);

    pic3.SetXRange({-1,1});
    pic3.SetYRange({0,0.3});
    pic3.Draw();
    pic3.Save("/home/valeriy/STAR_Qn/27_D/v2_Reco_protons_eta_centrality_4060","png");

}
