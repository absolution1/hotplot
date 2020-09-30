//STL
#include <vector>
//ROOT
#include "TH2F.h"
//Custom
#include "/dune/app/users/dbrailsf/tracs/plotting_scripts/hotplot/base/config2D.h"

//norm == 0  == no norm
//norm == 1  == unit norm
//norm == 2  == max height = 1.
std::vector<TH2F*> Make2DHists(std::vector<Config2D> const& confs, int norm = 0){
  gROOT->SetStyle("T2K");
  gROOT->ProcessLine(".x /dune/app/users/dbrailsf/tracs/plotting_scripts/hotplot/base/ttree_functions/load_ttree_functions.C");
  std::vector<TH2F*> hists;
  for (size_t i_conf = 0; i_conf < confs.size(); i_conf++){
    hists.emplace_back(new TH2F(confs[i_conf].name,"",confs[i_conf].nbinsx,confs[i_conf].binlowx,confs[i_conf].binhighx, confs[i_conf].nbinsy, confs[i_conf].binlowy, confs[i_conf].binhighy));
    hists[i_conf]->SetMarkerColor(confs[i_conf].markercolor);
    hists[i_conf]->SetMarkerSize(confs[i_conf].markersize);
    hists[i_conf]->SetMarkerStyle(confs[i_conf].markerstyle);
    hists[i_conf]->GetXaxis()->SetTitle(confs[i_conf].xaxis);
    hists[i_conf]->GetYaxis()->SetTitle(confs[i_conf].yaxis);
    hists[i_conf]->GetYaxis()->SetTitleOffset(1.2);
    confs[i_conf].chain->Draw(confs[i_conf].draw+">>+"+confs[i_conf].name,confs[i_conf].selection,"goff");

  }
  if (norm == 1){
    for (size_t i_hist = 0; i_hist < hists.size(); i_hist++){
      hists[i_hist]->Scale(1./hists[i_hist]->Integral());
    }
  }
  return hists;
}
