#include "CategoriesDefinition.h"

#include "TClass.h"


ClassImp(CategoriesDefinition)
  




std::vector<CategoryDef > CategoriesDefinition::CategoryList(){

  std::vector<CategoryDef > vectCategories;

  double nbins=10000;
  double xmin=0.0;
  double xmax=20.0;
  
  
  CategoryDef cat0;
  CategoryDef cat1;
  CategoryDef cat2;
  CategoryDef cat3;
  CategoryDef cat4;
  CategoryDef cat5;
  CategoryDef cat6;
  CategoryDef cat7;
  CategoryDef cat8;
  CategoryDef cat9;
  
  
  
  
  //categorie definitions:
  
  //cat 0  
  cat0.etaMax        = 2.7;
  cat0.etaMin        = 0;
  cat0.nHitsMax      = 50;
  cat0.nHitsMin      = 8;
  cat0.nPixelHitsMax = 1;
  cat0.nPixelHitsMin = 1;
  cat0.pMax          = 500000;
  cat0.pMin          = 0;
  cat0.chiMin        = 0;
  cat0.chiMax        = 5;
  cat0.withFirstPixelHit = 0;  
  cat0.histoname = "histoCat0";
  cat0.histo	    = new TH1D( cat0.histoname,  cat0.histoname, nbins, xmin, xmax);
  
  
  
  
  //cat 1
  cat1.etaMax        = 2.7;
  cat1.etaMin        = 0;
  cat1.nHitsMax      = 50;
  cat1.nHitsMin      = 8;
  cat1.nPixelHitsMax = 8;
  cat1.nPixelHitsMin = 2;
  cat1.pMax          = 500000;
  cat1.pMin          = 0;
  cat1.chiMin        = 2.5;
  cat1.chiMax        = 5;
  cat1.withFirstPixelHit  = 0;
  cat1.histoname = "histoCat1";
  cat1.histo	    = new TH1D( cat1.histoname,  cat1.histoname, nbins, xmin, xmax);
   
    
  //cat 2
  cat2.etaMax        = 0.8;
  cat2.etaMin        = 0;
  cat2.nHitsMax      = 50;
  cat2.nHitsMin      = 8;
  cat2.nPixelHitsMax = 8;
  cat2.nPixelHitsMin = 3;
  cat2.pMax          = 8;
  cat2.pMin          = 0;
  cat2.chiMin        = 0;
  cat2.chiMax        = 2.5;
  cat2.withFirstPixelHit  = 0;
  cat2.histoname = "histoCat2";
  cat2.histo	    = new TH1D( cat2.histoname,  cat2.histoname, nbins, xmin, xmax);


  //cat 3
  cat3.etaMax        = 1.6;
  cat3.etaMin        = 0.8;
  cat3.nHitsMax      = 50;
  cat3.nHitsMin      = 8;
  cat3.nPixelHitsMax = 8;
  cat3.nPixelHitsMin = 3;
  cat3.pMax          = 8;
  cat3.pMin          = 0;
  cat3.chiMin        = 0;
  cat3.chiMax        = 2.5;
  cat3.withFirstPixelHit  = 0;
  cat3.histoname = "histoCat3";
  cat3.histo	    = new TH1D( cat3.histoname,  cat3.histoname, nbins, xmin, xmax);



  //cat 4
  cat4.etaMax        = 2.7;
  cat4.etaMin        = 1.6;
  cat4.nHitsMax      = 50;
  cat4.nHitsMin      = 8;
  cat4.nPixelHitsMax = 8;
  cat4.nPixelHitsMin = 3;
  cat4.pMax          = 8;
  cat4.pMin          = 0;
  cat4.chiMin        = 0;
  cat4.chiMax        = 2.5;
  cat4.withFirstPixelHit  = 0;
  cat4.histoname = "histoCat4";
  cat4.histo	    = new TH1D( cat4.histoname,  cat4.histoname, nbins, xmin, xmax);


  //cat 5
  cat5.etaMax        = 2.7;
  cat5.etaMin        = 0;
  cat5.nHitsMax      = 50;
  cat5.nHitsMin      = 8;
  cat5.nPixelHitsMax = 2;
  cat5.nPixelHitsMin = 2;
  cat5.pMax          = 8;
  cat5.pMin          = 0;
  cat5.chiMin        = 0;
  cat5.chiMax        = 2.5;
  cat5.withFirstPixelHit  = 0;
  cat5.histoname = "histoCat5";
  cat5.histo	    = new TH1D( cat5.histoname,  cat5.histoname, nbins, xmin, xmax);



  //cat 6
  cat6.etaMax        = 0.8;
  cat6.etaMin        = 0;
  cat6.nHitsMax      = 50;
  cat6.nHitsMin      = 8;
  cat6.nPixelHitsMax = 8;
  cat6.nPixelHitsMin = 3;
  cat6.pMax          = 500000;
  cat6.pMin          = 8;
  cat6.chiMin        = 0;
  cat6.chiMax        = 2.5;
  cat6.withFirstPixelHit  = 0;
  cat6.histoname = "histoCat6";
  cat6.histo	    = new TH1D( cat6.histoname,  cat6.histoname, nbins, xmin, xmax);


  //cat 7
  cat7.etaMax        = 1.6;
  cat7.etaMin        = 0.8;
  cat7.nHitsMax      = 50;
  cat7.nHitsMin      = 8;
  cat7.nPixelHitsMax = 8;
  cat7.nPixelHitsMin = 3;
  cat7.pMax          = 50000;
  cat7.pMin          = 8;
  cat7.chiMin        = 0;
  cat7.chiMax        = 2.5;
  cat7.withFirstPixelHit  = 0;
  cat7.histoname = "histoCat7";
  cat7.histo	    = new TH1D( cat7.histoname,  cat7.histoname, nbins, xmin, xmax);
  
  //cat 8
  cat8.etaMax        = 2.7;
  cat8.etaMin        = 1.6;
  cat8.nHitsMax      = 50;
  cat8.nHitsMin      = 8;
  cat8.nPixelHitsMax = 8;
  cat8.nPixelHitsMin = 3;
  cat8.pMax          = 500000;
  cat8.pMin          = 8;
  cat8.chiMin        = 0;
  cat8.chiMax        = 2.5;
  cat8.withFirstPixelHit  = 0;
  cat8.histoname = "histoCat8";
  cat8.histo	    = new TH1D( cat8.histoname,  cat8.histoname, nbins, xmin, xmax);

  //cat 9
  cat9.etaMax        = 2.7;
  cat9.etaMin        = 0;
  cat9.nHitsMax      = 50;
  cat9.nHitsMin      = 8;
  cat9.nPixelHitsMax = 2;
  cat9.nPixelHitsMin = 2;
  cat9.pMax          = 500000;
  cat9.pMin          = 8;
  cat9.chiMin        = 0;
  cat9.chiMax        = 2.5;
  cat9.withFirstPixelHit  = 0; 
  cat9.histoname = "histoCat9";
  cat9.histo	    = new TH1D( cat9.histoname,  cat9.histoname, nbins, xmin, xmax);
  
    
  vectCategories.push_back(cat0);
  vectCategories.push_back(cat1);
  vectCategories.push_back(cat2);
  vectCategories.push_back(cat3);
  vectCategories.push_back(cat4);
  vectCategories.push_back(cat5);
  vectCategories.push_back(cat6);
  vectCategories.push_back(cat7);
  vectCategories.push_back(cat8);
  vectCategories.push_back(cat9);

  return vectCategories;
}

/*

std::vector<TH1F > CategoriesDefinition::HistoList(int nBin, double xmin, double xmax){

  std::vector<TH1F > vectHisto;
  //def a list of histograms
  
  return vectHisto;


}*/
