#include "CategoryDef.h"
#include "stdio.h"
#include <iostream>

ClassImp(CategoryDef)


CategoryDef::CategoryDef(): TObject()
{
  
}

CategoryDef::CategoryDef(const CategoryDef &catdef): TObject(catdef)
{
  ((CategoryDef&)catdef).Copy(*this);
}


void CategoryDef::Copy(TObject &obj) const 
{
  
  TObject::Copy(obj);
  ((CategoryDef&)obj).pMin          = pMin ;
  ((CategoryDef&)obj).pMax          = pMax ;
  ((CategoryDef&)obj).etaMin        = etaMin ;
  ((CategoryDef&)obj).etaMax        = etaMax ;
  ((CategoryDef&)obj).nHitsMin      = nHitsMin ;
  ((CategoryDef&)obj).nHitsMax      = nHitsMax ;
  ((CategoryDef&)obj).nPixelHitsMin = nPixelHitsMin ;
  ((CategoryDef&)obj).nPixelHitsMax = nPixelHitsMax ;
  ((CategoryDef&)obj).chiMin        = chiMin ;
  ((CategoryDef&)obj).chiMax        = chiMax ;
  ((CategoryDef&)obj).withFirstPixelHit = withFirstPixelHit ;
  ((CategoryDef&)obj).histoname         = histoname ;
  ((CategoryDef&)obj).histo             = histo ;
}


void CategoryDef::initHisto(const char* title, int nbin, double xmin, double xmax){
  histo = new TH1D(title, title, nbin, xmin, xmax);
}


void CategoryDef::fillHisto(double value, double weight){
  histo->Fill(value, weight);
}


void CategoryDef::GetHistoFromFile(TFile * thefile){
  histo = (TH1D*) thefile->Get( (histoname).Data() );
  if((TH1D*) thefile->Get( (histoname).Data() ) == 0) cout << "unable to retrieve the histogram " << endl;
}





