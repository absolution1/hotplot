//STL
#include <vector>
//ROOT
#include "TH1F.h"
#include "TEfficiency.h"
//Custom
//#include "/dune/app/users/dbrailsf/tracs/plotting_scripts/hotplot/base/config1D.h"

TEfficiency* MakeTEfficiency(TH1F const * const h_numerator, TH1F const * const h_denominator){
  gROOT->SetStyle("T2K");
  TEfficiency* efficiency = new TEfficiency(*h_numerator, *h_denominator);
  efficiency->SetTitle(h_numerator->GetTitle()+TString(";")+h_numerator->GetXaxis()->GetTitle()+TString(";Fraction (no units)"));
  efficiency->SetMarkerColor(h_numerator->GetLineColor());
  //efficiency->SetMarkerStyle(51);

  return efficiency;
}
