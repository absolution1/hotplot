//STL
#include <iostream>
//ROOT
//CUSTOM
#include "/dune/app/users/dbrailsf/tracs/plotting_scripts/hotplot/base/headers.h"

void hitPurityPrimaryTrackShowerMaxHits(){

  std::vector<Config1D> confs;

  confs.emplace_back(Config1D());
  confs.back().name="PCA_3DTrackFinder";
  confs.back().nbins = 100;
  confs.back().binlow = 0;
  confs.back().binhigh = 1;
  confs.back().linecolor = 1;
  confs.back().linewidth = 2;
  confs.back().linestyle = 1;
  confs.back().draw = "RecoInitialTrackTrueHitPurityPrimaryShowerParticle[RecoIndexShowerHighestNHits]";
  confs.back().selection = "RecoNShowers> 0 && RecoIndexShowerHighestNHits[RecoIndexShowerHighestNHits]>-999 && TruePDG[RecoTrueIndexPrimaryShowerParticle[RecoIndexShowerHighestNHits]] == 11 && TrueMotherID[RecoTrueIndexPrimaryShowerParticle[RecoIndexShowerHighestNHits]]==0 && RecoInitialTrackTrueIndexPrimaryShowerParticle[RecoIndexShowerHighestNHits]>-999";
  confs.back().xaxis = "Hit purity (primary e^{-})";
  confs.back().yaxis = "No. events";
  confs.back().legend = "PCA+3D track finder";
  confs.back().chain = new TChain("showertreebuilder/STB");
  confs.back().chain->Add("/dune/data/users/dbrailsf/tracs/electrons_with_vertex/showertree_tracs_reco_v08_30_00_A_v08_30_00_A_prodsingle_eminus_0.5-5.0GeV_piminus_0.5-2.0GeV_vertex-like_dune10kt_1x2x6_23398572_*.root");

  confs.emplace_back(Config1D());
  confs.back().name="PCA_IncrementalTrackFinder";
  confs.back().nbins = 100;
  confs.back().binlow = 0;
  confs.back().binhigh = 1;
  confs.back().linecolor = 2;
  confs.back().linewidth = 2;
  confs.back().linestyle = 1;
  confs.back().draw = "RecoInitialTrackTrueHitPurityPrimaryShowerParticle[RecoIndexShowerHighestNHits]";
  confs.back().selection = "RecoNShowers> 0 && RecoIndexShowerHighestNHits[RecoIndexShowerHighestNHits]>-999 && TruePDG[RecoTrueIndexPrimaryShowerParticle[RecoIndexShowerHighestNHits]] == 11 && TrueMotherID[RecoTrueIndexPrimaryShowerParticle[RecoIndexShowerHighestNHits]]==0 && RecoInitialTrackTrueIndexPrimaryShowerParticle[RecoIndexShowerHighestNHits]>-999";
  confs.back().xaxis = "Hit purity (primary e^{-})";
  confs.back().yaxis = "No. events";
  confs.back().legend = "PCA+Incremental track finder";
  confs.back().chain = new TChain("showertreebuilder/STB");
  confs.back().chain->Add("/dune/data/users/dbrailsf/tracs/electrons_with_vertex_incrementalhitfinderpandoraslidingfit/showertree_tracs_reco_v08_30_00_A_v08_30_00_A_prodsingle_eminus_0.5-5.0GeV_piminus_0.5-2.0GeV_vertex-like_dune10kt_1x2x6_23398572_*.root");




  std::vector<TH1F*> hists = Make1DHists(confs,0);
  TCanvas *canvas  = Draw1DHists(confs, hists);
  DrawLegend(confs,hists, canvas);

}
