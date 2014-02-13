#ifndef CategoryDef_H
#define CategoryDef_H


#include <string>
#include <TObject.h>
#include <TH1D.h>
#include <TFile.h>
#include <TString.h>
#include <TRef.h>

class CategoryDef  : public TObject {
  public :
    
    CategoryDef() ;
    CategoryDef(const CategoryDef &catdef) ;
  ~CategoryDef() {};
  
  void Copy(TObject &catdef) const;
  void initHisto(const char*, int, double, double);
  void fillHisto( double, double);


  double    pMin;
  double    pMax;
  double    etaMin;
  double    etaMax;
  int       nHitsMin;
  int       nHitsMax;
  int       nPixelHitsMin;
  int       nPixelHitsMax;
  double    chiMin;
  double    chiMax;
  int       withFirstPixelHit;
  TString   histoname;
  TH1D      *histo;//! blabla
  //TRef historef;
  void GetHistoFromFile(TFile * thefile);
  
  
  ClassDef(CategoryDef, 1)
};


#endif
