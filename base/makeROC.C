//STL
#include <vector>
//ROOT
#include "TH1F.h"
#include "TGraph.h"
//Custom
//#include "/dune/app/users/dbrailsf/tracs/plotting_scripts/hotplot/base/config1D.h"

TGraph* MakeROC(TH1F const * const h_signal, TH1F const * const h_background, bool cut_to_left, bool include_underflow, bool include_overflow){
  gROOT->SetStyle("T2K");
  TGraph* g_roc = new TGraph();
  g_roc->SetName("g_roc");
  g_roc->SetTitle(TString("ROC curve;")+h_signal->GetTitle()+TString(" efficiency;")+h_background->GetTitle()+TString(" rejection"));
  g_roc->SetMarkerColor(kBlack);

  const int binLow(include_underflow ? 0 : 1);
  const int binHigh(include_overflow ? h_signal->GetXaxis()->GetNbins() + 1 : h_signal->GetXaxis()->GetNbins());
  
  const int loopDirection(cut_to_left ? -1 : 1);
  const int binFirst(cut_to_left ? binHigh : binLow);
  const int binLast(cut_to_left ? binLow : binHigh);

  const float signalTotal(h_signal->Integral(binLow, binHigh));
  const float backgroundTotal(h_background->Integral(binLow, binHigh));

  for (int i_bin = binFirst; i_bin != binLast + loopDirection; i_bin += loopDirection)
  {
      const int integralLower(cut_to_left ? binLow : i_bin);
      const int integralUpper(cut_to_left ? i_bin : binHigh);

      const float selSignal(h_signal->Integral(integralLower, integralUpper));
      const float selBackground(h_background->Integral(integralLower, integralUpper));

      const float signalEfficiency(signalTotal > 0.f ? selSignal/signalTotal : 0.f);
      const float backgroundRejection(backgroundTotal > 0.f ? (backgroundTotal-selBackground)/backgroundTotal : 0.f);

      g_roc->SetPoint(g_roc->GetN(), signalEfficiency, backgroundRejection);
  }

  //g_roc->SetMarkerStyle(51);

  g_roc->SetLineWidth(2);
  g_roc->SetLineColor(kBlue+2);
  return g_roc;
}
