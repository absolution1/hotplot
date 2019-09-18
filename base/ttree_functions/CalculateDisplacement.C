//STL
//ROOT
#include "TVector3.h"
//CUSTOM

double CalculateDisplacement(double x1, double y1, double z1, double x2, double y2, double z2){
  TVector3 v1(x1,y1,z1);
  TVector3 v2(x2,y2,z2);

  double disp = (v2-v1).Mag();

  return disp;
}
