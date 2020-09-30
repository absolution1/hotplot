//STL
#include <vector>
//ROOT
#include "TH1F.h"
//Custom
#include "/dune/app/users/dbrailsf/tracs/plotting_scripts/hotplot/base/config1D.h"

//norm == 0  == no norm
//norm == 1  == unit norm
//norm == 2  == max height = 1.
std::vector<TH1F*> Make1DHists(std::vector<Config1D> const& confs, int norm = 0){
  gROOT->SetStyle("T2K");
  gROOT->ProcessLine(".x /dune/app/users/dbrailsf/tracs/plotting_scripts/hotplot/base/ttree_functions/load_ttree_functions.C");
  std::vector<TH1F*> hists;
  for (size_t i_conf = 0; i_conf < confs.size(); i_conf++){
    hists.emplace_back(new TH1F(confs[i_conf].name,"",confs[i_conf].nbins,confs[i_conf].binlow,confs[i_conf].binhigh));
    hists[i_conf]->SetLineColor(confs[i_conf].linecolor);
    hists[i_conf]->SetLineWidth(confs[i_conf].linewidth);
    hists[i_conf]->SetLineStyle(confs[i_conf].linestyle);
    hists[i_conf]->GetXaxis()->SetTitle(confs[i_conf].xaxis);
    hists[i_conf]->GetYaxis()->SetTitle(confs[i_conf].yaxis);
    hists[i_conf]->SetFillStyle(3003);
    hists[i_conf]->SetFillColor(confs[i_conf].linecolor);
    hists[i_conf]->GetYaxis()->SetTitleOffset(1.2);
    //confs[i_conf].chain->Scan("Run:Subrun:EventID:RecoShowerDirectionZ[RecoIndexShowerHighestNHits]:CalculateUnitDotProduct(RecoShowerDirectionX[RecoIndexShowerHighestNHits], RecoShowerDirectionY[RecoIndexShowerHighestNHits], RecoShowerDirectionZ[RecoIndexShowerHighestNHits], TrueStartMomX[0], TrueStartMomY[0], TrueStartMomZ[0])","RecoNShowers == 1 && RecoIndexShowerHighestNHits>-999 && TruePDG[RecoTrueIndexPrimaryShowerParticle[RecoIndexShowerHighestNHits]] == 11 && TrueMotherID[RecoTrueIndexPrimaryShowerParticle[RecoIndexShowerHighestNHits]]==0 ");
    //confs[i_conf].chain->Scan("Run:Subrun:EventID:RecoNShowerHits[RecoIndexShowerHighestNHits]:RecoNInitialTrackHits[RecoIndexShowerHighestNHits]:TruePDG[RecoInitialTrackTrueIndexPrimaryShowerParticle[RecoIndexShowerHighestNHits]]:RecoInitialTrackTrueFractionPrimaryParticleHitsInShower[RecoIndexShowerHighestNHits]","RecoNShowers> 0 && RecoIndexShowerHighestNHits>-999 && TruePDG[RecoTrueIndexPrimaryShowerParticle[RecoIndexShowerHighestNHits]] == 11 && TrueMotherID[RecoTrueIndexPrimaryShowerParticle[RecoIndexShowerHighestNHits]]==0 && RecoInitialTrackTrueIndexPrimaryShowerParticle[RecoIndexShowerHighestNHits]>-999");

    //confs[i_conf].chain->Scan("Run:Subrun:EventID:RecoNShowers:RecoNShowerSpacePoints[RecoIndexShowerHighestNHits]:RecoNShowerHits[RecoIndexShowerHighestNHits]:RecoTrueCompletenessPrimaryShowerParticle[RecoIndexShowerHighestNHits]","RecoTrueCompletenessPrimaryShowerParticle[RecoIndexShowerHighestNHits]<0.1 && TruePDG[RecoTrueIndexPrimaryShowerParticle[RecoIndexShowerHighestNHits]] == 11 && TrueMotherID[RecoTrueIndexPrimaryShowerParticle[RecoIndexShowerHighestNHits]]==0");
    //confs[i_conf].chain->Scan("Run:Subrun:EventID:TrueStartX[0]:TrueStartY[0]:TrueStartZ[0]:RecoPrimaryVertexX:RecoPrimaryVertexY:RecoPrimaryVertexZ:CalculateDisplacement(RecoPrimaryVertexX, RecoPrimaryVertexY, RecoPrimaryVertexZ, TrueStartX[0], TrueStartY[0], TrueStartZ[0])","CalculateDisplacement(RecoPrimaryVertexX, RecoPrimaryVertexY, RecoPrimaryVertexZ, TrueStartX[0], TrueStartY[0], TrueStartZ[0]) >50 && CalculateDisplacement(RecoPrimaryVertexX, RecoPrimaryVertexY, RecoPrimaryVertexZ, TrueStartX[0], TrueStartY[0], TrueStartZ[0]) < 60");
    confs[i_conf].chain->Draw(confs[i_conf].draw+">>+"+confs[i_conf].name,confs[i_conf].selection,"goff");

  }
  if (norm == 1){
    for (size_t i_hist = 0; i_hist < hists.size(); i_hist++){
      hists[i_hist]->Scale(1./hists[i_hist]->Integral());
    }
  }
  return hists;
}
