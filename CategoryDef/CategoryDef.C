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
  ((CategoryDef&)obj).binsCalib         = binsCalib ;
  ((CategoryDef&)obj).catIntegral       =  catIntegral;
  ((CategoryDef&)obj).IPmax          =  IPmax;
}


void CategoryDef::initHisto(const char* title, int nbin, double xmin, double xmax){
  histo = new TH1D(title, title, nbin, xmin, xmax);
}


void CategoryDef::fillHisto(double value, double weight){
  histo->Fill(value, weight);
}


void CategoryDef::FillBinsVector(){
  
  binsCalib.clear();
  
  catIntegral = 0;
  for(unsigned int i= 1; i<histo->GetNbinsX()+2; i++){
    binsCalib.push_back(histo->GetBinContent(i) );
    catIntegral += histo->GetBinContent(i);
  }
  
  IPmax = histo->GetXaxis()->GetXmax();
}

void CategoryDef::GetDistribFromFile(TFile * thefile){
  histo = (TH1D*) thefile->Get( (histoname).Data() );
  if((TH1D*) thefile->Get( (histoname).Data() ) == 0) cout << "unable to retrieve the histogram " << endl;
  FillBinsVector();
}



double CategoryDef::calculTrackProba(double IPsigm){
  
  if(binsCalib.size() == 0) return -1000000;
  
  double nbins = binsCalib.size()-1;
  double xmax = IPmax;
  int nbin = int(fabs(IPsigm)*(nbins+1)/xmax);
  
   
  double sum=0.0;
  for(int i=nbin; i<=(nbins) ; i++){
    sum += binsCalib[i]; 
  }
  
  double proba= sum/catIntegral;
  
  if(IPsigm<0) proba=-proba;
  
  return proba;
}




