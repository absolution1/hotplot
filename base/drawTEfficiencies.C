//STL
#include <vector>
#include <algorithm>
//ROOT
#include "TEfficiency.h"
#include "TCanvas.h"
//Custom

TCanvas* DrawTEfficiencies(std::vector<TEfficiency*> const& efficiencies){

  TCanvas *canvas = new TCanvas ("can","can",800,800);
  for (size_t i_efficiency = 0; i_efficiency < efficiencies.size(); i_efficiency++){
    TString draw = "same";
    if (i_efficiency==0) draw = "";
    efficiencies[i_efficiency]->Draw(draw);
    gPad->Update(); 
    auto graph = efficiencies[i_efficiency]->GetPaintedGraph(); 
    graph->SetMinimum(0);
    graph->SetMaximum(1.05); 
    gPad->Update(); 

  }

  return canvas;
}
