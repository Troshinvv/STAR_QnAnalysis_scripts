
// Created by mikhail on 5/6/21.
//

void Meanv1DrawpT(){
  gROOT->Macro( "/home/valeriy/flow_drawing_tools/example/style.cc" );
    auto leg1 = new TLegend( 0.2, 0.6, 0.4, 0.8 );
    auto leg2 = new TLegend( 0.2, 0.6, 0.4, 0.8 );
    auto leg3 = new TLegend( 0.2, 0.6, 0.4, 0.8 );
 // auto file_axis = TFile::Open( "/home/valeriy/hades_efficiency/cmake-build-debug/protons_axis.root" );
  TH1F* histo_axis;
 // file_axis->GetObject( "new_histogram", histo_axis );

//#frac{<cos(#phi_{1}-#Psi_{1}^{N,S})>}{R_{1}(#Psi_{1}^{N},#Psi_{1}^{S})}
  auto R1_qnqs_xx = new Correlation( "/home/valeriy/flow_calculator/build/STAR_27_D_pTall.root",
                                       {
                                               "v1_protons/v1w.bbcWest_RECENTERED(bbcWest_RECENTERED.bbcEast_RECENTERED).x1x1","v1_protons/v1w.bbcWest_RECENTERED(bbcWest_RECENTERED.bbcEast_RECENTERED).y1y1"

                                       }," bbcWest" );
  R1_qnqs_xx->SetCalculateSystematicsFromVariation(false);
  R1_qnqs_xx->SetStyle( kRed, kFullCircle );
  R1_qnqs_xx->Scale(-1);
     R1_qnqs_xx->Select({{"RecoEventExt_centrality", {5.,10.} },
                      {"TpcTracks_eta",5,0,1}});
  R1_qnqs_xx->Project({"TpcTracks_pT"});

  auto R1_qnqs_true_xx = new Correlation( "/home/valeriy/flow_calculator/build/STAR_27_D_pTall.root",
                                       {
                                               "v1_protons/v1w.bbcWest_RECENTERED(bbcWest_RECENTERED.bbcEast_RECENTERED).x1x1","v1_protons/v1w.bbcWest_RECENTERED(bbcWest_RECENTERED.bbcEast_RECENTERED).y1y1"

                                       },"10<cent<40 %" );
  R1_qnqs_true_xx->SetCalculateSystematicsFromVariation(false);
  R1_qnqs_true_xx->SetStyle( kBlue, kFullCircle );
  R1_qnqs_true_xx->Scale(-1);
  R1_qnqs_true_xx->Select({{"RecoEventExt_centrality", {10,20,30,40}},
                      {"TpcTracks_eta",5,0,1}});
  R1_qnqs_true_xx->Project({"TpcTracks_pT"});



  auto R1_qnqs_res_xx = new Correlation( "/home/valeriy/flow_calculator/build/STAR_27_D_pTall.root",
                                       {
                                               "v1_protons/v1w.bbcWest_RECENTERED(bbcWest_RECENTERED.bbcEast_RECENTERED).x1x1","v1_protons/v1w.bbcWest_RECENTERED(bbcWest_RECENTERED.bbcEast_RECENTERED).y1y1"

                                       },"40<cent<60 %" );
  R1_qnqs_res_xx->SetCalculateSystematicsFromVariation(false);
  R1_qnqs_res_xx->SetStyle( kGreen, kFullCircle );
  R1_qnqs_res_xx->Scale(-1);
  R1_qnqs_res_xx->Select({{"RecoEventExt_centrality", {40.,50.,60.}},
                      {"TpcTracks_eta",5,0,1}});
  R1_qnqs_res_xx->Project({"TpcTracks_pT"});


    auto R1_qnqs_xx1 = new Correlation( "/home/valeriy/flow_calculator/build/STAR_27_D_pTall.root",
                                       {
                                               "v1_protons/v1w.bbcEast_RECENTERED(bbcWest_RECENTERED.bbcEast_RECENTERED).x1x1","v1_protons/v1w.bbcEast_RECENTERED(bbcWest_RECENTERED.bbcEast_RECENTERED).y1y1"
                                       }," bbcEast" );
    R1_qnqs_xx1->SetCalculateSystematicsFromVariation(false);
    R1_qnqs_xx1->SetStyle( kBlack, kOpenSquare );
    R1_qnqs_xx1->Scale(-1);
    R1_qnqs_xx1->Select({{"RecoEventExt_centrality", {5.,10.} },
                        {"TpcTracks_eta",5,0,1}});
    R1_qnqs_xx1->Project({"TpcTracks_pT"});

    auto R1_qnqs_true_xx1 = new Correlation( "/home/valeriy/flow_calculator/build/STAR_27_D_pTall.root",
                                            {
                                                    "v1_protons/v1w.bbcEast_RECENTERED(bbcWest_RECENTERED.bbcEast_RECENTERED).x1x1","v1_protons/v1w.bbcEast_RECENTERED(bbcWest_RECENTERED.bbcEast_RECENTERED).y1y1"
                                            },"10<cent<40 %" );
    R1_qnqs_true_xx1->SetCalculateSystematicsFromVariation(false);
    R1_qnqs_true_xx1->SetStyle( kBlack, kOpenSquare );
    R1_qnqs_true_xx1->Scale(-1);
    R1_qnqs_true_xx1->Select({{"RecoEventExt_centrality", {10,20,30,40}},
                             {"TpcTracks_eta",5,0,1}});
    R1_qnqs_true_xx1->Project({"TpcTracks_pT"});



    auto R1_qnqs_res_xx1 = new Correlation( "/home/valeriy/flow_calculator/build/STAR_27_D_pTall.root",
                                           {
                                                   "v1_protons/v1w.bbcEast_RECENTERED(bbcWest_RECENTERED.bbcEast_RECENTERED).x1x1","v1_protons/v1w.bbcEast_RECENTERED(bbcWest_RECENTERED.bbcEast_RECENTERED).y1y1"
                                           },"40<cent<60 %" );
    R1_qnqs_res_xx1->SetCalculateSystematicsFromVariation(false);
    R1_qnqs_res_xx1->SetStyle( kBlack, kOpenSquare );
    R1_qnqs_res_xx1->Scale(-1);
    R1_qnqs_res_xx1->Select({{"RecoEventExt_centrality", {40.,50.,60.}},
                            {"TpcTracks_eta",5,0,1}});
    R1_qnqs_res_xx1->Project({"TpcTracks_pT"});

    auto R1_qnqs_xx2 = new Correlation( "/home/valeriy/flow_calculator/build/STAR_27_D_pTall.root",
                                       {
                                               "v1_protons/v1e.bbcWest_RECENTERED(bbcWest_RECENTERED.bbcEast_RECENTERED).x1x1","v1_protons/v1e.bbcWest_RECENTERED(bbcWest_RECENTERED.bbcEast_RECENTERED).y1y1"

                                       }," eW" );
    R1_qnqs_xx2->SetCalculateSystematicsFromVariation(false);
    R1_qnqs_xx2->SetStyle( kRed, kFullCircle );
    R1_qnqs_xx2->Scale(-1);
    R1_qnqs_xx2->Select({{"RecoEventExt_centrality", {5.,10.} },
                        {"TpcTracks_eta",5,0,1}});
    R1_qnqs_xx2->Project({"TpcTracks_pT"});

    auto R1_qnqs_true_xx2 = new Correlation( "/home/valeriy/flow_calculator/build/STAR_27_D_pTall.root",
                                            {
                                                    "v1_protons/v1e.bbcWest_RECENTERED(bbcWest_RECENTERED.bbcEast_RECENTERED).x1x1","v1_protons/v1e.bbcWest_RECENTERED(bbcWest_RECENTERED.bbcEast_RECENTERED).y1y1"

                                            },"10<cent<40 %" );
    R1_qnqs_true_xx2->SetCalculateSystematicsFromVariation(false);
    R1_qnqs_true_xx2->SetStyle( kBlue, kFullCircle );
    R1_qnqs_true_xx2->Scale(-1);
    R1_qnqs_true_xx2->Select({{"RecoEventExt_centrality", {10,20,30,40}},
                             {"TpcTracks_eta",5,0,1}});
    R1_qnqs_true_xx2->Project({"TpcTracks_pT"});



    auto R1_qnqs_res_xx2 = new Correlation( "/home/valeriy/flow_calculator/build/STAR_27_D_pTall.root",
                                           {
                                                   "v1_protons/v1e.bbcWest_RECENTERED(bbcWest_RECENTERED.bbcEast_RECENTERED).x1x1","v1_protons/v1e.bbcWest_RECENTERED(bbcWest_RECENTERED.bbcEast_RECENTERED).y1y1"
                                           },"40<cent<60 %" );
    R1_qnqs_res_xx2->SetCalculateSystematicsFromVariation(false);
    R1_qnqs_res_xx2->SetStyle( kGreen, kFullCircle );
    R1_qnqs_res_xx2->Scale(-1);
    R1_qnqs_res_xx2->Select({{"RecoEventExt_centrality", {40.,50.,60.}},
                            {"TpcTracks_eta",5,0,1}});
    R1_qnqs_res_xx2->Project({"TpcTracks_pT"});


    auto a1 = new Correlation( "/home/valeriy/flow_calculator/build/STAR_27_D_pTall.root",
                                        {

                                                "v1_protons/v1e.bbcEast_RECENTERED(bbcWest_RECENTERED.bbcEast_RECENTERED).x1x1","v1_protons/v1e.bbcEast_RECENTERED(bbcWest_RECENTERED.bbcEast_RECENTERED).y1y1"
                                        }," eE" );
    a1->SetCalculateSystematicsFromVariation(false);
    a1->SetStyle( kBlack, kOpenSquare );
    a1->Scale(-1);
    a1->Select({{"RecoEventExt_centrality", {5.,10.} },
                         {"TpcTracks_eta",5,0,1}});
    a1->Project({"TpcTracks_pT"});

    auto a2 = new Correlation( "/home/valeriy/flow_calculator/build/STAR_27_D_pTall.root",
                                             {

                                                     "v1_protons/v1e.bbcEast_RECENTERED(bbcWest_RECENTERED.bbcEast_RECENTERED).x1x1","v1_protons/v1e.bbcEast_RECENTERED(bbcWest_RECENTERED.bbcEast_RECENTERED).y1y1"
                                             },"10<cent<40 %" );
    a2->SetCalculateSystematicsFromVariation(false);
    a2->SetStyle( kBlack, kOpenSquare );
    a2->Scale(-1);
    a2->Select({{"RecoEventExt_centrality", {10,20,30,40}},
                              {"TpcTracks_eta",5,0,1}});
    a2->Project({"TpcTracks_pT"});



    auto a3 = new Correlation( "/home/valeriy/flow_calculator/build/STAR_27_D_pTall.root",
                                            {

                                                    "v1_protons/v1e.bbcEast_RECENTERED(bbcWest_RECENTERED.bbcEast_RECENTERED).x1x1","v1_protons/v1e.bbcEast_RECENTERED(bbcWest_RECENTERED.bbcEast_RECENTERED).y1y1"
                                            },"40<cent<60 %" );
    a3->SetCalculateSystematicsFromVariation(false);
    a3->SetStyle( kBlack, kOpenSquare );
    a3->Scale(-1);
    a3->Select({{"RecoEventExt_centrality", {40.,50.,60.}},
                             {"TpcTracks_eta",5,0,1}});
    a3->Project({"TpcTracks_pT"});





  HeapPicture pic( "v1_au123_y_slices_pT", {1000, 1000});
    pic.AddText({0.42, 0.9, "Reco p 0<|eta|<1"}, 0.04);
    pic.AddText({0.5, 0.85, "0-10 % "}, 0.04);

pic.AddDrawable(R1_qnqs_xx);
    pic.AddDrawable(R1_qnqs_xx1);
    pic.AddDrawable(R1_qnqs_xx2);
    pic.AddDrawable(a1);


leg1->AddEntry( R1_qnqs_xx->GetPoints(), R1_qnqs_xx->GetTitle().c_str(), "P" );
    leg1->AddEntry( R1_qnqs_xx1->GetPoints(), R1_qnqs_xx1->GetTitle().c_str(), "P" );

  pic.SetAxisTitles({"pT, GeV/c ", "v_{1}"});
  pic.AddLegend(leg1);

  pic.SetXRange({0,2});
  pic.SetYRange({-0.05,0.02});
  pic.Draw();
  pic.Save("/home/valeriy/STAR_Qn/27_D_f/v1_Reco_protons_pT_centrality_Recobbc010","png");

    HeapPicture pic2( "v1_au123_y_slices_pT2", {1000, 1000});
    pic2.AddText({0.42, 0.9, "Reco p 0<|eta|<1 "}, 0.04);
    pic2.AddText({0.7, 0.85, "10-40 % "}, 0.04);

pic2.AddDrawable(R1_qnqs_true_xx);
    pic2.AddDrawable(R1_qnqs_true_xx1);
    pic2.AddDrawable(R1_qnqs_true_xx2);
    pic2.AddDrawable(a2);
    leg2->AddEntry( R1_qnqs_true_xx->GetPoints(), R1_qnqs_xx->GetTitle().c_str(), "P" );
    leg2->AddEntry( R1_qnqs_xx1->GetPoints(), R1_qnqs_xx1->GetTitle().c_str(), "P" );


    pic2.SetAxisTitles({"pT, GeV/c ", "v_{1}"});
    pic2.AddLegend(leg2);

    pic2.SetXRange({0,2});
    pic2.SetYRange({-0.02,0.02});
    pic2.Draw();
    pic2.Save("/home/valeriy/STAR_Qn/27_D_f/v1_Reco_protons_pT_centrality_Recobbc1040","png");

    HeapPicture pic3( "v1_au123_y_slices_pT3", {1000, 1000});
    pic3.AddText({0.7, 0.85, "40-60 % "}, 0.04);

pic3.AddDrawable(R1_qnqs_res_xx);
    pic3.AddDrawable(R1_qnqs_res_xx1);
    pic3.AddDrawable(R1_qnqs_res_xx2);
    pic3.AddDrawable(a3);
    leg3->AddEntry( R1_qnqs_xx->GetPoints(), R1_qnqs_xx->GetTitle().c_str(), "P" );
    leg3->AddEntry( R1_qnqs_xx1->GetPoints(), R1_qnqs_xx1->GetTitle().c_str(), "P" );


    pic3.SetAxisTitles({"pT, GeV/c ", "v_{1}"});
    pic3.AddLegend(leg3);

    pic3.SetXRange({0,2});
    pic3.SetYRange({-0.05,0.02});
    pic3.Draw();
    pic3.Save("/home/valeriy/STAR_Qn/27_D_f/v1_Reco_protons_pT_centrality_Recobbc4060","png");

}
