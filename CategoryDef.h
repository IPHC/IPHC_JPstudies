#ifndef CategoryDef_H
#define CategoryDef_H


#include <string>
#include <TObject.h>
#include <TH1.h>
#include <vector>
#include <TStyle.h>
#include <TCanvas.h>
#include <TObject.h>


class CategoryDef{

public :
  CategoryDef(){};
  ~CategoryDef(){};

float   etaMax;	
float   etaMin;	
float   nHitsMax ;      
float   nHitsMin;
float   nPixelHitsMax; 
float   nPixelHitsMin; 
float   pMax;  	
float   pMin;  	
float   chiMin;	
float   chiMax;
int     withFirstPixelHit;
TH1D*   histoCalib;


};

#endif
