#ifndef CONFIG1D_DEF
#define CONFIG1D_DEF
//STL
//ROOT
#include "TChain.h"
#include "TString.h"
//CUSTOM

struct Config1D {
  TString name;
  TString draw;
  TString selection;
  TString legend;
  TString xaxis;
  TString yaxis;
  int nbins;
  double binlow;
  double binhigh;
  int linecolor;
  double linewidth;
  double linestyle;
  TChain *chain;
};
#endif
