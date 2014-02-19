#include "CategoriesDefinition.h"

#include "TClass.h"


ClassImp(CategoriesDefinition)
  




std::vector<CategoryDef > CategoriesDefinition::CategoryList(){

  std::vector<CategoryDef > vectCategories;

  double nbins=10000;
  double xmin=0.0;
  double xmax=50.0;
  
  
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
  cat0.etaMax        = 2.5;
  cat0.etaMin        = 0;
  cat0.nHitsMax      = 50;
  cat0.nHitsMin      = 8;
  cat0.nPixelHitsMax = 1;
  cat0.nPixelHitsMin = 1;
  cat0.pMax          = 5000;
  cat0.pMin          = 0;
  cat0.chiMin        = 0;
  cat0.chiMax        = 5;
  cat0.withFirstPixelHit = 0;  
  cat0.histoname = "histoCat0";
  cat0.histo	    = new TH1D( cat0.histoname,  cat0.histoname, nbins, xmin, xmax);
  
  
  
  
  //cat 1
  cat1.etaMax        = 2.5;
  cat1.etaMin        = 0;
  cat1.nHitsMax      = 50;
  cat1.nHitsMin      = 8;
  cat1.nPixelHitsMax = 8;
  cat1.nPixelHitsMin = 2;
  cat1.pMax          = 5000;
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
  cat4.etaMax        = 2.5;
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
  cat5.etaMax        = 2.5;
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
  cat6.pMax          = 5000;
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
  cat7.pMax          = 5000;
  cat7.pMin          = 8;
  cat7.chiMin        = 0;
  cat7.chiMax        = 2.5;
  cat7.withFirstPixelHit  = 0;
  cat7.histoname = "histoCat7";
  cat7.histo	    = new TH1D( cat7.histoname,  cat7.histoname, nbins, xmin, xmax);
  
  //cat 8
  cat8.etaMax        = 2.5;
  cat8.etaMin        = 1.6;
  cat8.nHitsMax      = 50;
  cat8.nHitsMin      = 8;
  cat8.nPixelHitsMax = 8;
  cat8.nPixelHitsMin = 3;
  cat8.pMax          = 5000;
  cat8.pMin          = 8;
  cat8.chiMin        = 0;
  cat8.chiMax        = 2.5;
  cat8.withFirstPixelHit  = 0;
  cat8.histoname = "histoCat8";
  cat8.histo	    = new TH1D( cat8.histoname,  cat8.histoname, nbins, xmin, xmax);

  //cat 9
  cat9.etaMax        = 2.5;
  cat9.etaMin        = 0;
  cat9.nHitsMax      = 50;
  cat9.nHitsMin      = 8;
  cat9.nPixelHitsMax = 2;
  cat9.nPixelHitsMin = 2;
  cat9.pMax          = 5000;
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



std::vector<CategoryDef > CategoriesDefinition::CategoryList(){

  std::vector<CategoryDef > vectCategories;

  double nbins=10000;
  double xmin=0.0;
  double xmax=50.0;
  
  
  CategoryDef cat0;
  CategoryDef cat01;
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
  cat0.etaMax        = 2.5;
  cat0.etaMin        = 0;
  cat0.nHitsMax      = 50;
  cat0.nHitsMin      = 8;
  cat0.nPixelHitsMax = 0;
  cat0.nPixelHitsMin = 0;
  cat0.pMax          = 5000;
  cat0.pMin          = 0;
  cat0.chiMin        = 0;
  cat0.chiMax        = 5;
  cat0.withFirstPixelHit = 0;  
  cat0.histoname = "histoCat0";
  cat0.histo	    = new TH1D( cat0.histoname,  cat0.histoname, nbins, xmin, xmax);
  
  
  //cat 01  
  cat01.etaMax        = 2.5;
  cat01.etaMin        = 0;
  cat01.nHitsMax      = 50;
  cat01.nHitsMin      = 8;
  cat01.nPixelHitsMax = 1;
  cat01.nPixelHitsMin = 1;
  cat01.pMax          = 5000;
  cat01.pMin          = 0;
  cat01.chiMin        = 0;
  cat01.chiMax        = 5;
  cat01.withFirstPixelHit = 0;  
  cat01.histoname = "histoCat01";
  cat01.histo	    = new TH1D( cat01.histoname,  cat01.histoname, nbins, xmin, xmax);
  
  
  //cat 1
  cat1.etaMax        = 2.5;
  cat1.etaMin        = 0;
  cat1.nHitsMax      = 50;
  cat1.nHitsMin      = 8;
  cat1.nPixelHitsMax = 8;
  cat1.nPixelHitsMin = 2;
  cat1.pMax          = 5000;
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
  cat4.etaMax        = 2.5;
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
  cat5.etaMax        = 2.5;
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
  cat6.pMax          = 5000;
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
  cat7.pMax          = 5000;
  cat7.pMin          = 8;
  cat7.chiMin        = 0;
  cat7.chiMax        = 2.5;
  cat7.withFirstPixelHit  = 0;
  cat7.histoname = "histoCat7";
  cat7.histo	    = new TH1D( cat7.histoname,  cat7.histoname, nbins, xmin, xmax);
  
  //cat 8
  cat8.etaMax        = 2.5;
  cat8.etaMin        = 1.6;
  cat8.nHitsMax      = 50;
  cat8.nHitsMin      = 8;
  cat8.nPixelHitsMax = 8;
  cat8.nPixelHitsMin = 3;
  cat8.pMax          = 5000;
  cat8.pMin          = 8;
  cat8.chiMin        = 0;
  cat8.chiMax        = 2.5;
  cat8.withFirstPixelHit  = 0;
  cat8.histoname = "histoCat8";
  cat8.histo	    = new TH1D( cat8.histoname,  cat8.histoname, nbins, xmin, xmax);

  //cat 9
  cat9.etaMax        = 2.5;
  cat9.etaMin        = 0;
  cat9.nHitsMax      = 50;
  cat9.nHitsMin      = 8;
  cat9.nPixelHitsMax = 2;
  cat9.nPixelHitsMin = 2;
  cat9.pMax          = 5000;
  cat9.pMin          = 8;
  cat9.chiMin        = 0;
  cat9.chiMax        = 2.5;
  cat9.withFirstPixelHit  = 0; 
  cat9.histoname = "histoCat9";
  cat9.histo	    = new TH1D( cat9.histoname,  cat9.histoname, nbins, xmin, xmax);
  
    
  vectCategories.push_back(cat0);
  vectCategories.push_back(cat01);
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

std::vector<CategoryDef > CategoriesDefinition::CategoryList(){

  std::vector<CategoryDef > vectCategories;

  double nbins=10000;
  double xmin=0.0;
  double xmax=50.0;
  
  
  CategoryDef cat0;
  CategoryDef cat1;
  CategoryDef cat2;
  CategoryDef cat3;
  CategoryDef cat4;
  CategoryDef cat5;
  CategoryDef cat61;
  CategoryDef cat62;
  CategoryDef cat63;
  CategoryDef cat64;
  CategoryDef cat71;
  CategoryDef cat72;
  CategoryDef cat73;
  CategoryDef cat74;
  CategoryDef cat81;
  CategoryDef cat82;
  CategoryDef cat83;
  CategoryDef cat84;
  CategoryDef cat91;
  CategoryDef cat92;
  CategoryDef cat93;
  
  
  
  
  //categorie definitions:
  
  //cat 0  
  cat0.etaMax        = 2.5;
  cat0.etaMin        = 0;
  cat0.nHitsMax      = 50;
  cat0.nHitsMin      = 8;
  cat0.nPixelHitsMax = 1;
  cat0.nPixelHitsMin = 1;
  cat0.pMax          = 10000;
  cat0.pMin          = 0;
  cat0.chiMin        = 0;
  cat0.chiMax        = 5;
  cat0.withFirstPixelHit = 0;  
  cat0.histoname = "histoCat0";
  cat0.histo	    = new TH1D( cat0.histoname,  cat0.histoname, nbins, xmin, xmax);
  
  
  
  
  //cat 1
  cat1.etaMax        = 2.5;
  cat1.etaMin        = 0;
  cat1.nHitsMax      = 50;
  cat1.nHitsMin      = 8;
  cat1.nPixelHitsMax = 8;
  cat1.nPixelHitsMin = 2;
  cat1.pMax          = 10000;
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
  cat4.etaMax        = 2.5;
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
  cat5.etaMax        = 2.5;
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



  //cat 61
  cat61.etaMax        = 0.8;
  cat61.etaMin        = 0;
  cat61.nHitsMax      = 50;
  cat61.nHitsMin      = 8;
  cat61.nPixelHitsMax = 8;
  cat61.nPixelHitsMin = 3;
  cat61.pMax          = 50;
  cat61.pMin          = 8;
  cat61.chiMin        = 0;
  cat61.chiMax        = 2.5;
  cat61.withFirstPixelHit  = 0;
  cat61.histoname = "histoCat61";
  cat61.histo	    = new TH1D( cat61.histoname,  cat61.histoname, nbins, xmin, xmax);
  
  
  //cat 6
  cat62.etaMax        = 0.8;
  cat62.etaMin        = 0;
  cat62.nHitsMax      = 50;
  cat62.nHitsMin      = 8;
  cat62.nPixelHitsMax = 8;
  cat62.nPixelHitsMin = 3;
  cat62.pMax          = 100;
  cat62.pMin          = 50;
  cat62.chiMin        = 0;
  cat62.chiMax        = 2.5;
  cat62.withFirstPixelHit  = 0;
  cat62.histoname = "histoCat62";
  cat62.histo	    = new TH1D( cat62.histoname,  cat62.histoname, nbins, xmin, xmax);
  
  //cat 6
  cat63.etaMax        = 0.8;
  cat63.etaMin        = 0;
  cat63.nHitsMax      = 50;
  cat63.nHitsMin      = 8;
  cat63.nPixelHitsMax = 8;
  cat63.nPixelHitsMin = 3;
  cat63.pMax          = 200;
  cat63.pMin          = 100;
  cat63.chiMin        = 0;
  cat63.chiMax        = 2.5;
  cat63.withFirstPixelHit  = 0;
  cat63.histoname = "histoCat63";
  cat63.histo	    = new TH1D( cat63.histoname,  cat63.histoname, nbins, xmin, xmax);
  
  //cat 6
  cat64.etaMax        = 0.8;
  cat64.etaMin        = 0;
  cat64.nHitsMax      = 50;
  cat64.nHitsMin      = 8;
  cat64.nPixelHitsMax = 8;
  cat64.nPixelHitsMin = 3;
  cat64.pMax          = 10000;
  cat64.pMin          = 200;
  cat64.chiMin        = 0;
  cat64.chiMax        = 2.5;
  cat64.withFirstPixelHit  = 0;
  cat64.histoname = "histoCat64";
  cat64.histo	    = new TH1D( cat64.histoname,  cat64.histoname, nbins, xmin, xmax);
  


  //cat 7
  cat71.etaMax        = 1.6;
  cat71.etaMin        = 0.8;
  cat71.nHitsMax      = 50;
  cat71.nHitsMin      = 8;
  cat71.nPixelHitsMax = 8;
  cat71.nPixelHitsMin = 3;
  cat71.pMax          = 50;
  cat71.pMin          = 8;
  cat71.chiMin        = 0;
  cat71.chiMax        = 2.5;
  cat71.withFirstPixelHit  = 0;
  cat71.histoname = "histoCat71";
  cat71.histo	    = new TH1D( cat71.histoname,  cat71.histoname, nbins, xmin, xmax);

  //cat 7
  cat72.etaMax        = 1.6;
  cat72.etaMin        = 0.8;
  cat72.nHitsMax      = 50;
  cat72.nHitsMin      = 8;
  cat72.nPixelHitsMax = 8;
  cat72.nPixelHitsMin = 3;
  cat72.pMax          = 100;
  cat72.pMin          = 50;
  cat72.chiMin        = 0;
  cat72.chiMax        = 2.5;
  cat72.withFirstPixelHit  = 0;
  cat72.histoname = "histoCat72";
  cat72.histo	    = new TH1D( cat72.histoname,  cat72.histoname, nbins, xmin, xmax);

  //cat 7
  cat73.etaMax        = 1.6;
  cat73.etaMin        = 0.8;
  cat73.nHitsMax      = 50;
  cat73.nHitsMin      = 8;
  cat73.nPixelHitsMax = 8;
  cat73.nPixelHitsMin = 3;
  cat73.pMax          = 200;
  cat73.pMin          = 100;
  cat73.chiMin        = 0;
  cat73.chiMax        = 2.5;
  cat73.withFirstPixelHit  = 0;
  cat73.histoname = "histoCat73";
  cat73.histo	    = new TH1D( cat73.histoname,  cat73.histoname, nbins, xmin, xmax);

  //cat 7
  cat74.etaMax        = 1.6;
  cat74.etaMin        = 0.8;
  cat74.nHitsMax      = 50;
  cat74.nHitsMin      = 8;
  cat74.nPixelHitsMax = 8;
  cat74.nPixelHitsMin = 3;
  cat74.pMax          = 10000;
  cat74.pMin          = 200;
  cat74.chiMin        = 0;
  cat74.chiMax        = 2.5;
  cat74.withFirstPixelHit  = 0;
  cat74.histoname = "histoCat74";
  cat74.histo	    = new TH1D( cat74.histoname,  cat74.histoname, nbins, xmin, xmax);
  
  //cat 8
  cat81.etaMax        = 2.5;
  cat81.etaMin        = 1.6;
  cat81.nHitsMax      = 50;
  cat81.nHitsMin      = 8;
  cat81.nPixelHitsMax = 8;
  cat81.nPixelHitsMin = 3;
  cat81.pMax          = 50;
  cat81.pMin          = 8;
  cat81.chiMin        = 0;
  cat81.chiMax        = 2.5;
  cat81.withFirstPixelHit  = 0;
  cat81.histoname = "histoCat81";
  cat81.histo	    = new TH1D( cat81.histoname,  cat81.histoname, nbins, xmin, xmax);
  
  //cat 8
  cat82.etaMax        = 2.5;
  cat82.etaMin        = 1.6;
  cat82.nHitsMax      = 50;
  cat82.nHitsMin      = 8;
  cat82.nPixelHitsMax = 8;
  cat82.nPixelHitsMin = 3;
  cat82.pMax          = 100;
  cat82.pMin          = 50;
  cat82.chiMin        = 0;
  cat82.chiMax        = 2.5;
  cat82.withFirstPixelHit  = 0;
  cat82.histoname = "histoCat82";
  cat82.histo	    = new TH1D( cat82.histoname,  cat82.histoname, nbins, xmin, xmax);
  
  //cat 8
  cat83.etaMax        = 2.5;
  cat83.etaMin        = 1.6;
  cat83.nHitsMax      = 50;
  cat83.nHitsMin      = 8;
  cat83.nPixelHitsMax = 8;
  cat83.nPixelHitsMin = 3;
  cat83.pMax          = 200;
  cat83.pMin          = 100;
  cat83.chiMin        = 0;
  cat83.chiMax        = 2.5;
  cat83.withFirstPixelHit  = 0;
  cat83.histoname = "histoCat83";
  cat83.histo	    = new TH1D( cat83.histoname,  cat83.histoname, nbins, xmin, xmax);
  
  //cat 8
  cat84.etaMax        = 2.5;
  cat84.etaMin        = 1.6;
  cat84.nHitsMax      = 50;
  cat84.nHitsMin      = 8;
  cat84.nPixelHitsMax = 8;
  cat84.nPixelHitsMin = 3;
  cat84.pMax          = 10000;
  cat84.pMin          = 200;
  cat84.chiMin        = 0;
  cat84.chiMax        = 2.5;
  cat84.withFirstPixelHit  = 0;
  cat84.histoname = "histoCat84";
  cat84.histo	    = new TH1D( cat84.histoname,  cat84.histoname, nbins, xmin, xmax);

  //cat 9
  cat91.etaMax        = 2.5;
  cat91.etaMin        = 0;
  cat91.nHitsMax      = 50;
  cat91.nHitsMin      = 8;
  cat91.nPixelHitsMax = 2;
  cat91.nPixelHitsMin = 2;
  cat91.pMax          = 50;
  cat91.pMin          = 8;
  cat91.chiMin        = 0;
  cat91.chiMax        = 2.5;
  cat91.withFirstPixelHit  = 0; 
  cat91.histoname = "histoCat91";
  cat91.histo	    = new TH1D( cat91.histoname,  cat91.histoname, nbins, xmin, xmax);
  
  //cat 9
  cat92.etaMax        = 2.5;
  cat92.etaMin        = 0;
  cat92.nHitsMax      = 50;
  cat92.nHitsMin      = 8;
  cat92.nPixelHitsMax = 2;
  cat92.nPixelHitsMin = 2;
  cat92.pMax          = 100;
  cat92.pMin          = 50;
  cat92.chiMin        = 0;
  cat92.chiMax        = 2.5;
  cat92.withFirstPixelHit  = 0; 
  cat92.histoname = "histoCat92";
  cat92.histo	    = new TH1D( cat92.histoname,  cat92.histoname, nbins, xmin, xmax);
  
  //cat 9
  cat93.etaMax        = 2.5;
  cat93.etaMin        = 0;
  cat93.nHitsMax      = 50;
  cat93.nHitsMin      = 8;
  cat93.nPixelHitsMax = 2;
  cat93.nPixelHitsMin = 2;
  cat93.pMax          = 10000;
  cat93.pMin          = 100;
  cat93.chiMin        = 0;
  cat93.chiMax        = 2.5;
  cat93.withFirstPixelHit  = 0; 
  cat93.histoname = "histoCat93";
  cat93.histo	    = new TH1D( cat93.histoname,  cat93.histoname, nbins, xmin, xmax);
  
    
  vectCategories.push_back(cat0);
  vectCategories.push_back(cat1);
  vectCategories.push_back(cat2);
  vectCategories.push_back(cat3);
  vectCategories.push_back(cat4);
  vectCategories.push_back(cat5);
  vectCategories.push_back(cat61);
  vectCategories.push_back(cat62);
  vectCategories.push_back(cat63);
  vectCategories.push_back(cat64);
  vectCategories.push_back(cat71);
  vectCategories.push_back(cat72);
  vectCategories.push_back(cat73);
  vectCategories.push_back(cat74);
  vectCategories.push_back(cat81);
  vectCategories.push_back(cat82);
  vectCategories.push_back(cat83);
  vectCategories.push_back(cat84);
  vectCategories.push_back(cat91);
  vectCategories.push_back(cat92);
  vectCategories.push_back(cat93);

  return vectCategories;
}
*/

