//STL
//ROOT
#include "TVector3.h"
//CUSTOM

double CalculateUnitDotProduct(double x1, double y1, double z1, double x2, double y2, double z2){
  TVector3 v1(x1,y1,z1);
  TVector3 v2(x2,y2,z2);

  TVector3 u1 = v1.Unit();
  TVector3 u2 = v2.Unit();

  double dot_product = u1.Dot(u2);

  return dot_product;
}
