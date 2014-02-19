#define HighPtStudy_cxx
#include "HighPtStudy.h"

#include <TH2.h>
#include <TH3.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TH1.h>
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
#include "TLorentzVector.h"





#include "TMVA/Tools.h"
#include "TMVA/Reader.h"
#include "TMVA/MethodCuts.h"




int e1 = int(1e+1);
int e2 = int(1e+2);
int e3 = int(1e+3);
int e4 = int(1e+4);
int e5 = int(1e+5);
int e6 = int(1e+6);
int e7 = int(1e+7);
int e8 = int(1e+8);

bool doDeltaRScan  = false;
bool doTrackPtScan = false;


bool doProbaTracks   = true;


bool doDeltaRcut   = true;
bool doBDTcut      = true;


int theIPsign = 1;

void HighPtStudy::Loop(const char*fileInPutName)
{
  
  
    
  cout << "initialize category files " << endl;
  TFile* myinputfile = new TFile(fileInPutName );
  CategoryDefCollection * pcatDefVector = (CategoryDefCollection*) myinputfile->Get("CategoryDefCollection");
  
  cout << "category files initialized" << endl;
  if(pcatDefVector == 0) cout << "null pointer " << endl;
  std::vector<CategoryDef > catDefList = pcatDefVector->ListOfCategory;

  for(unsigned int i=0; i<catDefList.size(); i++){
    catDefList[i].GetDistribFromFile(myinputfile );
  }

  
  TFile* myfile = new TFile("study_histo.root", "recreate");
  myfile->cd();
  
  float trackPt;    
  float DeltaRJet ; 
  float NPixHit  ;  
  float InvMtrtr ; 
  float PtRel;
  float NormChi2;
  float dxy;
  float dz;
  float length;
  float dist;
  float nHitStrip;
  float trackProba;

  
  float Weight;
  
  TTree * theouttree_btracks = new TTree("thetree_btracks", "tree for BDT btracks");
  
  theouttree_btracks->Branch("trackPt",   &trackPt ,   "trackPt/F");
  theouttree_btracks->Branch("DeltaRJet", &DeltaRJet , "DeltaRJet/F");
  theouttree_btracks->Branch("NPixHit",   &NPixHit ,   "NPixHit/F");
  theouttree_btracks->Branch("InvMtrtr",  &InvMtrtr ,  "InvMtrtr/F");
  theouttree_btracks->Branch("PtRel",     &PtRel ,     "PtRel/F");
  theouttree_btracks->Branch("NormChi2",  &NormChi2 ,  "NormChi2/F");
  theouttree_btracks->Branch("dxy",       &dxy ,       "dxy/F");
  theouttree_btracks->Branch("dz",        &dz ,        "dz/F");
  theouttree_btracks->Branch("length",    &length ,    "length/F");
  theouttree_btracks->Branch("dist",      &dist ,      "dist/F");
  theouttree_btracks->Branch("nHitStrip", &nHitStrip , "nHitStrip/F");
  //theouttree_btracks->Branch("trackProba", &trackProba , "trackProba/F");
  theouttree_btracks->Branch("Weight",    &Weight ,    "Weight/F");
  


  TTree * theouttree_nonbtracks = new TTree("thetree_nonbtracks", "tree for BDT btracks");
  
  theouttree_nonbtracks->Branch("trackPt",   &trackPt ,   "trackPt/F");
  theouttree_nonbtracks->Branch("DeltaRJet", &DeltaRJet , "DeltaRJet/F");
  theouttree_nonbtracks->Branch("NPixHit",   &NPixHit ,   "NPixHit/F");
  theouttree_nonbtracks->Branch("InvMtrtr",  &InvMtrtr ,  "InvMtrtr/F");
  theouttree_nonbtracks->Branch("PtRel",     &PtRel ,     "PtRel/F");
  theouttree_nonbtracks->Branch("NormChi2",  &NormChi2 ,  "NormChi2/F");
  theouttree_nonbtracks->Branch("dxy",       &dxy ,       "dxy/F");
  theouttree_nonbtracks->Branch("dz",        &dz ,        "dz/F");
  theouttree_nonbtracks->Branch("length",    &length ,    "length/F");
  theouttree_nonbtracks->Branch("dist",      &dist ,      "dist/F");
  theouttree_nonbtracks->Branch("nHitStrip", &nHitStrip , "nHitStrip/F");
  //theouttree_nonbtracks->Branch("trackProba", &trackProba , "trackProba/F");
  theouttree_nonbtracks->Branch("Weight",    &Weight ,    "Weight/F");
  
  
  //*****************
  //initiate TMVA
  //*****************
  // This loads the library
  
  /*
  cout << "initiate TMVA " << endl;
  TMVA::Tools::Instance();
  cout << "create reader" << endl;
  //create the BDT reader
  TMVA::Reader *reader = new TMVA::Reader( "!Color:!Silent" );
  	 
  
  cout << "add variables" << endl;
  reader->AddVariable("trackPt",   &trackPt);
  reader->AddVariable("DeltaRJet", &DeltaRJet);
  reader->AddVariable("NPixHit",   &NPixHit);
  reader->AddVariable("InvMtrtr",  &InvMtrtr);
  reader->AddVariable("PtRel",     &PtRel);
  reader->AddVariable("NormChi2",  &NormChi2);
  reader->AddVariable("dxy",       &dxy);
  reader->AddVariable("dz",        &dz);
  reader->AddVariable("length",    &length);
  reader->AddVariable("dist",      &dist);
  reader->AddVariable("nHitStrip", &nHitStrip);
  reader->AddVariable("trackProba", &trackProba);
  cout << "variables added" << endl;
  
  cout << "setup training" << endl;
  
  reader->BookMVA( "BDT", "weights/BDT_trainning_b_vs_nobtracks_BDT.weights.xml" ); 
  
  */
  std::vector<double > vectProba;
  std::vector<int > vectProba_idx;
  std::vector<int > vectTrack_type;
 
  
  //************************************
  //for performance curves, efficiencies
  //************************************
  
  TH1F * JetProba_bjets = new TH1F("JetProba_bjets", "JetProba_bjets", 500, 0, 5);
  TH1F * JetProba_cjets = new TH1F("JetProba_cjets", "JetProba_cjets", 500, 0, 5);
  TH1F * JetProba_ljets = new TH1F("JetProba_ljets", "JetProba_ljets", 500, 0, 5);
  
  TH1F * JetProbaNew_bjets = new TH1F("JetProbaNew_bjets", "JetProbaNew_bjets", 500, 0, 5);
  TH1F * JetProbaNew_cjets = new TH1F("JetProbaNew_cjets", "JetProbaNew_cjets", 500, 0, 5);
  TH1F * JetProbaNew_ljets = new TH1F("JetProbaNew_ljets", "JetProbaNew_ljets", 500, 0, 5);
  
  TH1F * JetProbaNew2_bjets = new TH1F("JetProbaNew2_bjets", "JetProbaNew2_bjets", 500, 0, 5);
  TH1F * JetProbaNew2_cjets = new TH1F("JetProbaNew2_cjets", "JetProbaNew2_cjets", 500, 0, 5);
  TH1F * JetProbaNew2_ljets = new TH1F("JetProbaNew2_ljets", "JetProbaNew2_ljets", 500, 0, 5);
  
  //TH1F * BDToutput_btracks_bjets    = new TH1F("BDToutput_btracks_bjets", "BDToutput_btracks_bjets", 100, -1, 1);
  //TH1F * BDToutput_nonbtracks_bjets = new TH1F("BDToutputnonbtracks_bjets", "BDToutputnonbtracks_bjets", 100, -1, 1);
  //TH1F * BDToutput_cjets = new TH1F("BDToutput_cjets", "BDToutput_cjets", 100, -1, 1);
  //TH1F * BDToutput_ljets = new TH1F("BDToutput_ljets", "BDToutput_ljets", 100, -1, 1);
  
  //************************************************
  //for performance curves, efficiencies vs jet pT
  //************************************************
  
  TH2F * jetPt_vs_JetProba_bjets = new TH2F("jetPt_vs_JetProba_bjets", "jetPt_vs_JetProba_bjets", 100, 0, 1000, 500, 0, 5);
  TH2F * jetPt_vs_JetProba_cjets = new TH2F("jetPt_vs_JetProba_cjets", "jetPt_vs_JetProba_cjets", 100, 0, 1000, 500, 0, 5);
  TH2F * jetPt_vs_JetProba_ljets = new TH2F("jetPt_vs_JetProba_ljets", "jetPt_vs_JetProba_ljets", 100, 0, 1000, 500, 0, 5);
  
  TH2F * jetPt_vs_JetProbaNew_bjets = new TH2F("jetPt_vs_JetProbaNew_bjets", "jetPt_vs_JetProbaNew_bjets", 100, 0, 1000, 500, 0, 5);
  TH2F * jetPt_vs_JetProbaNew_cjets = new TH2F("jetPt_vs_JetProbaNew_cjets", "jetPt_vs_JetProbaNew_cjets", 100, 0, 1000, 500, 0, 5);
  TH2F * jetPt_vs_JetProbaNew_ljets = new TH2F("jetPt_vs_JetProbaNew_ljets", "jetPt_vs_JetProbaNew_ljets", 100, 0, 1000, 500, 0, 5);
   
  TH2F * jetPt_vs_JetProbaNew2_bjets = new TH2F("jetPt_vs_JetProbaNew2_bjets", "jetPt_vs_JetProbaNew2_bjets", 100, 0, 1000, 500, 0, 5);
  TH2F * jetPt_vs_JetProbaNew2_cjets = new TH2F("jetPt_vs_JetProbaNew2_cjets", "jetPt_vs_JetProbaNew2_cjets", 100, 0, 1000, 500, 0, 5);
  TH2F * jetPt_vs_JetProbaNew2_ljets = new TH2F("jetPt_vs_JetProbaNew2_ljets", "jetPt_vs_JetProbaNew2_ljets", 100, 0, 1000, 500, 0, 5);
  
  
  //************************************************
  //2D plots for b-tracks vs non-btracks in bjets
  //************************************************
  
  TH2F * jetPt_vs_trackProba_btracks_noGS_bjets    = new TH2F("jetPt_vs_trackProba_btracks_noGS_bjets",    "jetPt_vs_trackProba_btracks_noGS_bjets", 100, 0, 1000, 500, 0, 5);
  TH2F * jetPt_vs_trackProba_nonbtracks_noGS_bjets = new TH2F("jetPt_vs_trackProba_nonbtracks_noGS_bjets", "jetPt_vs_trackProba_nonbtracks_noGS_bjets", 100, 0, 1000, 500, 0, 5);  
  
  TH2F * jetPt_vs_trackPt_btracks_noGS_bjets      = new TH2F("jetPt_vs_trackPt_btracks_noGS_bjets",      "jetPt_vs_trackPt_btracks_noGS_bjets",      100, 0, 1000, 100, 0, 500);
  TH2F * jetPt_vs_trackPt_nonbtracks_noGS_bjets   = new TH2F("jetPt_vs_trackPt_nonbtracks_noGS_bjets",   "jetPt_vs_trackPt_nonbtracks_noGS_bjets",   100, 0, 1000, 100, 0, 500);
  
  TH2F * jetPt_vs_DeltaRJet_btracks_noGS_bjets    = new TH2F("jetPt_vs_DeltaRJet_btracks_noGS_bjets",    "jetPt_vs_DeltaRJet_btracks_noGS_bjets",    100, 0, 1000, 100, 0, 0.3);
  TH2F * jetPt_vs_DeltaRJet_nonbtracks_noGS_bjets = new TH2F("jetPt_vs_DeltaRJet_nonbtracks_noGS_bjets", "jetPt_vs_DeltaRJet_nonbtracks_noGS_bjets", 100, 0, 1000, 100, 0, 0.3);
  
  TH2F * jetPt_vs_NPixHit_btracks_noGS_bjets      = new TH2F("jetPt_vs_NPixHit_btracks_noGS_bjets",      "jetPt_vs_NPixHit_btracks_noGS_bjets",      100, 0, 1000, 10, 0, 10);
  TH2F * jetPt_vs_NPixHit_nonbtracks_noGS_bjets   = new TH2F("jetPt_vs_NPixHit_nonbtracks_noGS_bjets",   "jetPt_vs_NPixHit_nonbtracks_noGS_bjets",   100, 0, 1000, 10, 0, 10);
  
  TH2F * jetPt_vs_InvMtrtr_btracks_noGS_bjets     = new TH2F("jetPt_vs_InvMtrtr_btracks_noGS_bjets",     "jetPt_vs_InvMtrtr_btracks_noGS_bjets",     100, 0, 1000, 100, 0, 10);
  TH2F * jetPt_vs_InvMtrtr_nonbtracks_noGS_bjets  = new TH2F("jetPt_vs_InvMtrtr_nonbtracks_noGS_bjets",  "jetPt_vs_InvMtrtr_nonbtracks_noGS_bjets",  100, 0, 1000, 100, 0, 10);
  
  TH2F * jetPt_vs_PtRel_btracks_noGS_bjets        = new TH2F("jetPt_vs_PtRel_btracks_noGS_bjets",        "jetPt_vs_PtRel_btracks_noGS_bjets",        100, 0, 1000, 100, 0, 25);
  TH2F * jetPt_vs_PtRel_nonbtracks_noGS_bjets     = new TH2F("jetPt_vs_PtRel_nonbtracks_noGS_bjets",     "jetPt_vs_PtRel_nonbtracks_noGS_bjets",     100, 0, 1000, 100, 0, 25);
  
  TH2F * jetPt_vs_NormChi2_btracks_noGS_bjets     = new TH2F("jetPt_vs_NormChi2_btracks_noGS_bjets",     "jetPt_vs_NormChi2_btracks_noGS_bjets",     100, 0, 1000, 100, 0, 5);
  TH2F * jetPt_vs_NormChi2_nonbtracks_noGS_bjets  = new TH2F("jetPt_vs_NormChi2_nonbtracks_noGS_bjets",  "jetPt_vs_NormChi2_nonbtracks_noGS_bjets",  100, 0, 1000, 100, 0, 5);
  
  TH2F * jetPt_vs_dxy_btracks_noGS_bjets          = new TH2F("jetPt_vs_dxy_btracks_noGS_bjets",          "jetPt_vs_dxy_btracks_noGS_bjets",     100, 0, 1000, 100, -0.2, 0.2);
  TH2F * jetPt_vs_dxy_nonbtracks_noGS_bjets       = new TH2F("jetPt_vs_dxy_nonbtracks_noGS_bjets",       "jetPt_vs_dxy_nonbtracks_noGS_bjets",  100, 0, 1000, 100, -0.2, 0.2);
  
  TH2F * jetPt_vs_dz_btracks_noGS_bjets           = new TH2F("jetPt_vs_dz_btracks_noGS_bjets",           "jetPt_vs_dz_btracks_noGS_bjets",     100, 0, 1000, 100, -0.5, 0.5);
  TH2F * jetPt_vs_dz_nonbtracks_noGS_bjets        = new TH2F("jetPt_vs_dz_nonbtracks_noGS_bjets",        "jetPt_vs_dz_nonbtracks_noGS_bjets",  100, 0, 1000, 100, -0.5, 0.5);
  
  TH2F * jetPt_vs_length_btracks_noGS_bjets       = new TH2F("jetPt_vs_length_btracks_noGS_bjets",       "jetPt_vs_length_btracks_noGS_bjets",     100, 0, 1000, 100, 0, 5);
  TH2F * jetPt_vs_length_nonbtracks_noGS_bjets    = new TH2F("jetPt_vs_length_nonbtracks_noGS_bjets",    "jetPt_vs_length_nonbtracks_noGS_bjets",  100, 0, 1000, 100, 0, 5);
  
  TH2F * jetPt_vs_dist_btracks_noGS_bjets         = new TH2F("jetPt_vs_dist_btracks_noGS_bjets",         "jetPt_vs_dist_btracks_noGS_bjets",     100, 0, 1000, 100, -0.07, 0.);
  TH2F * jetPt_vs_dist_nonbtracks_noGS_bjets      = new TH2F("jetPt_vs_dist_nonbtracks_noGS_bjets",      "jetPt_vs_dist_nonbtracks_noGS_bjets",  100, 0, 1000, 100, -0.07, 0.);

  TH2F * jetPt_vs_nHitStrip_btracks_noGS_bjets    = new TH2F("jetPt_vs_nHitStrip_btracks_noGS_bjets",	 "jetPt_vs_nHitStrip_btracks_noGS_bjets",     100, 0, 1000, 20, 0, 20);
  TH2F * jetPt_vs_nHitStrip_nonbtracks_noGS_bjets = new TH2F("jetPt_vs_nHitStrip_nonbtracks_noGS_bjets", "jetPt_vs_nHitStrip_nonbtracks_noGS_bjets",  100, 0, 1000, 20, 0, 20);


  TH2F * jetPt_vs_IPsign_btracks_noGS_bjets	 = new TH2F("jetPt_vs_IPsign_btracks_noGS_bjets",    "jetPt_vs_IPsign_btracks_noGS_bjets",     100, 0, 1000, 100, 0, 20);
  TH2F * jetPt_vs_IPsign_nonbtracks_noGS_bjets   = new TH2F("jetPt_vs_IPsign_nonbtracks_noGS_bjets", "jetPt_vs_IPsign_nonbtracks_noGS_bjets",  100, 0, 1000, 100, 0, 20);

  
  //************************************************
  //for performance as function of deltaR and jet pT
  //************************************************
  
  TH3F * jetPt_vs_DeltaR_vs_JetProba_bjets = new TH3F("jetPt_vs_DeltaR_vs_JetProba_bjets", "jetPt_vs_DeltaR_vs_JetProba_bjets", 100, 0, 1000, 100, 0.0, 0.3, 100, 0, 5 );
  TH3F * jetPt_vs_DeltaR_vs_JetProba_ljets = new TH3F("jetPt_vs_DeltaR_vs_JetProba_ljets", "jetPt_vs_DeltaR_vs_JetProba_ljets", 100, 0, 1000, 100, 0.0, 0.3, 100, 0, 5 );
  
  
  
  //************************************************
  //for performance as function of track pT and jet pT
  //************************************************
  
  TH3F * jetPt_vs_TrackPt_vs_JetProba_bjets = new TH3F("jetPt_vs_TrackPt_vs_JetProba_bjets", "jetPt_vs_TrackPt_vs_JetProba_bjets", 100, 0, 1000, 100, 0.0, 0.3, 100, 0, 500 );
  TH3F * jetPt_vs_TrackPt_vs_JetProba_ljets = new TH3F("jetPt_vs_TrackPt_vs_JetProba_ljets", "jetPt_vs_TrackPt_vs_JetProba_ljets", 100, 0, 1000, 100, 0.0, 0.3, 100, 0, 500 );
  
  //************************************
  //IPsign vs various distributions
  //************************************
  
  TH2F * IPsign_vs_trackPt_btracks_noGS_bjets       = new TH2F("IPsign_vs_trackPt_btracks_noGS_bjets",      "IPsign_vs_trackPt_btracks_noGS_bjets",      200, -50, 50, 500, 0, 500 );
  TH2F * IPsign_vs_trackPt_nonbtracks_noGS_bjets    = new TH2F("IPsign_vs_trackPt_nonbtracks_noGS_bjets",   "IPsign_vs_trackPt_nonbtracks_noGS_bjets",   200, -50, 50, 500, 0, 500 );
  TH2F * IPsign_vs_trackPt_ltracks_ljets            = new TH2F("IPsign_vs_trackPt_ltracks_ljets",           "IPsign_vs_trackPt_ltracks_ljets",           200, -50, 50, 500, 0, 500 ); 
  
  TH2F * IPsign_vs_trackP_btracks_noGS_bjets        = new TH2F("IPsign_vs_trackP_btracks_noGS_bjets",       "IPsign_vs_trackP_btracks_noGS_bjets",      200, -50, 50, 500, 0, 500 );
  TH2F * IPsign_vs_trackP_nonbtracks_noGS_bjets     = new TH2F("IPsign_vs_trackP_nonbtracks_noGS_bjets",    "IPsign_vs_trackP_nonbtracks_noGS_bjets",   200, -50, 50, 500, 0, 500 );
  TH2F * IPsign_vs_trackP_ltracks_ljets             = new TH2F("IPsign_vs_trackP_ltracks_ljets",            "IPsign_vs_trackP_ltracks_ljets",           200, -50, 50, 500, 0, 500 );
  
  TH2F * IPsign_vs_DeltaRJet_btracks_noGS_bjets     = new TH2F("IPsign_vs_DeltaRJet_btracks_noGS_bjets",    "IPsign_vs_DeltaRJet_btracks_noGS_bjets",    200, -50, 50,  100, 0, 0.3);
  TH2F * IPsign_vs_DeltaRJet_nonbtracks_noGS_bjets  = new TH2F("IPsign_vs_DeltaRJet_nonbtracks_noGS_bjets", "IPsign_vs_DeltaRJet_nonbtracks_noGS_bjets", 200, -50, 50,  100, 0, 0.3);
  TH2F * IPsign_vs_DeltaRJet_ltracks_ljets          = new TH2F("IPsign_vs_DeltaRJet_ltracks_ljets",         "IPsign_vs_DeltaRJet_ltracks_ljets",         200, -50, 50,  100, 0, 0.3);

  TH2F * IPsign_vs_NPixHit_btracks_noGS_bjets       = new TH2F("IPsign_vs_NPixHit_btracks_noGS_bjets",      "IPsign_vs_NPixHit_btracks_noGS_bjets",      200, -50, 50,  10, 0, 10);
  TH2F * IPsign_vs_NPixHit_nonbtracks_noGS_bjets    = new TH2F("IPsign_vs_NPixHit_nonbtracks_noGS_bjets",   "IPsign_vs_NPixHit_nonbtracks_noGS_bjets",   200, -50, 50,  10, 0, 10);
  TH2F * IPsign_vs_NPixHit_ltracks_ljets            = new TH2F("IPsign_vs_NPixHit_ltracks_ljets",           "IPsign_vs_NPixHit_ltracks_ljets",           200, -50, 50,  10, 0, 10);

  TH2F * IPsign_vs_InvMtrtr_btracks_noGS_bjets      = new TH2F("IPsign_vs_InvMtrtr_btracks_noGS_bjets",     "IPsign_vs_InvMtrtr_btracks_noGS_bjets",     200, -50, 50,  100, 0, 10);
  TH2F * IPsign_vs_InvMtrtr_nonbtracks_noGS_bjets   = new TH2F("IPsign_vs_InvMtrtr_nonbtracks_noGS_bjets",  "IPsign_vs_InvMtrtr_nonbtracks_noGS_bjets",  200, -50, 50,  100, 0, 10);
  TH2F * IPsign_vs_InvMtrtr_ltracks_ljets           = new TH2F("IPsign_vs_InvMtrtr_ltracks_ljets",          "IPsign_vs_InvMtrtr_ltracks_ljets",          200, -50, 50,  100, 0, 10);

  TH2F * IPsign_vs_PtRel_btracks_noGS_bjets         = new TH2F("IPsign_vs_PtRel_btracks_noGS_bjets",        "IPsign_vs_PtRel_btracks_noGS_bjets",        200, -50, 50,  100, 0, 25);
  TH2F * IPsign_vs_PtRel_nonbtracks_noGS_bjets      = new TH2F("IPsign_vs_PtRel_nonbtracks_noGS_bjets",     "IPsign_vs_PtRel_nonbtracks_noGS_bjets",     200, -50, 50,  100, 0, 25);
  TH2F * IPsign_vs_PtRel_ltracks_ljets              = new TH2F("IPsign_vs_PtRel_ltracks_ljets",             "IPsign_vs_PtRel_ltracks_ljets",             200, -50, 50,  100, 0, 25);

  TH2F * IPsign_vs_NormChi2_btracks_noGS_bjets      = new TH2F("IPsign_vs_NormChi2_btracks_noGS_bjets",     "IPsign_vs_NormChi2_btracks_noGS_bjets",     200, -50, 50,  100, 0, 5);
  TH2F * IPsign_vs_NormChi2_nonbtracks_noGS_bjets   = new TH2F("IPsign_vs_NormChi2_nonbtracks_noGS_bjets",  "IPsign_vs_NormChi2_nonbtracks_noGS_bjets",  200, -50, 50,  100, 0, 5);
  TH2F * IPsign_vs_NormChi2_ltracks_ljets           = new TH2F("IPsign_vs_NormChi2_ltracks_ljets",          "IPsign_vs_NormChi2_ltracks_ljets",          200, -50, 50,  100, 0, 5);

  TH2F * IPsign_vs_dxy_btracks_noGS_bjets           = new TH2F("IPsign_vs_dxy_btracks_noGS_bjets",          "IPsign_vs_dxy_btracks_noGS_bjets",          200, -50, 50,  100,-0.2, 0.2);
  TH2F * IPsign_vs_dxy_nonbtracks_noGS_bjets        = new TH2F("IPsign_vs_dxy_nonbtracks_noGS_bjets",       "IPsign_vs_dxy_nonbtracks_noGS_bjets",       200, -50, 50,  100,-0.2, 0.2);
  TH2F * IPsign_vs_dxy_ltracks_ljets                = new TH2F("IPsign_vs_dxy_ltracks_ljets",               "IPsign_vs_dxy_ltracks_ljets",               200, -50, 50,  100,-0.2, 0.2);

  TH2F * IPsign_vs_dz_btracks_noGS_bjets            = new TH2F("IPsign_vs_dz_btracks_noGS_bjets",           "IPsign_vs_dz_btracks_noGS_bjets",           200, -50, 50,  100,-0.5, 0.5);
  TH2F * IPsign_vs_dz_nonbtracks_noGS_bjets         = new TH2F("IPsign_vs_dz_nonbtracks_noGS_bjets",        "IPsign_vs_dz_nonbtracks_noGS_bjets",        200, -50, 50,  100,-0.5, 0.5);
  TH2F * IPsign_vs_dz_ltracks_ljets                 = new TH2F("IPsign_vs_dz_ltracks_ljets",                "IPsign_vs_dz_ltracks_ljets",                200, -50, 50,  100,-0.5, 0.5);

  TH2F * IPsign_vs_length_btracks_noGS_bjets        = new TH2F("IPsign_vs_length_btracks_noGS_bjets",       "IPsign_vs_length_btracks_noGS_bjets",       200, -50, 50,  100, 0, 5);
  TH2F * IPsign_vs_length_nonbtracks_noGS_bjets     = new TH2F("IPsign_vs_length_nonbtracks_noGS_bjets",    "IPsign_vs_length_nonbtracks_noGS_bjets",    200, -50, 50,  100, 0, 5);
  TH2F * IPsign_vs_length_ltracks_ljets             = new TH2F("IPsign_vs_length_ltracks_ljets",            "IPsign_vs_length_ltracks_ljets",            200, -50, 50,  100, 0, 5);

  TH2F * IPsign_vs_dist_btracks_noGS_bjets          = new TH2F("IPsign_vs_dist_btracks_noGS_bjets",         "IPsign_vs_dist_btracks_noGS_bjets",         200, -50, 50,  100, -0.07, 0.);
  TH2F * IPsign_vs_dist_nonbtracks_noGS_bjets       = new TH2F("IPsign_vs_dist_nonbtracks_noGS_bjets",      "IPsign_vs_dist_nonbtracks_noGS_bjets",      200, -50, 50,  100, -0.07, 0.);
  TH2F * IPsign_vs_dist_ltracks_ljets               = new TH2F("IPsign_vs_dist_ltracks_ljets",              "IPsign_vs_dist_ltracks_ljets",              200, -50, 50,  100, -0.07, 0.);

  TH2F * IPsign_vs_nHitStrip_btracks_noGS_bjets     = new TH2F("IPsign_vs_nHitStrip_btracks_noGS_bjets",    "IPsign_vs_nHitStrip_btracks_noGS_bjets",    200, -50, 50,  20, 0, 20);
  TH2F * IPsign_vs_nHitStrip_nonbtracks_noGS_bjets  = new TH2F("IPsign_vs_nHitStrip_nonbtracks_noGS_bjets", "IPsign_vs_nHitStrip_nonbtracks_noGS_bjets", 200, -50, 50,  20, 0, 20);
  TH2F * IPsign_vs_nHitStrip_ltracks_ljets          = new TH2F("IPsign_vs_nHitStrip_ltracks_ljets",         "IPsign_vs_nHitStrip_ltracks_ljets",         200, -50, 50,  20, 0, 20);

  
  
  //************************************
  //IPsign for NPixHit == 1
  //************************************
  TH1F * IPsign_NPixHit1_bjets = new TH1F("IPsign_NPixHit1_bjets", "IPsign_NPixHit1_bjets", 100, 0, 20);
  TH1F * IPsign_NPixHit1_cjets = new TH1F("IPsign_NPixHit1_cjets", "IPsign_NPixHit1_cjets", 100, 0, 20);
  TH1F * IPsign_NPixHit1_ljets = new TH1F("IPsign_NPixHit1_ljets", "IPsign_NPixHit1_ljets", 100, 0, 20);
  
  TH1F * IPsign_NPixHit0_bjets = new TH1F("IPsign_NPixHit0_bjets", "IPsign_NPixHit0_bjets", 100, 0, 20);
  TH1F * IPsign_NPixHit0_cjets = new TH1F("IPsign_NPixHit0_cjets", "IPsign_NPixHit0_cjets", 100, 0, 20);
  TH1F * IPsign_NPixHit0_ljets = new TH1F("IPsign_NPixHit0_ljets", "IPsign_NPixHit0_ljets", 100, 0, 20);
 
  
  TH2F * IPsign_vs_Chi2_NPixHit1_bjets = new TH2F("IPsign_vs_Chi2_NPixHit1_bjets", "IPsign_vs_Chi2_NPixHit1_bjets", 10, 0, 20, 10, 0, 5);
  TH2F * IPsign_vs_Chi2_NPixHit1_cjets = new TH2F("IPsign_vs_Chi2_NPixHit1_cjets", "IPsign_vs_Chi2_NPixHit1_cjets", 10, 0, 20, 10, 0, 5);
  TH2F * IPsign_vs_Chi2_NPixHit1_ljets = new TH2F("IPsign_vs_Chi2_NPixHit1_ljets", "IPsign_vs_Chi2_NPixHit1_ljets", 10, 0, 20, 10, 0, 5);
  
  TH2F * IPsign_vs_Chi2_NPixHit0_bjets = new TH2F("IPsign_vs_Chi2_NPixHit0_bjets", "IPsign_vs_Chi2_NPixHit0_bjets", 10, 0, 20, 10, 0, 5);
  TH2F * IPsign_vs_Chi2_NPixHit0_cjets = new TH2F("IPsign_vs_Chi2_NPixHit0_cjets", "IPsign_vs_Chi2_NPixHit0_cjets", 10, 0, 20, 10, 0, 5);
  TH2F * IPsign_vs_Chi2_NPixHit0_ljets = new TH2F("IPsign_vs_Chi2_NPixHit0_ljets", "IPsign_vs_Chi2_NPixHit0_ljets", 10, 0, 20, 10, 0, 5);
  
  TH2F * IPsign_vs_NStrip_NPixHit0_bjets = new TH2F("IPsign_vs_NStrip_NPixHit0_bjets", "IPsign_vs_NStrip_NPixHit0_bjets", 10, 0, 20, 50, 0, 50);
  TH2F * IPsign_vs_NStrip_NPixHit0_cjets = new TH2F("IPsign_vs_NStrip_NPixHit0_cjets", "IPsign_vs_NStrip_NPixHit0_cjets", 10, 0, 20, 50, 0, 50);
  TH2F * IPsign_vs_NStrip_NPixHit0_ljets = new TH2F("IPsign_vs_NStrip_NPixHit0_ljets", "IPsign_vs_NStrip_NPixHit0_ljets", 10, 0, 20, 50, 0, 50);
  
  TH2F * IPsign_vs_NStrip_NPixHit1_bjets = new TH2F("IPsign_vs_NStrip_NPixHit1_bjets", "IPsign_vs_NStrip_NPixHit1_bjets", 10, 0, 20, 50, 0, 50);
  TH2F * IPsign_vs_NStrip_NPixHit1_cjets = new TH2F("IPsign_vs_NStrip_NPixHit1_cjets", "IPsign_vs_NStrip_NPixHit1_cjets", 10, 0, 20, 50, 0, 50);
  TH2F * IPsign_vs_NStrip_NPixHit1_ljets = new TH2F("IPsign_vs_NStrip_NPixHit1_ljets", "IPsign_vs_NStrip_NPixHit1_ljets", 10, 0, 20, 50, 0, 50);
  
  
  TH2F * IPsign_vs_p_NPixHit0_bjets = new TH2F("IPsign_vs_p_NPixHit0_bjets", "IPsign_vs_p_NPixHit0_bjets", 10, 0, 20, 50, 0, 500);
  TH2F * IPsign_vs_p_NPixHit0_cjets = new TH2F("IPsign_vs_p_NPixHit0_cjets", "IPsign_vs_p_NPixHit0_cjets", 10, 0, 20, 50, 0, 500);
  TH2F * IPsign_vs_p_NPixHit0_ljets = new TH2F("IPsign_vs_p_NPixHit0_ljets", "IPsign_vs_p_NPixHit0_ljets", 10, 0, 20, 50, 0, 500);
  
  TH2F * IPsign_vs_p_NPixHit1_bjets = new TH2F("IPsign_vs_p_NPixHit1_bjets", "IPsign_vs_p_NPixHit1_bjets", 10, 0, 20, 50, 0, 500);
  TH2F * IPsign_vs_p_NPixHit1_cjets = new TH2F("IPsign_vs_p_NPixHit1_cjets", "IPsign_vs_p_NPixHit1_cjets", 10, 0, 20, 50, 0, 500);
  TH2F * IPsign_vs_p_NPixHit1_ljets = new TH2F("IPsign_vs_p_NPixHit1_ljets", "IPsign_vs_p_NPixHit1_ljets", 10, 0, 20, 50, 0, 500);
  
  TH2F * IPsign_vs_eta_NPixHit0_bjets = new TH2F("IPsign_vs_eta_NPixHit0_bjets", "IPsign_vs_eta_NPixHit0_bjets", 10, 0, 20, 10, 0, 2.5);
  TH2F * IPsign_vs_eta_NPixHit0_cjets = new TH2F("IPsign_vs_eta_NPixHit0_cjets", "IPsign_vs_eta_NPixHit0_cjets", 10, 0, 20, 10, 0, 2.5);
  TH2F * IPsign_vs_eta_NPixHit0_ljets = new TH2F("IPsign_vs_eta_NPixHit0_ljets", "IPsign_vs_eta_NPixHit0_ljets", 10, 0, 20, 10, 0, 2.5);
  
  TH2F * IPsign_vs_eta_NPixHit1_bjets = new TH2F("IPsign_vs_eta_NPixHit1_bjets", "IPsign_vs_eta_NPixHit1_bjets", 10, 0, 20, 10, 0, 2.5);
  TH2F * IPsign_vs_eta_NPixHit1_cjets = new TH2F("IPsign_vs_eta_NPixHit1_cjets", "IPsign_vs_eta_NPixHit1_cjets", 10, 0, 20, 10, 0, 2.5);
  TH2F * IPsign_vs_eta_NPixHit1_ljets = new TH2F("IPsign_vs_eta_NPixHit1_ljets", "IPsign_vs_eta_NPixHit1_ljets", 10, 0, 20, 10, 0, 2.5);
  
   
  
  
  TH1F * hdeltaROpt = new TH1F("hdeltaROpt", "hdeltaROpt", 100, 0, 0.4);
  
  
  
  
  
  
  
  
  int n30=0;
  int n50=0;
  int n80=0;
  int n120=0;
  int n170=0;
  int n300=0;
  int n470=0;
  int n600=0;
  int n800=0;  
  
  for(int i=0; i<100; i++){
    DeltaRTrackJetCut(1000*i/100., 0.01);
  }
  
  
  
  if (fChain == 0) return;
  
  Long64_t nentries = fChain->GetEntriesFast();
  
  float deltaRex=100.0;
  
  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0 ||jentry>100000000 ) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    // if (Cut(ientry) < 0) continue;
    
    if(jentry%10000 == 0) std::cout << "the processed event number is " << jentry << " over " << nentries << endl;
    
    
    //if(jentry == 10) break;
    
    if (30<pthat && pthat<50)   n30++;
    if (50<pthat && pthat<80)   n50++;
    if (80<pthat && pthat<120)  n80++;
    if (120<pthat && pthat<170) n120++;  
    if (170<pthat && pthat<300) n170++; 
    if (300<pthat && pthat<470) n300++;
    if (470<pthat && pthat<600) n470++;
    if (600<pthat && pthat<800) n600++;   
    if (800<pthat && pthat<1000)n800++;
    
    
    vectProba.clear();
    vectProba_idx.clear();
    vectTrack_type.clear();
    
    
    for (int ijet=0; ijet<nJet ; ijet++){
      
      if (Jet_pt[ijet]<200 || fabs(Jet_eta[ijet]) > 1.6) continue;
      //if (Jet_pt[ijet]<20 || fabs(Jet_eta[ijet]) > 1.6) continue;
      //cout << jentry << endl;
      //if(fabs(Jet_flavour[ijet]) != 5) continue; 
      TLorentzVector jet;
      jet.SetPtEtaPhiM(Jet_pt[ijet], Jet_eta[ijet], Jet_phi[ijet], 0 );
      //---------------------------------
      //test if b from gluon splitting
      //---------------------------------
      bool isGluonSplit=false;
      float dR=99999;
      if ( fabs(Jet_flavour[ijet]) == 5 ) {
       TLorentzVector  bquark;
       //jet.SetPtEtaPhiM(Jet_pt[ijet], Jet_eta[ijet], Jet_phi[ijet], 0 );
       
       
       //**********************************
       //Determine if it is Gluon Splitting
       //**********************************
       
       
       for (int k = 0; k < nbQuarks-1; k++) {
          if ( bQuark_status[k] != 2 ) continue;
	        bquark.SetPtEtaPhiM(bQuark_pT[k], bQuark_eta[k], bQuark_phi[k], 0);
                //dR = DeltaR( Jet_eta[ijet], Jet_phi[ijet], bQuark_eta[k], bQuark_phi[k] );
		dR = jet.DeltaR(bquark);
                if ( dR > 0.5 ) continue;
          for (int l = k+1; l < nbQuarks; l++) {
            if ( bQuark_status[l] != 2 ) continue;
            if ( bQuark_pdgID[k] * bQuark_pdgID[l] > 0 ) continue;
	    bquark.SetPtEtaPhiM(bQuark_pT[l], bQuark_eta[l], bQuark_phi[l], 0);
            //dR = DeltaR( Jet_eta[ijet], Jet_phi[ijet], bQuark_eta[l], bQuark_phi[l] );
	    dR =  jet.DeltaR(bquark);
            if ( dR < 0.5 ) isGluonSplit = true;
          }
        }
      }
      
      
      
      
      
      
      if(fabs(Jet_flavour[ijet]) == 5 && !isGluonSplit){
        JetProba_bjets->Fill(Jet_Proba[ijet]);
        jetPt_vs_JetProba_bjets->Fill(Jet_pt[ijet], Jet_Proba[ijet]);
	 
      }
      if(fabs(Jet_flavour[ijet]) == 4  ){
        JetProba_cjets->Fill(Jet_Proba[ijet]);
        jetPt_vs_JetProba_cjets->Fill(Jet_pt[ijet], Jet_Proba[ijet]);
      }
      
      if(fabs(Jet_flavour[ijet]) < 4 || fabs(Jet_flavour[ijet])  == 21  ) {
        JetProba_ljets->Fill(Jet_Proba[ijet]);
        jetPt_vs_JetProba_ljets->Fill(Jet_pt[ijet], Jet_Proba[ijet]);
      }
 
      
      //****************************
      //loop on DeltaR opening angle
      //****************************
      
      if(doDeltaRScan){
        for(int ideltaR=0; ideltaR<100; ideltaR++){
          double thedeltaRscan = ideltaR*0.3/100.;
	
	  std::vector<double > proba_tmp;
	  //loop on tracks  
          for( int jtrack=Jet_nFirstTrack[ijet]; jtrack< Jet_nLastTrack[ijet]; jtrack++){
	    TLorentzVector thetrack;
	    thetrack.SetPtEtaPhiM(Track_pt[jtrack], Track_eta[jtrack], Track_phi[jtrack], 0);
	    
	 
	    if(jet.DeltaR(thetrack) < thedeltaRscan){ 
	      proba_tmp.push_back(Track_Proba[jtrack]);
	    }
	  }//end loop on tracks
	  double jetP_tmp = 0;
	  if(proba_tmp.size() !=0) jetP_tmp = jetProbability( proba_tmp, theIPsign);
	 if(fabs(Jet_flavour[ijet]) == 5 && !isGluonSplit) jetPt_vs_DeltaR_vs_JetProba_bjets->Fill(Jet_pt[ijet], thedeltaRscan, jetP_tmp);
	  if(fabs(Jet_flavour[ijet]) <  4|| fabs(Jet_flavour[ijet])  == 21) jetPt_vs_DeltaR_vs_JetProba_ljets->Fill(Jet_pt[ijet], thedeltaRscan, jetP_tmp);	
        }
      }
      //
      
      
      
      //****************************
      //loop on trackPt opening angle
      //****************************
      
      
      if(doTrackPtScan){
        for(int itrackPt=0; itrackPt<100; itrackPt++){
          double thetrackPtscan = itrackPt*500/100.;
	
	  std::vector<double > proba_tmp;
	  //loop on tracks  
          for( int jtrack=Jet_nFirstTrack[ijet]; jtrack< Jet_nLastTrack[ijet]; jtrack++){
	 
	    if( Track_pt[jtrack] > thetrackPtscan){ 
	      proba_tmp.push_back(Track_Proba[jtrack]);
	    }
	  }//end loop on tracks
	  double jetP_tmp = 0;

	  if(proba_tmp.size() !=0) jetP_tmp = jetProbability( proba_tmp, theIPsign);
	  if(fabs(Jet_flavour[ijet]) == 5 && !isGluonSplit)                 jetPt_vs_TrackPt_vs_JetProba_bjets->Fill(Jet_pt[ijet], thetrackPtscan, jetP_tmp);
	  if(fabs(Jet_flavour[ijet]) <  4|| fabs(Jet_flavour[ijet])  == 21) jetPt_vs_TrackPt_vs_JetProba_ljets->Fill(Jet_pt[ijet], thetrackPtscan, jetP_tmp);
	}
      }
      
      

      //****************************
      //calculate probabilities with optimized deltaR
      //****************************
      
      std::vector<double > proba_tmp_TrackProba;
      
      
      if(doDeltaRcut){
        //double deltaROpt = 0.3;//optimizedDeltaR(Jet_pt[ijet]);hdeltaROpt->Fill(deltaROpt);
        for( int jtrack=Jet_nFirstTrack[ijet]; jtrack< Jet_nLastTrack[ijet]; jtrack++){
        
	
	  bool isSelectedTracks = passTrackSel(Track_nHitAll[jtrack],Track_nHitPixel[jtrack],Track_dxy[jtrack],Track_pt[jtrack],Track_length[jtrack],Track_chi2[jtrack],Track_dz[jtrack],Track_dist[jtrack],Track_eta[jtrack],Jet_eta[ijet],Track_phi[jtrack],Jet_phi[ijet],Jet_pt[ijet]);
	
        
	  if(!isSelectedTracks) continue;
	
	  TLorentzVector thetrack;
          thetrack.SetPtEtaPhiM(Track_pt[jtrack], Track_eta[jtrack], Track_phi[jtrack], 0);
	  
	  
        
          if(jet.DeltaR(thetrack) < 0.3){ 
            proba_tmp_TrackProba.push_back(Track_Proba[jtrack]);
          }
        }
      }
      
      std::vector<double > proba_tmp_TrackProbaNew;
      
      if(doProbaTracks ){
        for( int itrack=Jet_nFirstTrack[ijet]; itrack< Jet_nLastTrack[ijet]; itrack++){	
	
	 bool isSelectedTracks = passTrackSel(Track_nHitAll[itrack],Track_nHitPixel[itrack],Track_dxy[itrack],Track_pt[itrack],Track_length[itrack],Track_chi2[itrack],Track_dz[itrack],Track_dist[itrack],Track_eta[itrack],Jet_eta[ijet],Track_phi[itrack],Jet_phi[ijet],Jet_pt[ijet]);
    	 
	 //if(Track_Proba[itrack] > -100) cout <<  "before trackSel ********************"  << endl;
	 TLorentzVector track;
	 track.SetPtEtaPhiM(Track_pt[itrack], Track_eta[itrack], Track_phi[itrack], 0);
	 
	 if(!isSelectedTracks) continue;
	  
	  int catnum =-1;
	  
	  double proba=-1000;
	  catnum = IsInCategory(Track_eta[itrack],  Track_nHitAll[itrack] , Track_nHitPixel[itrack], Track_p[itrack] 
	  , Track_chi2[itrack], catDefList);

	   if(catnum >=0) {
	    proba= catDefList[catnum].calculTrackProba( Track_IPsig[itrack]); 	  
	    proba_tmp_TrackProbaNew.push_back(proba);
	    //cout << "recalculated proba " << proba << endl;
	    //cout << "Track_Proba[itrack] " << Track_Proba[itrack] << endl;
	    //if(Track_Proba[itrack] > -1000) cout <<  "********************"  << endl;
	    //if( track.DeltaR(jet) > 0.3) cout << "deltaR jet track " << track.DeltaR(jet) << endl;;
	    //cout << "track proba " << proba << endl;	
	   }else{
	    //cout << "no category found for this track " <<  endl;
	    //cout << "Track_p[itrack]		  " << Track_p[itrack]    << endl;
	    //cout << "Track_pt[itrack]	          " << Track_pt[itrack]    << endl;
	    //cout << "Track_eta[itrack]  	  " << Track_eta[itrack]  << endl;
	    //cout << "Track_chi2[itrack] 	  " << Track_chi2[itrack] << endl;
	    //cout << "Track_nHitPixel[itrack]	  " << Track_nHitPixel[itrack]<< endl;
	    //cout << "Track_nHitAll[itrack]	  " << Track_nHitAll[itrack]  << endl;	 
	  }
	  
	}
      }
      
      
      double jetP_tmp_TrackProbaNew = 0;
      double jetP_tmp_TrackProba = 0;
      
      if(proba_tmp_TrackProba.size() !=0)               jetP_tmp_TrackProba    = jetProbability( proba_tmp_TrackProba, theIPsign );
      if(proba_tmp_TrackProbaNew.size() !=0) jetP_tmp_TrackProbaNew = jetProbability( proba_tmp_TrackProbaNew, theIPsign );
      
      //cout << "     new jet proba TrackProba    " << jetP_tmp_TrackProba    << endl;
      //cout << "     new jet proba TrackProbaNew " << jetP_tmp_TrackProbaNew << endl;
      //cout << "     old jet proba               " << Jet_Proba[ijet]        << endl;
      
      
      double jetP_tmp = jetP_tmp_TrackProba;
      if(doProbaTracks) jetP_tmp = jetP_tmp_TrackProbaNew;
      
      if(fabs(Jet_flavour[ijet]) == 5 && !isGluonSplit){
        JetProbaNew_bjets->Fill( jetP_tmp);
        jetPt_vs_JetProbaNew_bjets->Fill(Jet_pt[ijet], jetP_tmp);
      }
      
      if(fabs(Jet_flavour[ijet]) == 4  ) {
        JetProbaNew_cjets->Fill(jetP_tmp);
        jetPt_vs_JetProbaNew_cjets->Fill(Jet_pt[ijet], jetP_tmp);
      }
      
      if(fabs(Jet_flavour[ijet]) < 4 || fabs(Jet_flavour[ijet])  == 21  ) {
        JetProbaNew_ljets->Fill(jetP_tmp);
        jetPt_vs_JetProbaNew_ljets->Fill(Jet_pt[ijet], jetP_tmp);
      }
      
      
      //cout << "Jet_pt[ijet] " << Jet_pt[ijet] << endl;
      //cout << "deltaROpt " << deltaROpt << endl;
      
      
      
      //************************************
      //loop on tracks to fill 2D histograms
      //************************************
      
      std::map<int, double > BDToutput;
      
      if( (abs(Jet_flavour[ijet]) == 5 || doBDTcut) && !isGluonSplit){
      for( int itrack=Jet_nFirstTrack[ijet]; itrack< Jet_nLastTrack[ijet]; itrack++){
         
 	
         //***********************
         //determine track history
         //***********************
 	 bool isSelectedTracks = passTrackSel(Track_nHitAll[itrack],Track_nHitPixel[itrack],Track_dxy[itrack],Track_pt[itrack],Track_length[itrack],Track_chi2[itrack],Track_dz[itrack],Track_dist[itrack],Track_eta[itrack],Jet_eta[ijet],Track_phi[itrack],Jet_phi[ijet],Jet_pt[ijet]);
	 if(!isSelectedTracks) continue;
	
  	 int cat = Track_history[itrack];
 	 //cout << "cat " << cat  << endl;
	 int catP = 0;
 	
         // Track History information
         if	   ( cat%e1 == 1		  || cat%e1 == 3)     catP = 1; // BWeakDecay
         else if ((cat%e2 >= e1 && cat%e2 < 2*e1) || cat%e2 >= 3*e1 ) catP = 2; // CWeakDecay
         else if ((cat%e3 >= e2 && cat%e3 < 2*e2) || cat%e3 >= 3*e2 ) catP = 3; // TauDecay
         else if ((cat%e4 >= e3 && cat%e4 < 2*e3) || cat%e4 >= 3*e3 ) catP = 4; // Conversion
         else if ((cat%e5 >= e4 && cat%e5 < 2*e4) || cat%e5 >= 3*e4 ) catP = 5; // KsDecay
         else if ((cat%e6 >= e5 && cat%e6 < 2*e5) || cat%e6 >= 3*e5 ) catP = 6; // LambdaDecay
         else if ((cat%e7 >= e6 && cat%e7 < 2*e6) || cat%e7 >= 3*e6 ) catP = 7; // Interaction
         else if ((cat%e8 >= e7 && cat%e8 < 2*e7) || cat%e8 >= 3*e7 ) catP = 8; // Fake
	 
	  
	 //compute deltaR(jet-track)
	 TLorentzVector thetrack;
	 thetrack.SetPtEtaPhiM(Track_pt[itrack], Track_eta[itrack], Track_phi[itrack], 0);
	 double deltaRJetTrack = jet.DeltaR(thetrack);
	 
	 
	 //compute invariate mass track-closest track
	 int idex_closesttrack  = -1;
	 double deltaR_closestTrack = 10000;
	 for( int jtrack=Jet_nFirstTrack[ijet]; jtrack< Jet_nLastTrack[ijet]; jtrack++){
	   if(itrack == jtrack) continue;
	   TLorentzVector theclosesttrack_tmp;
	   theclosesttrack_tmp.SetPtEtaPhiM(Track_pt[jtrack], Track_eta[jtrack], Track_phi[jtrack], 0);
	   double detlaR_tmp =  theclosesttrack_tmp.DeltaR(thetrack);
	   if(detlaR_tmp < deltaR_closestTrack){deltaR_closestTrack = detlaR_tmp;  idex_closesttrack=jtrack;}
	   
	 }
	 
	 TLorentzVector theclosesttrack;
	 theclosesttrack.SetPtEtaPhiM(Track_pt[idex_closesttrack], Track_eta[idex_closesttrack], Track_phi[idex_closesttrack], 0);
	 
	 double Minvtt = (theclosesttrack+thetrack).M();
	 
	 //compute pTrel
	 
	 double ptRel = calculPtRel( thetrack , jet);
	 trackPt   = -1;
         DeltaRJet = -1;
         NPixHit   = -1;
         InvMtrtr  = -1;
         PtRel     = -1;
         NormChi2  = -1;
   	 Weight = 1;

   	   
         if(Track_nHitPixel[itrack] == 1){
	   if(fabs(Jet_flavour[ijet]) == 5 && !isGluonSplit && catP == 1) {
	     IPsign_NPixHit1_bjets->Fill(Track_IPsig[itrack]);
	     IPsign_vs_Chi2_NPixHit1_bjets->Fill(Track_IPsig[itrack],   Track_chi2[itrack]);
	     IPsign_vs_NStrip_NPixHit1_bjets->Fill(Track_IPsig[itrack], Track_nHitAll[itrack] - Track_nHitPixel[itrack]);
	     IPsign_vs_p_NPixHit1_bjets->Fill(Track_IPsig[itrack],      Track_p[itrack]);
	     IPsign_vs_eta_NPixHit1_bjets->Fill(Track_IPsig[itrack],    fabs(Track_eta[itrack]));
	   }
	   if(fabs(Jet_flavour[ijet]) == 4 && catP == 2) {
	     IPsign_NPixHit1_cjets->Fill(Track_IPsig[itrack]);
	     IPsign_vs_Chi2_NPixHit1_cjets->Fill(Track_IPsig[itrack],   Track_chi2[itrack]);
	     IPsign_vs_NStrip_NPixHit1_cjets->Fill(Track_IPsig[itrack], Track_nHitAll[itrack] - Track_nHitPixel[itrack]);
	     IPsign_vs_p_NPixHit1_cjets->Fill(Track_IPsig[itrack],      Track_p[itrack]);  
	     IPsign_vs_eta_NPixHit1_cjets->Fill(Track_IPsig[itrack],    fabs(Track_eta[itrack]));    
	   }
	   if(fabs(Jet_flavour[ijet]) <  4		   ) {
	     IPsign_NPixHit1_ljets->Fill(Track_IPsig[itrack]);
	     IPsign_vs_Chi2_NPixHit1_ljets->Fill(Track_IPsig[itrack],   Track_chi2[itrack]);
	     IPsign_vs_NStrip_NPixHit1_ljets->Fill(Track_IPsig[itrack], Track_nHitAll[itrack] - Track_nHitPixel[itrack]);
	     IPsign_vs_p_NPixHit1_ljets->Fill(Track_IPsig[itrack],      Track_p[itrack]);    
	     IPsign_vs_eta_NPixHit1_ljets->Fill(Track_IPsig[itrack],    fabs(Track_eta[itrack]));	      
	   }
	 }
         if(Track_nHitPixel[itrack] == 0){
	   if(fabs(Jet_flavour[ijet]) == 5 && !isGluonSplit && catP == 1) {
	     IPsign_NPixHit0_bjets->Fill(Track_IPsig[itrack]);
	     IPsign_vs_Chi2_NPixHit0_bjets->Fill(Track_IPsig[itrack],   Track_chi2[itrack]);
	     IPsign_vs_NStrip_NPixHit0_bjets->Fill(Track_IPsig[itrack], Track_nHitAll[itrack] - Track_nHitPixel[itrack]);
	     IPsign_vs_p_NPixHit0_bjets->Fill(Track_IPsig[itrack],      Track_p[itrack]);  
	     IPsign_vs_eta_NPixHit0_bjets->Fill(Track_IPsig[itrack],    fabs(Track_eta[itrack]));     
	   }
	   if(fabs(Jet_flavour[ijet]) == 4 && catP == 2 ) {
	     IPsign_NPixHit0_cjets->Fill(Track_IPsig[itrack]);
	     IPsign_vs_Chi2_NPixHit0_cjets->Fill(Track_IPsig[itrack],   Track_chi2[itrack]);
	     IPsign_vs_NStrip_NPixHit0_cjets->Fill(Track_IPsig[itrack], Track_nHitAll[itrack] - Track_nHitPixel[itrack]);
	     IPsign_vs_p_NPixHit0_cjets->Fill(Track_IPsig[itrack],      Track_p[itrack]);  
	     IPsign_vs_eta_NPixHit0_cjets->Fill(Track_IPsig[itrack],    fabs(Track_eta[itrack]));     
	   }
	   if(fabs(Jet_flavour[ijet]) <  4		   ) {
	     IPsign_NPixHit0_ljets->Fill(Track_IPsig[itrack]);
	     IPsign_vs_Chi2_NPixHit0_ljets->Fill(Track_IPsig[itrack],   Track_chi2[itrack]);
	     IPsign_vs_NStrip_NPixHit0_ljets->Fill(Track_IPsig[itrack], Track_nHitAll[itrack] - Track_nHitPixel[itrack]);
	     IPsign_vs_p_NPixHit0_ljets->Fill(Track_IPsig[itrack],      Track_p[itrack]);  
	     IPsign_vs_eta_NPixHit0_ljets->Fill(Track_IPsig[itrack],    fabs(Track_eta[itrack]));     
	   }
	 }
	 
	 
	 
         if(catP == 1) { 
	   
	   
	   jetPt_vs_trackProba_btracks_noGS_bjets->Fill(     Jet_pt[ijet], Track_Proba[itrack]); 
           jetPt_vs_trackPt_btracks_noGS_bjets->Fill(        Jet_pt[ijet], Track_pt[itrack]);	 
           jetPt_vs_DeltaRJet_btracks_noGS_bjets->Fill(      Jet_pt[ijet], deltaRJetTrack); 
           jetPt_vs_NPixHit_btracks_noGS_bjets->Fill(        Jet_pt[ijet], Track_nHitPixel[itrack]);
           jetPt_vs_InvMtrtr_btracks_noGS_bjets->Fill(       Jet_pt[ijet], Minvtt); 
           jetPt_vs_PtRel_btracks_noGS_bjets->Fill(          Jet_pt[ijet], ptRel);
           jetPt_vs_NormChi2_btracks_noGS_bjets->Fill(       Jet_pt[ijet], Track_chi2[itrack]); 
           jetPt_vs_dxy_btracks_noGS_bjets->Fill(            Jet_pt[ijet], Track_dxy[itrack]);	  	  
           jetPt_vs_dz_btracks_noGS_bjets ->Fill(            Jet_pt[ijet], Track_dz[itrack]);		  
           jetPt_vs_length_btracks_noGS_bjets->Fill(         Jet_pt[ijet], Track_length[itrack]);	   
           jetPt_vs_dist_btracks_noGS_bjets->Fill(           Jet_pt[ijet], Track_dist[itrack]);		 
           jetPt_vs_nHitStrip_btracks_noGS_bjets ->Fill(     Jet_pt[ijet], Track_nHitStrip[itrack]);
	   
	   
           IPsign_vs_trackPt_btracks_noGS_bjets->Fill(        Track_IPsig[itrack], Track_pt[itrack]);	 
           IPsign_vs_trackP_btracks_noGS_bjets->Fill(         Track_IPsig[itrack], Track_p[itrack]);	 
           IPsign_vs_DeltaRJet_btracks_noGS_bjets->Fill(      Track_IPsig[itrack], deltaRJetTrack); 
           IPsign_vs_NPixHit_btracks_noGS_bjets->Fill(        Track_IPsig[itrack], Track_nHitPixel[itrack]);
           IPsign_vs_InvMtrtr_btracks_noGS_bjets->Fill(       Track_IPsig[itrack], Minvtt); 
           IPsign_vs_PtRel_btracks_noGS_bjets->Fill(          Track_IPsig[itrack], ptRel);
           IPsign_vs_NormChi2_btracks_noGS_bjets->Fill(       Track_IPsig[itrack], Track_chi2[itrack]); 
           IPsign_vs_dxy_btracks_noGS_bjets->Fill(            Track_IPsig[itrack], Track_dxy[itrack]);	  	  
           IPsign_vs_dz_btracks_noGS_bjets ->Fill(            Track_IPsig[itrack], Track_dz[itrack]);		  
           IPsign_vs_length_btracks_noGS_bjets->Fill(         Track_IPsig[itrack], Track_length[itrack]);	   
           IPsign_vs_dist_btracks_noGS_bjets->Fill(           Track_IPsig[itrack], Track_dist[itrack]);		 
           IPsign_vs_nHitStrip_btracks_noGS_bjets ->Fill(     Track_IPsig[itrack], Track_nHitStrip[itrack]);
	   
	   	 
	   
	   //cout << "Track_dist[itrack] " << Track_dist[itrack] << endl;
           trackPt   = Track_pt[itrack];    
           DeltaRJet = deltaRJetTrack; 
           NPixHit   = Track_nHitPixel[itrack];  
           InvMtrtr  = Minvtt; 
           PtRel     = ptRel;
           NormChi2  = Track_chi2[itrack];
           dxy       = Track_dxy[itrack];
           dz        = Track_dz[itrack];
           length    = Track_length[itrack];
           dist      = Track_dist[itrack];
           nHitStrip = Track_nHitStrip[itrack];
	   trackProba= Track_Proba[itrack];
	   theouttree_btracks->Fill(); 
	   //BDToutput[itrack] = reader->EvaluateMVA( "BDT");
	   //BDToutput_btracks_bjets->Fill(BDToutput[itrack]);   
	 }
         else{
	   
	   
	   if(abs(Jet_flavour[ijet]) == 5){
	     jetPt_vs_trackProba_nonbtracks_noGS_bjets->Fill(  Jet_pt[ijet], Track_Proba[itrack]);
             jetPt_vs_trackPt_nonbtracks_noGS_bjets->Fill(     Jet_pt[ijet], Track_pt[itrack]);  
             jetPt_vs_DeltaRJet_nonbtracks_noGS_bjets->Fill(   Jet_pt[ijet], deltaRJetTrack);    
             jetPt_vs_NPixHit_nonbtracks_noGS_bjets ->Fill(    Jet_pt[ijet], Track_nHitPixel[itrack]);    
             jetPt_vs_InvMtrtr_nonbtracks_noGS_bjets->Fill(    Jet_pt[ijet], Minvtt);      
             jetPt_vs_PtRel_nonbtracks_noGS_bjets->Fill(       Jet_pt[ijet], ptRel);	     
             jetPt_vs_NormChi2_nonbtracks_noGS_bjets->Fill(    Jet_pt[ijet], Track_chi2[itrack]); 
             jetPt_vs_dxy_nonbtracks_noGS_bjets->Fill(         Jet_pt[ijet], Track_dxy[itrack]);	  	  
             jetPt_vs_dz_nonbtracks_noGS_bjets ->Fill(         Jet_pt[ijet], Track_dz[itrack]);		  
             jetPt_vs_length_nonbtracks_noGS_bjets->Fill(      Jet_pt[ijet], Track_length[itrack]);	   
             jetPt_vs_dist_nonbtracks_noGS_bjets->Fill(        Jet_pt[ijet], Track_dist[itrack]);		 
             jetPt_vs_nHitStrip_nonbtracks_noGS_bjets ->Fill(  Jet_pt[ijet], Track_nHitStrip[itrack]);	
	   
	   
             IPsign_vs_trackPt_nonbtracks_noGS_bjets->Fill(     Track_IPsig[itrack], Track_pt[itrack]);  
             IPsign_vs_trackP_nonbtracks_noGS_bjets->Fill(      Track_IPsig[itrack], Track_p[itrack]);  
             IPsign_vs_DeltaRJet_nonbtracks_noGS_bjets->Fill(   Track_IPsig[itrack], deltaRJetTrack);    
             IPsign_vs_NPixHit_nonbtracks_noGS_bjets ->Fill(    Track_IPsig[itrack], Track_nHitPixel[itrack]);    
             IPsign_vs_InvMtrtr_nonbtracks_noGS_bjets->Fill(    Track_IPsig[itrack], Minvtt);      
             IPsign_vs_PtRel_nonbtracks_noGS_bjets->Fill(       Track_IPsig[itrack], ptRel);	     
             IPsign_vs_NormChi2_nonbtracks_noGS_bjets->Fill(    Track_IPsig[itrack], Track_chi2[itrack]); 
             IPsign_vs_dxy_nonbtracks_noGS_bjets->Fill(         Track_IPsig[itrack], Track_dxy[itrack]);	  	  
             IPsign_vs_dz_nonbtracks_noGS_bjets ->Fill(         Track_IPsig[itrack], Track_dz[itrack]);		  
             IPsign_vs_length_nonbtracks_noGS_bjets->Fill(      Track_IPsig[itrack], Track_length[itrack]);	   
             IPsign_vs_dist_nonbtracks_noGS_bjets->Fill(        Track_IPsig[itrack], Track_dist[itrack]);		 
             IPsign_vs_nHitStrip_nonbtracks_noGS_bjets ->Fill(  Track_IPsig[itrack], Track_nHitStrip[itrack]);	
	     
	   }else{
	     
             IPsign_vs_trackPt_ltracks_ljets->Fill(     Track_IPsig[itrack], Track_pt[itrack]);  
             IPsign_vs_trackP_ltracks_ljets->Fill(      Track_IPsig[itrack], Track_p[itrack]);  
             IPsign_vs_DeltaRJet_ltracks_ljets->Fill(   Track_IPsig[itrack], deltaRJetTrack);    
             IPsign_vs_NPixHit_ltracks_ljets ->Fill(    Track_IPsig[itrack], Track_nHitPixel[itrack]);    
             IPsign_vs_InvMtrtr_ltracks_ljets->Fill(    Track_IPsig[itrack], Minvtt);      
             IPsign_vs_PtRel_ltracks_ljets->Fill(       Track_IPsig[itrack], ptRel);	     
             IPsign_vs_NormChi2_ltracks_ljets->Fill(    Track_IPsig[itrack], Track_chi2[itrack]); 
             IPsign_vs_dxy_ltracks_ljets->Fill(         Track_IPsig[itrack], Track_dxy[itrack]);	  	  
             IPsign_vs_dz_ltracks_ljets ->Fill(         Track_IPsig[itrack], Track_dz[itrack]);		  
             IPsign_vs_length_ltracks_ljets->Fill(      Track_IPsig[itrack], Track_length[itrack]);	   
             IPsign_vs_dist_ltracks_ljets->Fill(        Track_IPsig[itrack], Track_dist[itrack]);		 
             IPsign_vs_nHitStrip_ltracks_ljets ->Fill(  Track_IPsig[itrack], Track_nHitStrip[itrack]);	
	     
	   }
	   
	   
	   
	   
           trackPt   = Track_pt[itrack];    
           DeltaRJet = deltaRJetTrack; 
           NPixHit   = Track_nHitPixel[itrack];  
           InvMtrtr  = Minvtt; 
           PtRel     = ptRel;
           NormChi2  = Track_chi2[itrack];
           dxy       = Track_dxy[itrack];
           dz        = Track_dz[itrack];
           length    = Track_length[itrack];
           dist      = Track_dist[itrack];
           nHitStrip = Track_nHitStrip[itrack];
	   trackProba= Track_Proba[itrack];
   	   
	   //theouttree_nonbtracks->Fill(); 
	   //BDToutput[itrack] = reader->EvaluateMVA( "BDT");
           //if(abs(Jet_flavour[ijet]) == 5 ) BDToutput_nonbtracks_bjets->Fill(BDToutput[itrack]); 
           //if(abs(Jet_flavour[ijet]) == 4 ) BDToutput_cjets->Fill(BDToutput[itrack]); 
           //if(abs(Jet_flavour[ijet]) != 4  && abs(Jet_flavour[ijet]) != 5)BDToutput_ljets->Fill(BDToutput[itrack]); 
	 }
        } //end loops on tracks
	
	
	

      //****************************
      //calculate probabilities with optimized deltaR
      //****************************
      
      std::vector<double > proba_tmp2;
      /*if(doBDTcut){

        for( int jtrack=Jet_nFirstTrack[ijet]; jtrack< Jet_nLastTrack[ijet]; jtrack++){
	  bool isSelectedTracks = passTrackSel(Track_nHitAll[jtrack],Track_nHitPixel[jtrack],Track_IP2D[jtrack],Track_pt[jtrack],Track_length[jtrack],Track_chi2[jtrack],Track_dz[jtrack],Track_dist[jtrack],Track_eta[jtrack],Jet_eta[ijet],Track_phi[jtrack],Jet_phi[ijet],Jet_pt[ijet]);
	  if(!isSelectedTracks || BDToutput[jtrack] < 0.0) continue;
	  //if(!isSelectedTracks ) continue;
	  //double BDTproba = (BDToutput[jtrack]+1)/2;
	  
	  //double BDTproba = BDTcalib_ljets->Integral( BDToutput[jtrack], 1);
	  //BDTproba /=BDTcalib_ljets->Integral();
          proba_tmp2.push_back(Track_Proba[jtrack]);
        }
      }*/
        
      
      double jetP_tmp2 = 0;
      if(proba_tmp2.size() !=0) jetP_tmp2 = jetProbability( proba_tmp2 , theIPsign);
      
      if(fabs(Jet_flavour[ijet]) == 5 && !isGluonSplit){
        JetProbaNew2_bjets->Fill( jetP_tmp2);
        jetPt_vs_JetProbaNew2_bjets->Fill(Jet_pt[ijet], jetP_tmp2);
      }
      
      if(fabs(Jet_flavour[ijet]) == 4  ) {
        JetProbaNew2_cjets->Fill(jetP_tmp2);
        jetPt_vs_JetProbaNew2_cjets->Fill(Jet_pt[ijet], jetP_tmp2);
      }
      
      if(fabs(Jet_flavour[ijet]) < 4 || fabs(Jet_flavour[ijet])  == 21  ) {
        JetProbaNew2_ljets->Fill(jetP_tmp2);
        jetPt_vs_JetProbaNew2_ljets->Fill(Jet_pt[ijet], jetP_tmp2);
      }
      
      
	
	
	
	
	
      }
    } //end loop JETS  
  }//END LOOP EVENT
  
  //}//end event selection
  
  //DeltaRtrk_jetPt->Draw();
  myfile->Write(); 
  cout << "deltaRex: "<< deltaRex<< endl;
}


void HighPtStudy::run(){
  
  //   Loop(30,1);
  
}


//-----------------------------------------------------Find the category of a given track----------------------------------------------------------------------------------------//
int HighPtStudy::IsInCategory(float trkEta, float trkHTrk, float trkHPix, float trkp, float trkChi2, std::vector<CategoryDef > d){
  
  int isIn=-1;
  
  for(unsigned int i=0; i<d.size(); i++){
   if (fabs(trkEta)>d[i].etaMin&&fabs(trkEta)<d[i].etaMax&&trkHTrk<=d[i].nHitsMax&&trkHTrk>=d[i].nHitsMin&&
     trkHPix<=d[i].nPixelHitsMax&&trkHPix>=d[i].nPixelHitsMin&&trkp<d[i].pMax&&trkp>d[i].pMin&&
     trkChi2>=d[i].chiMin&&trkChi2<=d[i].chiMax) isIn=i;
  }
  
  
  
  return isIn;
  
}

//-----------------------------------------------------Return true if track passes btag selection ---------------------------------------------------------------------------------//
bool HighPtStudy::passTrackSel(int hittrk, int hitpix, float ip2d, float pt, float len, float chi2, float zip, float dist, float eta, float etaJet, float phi, float phiJet, float ptJet)
{

  TLorentzVector track4P, jet4P;
  track4P.SetPtEtaPhiM(pt, eta,phi , 0. );
  jet4P.SetPtEtaPhiM(ptJet ,etaJet ,phiJet , 0 );

  float deltaR = jet4P.DeltaR(track4P);
  bool passSel=false;
  
  bool passhitTrk  = false;
  bool passIP      = false;
  bool passhitPix  = false;
  bool passPt   = false;
  bool passLen  = false;
  bool passChi2 = false;
  bool passDist = false;
  bool passZip  = false;
  bool passDR   = false;
  
  
  
  

  //if ((trk+pix)>=8)   passTrk=true;
  if (pt>1.0)         passPt     = true;  // minimumTransverseMomentum = cms.double(1.0),
  if (hittrk>=8)      passhitTrk = true;  // minimumNumberOfHits = cms.int32(8),
  if (hitpix>=2)      passhitPix = true;  // minimumNumberOfPixelHits = cms.int32(2),
  if (chi2<5.0)       passChi2   = true;  // maximumChiSquared = cms.double(5.0),
  if (fabs(ip2d)<0.2) passIP     = true;  // maximumTransverseImpactParameter = cms.double(0.2),  
  if (fabs(zip)<17.0) passZip    = true;  // maximumLongitudinalImpactParameter = cms.double(17.0),
  
  
  if (fabs(dist)<0.07)passDist   = true;  // maximumDistanceToJetAxis = cms.double(0.07),
  if (len<5.0)        passLen    = true;  // maximumDecayLength = cms.double(5.0)
  if (deltaR<0.3)     passDR     = true;
  
   
   


  if (passhitTrk&&passIP&&passhitPix&&passPt&&passLen&&passChi2&&passDist&&passZip&&passDR)  passSel=true;
  
  return passSel;
  
}
  

bool HighPtStudy::DeltaRTrackJetCut(double jetpT, double deltaR){
  
  
  double deltaR_vs_jetpt = 0.3;
  /*
  if(jetpT < 100) deltaR_vs_jetpt = 0.3;
  else if(jetpT > 600) deltaR_vs_jetpt = 0.048;
  else{
    deltaR_vs_jetpt = 2.71649e-01 -1.48591e-03*jetpT + 3.25829e-06*jetpT*jetpT -2.35229e-09*jetpT*jetpT*jetpT ;
    
  }
  deltaR_vs_jetpt += deltaR_vs_jetpt;
  //cout << "deltaR  " << deltaR << endl;
  //cout << "deltaR_vs_jetpt " << deltaR_vs_jetpt << endl;
  //cout << "deltaR_vs_jetpt " << deltaR_vs_jetpt << endl;
  */
  if(deltaR < deltaR_vs_jetpt) return true;
  else return false;
  
  
}


bool HighPtStudy::TrackPtCut(double jetpT, double trackpt){
  
  jetpT;
  double trackpT_vs_jetpt = 10000;
  if(trackpt < trackpT_vs_jetpt) return true;
  else return false;
  
  
  
  
}



double HighPtStudy::jetProbability( std::vector<double>  v, int ipsign) 

{
  std::vector<double> probabilities;
  int i=0;

  for(std::vector<double>::const_iterator it = v.begin(); it!=v.end(); ++it, i++)
  {
               
     float p =0;
     if(ipsign ==0 ) { 
	    if (*it >=0){p=*it/2.;}else{p=1.+*it/2.;}
     } else if( ipsign> 0){
	     if(*it >=0 ) p=*it; else continue; 
     } else {
       if(*it <=0 ) p= -*it; else continue; 
     } 
      probabilities.push_back(p);

  } 
	 
 
  double m_minTrackProb= 0.005;
  int ngoodtracks=probabilities.size();
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



double HighPtStudy::optimizedDeltaR(double jetpT){

  double deltaR = 0.3;
  jetpT;
  //if(jetpT>20 && jetpT <130) deltaR = exp(-0.91-0.01*jetpT);
  //if(jetpT>130) deltaR = 0.122 - 1.96581e-04*jetpT+ 1.22916e-07*jetpT*jetpT;
  
  
  //if(jetpT > 200)deltaR = 0.25;
  //else deltaR = 0.3;
  
  return deltaR;

}







float HighPtStudy::calculPtRel(TLorentzVector theTrack, TLorentzVector theJet )
{
  double pmu = sqrt( theTrack.Px()*theTrack.Px() + theTrack.Py()*theTrack.Py()  + theTrack.Pz()*theTrack.Pz() );

  double jetPx = 0 ;
  double jetPy = 0 ;
  double jetPz = 0 ;

  jetPx = theJet.Px();
  jetPy = theJet.Py();
  jetPz = theJet.Pz();

  double jetp = sqrt(jetPx*jetPx + jetPy*jetPy + jetPz*jetPz);

  double ptrel  = ( jetPx * theTrack.Px()  + jetPy * theTrack.Py() + jetPz * theTrack.Pz() ) / jetp;
  ptrel = sqrt( pmu * pmu  - ptrel * ptrel );

  return ptrel;
}










