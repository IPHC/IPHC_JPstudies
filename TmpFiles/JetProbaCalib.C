#define JetProbaCalib_cxx
#include "JetProbaCalib.h"
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


using namespace std;

std::ofstream out_txt("Histo_25.xml", ios::out);

//-------------------------------------------Define different categories---------------------------------------------------------------------------------------------------//
std::vector<CategoryDef > JetProbaCalib::DefCategories()
{  
  std::vector<CategoryDef >  vectCat;
  
  vectCat.clear();
  
  nbins=10000;
  xmin=0.0;
  xmax=20.0;
  
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
 
   
  number_of_category=vectCat.size();
  
  return vectCat; 
}


//-----------------------------------------------------Find the category of a given track----------------------------------------------------------------------------------------//
bool JetProbaCalib::IsInCategory(float trkEta, float trkHTrk, float trkHPix, float trkp, float trkChi2, CategoryDef d){
  
  bool isIn=false;
  
  if (fabs(trkEta)>d.etaMin&&fabs(trkEta)<d.etaMax&&trkHTrk<=d.nHitsMax&&trkHTrk>=d.nHitsMin&&trkHPix<=d.nPixelHitsMax&&trkHPix>=d.nPixelHitsMin&&trkp<d.pMax&&trkp>d.pMin&&trkChi2>=d.chiMin&&trkChi2<=d.chiMax) isIn=true;
  
  return isIn;
  
}


//-----------------------------------------------------Return true if track passes btag selection ---------------------------------------------------------------------------------//
bool JetProbaCalib::passTrackSel(int trk, int pix, float ip2d, float pt, float len, float chi2, float zip, float dist, float eta, float etaJet, float phi, float phiJet, float ptJet)
{
//    float deta = eta - etaJet;
//    float dphi = phi - phiJet;
//  
//    if ( dphi > TMath::Pi() ) dphi = 2.*TMath::Pi() - dphi;
//    float deltaR = TMath::Sqrt(deta*deta + dphi*dphi);


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
//     
//    cout <<"----------------------------------------------------------------------------"<<endl;
//    cout <<"trk : " <<trk << endl;
//    cout <<"ip2d : " <<ip2d << endl;
//    cout <<"pix : " <<pix << endl;
//    cout <<"pt : " << pt<< endl;
//    cout <<"len : " <<len << endl;
//    cout <<"chi2 : " << chi2<< endl;
//    cout <<"zip : " << zip<< endl;
//    cout <<"dist : " << dist<< endl;
//    cout <<"deltaR : " <<deltaR << endl;
  
  
  
  }
  
  return passSel;
  
}

std::vector<TH1D* > JetProbaCalib::GetCategories(const char* fileInPutName){
  
  
  TFile * myInputFile = new TFile(fileInPutName);
  myInputFile->cd();
  myInputFile->ls();
  std::vector<TH1D* >  vectH;
  vectH.clear();
  
  for(int i = 0; i < 10; i++){
    
    TH1D* histo ;
    
    if(i == 0) histo= (TH1D*)gROOT->FindObject("histoCat0"); 
    if(i == 1) histo= (TH1D*)gROOT->FindObject("histoCat1"); 
    if(i == 2) histo= (TH1D*)gROOT->FindObject("histoCat2"); 
    if(i == 3) histo= (TH1D*)gROOT->FindObject("histoCat3"); 
    if(i == 4) histo= (TH1D*)gROOT->FindObject("histoCat4"); 
    if(i == 5) histo= (TH1D*)gROOT->FindObject("histoCat5"); 
    if(i == 6) histo= (TH1D*)gROOT->FindObject("histoCat6"); 
    if(i == 7) histo= (TH1D*)gROOT->FindObject("histoCat7"); 
    if(i == 8) histo= (TH1D*)gROOT->FindObject("histoCat8"); 
    if(i == 9) histo= (TH1D*)gROOT->FindObject("histoCat9"); 
    if(i == 10) histo= (TH1D*)gROOT->FindObject("histoCat10"); 
    if(i == 11) histo= (TH1D*)gROOT->FindObject("histoCat11"); 
    if(i == 12) histo= (TH1D*)gROOT->FindObject("histoCat12"); 
    if(i == 13) histo= (TH1D*)gROOT->FindObject("histoCat13"); 
    if(i == 14) histo= (TH1D*)gROOT->FindObject("histoCat14"); 
    if(i == 15) histo= (TH1D*)gROOT->FindObject("histoCat15"); 
    if(i == 16) histo= (TH1D*)gROOT->FindObject("histoCat16"); 
    if(i == 17) histo= (TH1D*)gROOT->FindObject("histoCat17"); 
    if(i == 18) histo= (TH1D*)gROOT->FindObject("histoCat18"); 
    if(i == 19) histo= (TH1D*)gROOT->FindObject("histoCat19"); 
    if(i == 20) histo= (TH1D*)gROOT->FindObject("histoCat20"); 
    if(i == 21) histo= (TH1D*)gROOT->FindObject("histoCat21"); 
    if(i == 22) histo= (TH1D*)gROOT->FindObject("histoCat22"); 
    if(i == 23) histo= (TH1D*)gROOT->FindObject("histoCat23"); 
    if(i == 24) histo= (TH1D*)gROOT->FindObject("histoCat24"); 
    if(i == 25) histo= (TH1D*)gROOT->FindObject("histoCat25"); 
    if(i == 26) histo= (TH1D*)gROOT->FindObject("histoCat26"); 
    if(i == 27) histo= (TH1D*)gROOT->FindObject("histoCat27"); 
    if(i == 28) histo= (TH1D*)gROOT->FindObject("histoCat28"); 
    if(i == 29) histo= (TH1D*)gROOT->FindObject("histoCat29"); 
    if(i == 30) histo= (TH1D*)gROOT->FindObject("histoCat30"); 
    if(i == 31) histo= (TH1D*)gROOT->FindObject("histoCat31"); 
    if(i == 32) histo= (TH1D*)gROOT->FindObject("histoCat32"); 
    if(i == 33) histo= (TH1D*)gROOT->FindObject("histoCat33"); 
    if(i == 34) histo= (TH1D*)gROOT->FindObject("histoCat34"); 
    if(i == 35) histo= (TH1D*)gROOT->FindObject("histoCat35"); 
    if(i == 36) histo= (TH1D*)gROOT->FindObject("histoCat36"); 
    if(i == 37) histo= (TH1D*)gROOT->FindObject("histoCat37"); 
    if(i == 38) histo= (TH1D*)gROOT->FindObject("histoCat38"); 
    if(i == 39) histo= (TH1D*)gROOT->FindObject("histoCat39"); 
    if(i == 40) histo= (TH1D*)gROOT->FindObject("histoCat40"); 
    if(i > 40) cout << "WARNING !!! max number of category  == 40 !!! " << endl;
    vectH.push_back(histo);
  }
  
  return vectH;
  
}
  
  
  
  
//-----------------------------------------------------Compute the probability that a track comes from PV ---------------------------------------------------------------------------//
double JetProbaCalib::calculTrackProba(float p, float eta,int nhit, int npix, float chi,float ipsig, std::vector<TH1D*> vectHis, std::vector<TH1D*> vectTrkP,std::vector<CategoryDef> vectHisCat){

   
  bool foundCat = false;
  TH1D * myHisto;
  TH1D * myHistoTrk;
  for(unsigned int i=0; i< vectHisCat.size(); i++){
    //cout << vectD[i].histo << endl;
    if(IsInCategory(eta,nhit ,npix ,p, chi, vectHisCat[i])) {
      foundCat = true;
      myHisto = vectHis[i];
      myHistoTrk= vectTrkP[i];
    }
  }
  
  double proba= -1000.0;
  double histoIntegral = 1.0;
  if( foundCat == true){
    int nbin = int(fabs(ipsig)*(nbins+1)/xmax);
    //int nbin = int(fabs(ipsig)*(nbins)/xmax)+1;
    //int nbin = int(fabs(ipsig)*(nbins)/xmax)+1;
    //cout << "-------------------------------------------" << endl;
    //cout << "nbin: " <<nbin << endl;  
    //cout << "ipsig:" << ipsig<< endl;
    
    
//cout << "1385: " << myHisto->GetBinContent(1385)  << endl; 
//cout << "1386: " << myHisto->GetBinContent(1386)  << endl; 
    
//    histoIntegral = myHisto->Integral();
//     proba = (myHisto->Integral(nbin, nbins  ))/histoIntegral;


  double sum=0.0;
  for(int i=nbin; i<=(nbins) ; i++){
    double x=myHisto->GetBinContent(i);
    sum=sum+x;
  }
  
  double sum_tot=0.0;
  for(int i=1; i<=(nbins) ; i++){
    double x=myHisto->GetBinContent(i);
    sum_tot=sum_tot+x;
  }    
  proba=sum/sum_tot;
  
    if (ipsig < 0) proba=-proba;
  
    myHistoTrk->Fill(fabs(proba));
    vectTrkP[10]->Fill(fabs(proba));
  
  }
  else proba = -100.0;		
    
return proba;
  
  
  
}


double JetProbaCalib::jetProbability( std::vector<double>  v) 

{
  std::vector<double> probabilities;
  int i=0;

  for(std::vector<double>::const_iterator it = v.begin(); it!=v.end(); ++it, i++)
  {
         
      float p;
      if(*it >=0 ) p=*it; else continue; 
      //if (*it >=0){p=*it/2.;}else{p=1.-*it/2.;}
      //p=*it ; 
      probabilities.push_back(p);

  } 
	 
 
  double m_minTrackProb= 0.005;
  int ngoodtracks=v.size();
  double SumJet=0.;


  for(std::vector<double>::const_iterator q = probabilities.begin(); q != probabilities.end(); q++){
    SumJet+=(*q>m_minTrackProb)?log(*q):log(m_minTrackProb);
  }

  double ProbJet;
  double Loginvlog=0;

  if(SumJet<0.){
    if(ngoodtracks>=2){
      Loginvlog=log(-SumJet);
    }
    double Prob=1.;
    double lfact=1.;
    for(int l=1; l!=ngoodtracks; l++){
       lfact*=l;
      Prob+=exp(l*Loginvlog-log(1.*lfact));
    }
    double LogProb=log(Prob);
    ProbJet=
      std::min(exp(std::max(LogProb+SumJet,-30.)),1.);
  }else{
    ProbJet=1.;
  }
  if(ProbJet>1)
   std::cout << "ProbJet too high: "  << ProbJet << std::endl;

  //double LogProbJet=-log(ProbJet);
  //  //return 1.-ProbJet;
      return -log10(ProbJet)/4.;
      
}


void  JetProbaCalib::rootxmlFirst_newFormat()
{
  out_txt << "<Object class=\"TrackProbabilityCalibration\">" << endl;
  out_txt << "  <Class name=\"TrackProbabilityCalibration\" version=\"1\">" << endl;
  out_txt << "    <Member name=\"data\">" << endl;
  out_txt << "      <Item name=\"Version\" v=\"6\"/>" << endl;
  out_txt << "      <Item name=\"Int_t\" v=\"10\"/>" << endl;
 
}




void  JetProbaCalib::rootxml_newFormat( CategoryDef cat )
{ 

  // TH1D* hcat = (TH1D*)gROOT->FindObject((catname.c_str()));  
  
  
  //TH1F *hcat = &cat.histo;
  
  TH1D* hcat = cat.histoCalib;  
  
  out_txt << "       <Object class=\"TrackProbabilityCalibration::Entry\">" << endl; 
  out_txt << "        <Class name=\"TrackProbabilityCalibration::Entry\" version=\"1\">" << endl;
  out_txt << "  	<Member name=\"category\">"  << endl;
  out_txt << "  	  <Class name=\"TrackProbabilityCategoryData\" version=\"1\"> " << endl;
  

  out_txt << "  	       <Member name=\"pMin\" v=\""<<	       cat.pMin  << "\"/>" << endl;
  out_txt << "  	       <Member name=\"pMax\" v=\""<<	       cat.pMax  << "\"/>" << endl;
  out_txt << "  	       <Member name=\"etaMin\" v=\""<<         cat.etaMin << "\"/>" << endl;
  out_txt << "  	       <Member name=\"etaMax\" v=\""<<         cat.etaMax << "\"/>" << endl;
  out_txt << "  	       <Member name=\"nHitsMin\" v=\""<<       cat.nHitsMin << "\"/>" << endl;
  out_txt << "  	       <Member name=\"nHitsMax\" v=\""<<       cat.nHitsMax << "\"/>" << endl;
  out_txt << "  	       <Member name=\"nPixelHitsMin\" v=\""<<  cat.nPixelHitsMin  << "\"/>" << endl;
  out_txt << "  	       <Member name=\"nPixelHitsMax\" v=\""<<  cat.nPixelHitsMax << "\"/>" << endl;
  out_txt << "  	       <Member name=\"chiMin\" v=\""<<         cat.chiMin << "\"/>" << endl;
  out_txt << "  	       <Member name=\"chiMax\" v=\""<<         cat.chiMax << "\"/>" << endl;
  out_txt << "  	       <Member name=\"withFirstPixel\" v=\""<< cat.withFirstPixelHit << "\"/>" << endl;
  out_txt << "  	       <Member name=\"trackQuality\" v=\""<< 1000 << "\"/>" << endl;
  


  out_txt << "  	       </Class>"									 << endl;
  out_txt << "  	      </Member>"									 << endl;
  out_txt << "  	      <Member name=\"histogram\">"							 << endl;
  out_txt << "  	       <Class name=\"PhysicsTools::Calibration::Histogram_float_float_\" version=\"1\">" << endl;
  out_txt << "  		 <Member name=\"binULimits\">"  						 << endl;
  out_txt << "  		  <Item name=\"Version\" v=\"6\"/>"						 << endl;
  out_txt << "  		  <Item name=\"Int_t\" v=\"0\"/>"						 << endl;
  out_txt << "  		 </Member>"									 << endl;
  out_txt << "  		 <Member name=\"binValues\">"							 << endl;
  out_txt << "  		  <Item name=\"Version\" v=\"6\"/>"						 << endl;
  out_txt << "  		  <Item name=\"Int_t\" v=\""<<hcat->GetNbinsX() <<"\"/>"		       << endl;
  out_txt << "  		  <Item name=\"Array\">  "							 << endl;
  
       
         

  for(int i=1;i <= nbins;i++)
    {   double entry = hcat->GetBinContent(i);
        out_txt << "                      <Item name=\"Float_t\" v=\""<<
	fixed<<setprecision(6)<<entry <<  "\"/>" << endl; 
      //cout << " get bin x " << hcat->GetBinContent(i) <<  endl; 
    }

 out_txt << "		    </Item> "<< endl;
 out_txt << "		   </Member> "<< endl;
 out_txt << "		   <Member name=\"limits\"> "<< endl;
 out_txt << "		     <Class name=\"PhysicsTools::Calibration::Range_float_\" version=\"1\"> "<< endl;
 out_txt << "		       <Member name=\"min\" v=\"0.000000\"/> "<< endl;
 out_txt << "		       <Member name=\"max\" v=\""<< hcat->GetXaxis()->GetXmax() <<"\"/> "<< endl;
 out_txt << "		     </Class> "<< endl;
 out_txt << "		   </Member> "<< endl;
 out_txt << "		 </Class> "<< endl;
 out_txt << "	       </Member> "<< endl;
 out_txt << "	     </Class> "<< endl;
 out_txt << "	   </Object> "<< endl;




}


void  JetProbaCalib::rootxmlLast_newFormat(){

 out_txt << "	 </Member>"<< endl;
 out_txt << "  </Class>"<< endl;
 out_txt << "</Object>"<< endl;

}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//--------------------------------------------------FIRST LOOP TO FILL CATEGORIES------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

void JetProbaCalib::Loop(int choice)
{
  double ptmax=10;
  
  TFile* myfile = new TFile("calibeHistoWrite.root", "recreate");
  myfile->cd();
  
  if (fChain == 0) return;
  
  Long64_t nentries = fChain->GetEntriesFast();
  
  Long64_t nbytes = 0, nb = 0;
  
  
  std::vector<CategoryDef > vectCat=DefCategories();  
  
  //-------------------------------------// EVENT LOOP //---------------------------------------------------------------------------------------------//
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0 ) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    // if (Cut(ientry) < 0) continue;
    
    for (int ijet=0; ijet<nJet ; ijet++){
      
      if (fabs(Jet_eta[ijet]) < 2.5 && Jet_pt[ijet]>10){
        for( int itrack=Jet_nFirstTrack[ijet]; itrack< Jet_nLastTrack[ijet]; itrack++){
	  
	  bool passSelection=passTrackSel(Track_nHitAll[itrack],Track_nHitPixel[itrack],Track_IP2D[itrack],Track_pt[itrack],Track_length[itrack],Track_chi2[itrack],Track_zIP[itrack],Track_dist[itrack],Track_eta[itrack],Jet_eta[ijet],Track_phi[itrack],Jet_phi[ijet],Jet_pt[ijet]);           
          
//                cout <<"------------------------------------------------"<< endl;
//                cout <<"Track_pt[itrack] : "<< Track_pt[itrack]<< endl;	      
// 	       	      
//                cout <<"Track_eta[itrack] : "<< Track_eta[itrack]<< endl;	      
//                cout <<"Track_nHitAll[itrack] : "<< Track_nHitAll[itrack]<< endl;	      
//                cout <<"Track_nHitPixel[itrack] : "<<Track_nHitPixel[itrack] << endl;	      
//                cout <<"Track_pt[itrack] : "<<Track_pt[itrack] << endl;	      
//                cout <<"Track_chi2[itrack] : "<< Track_chi2[itrack]<< endl;
//                cout <<"Track_IP2D[itrack] : "<< Track_IP2D[itrack]<< endl;
//                cout <<"Track_zIP[itrack] : "<< Track_zIP[itrack]<< endl;
//                cout <<"Track_dist[itrack] : "<< Track_dist[itrack]<< endl;	       	       
//                cout <<"Track_length[itrack] : "<< Track_length[itrack]<< endl;	       	       
	       	  
	  
	  
	  if(Track_IP[itrack]<0 && passSelection){

	       	       	       
	    for (int i=0 ; i<10 ; i++){
	      bool fill=false;

	      fill = IsInCategory(Track_eta[itrack],Track_nHitAll[itrack] ,Track_nHitPixel[itrack] ,Track_p[itrack] , Track_chi2[itrack], vectCat[i]);
	      
	      if (fill) {
	        int cat=i;
	      
		//if(fabs(Track_IPsig[itrack])>xmax) vectCat[i].histoCalib->SetBinContent(nbins,-1*Track_IPsig[itrack] ); 
		//else                               vectCat[i].histoCalib->Fill(-1*Track_IPsig[itrack]);
               vectCat[cat].histoCalib->Fill(-1*Track_IPsig[itrack]);
	      }	      
	    }
	  }
	}
      }
    }
  }
  

	
	  
   //Store histograms into DB format

  rootxmlFirst_newFormat();
    
    
  for(int i=0; i< vectCat.size(); i++){
    rootxml_newFormat( vectCat[i]);
  }  
    
    
  rootxmlLast_newFormat();
  
  
  //-------------------------------------// END VENT LOOP //---------------------------------------------------------------------------------------------//
  
  myfile->Write();   
  
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//--------------------------------------------------SECOND LOOP TO FILL COMPUTE TRACK PROBABILTY-----------------------------------------------------------------------------------//
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

void JetProbaCalib::ComputeProba(const char*fileInPutName)
{
  
  TFile* myfileout = new TFile("JP_myCalib.root", "recreate");
  myfileout->cd();
  
  int nbin_trkH=50;
  float xmin_trkH=0.0;
  float xmax_trkH=1.02;  
  
  std::vector<CategoryDef> vecthistoCatDef=DefCategories();

  std::vector<TH1D*> vecthistoCatFile=GetCategories(fileInPutName);
  

  
  TH1D * JetProba = new TH1D("JetProba", "JetProba", 100, 0.0, 2.5);
  
  TH1D * trackPCat_all = new TH1D("trackPCat_all", "trackPCat_all", nbin_trkH, xmin_trkH, xmax_trkH);
  
  TH1D * trackPCat0 = new TH1D("trackPCat0", "trackPCat0", nbin_trkH, xmin_trkH, xmax_trkH);
  TH1D * trackPCat1 = new TH1D("trackPCat1", "trackPCat1", nbin_trkH, xmin_trkH, xmax_trkH);
  TH1D * trackPCat2 = new TH1D("trackPCat2", "trackPCat2", nbin_trkH, xmin_trkH, xmax_trkH);
  TH1D * trackPCat3 = new TH1D("trackPCat3", "trackPCat3", nbin_trkH, xmin_trkH, xmax_trkH);
  TH1D * trackPCat4 = new TH1D("trackPCat4", "trackPCat4", nbin_trkH, xmin_trkH, xmax_trkH);
  TH1D * trackPCat5 = new TH1D("trackPCat5", "trackPCat5", nbin_trkH, xmin_trkH, xmax_trkH);
  TH1D * trackPCat6 = new TH1D("trackPCat6", "trackPCat6", nbin_trkH, xmin_trkH, xmax_trkH);
  TH1D * trackPCat7 = new TH1D("trackPCat7", "trackPCat7", nbin_trkH, xmin_trkH, xmax_trkH);
  TH1D * trackPCat8 = new TH1D("trackPCat8", "trackPCat8", nbin_trkH, xmin_trkH, xmax_trkH);
  TH1D * trackPCat9 = new TH1D("trackPCat9", "trackPCat9", nbin_trkH, xmin_trkH, xmax_trkH);
  
  
  TH1F * jetProbaDiscriB = new TH1F("jetProbaDiscriB", "jetProbaDiscriB", 101, 0, 1); 
  TH1F * jetProbaDiscriUDSG = new TH1F("jetProbaDiscriUDSG", "jetProbaDiscriUDSG", 101, 0, 1);
   
  std::vector<TH1D *> vectTrkProba; 
   
  vectTrkProba.push_back(trackPCat0);
  vectTrkProba.push_back(trackPCat1);
  vectTrkProba.push_back(trackPCat2);  
  vectTrkProba.push_back(trackPCat3);  
  vectTrkProba.push_back(trackPCat4);  
  vectTrkProba.push_back(trackPCat5);  
  vectTrkProba.push_back(trackPCat6);
  vectTrkProba.push_back(trackPCat7);  
  vectTrkProba.push_back(trackPCat8);  
  vectTrkProba.push_back(trackPCat9); 
  vectTrkProba.push_back(trackPCat_all);
  
  std::vector<double > vectProba;
  //std::vector<double>  vectProba_trueMC ;
  
  
  Long64_t nentries = fChain->GetEntriesFast();
  
  Long64_t nbytes = 0, nb = 0;  
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0 ) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    
    
    for (int ijet=0; ijet<nJet ; ijet++){
    
      
      if (Jet_pt[ijet]>10 && fabs(Jet_eta[ijet]) < 2.5 ){
      
	  //cout <<"-----------"<<jentry<<"--------------" << endl;
      
        double jetP=0.0;
        vectProba.clear();
	//vectProba_trueMC.clear();
	
	
	for( int itrack=Jet_nFirstTrack[ijet]; itrack< Jet_nLastTrack[ijet]; itrack++){
	
	  double proba=-1000;
	   	  
	  bool passSelection=passTrackSel(Track_nHitAll[itrack],Track_nHitPixel[itrack],Track_IP2D[itrack],Track_pt[itrack],Track_length[itrack],Track_chi2[itrack],Track_zIP[itrack],Track_dist[itrack],Track_eta[itrack],Jet_eta[ijet],Track_phi[itrack],Jet_phi[ijet],Jet_pt[ijet]);    
	  
	  if(passSelection && Track_IPsig[itrack]<0) {          

	    
            proba=calculTrackProba(Track_p[itrack],Track_eta[itrack],Track_nHitAll[itrack],Track_nHitPixel[itrack],Track_chi2[itrack],Track_IPsig[itrack],vecthistoCatFile, vectTrkProba, vecthistoCatDef);
            
	    
	    
	    //cout <<"proba : " << proba  <<"and Track_Proba : " << Track_Proba[itrack] << endl;
	    
	    vectProba.push_back(proba);
	    
	    
	    //if (proba>0) trackPCat_all->Fill(proba);
//                cout <<"------------------------------------------------"<< endl;	      
//                cout <<"track number  : "<< itrack<< endl;	      
//  	       cout << "Track_Proba : " << Track_Proba[itrack] << endl;
//                cout <<"Track_eta[itrack] : "<< Track_eta[itrack]<< endl;	      
//                cout <<"Track_nHitStrip[itrack] : "<< Track_nHitStrip[itrack]<< endl;	      
//                cout <<"Track_nHitPixel[itrack] : "<<Track_nHitPixel[itrack] << endl;	      
//                cout <<"Track_pt[itrack] : "<<Track_pt[itrack] << endl;	      
//                cout <<"Track_chi2[itrack] : "<< Track_chi2[itrack]<< endl;
//                cout <<"Track_IP2D[itrack] : "<< Track_IP[itrack]<< endl;


	  
	  }	    
	  
	}
	
        if (vectProba.size()!=0) jetP=jetProbability( vectProba);
	
	
	    //cout <<"jetP : " << jetP << endl;
	    //cout <<"jetP true MC : " << Jet_Proba[ijet] << endl;
	    
	
	JetProba->Fill(jetP);
	//cout << "jetP :" <<jetP << "and Jet_Proba" <<Jet_Proba[ijet] << endl;
	if(Jet_flavour[ijet]==5)jetProbaDiscriB->Fill(Jet_Proba[ijet]);
	
	if(Jet_flavour[ijet]== 1 || Jet_flavour[ijet]== 2 || Jet_flavour[ijet]==3 || Jet_flavour[ijet]==21) jetProbaDiscriUDSG->Fill(Jet_Proba[ijet]);
	
      }
    
    }
  }  
  
  myfileout->cd();
  trackPCat0->Write();
  trackPCat1->Write();
  trackPCat2->Write();
  trackPCat3->Write();
  trackPCat4->Write();
  trackPCat5->Write(); 
  trackPCat6->Write();
  trackPCat7->Write(); 
  trackPCat8->Write(); 
  trackPCat9->Write(); 
  trackPCat_all->Write();  
  jetProbaDiscriB ->Write(); 
  jetProbaDiscriUDSG->Write(); 

  myfileout->Write();
}


// void JetProbaCalib::plotPerf()
// {
// 
// 
// 
//   TH1D *  bjet_btag = new TH1D("bjet_btag", "bjet_btag", 100, 0, 2.5);
//   TH1D *  ljet_btag = new TH1D("ljet_btag", "ljet_btag", 100, 0, 2.5); 
//   TH1D *  eff_btag= new TH1D("eff_btag", "eff_btag", 100, 0.0, 1.0);   
//   TH1D *  mis_btag= new TH1D("mis_btag", "mis_btag", 100, 0.0, 1.0);    
// 
// 
//   Long64_t nentries = fChain->GetEntriesFast();
//   
//   Long64_t nbytes = 0, nb = 0;  
// 
//   for (Long64_t jentry=0; jentry<nentries;jentry++) {
//     Long64_t ientry = LoadTree(jentry);
//     if (ientry < 0 ) break;
//     nb = fChain->GetEntry(jentry);   nbytes += nb;
//     
//     
//     for (int ijet=0; ijet<nJet ; ijet++){
//     
//       
//       if (Jet_pt[ijet]>10 && fabs(Jet_eta[ijet]) < 2.5 ){
//         if (Jet_flavour[ijet]==5) bjet_btag->Fill(Jet_Proba[ijet]);
//         else                      ljet_btag->Fill(Jet_Proba[ijet]);
// 	
//  
// 	}
// 	
//       }
//     
//   }
// 
// 
//   for (int i=1; i<101 ; i++){
//     eff_btag->SetBinContent(i,((bjet_btag->Integral(1,i))/(bjet_btag->Integral())));
//     mis_btag->SetBinContent(i,((ljet_btag->Integral(1,i))/(ljet_btag->Integral())));    
//   }
//   
//   
//   double eff[100];
//   double mis[100];  
//   
//   for (int i=0; i<100 ; i++){
//     
//     eff[i]= eff_btag->GetBinContent(i+1);
//     mis[i]= mis_btag->GetBinContent(i+1);
//     
//   }
//   
//   TGraph *g = new TGraph(100,eff, mis);   
//   g->Draw("ac");
//   
//  bjet_btag->SetLineColor(2);
//  //ljet_btag->Draw();
//  //bjet_btag->Draw("same");
//  
// }

void JetProbaCalib::plotPerf()
{

  TFile *f1 = new TFile("study_histo40_pt.root"); 
  TFile *f2 = new TFile("study_histo40_pt.root");  
  
  Int_t stati=0;
  Bool_t  fit=1;
  Bool_t logy=1;
  
  // *****************************************************************************
  
  TCanvas *c1 = new TCanvas("c1", "plots",200,10,700,800);
  c1->SetFillColor(10);
  c1->SetFillStyle(4000);
  c1->SetBorderSize(2);
  
  // *****************************************************************************
  
  // TPostScript *ps = new TPostScript("plot.ps",113);
  
  // *****************************************************************************
  
  //TPaveLabel *p01 = new TPaveLabel(0.05,0.94,0.97,0.99,"Jet Probability performances, 10pb^{-1} scenario","br");
  TPaveLabel *p01 = new TPaveLabel(0.05,0.94,0.97,0.99,"Jet Probability performances, 80<#hat{pT}<120 GeV","br");
  p01->SetFillColor(7);
  p01->SetTextSize(0.8);
  p01->SetFillStyle(3017);
  p01->Draw();
  
  
  TPad *pad1 = new TPad("pad1","This is pad1",0.04,0.04,0.91,0.91,21);
  
  
  
  TH2F* Eff = new TH2F("Eff", "", 1000, 0, 1., 1000, 0.00001, 1.);
  
  Eff->GetYaxis()->SetTitle("non b-jet efficiency");
  Eff->GetYaxis()->SetTitleSize(0.05);
  Eff->GetXaxis()->SetTitle("b-jet efficiency");
  Eff->GetXaxis()->SetTitleSize(0.05);
  Eff->GetYaxis()->SetTitleOffset(1.1);
  
  
  pad1->SetFillColor(0);
  pad1->SetBorderMode(0);
  pad1->SetFrameFillColor(10);
  pad1->Draw();
  pad1->SetLogy(logy);
  pad1->SetTopMargin(0.05);
  pad1->SetBottomMargin(0.15);
  pad1->SetRightMargin(0.05);
  pad1->SetLeftMargin(0.15);
  
  f1->cd();
  pad1->cd();
  TH1F* hnBjets = (TH1F*)gROOT->FindObject("histoIP_thirdTk_b");
  TH1F* hnLGjets = (TH1F*)gROOT->FindObject("histoIP_thirdTk_l");
  
  Float_t x[101],  yudsg[101], ex[101],  eyudsg[101];
  
  double NTotB      = hnBjets->Integral();
  double NTotUDSG   = hnLGjets->Integral();

  
  int nbin = 101.;
  double Cut0 = 0;
  for(int k=0; k!=100; k++){
    
    Cut0 = Cut0 + (1./100.);
    double NselectedB = 0;
    double NselectedUDSG = 0;
    for(int i= 1; i!= nbin; i++ ){  
      if(  i*1./100. > Cut0 ) {
	NselectedB  = NselectedB +  hnBjets->GetBinContent(i); 
	NselectedUDSG = NselectedUDSG +  hnLGjets->GetBinContent(i); 
      }
      
    }
      x[k] = NselectedB/NTotB;
      yudsg[k] = NselectedUDSG/NTotUDSG;
      ex[k]=TMath::Sqrt(NselectedB*(1-NselectedB/NTotB))/NTotB;
      eyudsg[k]=TMath::Sqrt(NselectedUDSG*(1-NselectedUDSG/NTotUDSG))/NTotUDSG;
  }
  
  Eff->Draw("l");
  
  TGraphErrors *gr1 = new TGraphErrors(100,x,yudsg,ex,eyudsg);
  gr1->SetLineColor(1);
  gr1->SetMarkerColor(4);
  gr1->SetMarkerStyle(22);
  gr1->SetMarkerSize(1.1);
  gr1->Draw("p");  
  
  f2->cd();
//   TH1F* hnBjets2 = (TH1F*)gROOT->FindObject("jetProbaDiscriB");
//   TH1F* hnLGjets2 = (TH1F*)gROOT->FindObject("jetProbaDiscriUDSG");

   TH1F* hnBjets2 = (TH1F*)gROOT->FindObject("decayL_thirdTk_b");
   TH1F* hnLGjets2 = (TH1F*)gROOT->FindObject("decayL_thirdTk_l");
  
  Float_t x2[101],  yudsg2[101], ex2[101],  eyudsg2[101];
  
  double NTotB2      = hnBjets2->Integral();
  double NTotUDSG2   = hnLGjets2->Integral();
  

  double Cut1 = 0;
  for(int k=0; k!=100; k++){
    
    Cut1 = Cut1 + (1./100.);
    double NselectedB = 0;
    double NselectedUDSG = 0;
    for(int i= 1; i!= nbin; i++ ){  
      if(  i*1./100. > Cut1 ) {
	NselectedB  = NselectedB +  hnBjets2->GetBinContent(i); 
	NselectedUDSG = NselectedUDSG +  hnLGjets2->GetBinContent(i); 
      }
      
    }
    x2[k] = NselectedB/NTotB2;
    yudsg2[k] = NselectedUDSG/NTotUDSG2;
    ex2[k]=TMath::Sqrt(NselectedB*(1-NselectedB/NTotB2))/NTotB2;
    eyudsg2[k]=TMath::Sqrt(NselectedUDSG*(1-NselectedUDSG/NTotUDSG2))/NTotUDSG2;
  }
  
  
  
  TGraphErrors *gr2 = new TGraphErrors(100,x2,yudsg2,ex2,eyudsg2);
  gr2->SetLineColor(1);
  gr2->SetMarkerColor(2);
  gr2->SetMarkerStyle(22);
  gr2->SetMarkerSize(0.9);
  gr2->Draw("psame");
  
  
  TLegend* leg = new TLegend(0.60,0.15,0.85,0.40);

  leg->AddEntry(gr1, "Impact Parameter significance","P");
  leg->AddEntry(gr2, "Decay length significance ","P");
  leg->Draw();
  
}

