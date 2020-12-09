//STL
#include <vector>
#include <algorithm>
//ROOT
#include "TH1F.h"
#include "TEfficiency.h"
#include "TCanvas.h"
#include "TLegend.h"
//Custom
#include "/dune/app/users/dbrailsf/tracs/plotting_scripts/hotplot/base/config1D.h"

void DrawLegend(std::vector<Config1D> const& confs, std::vector<TH1F*> & hists, TCanvas *canvas){

  canvas->cd();
  TLegend *leg = new TLegend(0.40,0.74,0.99,0.85);
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

void DrawLegend(std::vector<TEfficiency*> efficiencies, TCanvas *canvas)
{
    canvas->cd();
    TLegend *leg = new TLegend(0.40,0.74,0.99,0.85);

    for (int i_efficiency = efficiencies.size()-1; i_efficiency >= 0; i_efficiency--){
      TLegendEntry *entry = leg->AddEntry(efficiencies[i_efficiency],efficiencies[i_efficiency]->GetTitle(),"");
      entry->SetTextColor(efficiencies[i_efficiency]->GetPaintedGraph()->GetMarkerColor());
    }

    leg->SetLineColor(0);
    leg->SetFillStyle(0);
    leg->SetBorderSize(0);
    leg->SetTextSize(0.035);
    leg->Draw();


}
