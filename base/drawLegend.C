//STL
#include <vector>
#include <algorithm>
//ROOT
#include "TH1F.h"
#include "TCanvas.h"
#include "TLegend.h"
//Custom
#include "/dune/app/users/dbrailsf/tracs/plotting_scripts/hotplot/base/config1D.h"

void DrawLegend(std::vector<Config1D> const& confs, std::vector<TH1F*> & hists, TCanvas *canvas){

  canvas->cd();
  TLegend *leg = new TLegend(0.12,0.71,0.71,0.83);
  for (int i_hist = hists.size()-1; i_hist >= 0; i_hist--){
    TLegendEntry *entry = leg->AddEntry(hists[i_hist],confs[i_hist].legend,"");
    entry->SetTextColor(confs[i_hist].linecolor);
  }

  leg->SetLineColor(0);
  leg->SetFillStyle(0);
  leg->SetBorderSize(0);
  leg->SetTextSize(0.035);
  leg->Draw();

  return;
}
