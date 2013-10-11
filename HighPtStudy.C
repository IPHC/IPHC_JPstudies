#define HighPtStudy_cxx
#include "HighPtStudy.h"

#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TH1.h>
#include "CategoryDef.h"
#include <vector>
#include "TClass.h"
#include "TMath.h"
#include "TLorentzVector.h"
#include <iomanip>
#include "TGraph.h"
#include "TPaveLabel.h"
#include "TPad.h"
#include "TGraphErrors.h"
#include "TLegend.h"
#include "TMultiGraph.h"

std::vector<CategoryDef > HighPtStudy::DefCategories()
{  
  std::vector<CategoryDef >  vectCat;
  
  vectCat.clear();
  
  int nbins=10000;
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
  cat0.histoCalib    = new TH1D("histoCat0"	  ,"histoCat0"	,nbins,xmin,xmax);
  
  
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
  cat1.histoCalib    = new TH1D("histoCat1"	  ,"histoCat1"	,nbins,xmin,xmax);
    
    
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
  cat2.histoCalib     = new TH1D("histoCat2"	  ,"histoCat2"	,nbins,xmin,xmax);


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
  cat3.histoCalib    = new TH1D("histoCat3"	  ,"histoCat3"	,nbins,xmin,xmax);



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
  cat4.histoCalib    = new TH1D("histoCat4"	  ,"histoCat4"	,nbins,xmin,xmax);


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
  cat5.histoCalib    = new TH1D("histoCat5"	  ,"histoCat5"	,nbins,xmin,xmax);



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
  cat6.histoCalib    = new TH1D("histoCat6"	  ,"histoCat6"	,nbins,xmin,xmax);


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
  cat7.histoCalib    = new TH1D("histoCat7"	  ,"histoCat7"	,nbins,xmin,xmax);

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
  cat8.histoCalib    = new TH1D("histoCat8"	  ,"histoCat8"	,nbins,xmin,xmax);

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
  cat9.histoCalib    = new TH1D("histoCat9"	  ,"histoCat9"	,nbins,xmin,xmax);
  
  vectCat.push_back(cat0);
  vectCat.push_back(cat1);
  vectCat.push_back(cat2);
  vectCat.push_back(cat3);
  vectCat.push_back(cat4);
  vectCat.push_back(cat5);
  vectCat.push_back(cat6);
  vectCat.push_back(cat7);
  vectCat.push_back(cat8);
  vectCat.push_back(cat9);
 
   
  
  return vectCat; 
}


//-----------------------------------------------------Find the category of a given track----------------------------------------------------------------------------------------//
bool HighPtStudy::IsInCategory(float trkEta, float trkHTrk, float trkHPix, float trkp, float trkChi2, CategoryDef d){
  
  bool isIn=false;
  
  if (fabs(trkEta)>d.etaMin&&fabs(trkEta)<d.etaMax&&trkHTrk<=d.nHitsMax&&trkHTrk>=d.nHitsMin&&trkHPix<=d.nPixelHitsMax&&trkHPix>=d.nPixelHitsMin&&trkp<d.pMax&&trkp>d.pMin&&trkChi2>=d.chiMin&&trkChi2<=d.chiMax) isIn=true;
  
  return isIn;
  
}


//-----------------------------------------------------Return true if track passes btag selection ---------------------------------------------------------------------------------//
bool HighPtStudy::passTrackSel(int trk, int pix, float ip2d, float pt, float len, float chi2, float zip, float dist, float eta, float etaJet, float phi, float phiJet, float ptJet)
{

  TLorentzVector track4P, jet4P;
  track4P.SetPtEtaPhiM(pt, eta,phi , 0. );
  jet4P.SetPtEtaPhiM(ptJet ,etaJet ,phiJet , 0 );

  float deltaR = jet4P.DeltaR(track4P);
  bool passSel=false;
  
  bool passTrk=false;
  bool passIP=false;
  bool passPix=false;
  bool passPt=false;
  bool passLen=false;
  bool passChi2=false;
  bool passDist=false;
  bool passZip=false;
  bool passDR=false;
  
  //if ((trk+pix)>=8)   passTrk=true;
  if ((trk)>=8)   passTrk=true;
  
  if (fabs(ip2d)<0.2) passIP=true;
  if (pix>=2)         passPix=true;
  if (pt>1.0)         passPt=true;
  if (len<5.0)        passLen=true;
  if (chi2<5.0)       passChi2=true;
  if (fabs(dist)<0.07)passDist=true;
  if (fabs(zip)<17.0) passZip=true;
  if (deltaR<0.3)     passDR=true;


  
  if (passTrk&&passIP&&passPix&&passPt&&passLen&&passChi2&&passDist&&passZip&&passDR) {
  
    passSel=true;

  
  }
  
  return passSel;
  
}

void HighPtStudy::plotLoop(){
  
//   plot1D("histoIPsig",0);
//   plot1D("deltaRmin",0);
//   plot1D("NHits",0);
//   plot1D("TrkMulti",0);
//   plot1D("chi2",0);
//   
//   plot1D("histoIPsig",1);
//   plot1D("deltaRmin",1);
//   plot1D("NHits",1);
//   plot1D("TrkMulti",1);
//   plot1D("chi2",1);
  
  plot1D("histoIPsig",1);
  plot1D("deltaRmin",1);
//   plot1D("NHits",2);
//   plot1D("TrkMulti",2);
//   plot1D("chi2",2);
  
  
  
//   plot2D("mutliTrk_jetPt");
//   plot2D("Nhits_jetPt");
//   plot2D("DeltaRtrk_jetPt");
//   plot2D("JetProba_jetPt");
//   plot2D("chi2Trk_jetPt");
//   
//  plot2D("mutliTrk_deltaR"); 
//   plot2D("Nhits_deltaR");   
//   plot2D("JetProba_deltaR"); 
//   plot2D("chi2Trk_deltaR");  
}

void HighPtStudy::Loop(int cut, int type)
{

  TString next;
  if(type==1)           next="_pt";
  else if(type==0)      next="_DR";
  else                  next="_IPsig";
  TString str = ""; 
  str += cut;
  
  TFile* myfile = new TFile("study_histo"+str+next+".root", "recreate");
  myfile->cd();
  
  std::vector<CategoryDef > vectCat=DefCategories(); 
  
  // Histo 1d---------------------------------------------------------------------------//
  
  
  TH1F *histoIPsig_b  = new TH1F("histoIPsig_b",  "histoIPsig_b",  70 ,  0.0 , 7.0);
  TH1F *histoIPsig_c  = new TH1F("histoIPsig_c",  "histoIPsig_c",  70 ,  0.0 , 7.0); 
  TH1F *histoIPsig_l  = new TH1F("histoIPsig_l",  "histoIPsig_l",  70 ,  0.0 , 7.0);
  
  TH1F *histoIP2Dsig_b  = new TH1F("histoIP2Dsig_b",  "histoIP2Dsig_b",  70 ,  0.0 , 7.0);
  TH1F *histoIP2Dsig_c  = new TH1F("histoIP2Dsig_c",  "histoIP2Dsig_c",  70 ,  0.0 , 7.0); 
  TH1F *histoIP2Dsig_l  = new TH1F("histoIP2Dsig_l",  "histoIP2Dsig_l",  70 ,  0.0 , 7.0);
    
  TH1F *histoIP_b  = new TH1F("histoIP_b",  "histoIP_b",  70 ,  0.0 , 0.03);
  TH1F *histoIP_c  = new TH1F("histoIP_c",  "histoIP_c",  70 ,  0.0 , 0.03); 
  TH1F *histoIP_l  = new TH1F("histoIP_l",  "histoIP_l",  70 ,  0.0 , 0.03);
  
  TH1F *histoIP2D_b  = new TH1F("histoIP2D_b",  "histoIP2D_b",  70 ,  0.0 , 0.03);
  TH1F *histoIP2D_c  = new TH1F("histoIP2D_c",  "histoIP2D_c",  70 ,  0.0 , 0.03); 
  TH1F *histoIP2D_l  = new TH1F("histoIP2D_l",  "histoIP2D_l",  70 ,  0.0 , 0.03);
    
  TH1F *decayL_thirdTk_all  = new TH1F("decayL_thirdTk_all",  "decayL_thirdTk_all",  101 ,  0.0 , 5);
  TH1F *decayL_thirdTk_b  = new TH1F("decayL_thirdTk_b",  "decayL_thirdTk_b",  101 ,  0.0 , 5);
  TH1F *decayL_thirdTk_l  = new TH1F("decayL_thirdTk_l",  "decayL_thirdTk_l",  101 ,  0.0 , 5);
  
  
  TH1F *decayL_secTk_all  = new TH1F("decayL_secTk_all",  "decayL_secTk_all",  101 ,  0.0 , 5);  
  TH1F *decayL_secTk_b  = new TH1F("decayL_secTk_b",  "decayL_secTk_b",  101 ,  0.0 ,5);
  TH1F *decayL_secTk_l  = new TH1F("decayL_secTk_l",  "decayL_secTk_l",  101 ,  0.0 , 5);
  
     
  TH1F *decayL_firstTk_all  = new TH1F("decayL_firstTk_all","decayL_firstTk_all",  101 ,  0.0 , 5);
  TH1F *decayL_firstTk_b    = new TH1F("decayL_firstTk_b",  "decayL_firstTk_b",  101 ,  0.0 , 5);
  TH1F *decayL_firstTk_l    = new TH1F("decayL_firstTk_l",  "decayL_firstTk_l",  101 ,  0.0 , 5);
  
  TH1F *decayLsig_thirdTk_all  = new TH1F("decayLsig_thirdTk_all",  "decayLsig_thirdTk_all",  101 ,  0.0 , 0.3);
  TH1F *decayLsig_thirdTk_b  = new TH1F("decayLsig_thirdTk_b",  "decayLsig_thirdTk_b",  101 ,  0.0 , 0.3);
  TH1F *decayLsig_thirdTk_l  = new TH1F("decayLsig_thirdTk_l",  "decayLsig_thirdTk_l",  101 ,  0.0 , 0.3);
  
  
  TH1F *decayLsig_secTk_all  = new TH1F("decayLsig_secTk_all",  "decayLsig_secTk_all",  101 ,  0.0 , 0.3);  
  TH1F *decayLsig_secTk_b  = new TH1F("decayLsig_secTk_b",  "decayLsig_secTk_b",  101 ,  0.0 ,0.3);
  TH1F *decayLsig_secTk_l  = new TH1F("decayLsig_secTk_l",  "decayLsig_secTk_l",  101 ,  0.0 , 0.3);
  
     
  TH1F *decayLsig_firstTk_all  = new TH1F("decayLsig_firstTk_all","decayLsig_firstTk_all",  101 ,  0.0 , 0.3);
  TH1F *decayLsig_firstTk_b    = new TH1F("decayLsig_firstTk_b",  "decayLsig_firstTk_b",  101 ,  0.0 , 0.3);
  TH1F *decayLsig_firstTk_l    = new TH1F("decayLsig_firstTk_l",  "decayLsig_firstTk_l",  101 ,  0.0 , 0.3); 
  
  
   
  TH1F *histoIPsig_thirdTk_all  = new TH1F("histoIPsig_thirdTk_all",  "histoIPsig_thirdTk_all",  101 ,  0.0 , 20);
  TH1F *histoIPsig_thirdTk_b  = new TH1F("histoIPsig_thirdTk_b",  "histoIPsig_thirdTk_b",  101 ,  0.0 , 20);
  TH1F *histoIPsig_thirdTk_l  = new TH1F("histoIPsig_thirdTk_l",  "histoIPsig_thirdTk_l",  101 ,  0.0 , 20);
  
  
  TH1F *histoIPsig_secTk_all  = new TH1F("histoIPsig_secTk_all",  "histoIPsig_secTk_all",  101 ,  0.0 , 20);  
  TH1F *histoIPsig_secTk_b  = new TH1F("histoIPsig_secTk_b",  "histoIPsig_secTk_b",  101 ,  0.0 , 20);
  TH1F *histoIPsig_secTk_l  = new TH1F("histoIPsig_secTk_l",  "histoIPsig_secTk_l",  101 ,  0.0 , 20);
  
     
  TH1F *histoIPsig_firstTk_all  = new TH1F("histoIPsig_firstTk_all","histoIPsig_firstTk_all",  101 ,  0.0 , 20);
  TH1F *histoIPsig_firstTk_b    = new TH1F("histoIPsig_firstTk_b",  "histoIPsig_firstTk_b",  101 ,  0.0 , 20);
  TH1F *histoIPsig_firstTk_l    = new TH1F("histoIPsig_firstTk_l",  "histoIPsig_firstTk_l",  101 ,  0.0 , 20);  
  		  
  TH1F *histoIP_thirdTk_all  = new TH1F("histoIP_thirdTk_all",  "histoIP_thirdTk_all",  101 ,  0.0 , 0.03);
  TH1F *histoIP_thirdTk_b  = new TH1F("histoIP_thirdTk_b",  "histoIP_thirdTk_b",  101 ,  0.0 , 0.03);
  TH1F *histoIP_thirdTk_l  = new TH1F("histoIP_thirdTk_l",  "histoIP_thirdTk_l",  101 ,  0.0 , 0.03);
  
  
  TH1F *histoIP_secTk_all  = new TH1F("histoIP_secTk_all",  "histoIP_secTk_all",  101 ,  0.0 , 0.03);  
  TH1F *histoIP_secTk_b  = new TH1F("histoIP_secTk_b",  "histoIP_secTk_b",  101 ,  0.0 , 0.03);
  TH1F *histoIP_secTk_l  = new TH1F("histoIP_secTk_l",  "histoIP_secTk_l",  101 ,  0.0 , 0.03);
  
     
  TH1F *histoIP_firstTk_all  = new TH1F("histoIP_firstTk_all","histoIP_firstTk_all",  101 ,  0.0 , 0.03);
  TH1F *histoIP_firstTk_b    = new TH1F("histoIP_firstTk_b",  "histoIP_firstTk_b",  101 ,  0.0 , 0.03);
  TH1F *histoIP_firstTk_l    = new TH1F("histoIP_firstTk_l",  "histoIP_firstTk_l",  101 ,  0.0 , 0.03);  
		  
  TH1F *histoIPerr_b  = new TH1F("histoIPerr_b",  "histoIPerr_b",  70 ,  0.0 , 0.05);
  TH1F *histoIPerr_c  = new TH1F("histoIPerr_c",  "histoIPerr_c",  70 ,  0.0 , 0.05); 
  TH1F *histoIPerr_l  = new TH1F("histoIPerr_l",  "histoIPerr_l",  70 ,  0.0 , 0.05);  
    
  TH1F *decayL_b  = new TH1F("decayL_b",  "decayL_b",  70 ,  0.0 , 2.0);
  TH1F *decayL_c  = new TH1F("decayL_c",  "decayL_c",  70 ,  0.0 , 2.0); 
  TH1F *decayL_l  = new TH1F("decayL_l",  "decayL_l",  70 ,  0.0 , 2.0);  
  
  TH1F *deltaRmin_b  = new TH1F("deltaRmin_b",  "deltaRmin_b",  100 ,  0.0 , 0.003);
  TH1F *deltaRmin_c  = new TH1F("deltaRmin_c",  "deltaRmin_c",  100 ,  0.0 , 0.003); 
  TH1F *deltaRmin_l  = new TH1F("deltaRmin_l",  "deltaRmin_l",  100 ,  0.0 , 0.003); 
  
  TH1F *NHits_b  = new TH1F("NHits_b",  "NHits_b",  100 ,  0.0 , 30);
  TH1F *NHits_c  = new TH1F("NHits_c",  "NHits_c",  100 ,  0.0 , 30); 
  TH1F *NHits_l  = new TH1F("NHits_l",  "NHits_l",  100 ,  0.0 , 30);
  
  TH1F *TrkMulti_b  = new TH1F("TrkMulti_b",  "TrkMulti_b",  100 ,  0.0 , 30);
  TH1F *TrkMulti_c  = new TH1F("TrkMulti_c",  "TrkMulti_c",  100 ,  0.0 , 30); 
  TH1F *TrkMulti_l  = new TH1F("TrkMulti_l",  "TrkMulti_l",  100 ,  0.0 , 30); 
  
   
  TH1F *chi2_b  = new TH1F("chi2_b",  "chi2_b",  100 ,  0.0 , 3);
  TH1F *chi2_c  = new TH1F("chi2_c",  "chi2_c",  100 ,  0.0 , 3); 
  TH1F *chi2_l  = new TH1F("chi2_l",  "chi2_l",  100 ,  0.0 , 3); 
  
  TH1F *deltaRsum_b  = new TH1F("deltaRsum_b",  "deltaRsum_b",  100 ,  0.0 , 0.5);
  TH1F *deltaRsum_c  = new TH1F("deltaRsum_c",  "deltaRsum_c",  100 ,  0.0 , 0.5); 
  TH1F *deltaRsum_l  = new TH1F("deltaRsum_l",  "deltaRsum_l",  100 ,  0.0 , 0.5); 
   
  TH1F *ptRatio_b  = new TH1F("ptRatio_b",  "ptRatio_b",  100 ,  0.0 , 0.2);
  TH1F *ptRatio_c  = new TH1F("ptRatio_c",  "ptRatio_c",  100 ,  0.0 , 0.2); 
  TH1F *ptRatio_l  = new TH1F("ptRatio_l",  "ptRatio_l",  100 ,  0.0 , 0.2);     
//   
//     
//   // b-jets histo-------------------------------------------------------------------------------------//
// 
//   TH2F *mutliTrk_jetPt_l  = new TH2F("mutliTrk_jetPt_l",  "mutliTrk_jetPt_l",  100 ,    0.0 ,300.0,50,0,50);
//   TH2F *Nhits_jetPt_l     = new TH2F("Nhits_jetPt_l",     "Nhits_jetPt_l",     100 ,    0.0 ,300.0,50,0,50);  
//   TH2F *DeltaRtrk_jetPt_l = new TH2F("DeltaRtrk_jetPt_l", "DeltaRtrk_jetPt_l", 100 ,    0.0 ,300.0,50,0,1);  
//   TH2F *JetProba_jetPt_l  = new TH2F("JetProba_jetPt_l",  "JetProba_jetPt_l",  100 ,    0.0 ,300.0,25,0,2.5);  
//   TH2F *TrackProba_jetPt_l= new TH2F("TrackProba_jetPt_l","TrackProba_jetPt_l",100 ,    0.0 ,300.0,100,-1.0,1.0);  
//   TH2F *chi2Trk_jetPt_l   = new TH2F("chi2Trk_jetPt_l",   "chi2Trk_jetPt_l",   100 ,    0.0 ,300.0,50,0,5);
//   
//   TH2F *mutliTrk_deltaR_l  = new TH2F("mutliTrk_deltaR_l",  "mutliTrk_deltaR_l",  100 ,    0.0 ,0.6,50,0,50);
//   TH2F *Nhits_deltaR_l     = new TH2F("Nhits_deltaR_l",     "Nhits_deltaR_l",     100 ,    0.0 ,0.6,50,0,50);  
//   TH2F *JetProba_deltaR_l  = new TH2F("JetProba_deltaR_l",  "JetProba_deltaR_l",  100 ,    0.0 ,0.6,25,0,2.5);  
//   TH2F *TrackProba_deltaR_l= new TH2F("TrackProba_deltaR_l","TrackProba_deltaR_l",100 ,    0.0 ,0.6,100,-1.0,1.0);  
//   TH2F *chi2Trk_deltaR_l   = new TH2F("chi2Trk_deltaR_l",   "chi2Trk_deltaR_l",   100 ,    0.0 ,0.6,50,0,5); 
//   
//   
//   // b-jets histo-------------------------------------------------------------------------------------//
// 
//   TH2F *mutliTrk_jetPt_c  = new TH2F("mutliTrk_jetPt_c",  "mutliTrk_jetPt_c",  100 ,    0.0 ,300.0,50,0,50);
//   TH2F *Nhits_jetPt_c     = new TH2F("Nhits_jetPt_c",     "Nhits_jetPt_c",     100 ,    0.0 ,300.0,50,0,50);  
//   TH2F *DeltaRtrk_jetPt_c = new TH2F("DeltaRtrk_jetPt_c", "DeltaRtrk_jetPt_c", 100 ,    0.0 ,300.0,50,0,1);  
//   TH2F *JetProba_jetPt_c  = new TH2F("JetProba_jetPt_c",  "JetProba_jetPt_c",  100 ,    0.0 ,300.0,25,0,2.5);  
//   TH2F *TrackProba_jetPt_c= new TH2F("TrackProba_jetPt_c","TrackProba_jetPt_c",100 ,    0.0 ,300.0,100,-1.0,1.0);  
//   TH2F *chi2Trk_jetPt_c   = new TH2F("chi2Trk_jetPt_c",   "chi2Trk_jetPt_c",   100 ,    0.0 ,300.0,50,0,5);
//   
//   TH2F *mutliTrk_deltaR_c  = new TH2F("mutliTrk_deltaR_c",  "mutliTrk_deltaR_c",  100 ,    0.0 ,0.6,50,0,50);
//   TH2F *Nhits_deltaR_c     = new TH2F("Nhits_deltaR_c",     "Nhits_deltaR_c",     100 ,    0.0 ,0.6,50,0,50);  
//   TH2F *JetProba_deltaR_c  = new TH2F("JetProba_deltaR_c",  "JetProba_deltaR_c",  100 ,    0.0 ,0.6,25,0,2.5);  
//   TH2F *TrackProba_deltaR_c= new TH2F("TrackProba_deltaR_c","TrackProba_deltaR_c",100 ,    0.0 ,0.6,100,-1.0,1.0);  
//   TH2F *chi2Trk_deltaR_c   = new TH2F("chi2Trk_deltaR_c",   "chi2Trk_deltaR_c",   100 ,    0.0 ,0.6,50,0,5);   
//   
//   
//    // b-jets histo-------------------------------------------------------------------------------------//
// 
//   TH2F *mutliTrk_jetPt_b  = new TH2F("mutliTrk_jetPt_b",  "mutliTrk_jetPt_b",  100 ,    0.0 ,300.0,50,0,50);
//   TH2F *Nhits_jetPt_b     = new TH2F("Nhits_jetPt_b",     "Nhits_jetPt_b",     100 ,    0.0 ,300.0,50,0,50);  
//   TH2F *DeltaRtrk_jetPt_b = new TH2F("DeltaRtrk_jetPt_b", "DeltaRtrk_jetPt_b", 100 ,    0.0 ,300.0,50,0,1);  
//   TH2F *JetProba_jetPt_b  = new TH2F("JetProba_jetPt_b",  "JetProba_jetPt_b",  100 ,    0.0 ,300.0,25,0,2.5);  
//   TH2F *TrackProba_jetPt_b= new TH2F("TrackProba_jetPt_b","TrackProba_jetPt_b",100 ,    0.0 ,300.0,100,-1.0,1.0);  
//   TH2F *chi2Trk_jetPt_b   = new TH2F("chi2Trk_jetPt_b",   "chi2Trk_jetPt_b",   100 ,    0.0 ,300.0,50,0,5);
//   
//   TH2F *mutliTrk_deltaR_b  = new TH2F("mutliTrk_deltaR_b",  "mutliTrk_deltaR_b",  100 ,    0.0 ,0.6,50,0,50);
//   TH2F *Nhits_deltaR_b     = new TH2F("Nhits_deltaR_b",     "Nhits_deltaR_b",     100 ,    0.0 ,0.6,50,0,50);  
//   TH2F *JetProba_deltaR_b  = new TH2F("JetProba_deltaR_b",  "JetProba_deltaR_b",  100 ,    0.0 ,0.6,25,0,2.5);  
//   TH2F *TrackProba_deltaR_b= new TH2F("TrackProba_deltaR_b","TrackProba_deltaR_b",100 ,    0.0 ,0.6,100,-1.0,1.0);  
//   TH2F *chi2Trk_deltaR_b   = new TH2F("chi2Trk_deltaR_b",   "chi2Trk_deltaR_b",   100 ,    0.0 ,0.6,50,0,5);  
   
  int n30=0;
  int n50=0;
  int n80=0;
  int n120=0;
  int n170=0;
  int n300=0;
  int n470=0;
  int n600=0;
  int n800=0;  
  if (fChain == 0) return;
  
  Long64_t nentries = fChain->GetEntriesFast();
  
  float deltaRex=100.0;
  
  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0 ||jentry>1000000 ) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    // if (Cut(ientry) < 0) continue;
   
    if (30<pthat && pthat<50)   n30++;
    if (50<pthat && pthat<80)   n50++;
    if (80<pthat && pthat<120)  n80++;
    if (120<pthat && pthat<170) n120++;  
    if (170<pthat && pthat<300) n170++; 
    if (300<pthat && pthat<470) n300++;
    if (470<pthat && pthat<600) n470++;
    if (600<pthat && pthat<800) n600++;   
    if (800<pthat && pthat<1000)n800++;
    
    //if (n30 < 1000 || n50<1000 || n80<1000 || n120<1000 || n170<500000 || n300<700000 || n470<100000 || n600<100000 || n800<10000){
      //if (n30 > 100 || n50>100 || n80>100 || n120>1000 || n170>5000 || n300>5000 || n470>5000 || n600>5000 || n800>5000) continue;
      
      for (int ijet=0; ijet<nJet ; ijet++){
	
	if (Jet_pt[ijet]>10 && fabs(Jet_eta[ijet]) < 2.5){
	
	  int n1_dlsig=-1;
	  int n2_dlsig=-1;
	  int n3_dlsig=-1;
	  float del1_dlsig=-9999;
	  float del2_dlsig=-9999;
	  float del3_dlsig=-9999;
	      
	  int n1_ipsig=-1;
	  int n2_ipsig=-1;
	  int n3_ipsig=-1;
	  float sig1_ipsig=-9999;
	  float sig2_ipsig=-9999;
	  float sig3_ipsig=-9999;
	  
	  int n1_dl=-1;
	  int n2_dl=-1;
	  int n3_dl=-1;
	  float del1_dl=-9999;
	  float del2_dl=-9999;
	  float del3_dl=-9999;
	      
	  int n1_ip=-1;
	  int n2_ip=-1;
	  int n3_ip=-1;
	  float sig1_ip=-9999;
	  float sig2_ip=-9999;
	  float sig3_ip=-9999;	  
	  
	  
	  
	  	      
	  for( int itrack=Jet_nFirstTrack[ijet]; itrack< Jet_nLastTrack[ijet]; itrack++){
	    
	    bool passSelection=passTrackSel(Track_nHitAll[itrack],Track_nHitPixel[itrack],Track_IP2D[itrack],Track_pt[itrack],Track_length[itrack],Track_chi2[itrack],Track_zIP[itrack],Track_dist[itrack],Track_eta[itrack],Jet_eta[ijet],Track_phi[itrack],Jet_phi[ijet],Jet_pt[ijet]);
	    bool fill = IsInCategory(Track_eta[itrack],Track_nHitAll[itrack] ,Track_nHitPixel[itrack] ,Track_p[itrack] , Track_chi2[itrack], vectCat[2]); 
	    
	    
	    if (passSelection && fill){
	    
	      TLorentzVector track1, track2, deltaRsum;
	      track1.SetPtEtaPhiM(Track_pt[itrack], Track_eta[itrack],Track_phi[itrack] , 0. );
	      std::vector<TLorentzVector >  vect4V;
	      
	      double deltaRmin=100.0;
	      
	      for( int itra=Jet_nFirstTrack[ijet]; itra< Jet_nLastTrack[ijet]; itra++){
	        if (itra != itrack) {
		  track2.SetPtEtaPhiM(Track_pt[itra], Track_eta[itra],Track_phi[itra] , 0. );
		  
		  vect4V.push_back(track2);
		  
		  double deltaR = track1.DeltaR(track2);
		  if(deltaR<deltaRmin) deltaRmin=deltaR;
		  if(deltaR<deltaRex)  deltaRex=deltaR;
		}
	      }
	      
              deltaRsum.SetPtEtaPhiM(0,0,0,0);
		
              for(int i=0 ; i<vect4V.size(); i++){
		deltaRsum = deltaRsum +vect4V[i];
	      }
	      
	      double deltaRsumm_all = track1.DeltaR(deltaRsum);
	      
	      bool passCut=false;
		
	      if(type==0 && deltaRmin< (cut*0.001)+0.003 &&deltaRmin > (cut*0.001))                     passCut=true;
	      else if (type==1 && Jet_pt[ijet]> 20)                         passCut=true;
	      else if (type==2 && fabs(Track_IPsig[itrack])< cut+1 && fabs(Track_IPsig[itrack])> cut-1) passCut=true;
	      
	      if(passCut){		    
	      
	        float delsig=Track_length[itrack]*Track_IPsig[itrack];
		    if (delsig>del1_dl) {
		      del3_dlsig=del2_dlsig;
		      del2_dlsig=del1_dlsig;
		      del1_dlsig=delsig;
		      n3_dlsig=n2_dlsig;
		      n2_dlsig=n1_dlsig;
		      n1_dlsig=itrack;
		    }
		    else if (delsig>del2_dlsig) {
		      del3_dlsig=del2_dlsig;
		      del2_dlsig=delsig;
		      n3_dlsig=n2_dlsig;
		      n2_dlsig=itrack;
		    }
		    else if (delsig>del3_dlsig) {
		      del3_dlsig=delsig;
		      n3_dlsig=itrack;
		    }
	        float ipsig=Track_IPsig[itrack];
		    if (ipsig>sig1_ipsig) {
		      sig3_ipsig=sig2_ipsig;
		      sig2_ipsig=sig1_ipsig;
		      sig1_ipsig=ipsig;
		      n3_ipsig=n2_ipsig;
		      n2_ipsig=n1_ipsig;
		      n1_ipsig=itrack;
		    }
		    else if (ipsig>sig2_ipsig) {
		      sig3_ipsig=sig2_ipsig;
		      sig2_ipsig=ipsig;
		      n3_ipsig=n2_ipsig;
		      n2_ipsig=itrack;
		    }
		    else if (ipsig>sig3_ipsig) {
		      sig3_ipsig=ipsig;
		      n3_ipsig=itrack;
		    }	
		    
		    
	        float del=Track_length[itrack];
		    if (del>del1_dl) {
		      del3_dl=del2_dl;
		      del2_dl=del1_dl;
		      del1_dl=del;
		      n3_dl=n2_dl;
		      n2_dl=n1_dl;
		      n1_dl=itrack;
		    }
		    else if (del>del2_dl) {
		      del3_dl=del2_dl;
		      del2_dl=del;
		      n3_dl=n2_dl;
		      n2_dl=itrack;
		    }
		    else if (del>del3_dl) {
		      del3_dl=del;
		      n3_dl=itrack;
		    }
	        float sig=Track_IP[itrack];
		    if (sig>sig1_ip) {
		      sig3_ip=sig2_ip;
		      sig2_ip=sig1_ip;
		      sig1_ip=sig;
		      n3_ip=n2_ip;
		      n2_ip=n1_ip;
		      n1_ip=itrack;
		    }
		    else if (sig>sig2_ip) {
		      sig3_ip=sig2_ip;
		      sig2_ip=sig;
		      n3_ip=n2_ip;
		      n2_ip=itrack;
		    }
		    else if (sig>sig3_ip) {
		      sig3_ip=sig;
		      n3_ip=itrack;
		    }			    
		    
		    	    
	        decayL_firstTk_all->Fill(del1_dl);
	        decayL_secTk_all->Fill(del2_dl);	   
	        decayL_thirdTk_all->Fill(del3_dl);		   
    
	        histoIP_firstTk_all->Fill(sig1_ip);
	        histoIP_secTk_all->Fill(sig2_ip);	   
	        histoIP_thirdTk_all->Fill(sig3_ip);		    
	      
	        if(fabs(Jet_flavour[ijet])==5){
		
	         histoIP_firstTk_b->Fill(sig1_ip);
	         histoIP_secTk_b->Fill(sig2_ip);		
	         histoIP_thirdTk_b->Fill(sig3_ip);
		
	         decayL_firstTk_b->Fill(del1_dl);
	         decayL_secTk_b->Fill(del2_dl);	   
	         decayL_thirdTk_b->Fill(del3_dl);
		
		
                 histoIPsig_b->Fill(fabs(Track_IPsig[itrack]));
                 histoIP_b->Fill(fabs(Track_IP[itrack]));		 
                 histoIPerr_b->Fill(fabs(Track_IPerr[itrack]));
                 decayL_b->Fill(fabs(Track_length[itrack]));
		 		 
                 NHits_b     ->Fill(Track_nHitAll[itrack]);
                 TrkMulti_b  ->Fill(Jet_ntracks[ijet]);
                 chi2_b      ->Fill(Track_chi2[itrack]);
                 deltaRmin_b ->Fill(deltaRmin);
		 deltaRsum_b ->Fill(deltaRsumm_all);
		 ptRatio_b   ->Fill(Track_pt[itrack]/Jet_pt[ijet]);
		 
// 		  DeltaRtrk_jetPt_b  ->Fill(Jet_pt[ijet],deltaRmin);
// 		  mutliTrk_deltaR_b  ->Fill(deltaRmin,Jet_ntracks[ijet]);
// 		  Nhits_deltaR_b     ->Fill(deltaRmin,Track_nHitAll[itrack]);
// 		  JetProba_deltaR_b  ->Fill(deltaRmin,Jet_Proba[ijet]);
// 		  TrackProba_deltaR_b->Fill(deltaRmin,Track_Proba[itrack]);
// 		  chi2Trk_deltaR_b   ->Fill(deltaRmin,Track_chi2[itrack]);		
// 		  mutliTrk_jetPt_b  ->Fill(Jet_pt[ijet],Jet_ntracks[ijet]);
// 		  Nhits_jetPt_b     ->Fill(Jet_pt[ijet],Track_nHitAll[itrack]);
// 		  JetProba_jetPt_b  ->Fill(Jet_pt[ijet],Jet_Proba[ijet]);
// 		  TrackProba_jetPt_b->Fill(Jet_pt[ijet],Track_Proba[itrack]);
// 		  chi2Trk_jetPt_b   ->Fill(Jet_pt[ijet],Track_chi2[itrack]);
	    
	        }	    
	        else if(fabs(Jet_flavour[ijet])==4){
		
	          histoIPsig_c->Fill(fabs(Track_IPsig[itrack]));
                  histoIP_c->Fill(fabs(Track_IP[itrack]));		 
                  histoIPerr_c->Fill(fabs(Track_IPerr[itrack]));
                  decayL_c->Fill(fabs(Track_length[itrack]));	          
		 
		 
		  NHits_c     ->Fill(Track_nHitAll[itrack]);
	          TrkMulti_c  ->Fill(Jet_ntracks[ijet]);
	          chi2_c      ->Fill(Track_chi2[itrack]);
	          deltaRmin_c ->Fill(deltaRmin);  		 
		  deltaRsum_c ->Fill(deltaRsumm_all);
		  ptRatio_c   ->Fill(Track_pt[itrack]/Jet_pt[ijet]);

// 	          DeltaRtrk_jetPt_c  ->Fill(Jet_pt[ijet],deltaRmin);
// 	          mutliTrk_deltaR_c  ->Fill(deltaRmin,Jet_ntracks[ijet]);
// 	          Nhits_deltaR_c     ->Fill(deltaRmin,Track_nHitAll[itrack]);
// 	          JetProba_deltaR_c  ->Fill(deltaRmin,Jet_Proba[ijet]);
// 	          TrackProba_deltaR_c->Fill(deltaRmin,Track_Proba[itrack]);
// 	          chi2Trk_deltaR_c   ->Fill(deltaRmin,Track_chi2[itrack]);
		
// 		  mutliTrk_jetPt_c  ->Fill(Jet_pt[ijet],Jet_ntracks[ijet]);
// 		  Nhits_jetPt_c     ->Fill(Jet_pt[ijet],Track_nHitAll[itrack]);
// 		  JetProba_jetPt_c  ->Fill(Jet_pt[ijet],Jet_Proba[ijet]);
// 		  TrackProba_jetPt_c->Fill(Jet_pt[ijet],Track_Proba[itrack]);
// 		  chi2Trk_jetPt_c   ->Fill(Jet_pt[ijet],Track_chi2[itrack]);
		
	        }	         
		
		else if(fabs(Jet_flavour[ijet])<4 || fabs(Jet_flavour[ijet])==21 ){
		 histoIP_firstTk_l->Fill(sig1_ip);
	         histoIP_secTk_l->Fill(sig2_ip);		
	         histoIP_thirdTk_l->Fill(sig3_ip);	         
		 
		 decayL_firstTk_l->Fill(del1_dl);
	         decayL_secTk_l->Fill(del2_dl);	   
	         decayL_thirdTk_l->Fill(del3_dl);
	        }	    
	        else{
		
		  histoIPsig_l->Fill(fabs(Track_IPsig[itrack]));
                  histoIP_l->Fill(fabs(Track_IP[itrack]));		 
                  histoIPerr_l->Fill(fabs(Track_IPerr[itrack]));
                  decayL_l->Fill(fabs(Track_length[itrack]));		  
		  NHits_l     ->Fill(Track_nHitAll[itrack]);
		  TrkMulti_l  ->Fill(Jet_ntracks[ijet]);
		  chi2_l      ->Fill(Track_chi2[itrack]);
		  deltaRmin_l ->Fill(deltaRmin); 
		  deltaRsum_l ->Fill(deltaRsumm_all);
		  ptRatio_l   ->Fill(Track_pt[itrack]/Jet_pt[ijet]);
		
// 		  DeltaRtrk_jetPt_l  ->Fill(Jet_pt[ijet],deltaRmin);
// 		  mutliTrk_deltaR_l  ->Fill(deltaRmin,Jet_ntracks[ijet]);
// 		  Nhits_deltaR_l     ->Fill(deltaRmin,Track_nHitAll[itrack]);
// 		  JetProba_deltaR_l  ->Fill(deltaRmin,Jet_Proba[ijet]);
// 		  TrackProba_deltaR_l->Fill(deltaRmin,Track_Proba[itrack]);
// 		  chi2Trk_deltaR_l   ->Fill(deltaRmin,Track_chi2[itrack]);		
// 		  mutliTrk_jetPt_l  ->Fill(Jet_pt[ijet],Jet_ntracks[ijet]);
// 		  Nhits_jetPt_l     ->Fill(Jet_pt[ijet],Track_nHitAll[itrack]);
// 		  JetProba_jetPt_l  ->Fill(Jet_pt[ijet],Jet_Proba[ijet]);
// 		  TrackProba_jetPt_l->Fill(Jet_pt[ijet],Track_Proba[itrack]);
// 		  chi2Trk_jetPt_l   ->Fill(Jet_pt[ijet],Track_chi2[itrack]);
		
	        }	    

	      }//end condition        
	    }// end track selection
	  }// end loop TRACKS
        }//end selection JETS
      } //end loop JETS  
    }//END LOOP EVENT
  
  //}//end event selection
  
   //DeltaRtrk_jetPt->Draw();
  myfile->Write(); 
  cout << "deltaRex: "<< deltaRex<< endl;
}


void HighPtStudy::run(){
  
//   Loop(30,1);
//   Loop(50,1);
   Loop(70,1);
  Loop(90,1);
  Loop(110,1);
  Loop(130,1);
//   Loop(150,1);
//   Loop(170,1);
//   Loop(190,1);
//   Loop(210,1);
//   Loop(230,1);
//  Loop(250,1);
//  Loop(270,1);
//   Loop(290,1);
//   Loop(310,1);
//   
//   Loop(3,0);
//   Loop(4,0);   
//  Loop(5,0);
  //Loop(6,0);   
  //Loop(7,0);
//  Loop(8,0);
  //Loop(9,0);
 //Loop(10,0);
// Loop(11,0);
//Loop(12,0);
// Loop(14,0);
 
//    Loop(1,2);
//    Loop(3,2);
//    Loop(5,2);
//    Loop(10,2);
 


//   Loop(70,0);
//   Loop(80,0);
//   Loop(90,0);
//   Loop(100,0);
//   Loop(150,0);
//   Loop(200,0);
//   Loop(300,0);
//   Loop(5,0);  
  
}


void HighPtStudy::plot1D(TString histo_name, int whatPlot){
  
  TCanvas *c1 = new TCanvas("c1", "c1",30,32,782,752);
  
  c1->SetFillColor(10);
  c1->SetFillStyle(4000);
  c1->SetBorderSize(2);
  c1->SetLogy(0); 
  
  gStyle->SetPadRightMargin(0.13);
  gStyle->SetPadLeftMargin(0.13);
  gStyle->SetOptDate(0);
  gStyle->SetStatColor(0);
  gStyle->SetTitleColor(1);
  
  TFile *myFile30     = new TFile("study_histo30_pt.root");
  myFile30->cd(); 
  TH1F*  histo30_b = (TH1F*)gROOT->FindObject(histo_name+"_b");
  TH1F*  histo30_c = (TH1F*)gROOT->FindObject(histo_name+"_c");
  TH1F*  histo30_l = (TH1F*)gROOT->FindObject(histo_name+"_l");
  
  
  TFile *myFile50     = new TFile("study_histo50_pt.root");
  myFile50->cd(); 
  TH1F*  histo50_b = (TH1F*)gROOT->FindObject(histo_name+"_b");
  TH1F*  histo50_c = (TH1F*)gROOT->FindObject(histo_name+"_c");
  TH1F*  histo50_l = (TH1F*)gROOT->FindObject(histo_name+"_l"); 
  
  
  TFile *myFile70     = new TFile("study_histo70_pt.root");
  myFile70->cd(); 
  TH1F*  histo70_b = (TH1F*)gROOT->FindObject(histo_name+"_b");
  TH1F*  histo70_c = (TH1F*)gROOT->FindObject(histo_name+"_c");
  TH1F*  histo70_l = (TH1F*)gROOT->FindObject(histo_name+"_l");  
  
  
  TFile *myFile90     = new TFile("study_histo90_pt.root");
  myFile90->cd(); 
  TH1F*  histo90_b = (TH1F*)gROOT->FindObject(histo_name+"_b");
  TH1F*  histo90_c = (TH1F*)gROOT->FindObject(histo_name+"_c");
  TH1F*  histo90_l = (TH1F*)gROOT->FindObject(histo_name+"_l"); 
  
  
  TFile *myFile110     = new TFile("study_histo110_pt.root");
  myFile110->cd(); 
  TH1F*  histo110_b = (TH1F*)gROOT->FindObject(histo_name+"_b");
  TH1F*  histo110_c = (TH1F*)gROOT->FindObject(histo_name+"_c");
  TH1F*  histo110_l = (TH1F*)gROOT->FindObject(histo_name+"_l"); 
  
  
  TFile *myFile130     = new TFile("study_histo130_pt.root");
  myFile130->cd(); 
  TH1F*  histo130_b = (TH1F*)gROOT->FindObject(histo_name+"_b");
  TH1F*  histo130_c = (TH1F*)gROOT->FindObject(histo_name+"_c");
  TH1F*  histo130_l = (TH1F*)gROOT->FindObject(histo_name+"_l"); 
  
  
  TFile *myFile150     = new TFile("study_histo150_pt.root");
  myFile150->cd(); 
  TH1F*  histo150_b = (TH1F*)gROOT->FindObject(histo_name+"_b");
  TH1F*  histo150_c = (TH1F*)gROOT->FindObject(histo_name+"_c");
  TH1F*  histo150_l = (TH1F*)gROOT->FindObject(histo_name+"_l"); 
  
  
  TFile *myFile170     = new TFile("study_histo170_pt.root");
  myFile170->cd(); 
  TH1F*  histo170_b = (TH1F*)gROOT->FindObject(histo_name+"_b");
  TH1F*  histo170_c = (TH1F*)gROOT->FindObject(histo_name+"_c");
  TH1F*  histo170_l = (TH1F*)gROOT->FindObject(histo_name+"_l"); 
  
  TFile *myFile190     = new TFile("study_histo190_pt.root");
  myFile190->cd(); 
  TH1F*  histo190_b = (TH1F*)gROOT->FindObject(histo_name+"_b");
  TH1F*  histo190_c = (TH1F*)gROOT->FindObject(histo_name+"_c");
  TH1F*  histo190_l = (TH1F*)gROOT->FindObject(histo_name+"_l"); 
  
  TFile *myFile210     = new TFile("study_histo210_pt.root");
  myFile210->cd(); 
  TH1F*  histo210_b = (TH1F*)gROOT->FindObject(histo_name+"_b");
  TH1F*  histo210_c = (TH1F*)gROOT->FindObject(histo_name+"_c");
  TH1F*  histo210_l = (TH1F*)gROOT->FindObject(histo_name+"_l"); 
  
  TFile *myFile230     = new TFile("study_histo230_pt.root");
  myFile230->cd(); 
  TH1F*  histo230_b = (TH1F*)gROOT->FindObject(histo_name+"_b");
  TH1F*  histo230_c = (TH1F*)gROOT->FindObject(histo_name+"_c");
  TH1F*  histo230_l = (TH1F*)gROOT->FindObject(histo_name+"_l"); 
  
  TFile *myFile250     = new TFile("study_histo250_pt.root");
  myFile250->cd(); 
  TH1F*  histo250_b = (TH1F*)gROOT->FindObject(histo_name+"_b");
  TH1F*  histo250_c = (TH1F*)gROOT->FindObject(histo_name+"_c");
  TH1F*  histo250_l = (TH1F*)gROOT->FindObject(histo_name+"_l"); 
  
  TFile *myFile270     = new TFile("study_histo270_pt.root");
  myFile270->cd(); 
  TH1F*  histo270_b = (TH1F*)gROOT->FindObject(histo_name+"_b");
  TH1F*  histo270_c = (TH1F*)gROOT->FindObject(histo_name+"_c");
  TH1F*  histo270_l = (TH1F*)gROOT->FindObject(histo_name+"_l"); 
  
  TFile *myFile290     = new TFile("study_histo290_pt.root");
  myFile290->cd(); 
  TH1F*  histo290_b = (TH1F*)gROOT->FindObject(histo_name+"_b");
  TH1F*  histo290_c = (TH1F*)gROOT->FindObject(histo_name+"_c");
  TH1F*  histo290_l = (TH1F*)gROOT->FindObject(histo_name+"_l"); 
  
  TFile *myFile310     = new TFile("study_histo310_pt.root");
  myFile310->cd(); 
  TH1F*  histo310_b = (TH1F*)gROOT->FindObject(histo_name+"_b");
  TH1F*  histo310_c = (TH1F*)gROOT->FindObject(histo_name+"_c");
  TH1F*  histo310_l = (TH1F*)gROOT->FindObject(histo_name+"_l"); 
  
  if (whatPlot==0){
    
//     histo30_l->Add(histo50_l);
//     histo30_l->Add(histo70_l);
//     histo30_l->Add(histo90_l);
//     histo30_l->Add(histo110_l);
//     histo30_l->Add(histo130_l);
//     histo30_l->Add(histo150_l);
//     histo30_l->Add(histo170_l);
//     histo30_l->Add(histo190_l);
//     histo30_l->Add(histo210_l);
//     histo30_l->Add(histo230_l);
//     histo30_l->Add(histo250_l);
//     histo30_l->Add(histo270_l);
//     histo30_l->Add(histo290_l);
//     histo30_l->Add(histo310_l); 
//     
//     histo30_b->Add(histo50_b);
//     histo30_b->Add(histo70_b);
//     histo30_b->Add(histo90_b);
//     histo30_b->Add(histo110_b);
//     histo30_b->Add(histo130_b);
//     histo30_b->Add(histo150_b);
//     histo30_b->Add(histo170_b);
//     histo30_b->Add(histo190_b);
//     histo30_b->Add(histo210_b);
//     histo30_b->Add(histo230_b);
//     histo30_b->Add(histo250_b);
//     histo30_b->Add(histo270_b);
//     histo30_b->Add(histo290_b);
//     histo30_b->Add(histo310_b);
//     
//     histo30_c->Add(histo50_c);
//     histo30_c->Add(histo70_c);
//     histo30_c->Add(histo90_c);
//     histo30_c->Add(histo110_c);
//     histo30_c->Add(histo130_c);
//     histo30_c->Add(histo150_c);
//     histo30_c->Add(histo170_c); 
//     histo30_c->Add(histo190_c);
//     histo30_c->Add(histo210_c);
//     histo30_c->Add(histo230_c);
//     histo30_c->Add(histo250_c);
//     histo30_c->Add(histo270_c);
//     histo30_c->Add(histo290_c);
//     histo30_c->Add(histo310_c);
    
    
    histo270_l->Scale(1/histo270_l->Integral());
    histo270_b->Scale(1/histo270_b->Integral());
    histo270_c->Scale(1/histo270_c->Integral());
    
    histo270_l->SetLineColor(3);
    histo270_b->SetLineColor(2);
    histo270_c->SetLineColor(4);
    
    histo270_l->GetXaxis()->SetTitle(histo_name);
    
    histo270_l->Draw();
    histo270_b->Draw("same");
    histo270_c->Draw("same");       
    
    TLegend* qw = 0;
    qw = new TLegend(0.50,0.70,0.80,0.80);
    
    qw->AddEntry(histo270_l,"light jets");
    qw->AddEntry(histo270_c,"c jets");
    qw->AddEntry(histo270_b,"b jets"); 
    qw->Draw();
    
  }
  
  else {
    
    histo30_c->Add(histo30_b);
    histo30_c->Add(histo30_l);
    
//     histo50_c->Add(histo50_b);
//     histo50_c->Add(histo50_l); 
//     
    histo70_c->Add(histo70_b);
    histo70_c->Add(histo70_l);
    
//      histo90_c->Add(histo90_b);
//      histo90_c->Add(histo90_l);
//     
//     histo110_c->Add(histo110_b);
//     histo110_c->Add(histo110_l); 
//     
//     histo130_c->Add(histo130_b);
//     histo130_c->Add(histo130_l);  
    
    histo150_c->Add(histo150_b);
    histo150_c->Add(histo150_l);
    
    histo170_c->Add(histo170_b);
    histo170_c->Add(histo170_l);  
    
    histo190_c->Add(histo190_b);
    histo190_c->Add(histo190_l);
    
    histo210_c->Add(histo210_b);
    histo210_c->Add(histo210_l);
    
    histo230_c->Add(histo230_b);
    histo230_c->Add(histo230_l);
    
    histo250_c->Add(histo250_b);
    histo250_c->Add(histo250_l); 
     
    histo270_c->Add(histo270_b);
    histo270_c->Add(histo270_l); 
    
    histo290_c->Add(histo290_b);
    histo290_c->Add(histo290_l); 
    
    histo310_c->Add(histo310_b);
    histo310_c->Add(histo310_l);     
    
    
    if (whatPlot==1){
      
       histo30_c ->Scale(1/histo30_c->Integral());
       histo70_c ->Scale(1/histo70_c->Integral());
//       histo50_c->Scale(1/histo50_c->Integral());
//        histo90_c->Scale(1/histo90_c->Integral());
//       
//       histo110_c->Scale(1/histo210_c->Integral());
      histo190_c->Scale(1/histo190_c->Integral());      
      //histo130_c->Scale(1/histo130_c->Integral());
      histo170_c->Scale(1/histo170_c->Integral());
      histo150_c->Scale(1/histo150_c->Integral());
      histo210_c->Scale(1/histo210_c->Integral());
      histo230_c->Scale(1/histo230_c->Integral());
      histo270_c->Scale(1/histo270_c->Integral());
      histo290_c->Scale(1/histo290_c->Integral());
      histo310_c->Scale(1/histo310_c->Integral());
      
      histo30_c ->SetLineColor(1);
      histo70_c ->SetLineColor(2);
      histo270_c->SetLineColor(5);
      histo210_c->SetLineColor(4);
      histo150_c->SetLineColor(3);
      
      
           
      histo30_c->GetXaxis()->SetTitle(histo_name);
      
      //histo210_c ->Draw();
      histo30_c->Draw();
      histo70_c->Draw("same");
      histo150_c->Draw("same");    
      histo210_c->Draw("same");    
      //histo270_c->Draw("same");    
     
      
      TLegend* qw = 0;
      qw = new TLegend(0.50,0.70,0.80,0.80);
    
//       qw->AddEntry(histo30_c,"0.005<deltaRmin<0.015 ");
//       qw->AddEntry(histo70_c,"0.025<deltaRmin<0.035");
//       qw->AddEntry(histo150_c,"0.065<deltaRmin<0.075"); 
//       qw->AddEntry(histo190_c,"0.085<deltaRmin<0.095");
//       qw->AddEntry(histo230_c,"0.145<deltaRmin<0.0155");	    
//       qw->AddEntry(histo270_c,"0.0.0025<deltaRmin<0.00075");

	
        qw->AddEntry(histo30_c," 20<pt Jet<40 GeV");
        qw->AddEntry(histo70_c," 60<pt Jet<80 GeV");
        qw->AddEntry(histo150_c," 140<pt Jet<160 GeV ");
        qw->AddEntry(histo210_c," 200<pt Jet<220 GeV");
        //qw->AddEntry(histo270_c," 260<pt Jet<280 GeV");
	   
     
      qw->Draw();
    }
    
    else if (whatPlot==2){
      
      double x25[140];
      double x35[140];
      double x45[140];
      double x55[140];
      double x65[140];
      double x75[140];
      double x85[140];
      double x95[140];
      double x125[140];
      double x175[140];
      double x0[140];
      double x1[140];
      double x2[140];
      double x3[140];
      
 //      for (int i=0; i<140 ; i++){
// 	x25[i]=(histo30_c->Integral(i,140))/(histo30_c->Integral());
// 	x35[i]=(histo50_c->Integral(i,140))/(histo50_c->Integral());
// 	x45[i]=(histo70_c->Integral(i,140))/(histo70_c->Integral());
// 	x55[i]=(histo90_c->Integral(i,140))/(histo90_c->Integral());
// 	x65[i]=(histo110_c->Integral(i,140))/(histo110_c->Integral());
// 	x75[i]=(histo130_c->Integral(i,140))/(histo130_c->Integral());
// 	x85[i]=(histo150_c->Integral(i,140))/(histo150_c->Integral());
// 	x95[i]=(histo170_c->Integral(i,140))/(histo170_c->Integral());
// 	x125[i]=(histo190_c->Integral(i,140))/(histo190_c->Integral());
// 	x175[i]=(histo210_c->Integral(i,140))/(histo210_c->Integral());
// 	x0[i]=(histo230_c->Integral(i,140))/(histo230_c->Integral());
// 	x1[i]=(histo250_c->Integral(i,140))/(histo250_c->Integral());
// 	x2[i]=(histo270_c->Integral(i,140))/(histo270_c->Integral());    
// 	x3[i]=(histo290_c->Integral(i,140))/(histo290_c->Integral());    
//       }
//       
//       int cut20=30;
//       double xGraph20[14]={x25[cut20],x35[cut20],x45[cut20],x55[cut20],x65[cut20],x75[cut20],x85[cut20],x95[cut20],x125[cut20],x175[cut20],x0[cut20],x1[cut20],x2[cut20],x3[cut20]};
//       double yGraph20[14]={30,50,70,90,110,130,150,170,190,210,230,250,270,290};
//       
//       
//       TGraph *g20 = new TGraph(14,yGraph20, xGraph20);
//       g20->SetMarkerStyle(20);
//       g20->SetLineColor(6);
//       
//       int cut130=50;
//       double xGraph130[14]={x25[cut130],x35[cut130],x45[cut130],x55[cut130],x65[cut130],x75[cut130],x85[cut130],x95[cut130],x125[cut130],x175[cut130],x0[cut130],x1[cut130],x2[cut130],x3[cut130]};
//       double yGraph130[14]={30,50,70,90,110,130,150,170,190,210,230,250,270,290};
//       
//       
//       TGraph *g130 = new TGraph(14,yGraph130, xGraph130);
//       g130->SetMarkerStyle(130);
//       g130->SetLineColor(2);
//       
//       
//       int cut40=40;
//       double xGraph40[14]={x25[cut40],x35[cut40],x45[cut40],x55[cut40],x65[cut40],x75[cut40],x85[cut40],x95[cut40],x125[cut40],x175[cut40],x0[cut40],x1[cut40],x2[cut40],x3[cut40]};
//       double yGraph40[14]={30,50,70,90,110,130,150,170,190,210,230,250,270,290};
//       
//       
//       TGraph *g40 = new TGraph(14,yGraph40, xGraph40);
//       g40->SetMarkerStyle(40);
//       g40->SetLineColor(3);  
//       
//       int cut60=10;
//       double xGraph60[14]={x25[cut60],x35[cut60],x45[cut60],x55[cut60],x65[cut60],x75[cut60],x85[cut60],x95[cut60],x125[cut60],x175[cut60],x0[cut60],x1[cut60],x2[cut60],x3[cut60]};
//       double yGraph60[14]={30,50,70,90,110,130,150,170,190,210,230,250,270,290};
//       
//       int cut100=20;
//       double xGraph100[14]={x25[cut100],x35[cut100],x45[cut100],x55[cut100],x65[cut100],x75[cut100],x85[cut100],x95[cut100],x125[cut100],x175[cut100],x0[cut100],x1[cut100],x2[cut100],x3[cut100]};
//       double yGraph100[14]={30,50,70,90,110,130,150,170,190,210,230,250,270,290};
//       
//       
//       TGraph *g100 = new TGraph(14,yGraph100, xGraph100);
//       g100->SetMarkerStyle(100);
//       g100->SetLineColor(4);
//       
//       
//       TGraph *g60 = new TGraph(14,yGraph60, xGraph60);
//       g60->SetMarkerStyle(60);
//       g60->SetLineColor(5); 
//       
//       
//       
//       TMultiGraph *mg = new TMultiGraph();
//       
//       //mg->GetXaxis()->SetTitle("jetPT");
//       //mg->GetYaxis()->SetTitle("fraction of tracks with IPsig < x");      
//       mg->Add(g20);
//       mg->Add(g130);
//       mg->Add(g40);
//       mg->Add(g100);
//       mg->Add(g60);    
//       mg->Draw("AC");
//       
//       
//       
//       
//       TLegend* qw2 = 0;
//       qw2 = new TLegend(0.50,0.70,0.80,0.80);  
//       qw2->AddEntry(g60,"cut Ipsig=1"); 
//       qw2->AddEntry(g100,"cut Ipsig=2");      
//       qw2->AddEntry(g20,"cut Ipsig =3");
//       qw2->AddEntry(g40,"cut Ipsig=4");
//       qw2->AddEntry(g130,"cut Ipsig=5");    
//       
// 
//       qw2->Draw();
    }
    
    
  }
    
  TString next;
  if (whatPlot==0)     next="norm";
  else if(whatPlot==1) next="diffPtJet";
  else                 next="integral";
  
  c1->SaveAs(histo_name+next+".gif");
  
  
}
  
void HighPtStudy::plot2D(TString histo_name){
    
 TCanvas *c1 = new TCanvas("c1", "c1",30,32,782,752);
 
 c1->SetFillColor(10);
 c1->SetFillStyle(4000);
 c1->SetBorderSize(2);
 c1->SetLogy(0); 
 
 gStyle->SetPadRightMargin(0.13);
 gStyle->SetPadLeftMargin(0.13);
 gStyle->SetOptDate(0);
 gStyle->SetStatColor(0);
 gStyle->SetTitleColor(1);
 
 
  
 TFile *myFile310     = new TFile("study_histo14.root");
 myFile310->cd(); 
 TH2F*  histo310_b = (TH2F*)gROOT->FindObject(histo_name+"_b");
 TH2F*  histo310_c = (TH2F*)gROOT->FindObject(histo_name+"_c");
 TH2F*  histo310_l = (TH2F*)gROOT->FindObject(histo_name+"_l"); 
 
 
 histo310_l->Draw("colz");
 histo310_b->Draw("colzsame");
 histo310_c->Draw("colzsame");  

 cout << "correlation factor light jets : " << histo310_l->GetCorrelationFactor() << endl;
 cout << "correlation factor c jets : " << histo310_c->GetCorrelationFactor() << endl;
 cout << "correlation factor b jets : " << histo310_b->GetCorrelationFactor() << endl;
 
 cout << "Covariance light jets : " << histo310_l->GetCovariance() << endl; 
 cout << "Covariance c jets : " << histo310_c->GetCovariance() << endl; 
 cout << "Covariance b jets : " << histo310_b->GetCovariance() << endl; 
 
 
 c1->SaveAs(histo_name+".gif");
}

