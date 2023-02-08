
void full_calculator(){
  auto file = TFile::Open( "/home/valeriy/STAR_Qn/STAR27Gev_pTall.root" );

  auto file_out = TFile::Open( "STAR_27_D_pTall.root", "recreate" );
  file_out->cd();
  file_out->mkdir("resolutions");
  file_out->mkdir("v1_protons");
  file_out->mkdir("v1_pions");
  file_out->mkdir("v2_protons");
  file_out->mkdir("v2_pions");


  Correlation fn_fs( file, "QQ", {"bbcWest_RECENTERED", "bbcEast_RECENTERED"}, {"x1x1", "y1y1"});
  auto Ofn_fs = fn_fs*(-2);
  auto resolutionqnqs = Sqrt(Ofn_fs);
  file_out->cd("resolutions");
  resolutionqnqs.Save("R1.bbcWest_RECENTERED.bbcEast_RECENTERED");

    Correlation fn_fsext( file, "QQ", {"bbcWest_RECENTERED", "bbcEast_RECENTERED"}, {"x1x1","x1x1","y1y1", "y1y1"});
    auto Ofn_fsext = fn_fsext*(-2);
    auto resolutionqnqsext = Sqrt(Ofn_fsext);

    Correlation fn_fsext2( file, "QQ", {"bbcWest_RECENTERED", "bbcEast_RECENTERED"}, {"x1x1","y1y1","x1x1", "y1y1"});
    auto Ofn_fsext2 = fn_fsext2*(-2);
    auto resolutionqnqsext2 = Sqrt(Ofn_fsext2);





  Correlation fn_fs2( file, "QQ", {"hadronsW_RECENTERED", "hadronsE_RECENTERED"}, {"x2x2", "y2y2"});
  fn_fs2.Save("C2.hadronsW_RECENTERED.hadronsE_RECENTERED");
  auto Ofn_fs2 = fn_fs2*(2);
  auto resolutionqnqs2 = Sqrt(Ofn_fs2);
  file_out->cd("resolutions");
  resolutionqnqs2.Save("R2.hadronsW_RECENTERED.hadronsE_RECENTERED");

    Correlation fn_fs21( file, "uQ", {"hadronsWv_RECENTERED", "hadronsE_RECENTERED"}, {"x2x2", "y2y2"});
    fn_fs21.Save("C2w.hadronsWv_RECENTERED.hadronsE_RECENTERED");
    auto Ofn_fs21 = fn_fs21*(2)/resolutionqnqs2;
    file_out->cd("resolutions");
    Ofn_fs21.Save("V2w.hadronsWv_RECENTERED.hadronsE_RECENTERED");

    Correlation fn_fs22( file, "uQ", {"hadronsEv_RECENTERED", "hadronsW_RECENTERED"}, {"x2x2", "y2y2"});
    fn_fs22.Save("C2e.hadronsEv_RECENTERED.hadronsW_RECENTERED");
    auto Ofn_fs22 = fn_fs22*(2)/resolutionqnqs2;
    file_out->cd("resolutions");
    Ofn_fs22.Save("V2e.hadronsEv_RECENTERED.hadronsW_RECENTERED");




  Correlation u1p_fn( file, "uQ", {"protonW_RECENTERED", "bbcWest_RECENTERED"}, {"x1x1", "y1y1"});
  file_out->cd("v1_protons");
  auto v1p_fnres = u1p_fn*2 /resolutionqnqs;
  v1p_fnres.Save("v1w.bbcWest_RECENTERED(bbcWest_RECENTERED.bbcEast_RECENTERED)");


  Correlation u1p_fs( file, "uQ", {"protonW_RECENTERED", "bbcEast_RECENTERED"}, {"x1x1", "y1y1"});
  file_out->cd("v1_protons");
  auto v1p_fsres = u1p_fs*(-2) /resolutionqnqs;
  v1p_fsres.Save("v1w.bbcEast_RECENTERED(bbcWest_RECENTERED.bbcEast_RECENTERED)");

  Correlation u1pi_fn( file, "uQ", {"pionW_RECENTERED", "bbcWest_RECENTERED"}, {"x1x1", "y1y1"});
  file_out->cd("v1_pions");
  auto v1pi_fnres = u1pi_fn*2 /resolutionqnqs;
  v1pi_fnres.Save("v1w.bbcWest_RECENTERED(bbcWest_RECENTERED.bbcEast_RECENTERED)");


  Correlation u1pi_fs( file, "uQ", {"pionW_RECENTERED", "bbcEast_RECENTERED"}, {"x1x1", "y1y1"});
  file_out->cd("v1_pions");
  auto v1pi_fsres = u1pi_fs*(-2) /resolutionqnqs;
  v1pi_fsres.Save("v1w.bbcEast_RECENTERED(bbcWest_RECENTERED.bbcEast_RECENTERED)");

    Correlation u1p_fn1( file, "uQ", {"protonE_RECENTERED", "bbcWest_RECENTERED"}, {"x1x1", "y1y1"});
    file_out->cd("v1_protons");
    auto v1p_fn1res = u1p_fn1*2 /resolutionqnqs;
    v1p_fn1res.Save("v1e.bbcWest_RECENTERED(bbcWest_RECENTERED.bbcEast_RECENTERED)");


    Correlation u1p_fs1( file, "uQ", {"protonE_RECENTERED", "bbcEast_RECENTERED"}, {"x1x1", "y1y1"});
    file_out->cd("v1_protons");
    auto v1p_fs1res = u1p_fs1*(-2) /resolutionqnqs;
    v1p_fs1res.Save("v1e.bbcEast_RECENTERED(bbcWest_RECENTERED.bbcEast_RECENTERED)");

    Correlation u1pi_fn1( file, "uQ", {"pionE_RECENTERED", "bbcWest_RECENTERED"}, {"x1x1", "y1y1"});
    file_out->cd("v1_pions");
    auto v1pi_fn1res = u1pi_fn1*2 /resolutionqnqs;
    v1pi_fn1res.Save("v1e.bbcWest_RECENTERED(bbcWest_RECENTERED.bbcEast_RECENTERED)");


    Correlation u1pi_fs1( file, "uQ", {"pionE_RECENTERED", "bbcEast_RECENTERED"}, {"x1x1", "y1y1"});
    file_out->cd("v1_pions");
    auto v1pi_fs1res = u1pi_fs1*(-2) /resolutionqnqs;
    v1pi_fs1res.Save("v1e.bbcEast_RECENTERED(bbcWest_RECENTERED.bbcEast_RECENTERED)");




 /*   Correlation u2p_fn( file, "uQ", {"protonW_RECENTERED", "hadronsW_RECENTERED"}, {"x2x2","y2y2"});
    file_out->cd("v2_protons");
    auto v2p_fnres = u2p_fn*2 /resolutionqnqs2;
    v2p_fnres.Save("v2w.hadronsW_RECENTERED(hadronsW_RECENTERED.hadronsE_RECENTERED)");*/


    Correlation u2p_fs( file, "uQ", {"protonW_RECENTERED", "hadronsE_RECENTERED"}, {"x2x2","y2y2"});
    file_out->cd("v2_protons");
    auto v2p_fsres = u2p_fs*(2)/resolutionqnqs2 ;
    v2p_fsres.Save("v2w.hadronsE_RECENTERED(hadronsW_RECENTERED.hadronsE_RECENTERED)");

 /*   Correlation u2pi_fn( file, "uQ", {"pionW_RECENTERED", "hadronsW_RECENTERED"}, {"x2x2","y2y2"});
    file_out->cd("v2_pions");
    auto v2pi_fnres = u2pi_fn*2 /resolutionqnqs2;
    v2pi_fnres.Save("v2w.hadronsW_RECENTERED(hadronsW_RECENTERED.hadronsE_RECENTERED)");*/


    Correlation u2pi_fs( file, "uQ", {"pionW_RECENTERED", "hadronsE_RECENTERED"}, {"x2x2","y2y2"});
    file_out->cd("v2_pions");
    auto v2pi_fsres = u2pi_fs*(2) /resolutionqnqs2;
    v2pi_fsres.Save("v2w.hadronsE_RECENTERED(hadronsW_RECENTERED.hadronsE_RECENTERED)");

    Correlation u2p_fn1( file, "uQ", {"protonE_RECENTERED", "hadronsW_RECENTERED"}, {"x2x2","y2y2"});
    file_out->cd("v2_protons");
    auto v2p_fnres1 = u2p_fn1*2 /resolutionqnqs2;
    v2p_fnres1.Save("v2e.hadronsW_RECENTERED(hadronsW_RECENTERED.hadronsE_RECENTERED)");


 /*   Correlation u2p_fs1( file, "uQ", {"protonE_RECENTERED", "hadronsE_RECENTERED"}, {"x2x2","y2y2"});
    file_out->cd("v2_protons");
    auto v2p_fsres1 = u2p_fs1*(2) /resolutionqnqs2;
    v2p_fsres1.Save("v2e.hadronsE_RECENTERED(hadronsW_RECENTERED.hadronsE_RECENTERED)");*/

    Correlation u2pi_fn1( file, "uQ", {"pionE_RECENTERED", "hadronsW_RECENTERED"}, {"x2x2","y2y2"});
    file_out->cd("v2_pions");
    auto v2pi_fnres1 = u2pi_fn1*2 /resolutionqnqs2;
    v2pi_fnres1.Save("v2e.hadronsW_RECENTERED(hadronsW_RECENTERED.hadronsE_RECENTERED)");


  /*  Correlation u2pi_fs1( file, "uQ", {"pionE_RECENTERED", "hadronsE_RECENTERED"}, {"x2x2","y2y2"});
    file_out->cd("v2_pions");
    auto v2pi_fsres1 = u2pi_fs1*(2) /resolutionqnqs2;
    v2pi_fsres1.Save("v2e.hadronsE_RECENTERED(hadronsW_RECENTERED.hadronsE_RECENTERED)");*/

/*
    Correlation u2p_fn1( file, "uQ", {"protonW_RECENTERED", "bbcWest_RECENTERED"}, {"x2x1","y2y1"});
    file_out->cd("v2_protons");
    auto v2p_fnres1 = u2p_fn1*2 /resolutionqnqs;
    v2p_fnres1.Save("v2q1.bbcWest_RECENTERED(bbcWest_RECENTERED.bbcEast_RECENTERED)");


    Correlation u2p_fs1( file, "uQ", {"protonW_RECENTERED", "bbcEast_RECENTERED"}, {"x2x1","y2y1"});
    file_out->cd("v2_protons");
    auto v2p_fsres1 = u2p_fs1*(2) /resolutionqnqs;
    v2p_fsres1.Save("v2q1.bbcEast_RECENTERED(bbcWest_RECENTERED.bbcEast_RECENTERED)");

    Correlation u2pi_fn1( file, "uQ", {"pionW_RECENTERED", "bbcWest_RECENTERED"}, {"x2x1","y2y1"});
    file_out->cd("v2_pions");
    auto v2pi_fnres1 = u2pi_fn1*2 /resolutionqnqs;
    v2pi_fnres1.Save("v2q1.bbcWest_RECENTERED(bbcWest_RECENTERED.bbcEast_RECENTERED)");


    Correlation u2pi_fs1( file, "uQ", {"pionW_RECENTERED", "bbcEast_RECENTERED"}, {"x2x1","y2y1"});
    file_out->cd("v2_pions");
    auto v2pi_fsres1 = u2pi_fs1*(2) /resolutionqnqs;
    v2pi_fsres1.Save("v2q1.bbcEast_RECENTERED(bbcWest_RECENTERED.bbcEast_RECENTERED)");

*/


  /*

    Correlation u2p_qnqs (file, "uQ", {"protonW_RECENTERED","bbcWest_RECENTERED","bbcEast_RECENTERED"},{"x2x1x1", "y2x1y1","y2y1x1","x2y1y1"});
    u2p_qnqs = u2p_qnqs*std::vector{-4.0, -4.0, -4.0, 4.0}/(resolutionqnqsext*resolutionqnqsext2);
    file_out->cd("v2_protons");
    u2p_qnqs.Save("v2.bbcWest_RECENTERED.bbcEast_RECENTERED");

    Correlation u2pi_qnqs (file, "uQ", {"pionW_RECENTERED","bbcWest_RECENTERED","bbcEast_RECENTERED"},{"x2x1x1", "y2x1y1","y2y1x1","x2y1y1"});
    u2pi_qnqs = u2pi_qnqs*std::vector{-4.0, -4.0, -4.0, 4.0}/(resolutionqnqsext*resolutionqnqsext2);
    file_out->cd("v2_pions");
    u2pi_qnqs.Save("v2.bbcWest_RECENTERED.bbcEast_RECENTERED");*/











/*  auto v1odd = (v1p_fnres - v1p_fsres)/2;
  auto v1even = (v1p_fnres + v1p_fsres)/2;
  v1odd.Save("v1odd");
  v1even.Save("v1even");*/

  file_out->Close();
  file->Close();
}