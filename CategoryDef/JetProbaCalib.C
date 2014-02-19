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



//-----------------------------------------------------Find the category of a given track----------------------------------------------------------------------------------------//
int JetProbaCalib::IsInCategory(float trkEta, float trkHTrk, float trkHPix, float trkp, float trkChi2, std::vector<CategoryDef >  d){
  
  int isIn=-1;
  
  
  for(unsigned int i=0; i<d.size(); i++){
   if (fabs(trkEta)>d[i].etaMin&&fabs(trkEta)<d[i].etaMax&&trkHTrk<=d[i].nHitsMax&&trkHTrk>=d[i].nHitsMin&&
     trkHPix<=d[i].nPixelHitsMax&&trkHPix>=d[i].nPixelHitsMin&&trkp<d[i].pMax&&trkp>d[i].pMin&&
     trkChi2>=d[i].chiMin&&trkChi2<=d[i].chiMax) isIn=i;
  }
  
  return isIn;
  
}


//-----------------------------------------------------Return true if track passes btag selection ---------------------------------------------------------------------------------//
bool JetProbaCalib::passTrackSel(int trk, int pix, float ip2d, float pt, float len, float chi2, float zip, float dist, float eta, float etaJet, float phi, float phiJet, float ptJet)
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


  
 
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//--------------------------------------------------FIRST LOOP TO FILL CATEGORIES------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

void JetProbaCalib::Loop()
{
  double ptmax=10;
  
  TFile* myfile = new TFile("CalibrationFiles/calibeHistoWrite_std.root", "recreate");
  myfile->cd();
  
  if (fChain == 0) return;
  
  Long64_t nentries = fChain->GetEntriesFast();
  
  Long64_t nbytes = 0, nb = 0;
  
  //----------------------------------
  //Setup categories
  //----------------------------------
  CategoriesDefinition catDef;
  std::vector<CategoryDef >  vectCategories =  catDef.CategoryList();
  
  
  
  
  //-------------------------------------// EVENT LOOP //---------------------------------------------------------------------------------------------//
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0 ) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    // if (Cut(ientry) < 0) continue;
    
    if(jentry%10000 == 0) std::cout << "the processed event number is " << jentry << " over " << nentries << endl;
   
    //if(jentry>=1000000) break; 
    
    
    for (int ijet=0; ijet<nJet ; ijet++){
      
      if (fabs(Jet_eta[ijet]) > 2.5 || Jet_pt[ijet]<10 ) continue;
      for( int itrack=Jet_nFirstTrack[ijet]; itrack< Jet_nLastTrack[ijet]; itrack++){
        
        bool passSelection=passTrackSel(Track_nHitAll[itrack],Track_nHitPixel[itrack],Track_dxy[itrack],Track_pt[itrack],Track_length[itrack],Track_chi2[itrack],Track_dz[itrack],Track_dist[itrack],Track_eta[itrack],Jet_eta[ijet],Track_phi[itrack],Jet_phi[ijet],Jet_pt[ijet]);		
        
	if(Track_IP[itrack]>0 || !passSelection) continue;

        		
        int catnumb = -1;   
        catnumb = IsInCategory(Track_eta[itrack],Track_nHitAll[itrack] ,Track_nHitPixel[itrack] ,Track_p[itrack] ,
	Track_chi2[itrack], vectCategories);
        
        
        if(catnumb >= 0) vectCategories[catnumb].histo->Fill(-1*Track_IPsig[itrack]) ;
	else{
	  //cout << "no category found for this track " << endl;
	  //cout << "Track_p[itrack]          " << Track_p[itrack] << endl;
	  //cout << "Track_eta[itrack]        " << Track_eta[itrack] << endl;
	  //cout << "Track_nHitAll[itrack]    " << Track_nHitAll[itrack] << endl;
	  //cout << "Track_nHitPixel[itrack]  " << Track_nHitPixel[itrack] << endl;
	  //cout << "Track_chi2[itrack]       " << Track_chi2[itrack] << endl;
	}
	
        
      } //end loop on tracks
    } //end lopp on jets
  }//end lopp on events
  

	
	  
   //Store histograms into DB format

    
  
  //store histograms into root format
  CategoryDefCollection  catDefVector;
  for(int i=0; i< vectCategories.size(); i++){
    (catDefVector.ListOfCategory).push_back((vectCategories[i]));
  }   
  
  CategoryDefCollection * pcatDefVector = & catDefVector;
  //histoVector             ClassvectHisto;
  //ClassvectHisto.ListOfHisto = vectHisto;
  
  //ClassvectHisto.Write();
  pcatDefVector->Write();
  
  for(int i=0; i< vectCategories.size(); i++){
    ((*pcatDefVector).ListOfCategory)[i].histo->Write();
  }   




    
  
}



