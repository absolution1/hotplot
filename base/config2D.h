#ifndef CONFIG2D_DEF
#define CONFIG2D_DEF
//STL
//ROOT
#include "TChain.h"
#include "TString.h"
//CUSTOM

struct Config2D {
  TString name;
  TString draw;
  TString selection;
  TString legend;
  TString xaxis;
  TString yaxis;
  TString zaxis;
  int nbinsx;
  double binlowx;
  double binhighx;
  int nbinsy;
  double binlowy;
  double binhighy;
  int markercolor;
  int markerstyle;
  int markersize;
  TChain *chain;
};
#endif
