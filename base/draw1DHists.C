//STL
#include <vector>
#include <algorithm>
//ROOT
#include "TH1F.h"
#include "TCanvas.h"
//Custom
#include "/dune/app/users/dbrailsf/tracs/plotting_scripts/hotplot/base/config1D.h"

TCanvas* Draw1DHists(std::vector<Config1D> const& confs, std::vector<TH1F*> & hists){

  //Set the max
  double max = -99999999.;
  for (size_t i_hist = 0; i_hist < hists.size(); i_hist++){
    double curr_hist_max = hists[i_hist]->GetMaximum();
    max = std::max(curr_hist_max,max);
  }
  max *= 1.05;
  for (size_t i_hist = 0; i_hist < hists.size(); i_hist++){
    hists[i_hist]->SetMaximum(max);
  }
  TCanvas *canvas = new TCanvas ("can","can",800,800);
  for (size_t i_hist = 0; i_hist < hists.size(); i_hist++){
    TString draw = "histsame";
    if (i_hist==0) draw = "hist";
    hists[i_hist]->Draw(draw);
  }

  return canvas;
}
