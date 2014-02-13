#define HighPtStudy_cxx
#include "HighPtStudy.h"

#include <TH2.h>
#include <TH3.h>
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


bool doProbaTracks   = false;
bool doNewTrackCalib = false;


bool doDeltaRcut   = false;
bool doBDTcut      = false;


void HighPtStudy::Loop(int cut, int type)
{
  

  
  
  TString next;
  if(type==1)           next="_pt";
  else if(type==0)      next="_DR";
  else                  next="_IPsig";
  TString str = ""; 
  str += cut;
  
  //TFile * filechannel = new TFile("study_histo.root"  );
  //TH1F * BDTcalib_ljets = (TH1F*)filechannel->Get( "BDToutput_ljets" );
 
  // Load track probabilities
  
  
  std::vector<CategoryDef> vecthistoCatDef=DefCategories();

  std::vector<TH1D*> vecthistoCatFile;
  if(doNewTrackCalib)  vecthistoCatFile=GetCategories("calibeHistoWrite_highPTJets.root");
  else                 vecthistoCatFile=GetCategories("calibeHistoWrite_highPTJets.root");
  
  
  
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
  
  
  std::vector<double > vectProba;
  std::vector<int > vectProba_idx;
  std::vector<int > vectTrack_type;
   
  int nbin_trkH=50;
  float xmin_trkH=0.0;
  float xmax_trkH=1.02;  
  TH1D * trackPCat0  = new TH1D("trackPCat0",  "trackPCat0",   nbin_trkH, xmin_trkH, xmax_trkH);
  TH1D * trackPCat1  = new TH1D("trackPCat1",  "trackPCat1",   nbin_trkH, xmin_trkH, xmax_trkH);
  TH1D * trackPCat2  = new TH1D("trackPCat2",  "trackPCat2",   nbin_trkH, xmin_trkH, xmax_trkH);
  TH1D * trackPCat3  = new TH1D("trackPCat3",  "trackPCat3",   nbin_trkH, xmin_trkH, xmax_trkH);
  TH1D * trackPCat4  = new TH1D("trackPCat4",  "trackPCat4",   nbin_trkH, xmin_trkH, xmax_trkH);
  TH1D * trackPCat5  = new TH1D("trackPCat5",  "trackPCat5",   nbin_trkH, xmin_trkH, xmax_trkH);
  TH1D * trackPCat51 = new TH1D("trackPCat51", "trackPCat51",  nbin_trkH, xmin_trkH, xmax_trkH);
  TH1D * trackPCat52 = new TH1D("trackPCat52", "trackPCat52",  nbin_trkH, xmin_trkH, xmax_trkH);
  TH1D * trackPCat53 = new TH1D("trackPCat53", "trackPCat53",  nbin_trkH, xmin_trkH, xmax_trkH);
  TH1D * trackPCat6  = new TH1D("trackPCat6",  "trackPCat6",   nbin_trkH, xmin_trkH, xmax_trkH);
  TH1D * trackPCat7  = new TH1D("trackPCat7",  "trackPCat7",   nbin_trkH, xmin_trkH, xmax_trkH);
  TH1D * trackPCat8  = new TH1D("trackPCat8",  "trackPCat8",   nbin_trkH, xmin_trkH, xmax_trkH);
  TH1D * trackPCat9  = new TH1D("trackPCat9",  "trackPCat9",     nbin_trkH, xmin_trkH, xmax_trkH);
  TH1D * trackPCat91  = new TH1D("trackPCat91",  "trackPCat91",     nbin_trkH, xmin_trkH, xmax_trkH);
  TH1D * trackPCat92  = new TH1D("trackPCat92",  "trackPCat92",     nbin_trkH, xmin_trkH, xmax_trkH);
  TH1D * trackPCat93  = new TH1D("trackPCat93",  "trackPCat93",     nbin_trkH, xmin_trkH, xmax_trkH);
  //TH1D * trackPCat_all = new TH1D("trackPCat_all", "trackPCat_all", nbin_trkH, xmin_trkH, xmax_trkH);
 
  
  TH1D * trackNegPCat_all = new TH1D("trackNegPCat_all", "trackNegPCat_all", nbin_trkH, xmin_trkH, xmax_trkH);
  std::vector<TH1D *> vectTrkProba; 
   
  vectTrkProba.push_back(trackPCat0);
  vectTrkProba.push_back(trackPCat1);
  vectTrkProba.push_back(trackPCat2);  
  vectTrkProba.push_back(trackPCat3);  
  vectTrkProba.push_back(trackPCat4); 
  if(!doNewTrackCalib){ 
    vectTrkProba.push_back(trackPCat5);
  }else{
    vectTrkProba.push_back(trackPCat51);
    vectTrkProba.push_back(trackPCat52);
    vectTrkProba.push_back(trackPCat53);
  }  
  vectTrkProba.push_back(trackPCat6);
  vectTrkProba.push_back(trackPCat7);  
  vectTrkProba.push_back(trackPCat8);
  if(!doNewTrackCalib){   
    vectTrkProba.push_back(trackPCat9); 
  }else{
    vectTrkProba.push_back(trackPCat91); 
    vectTrkProba.push_back(trackPCat92); 
    vectTrkProba.push_back(trackPCat93); 
  }
  //vectTrkProba.push_back(trackPCat_all);
  
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
  
  TH1F * BDToutput_btracks_bjets    = new TH1F("BDToutput_btracks_bjets", "BDToutput_btracks_bjets", 100, -1, 1);
  TH1F * BDToutput_nonbtracks_bjets = new TH1F("BDToutputnonbtracks_bjets", "BDToutputnonbtracks_bjets", 100, -1, 1);
  TH1F * BDToutput_cjets = new TH1F("BDToutput_cjets", "BDToutput_cjets", 100, -1, 1);
  TH1F * BDToutput_ljets = new TH1F("BDToutput_ljets", "BDToutput_ljets", 100, -1, 1);
  
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
    
    
    //if(jentry == 1000000) break;
    
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
      
      //if (Jet_pt[ijet]<200 || Jet_pt[ijet]> 300 || fabs(Jet_eta[ijet]) > 1.1) continue;
      if (Jet_pt[ijet]<20 || fabs(Jet_eta[ijet]) > 1.1) continue;
      
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
	  if(proba_tmp.size() !=0) jetP_tmp = jetProbability( proba_tmp);
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

	  if(proba_tmp.size() !=0) jetP_tmp = jetProbability( proba_tmp);
	  if(fabs(Jet_flavour[ijet]) == 5 && !isGluonSplit)                 jetPt_vs_TrackPt_vs_JetProba_bjets->Fill(Jet_pt[ijet], thetrackPtscan, jetP_tmp);
	  if(fabs(Jet_flavour[ijet]) <  4|| fabs(Jet_flavour[ijet])  == 21) jetPt_vs_TrackPt_vs_JetProba_ljets->Fill(Jet_pt[ijet], thetrackPtscan, jetP_tmp);
	}
      }
      
      

      //****************************
      //calculate probabilities with optimized deltaR
      //****************************
      
      std::vector<double > proba_tmp;
      if(doDeltaRcut && !doProbaTracks){
        double deltaROpt = optimizedDeltaR(Jet_pt[ijet]);hdeltaROpt->Fill(deltaROpt);
        for( int jtrack=Jet_nFirstTrack[ijet]; jtrack< Jet_nLastTrack[ijet]; jtrack++){
        
	
	  bool isSelectedTracks = passTrackSel(Track_nHitAll[jtrack],Track_nHitPixel[jtrack],Track_IP2D[jtrack],Track_pt[jtrack],Track_length[jtrack],Track_chi2[jtrack],Track_zIP[jtrack],Track_dist[jtrack],Track_eta[jtrack],Jet_eta[ijet],Track_phi[jtrack],Jet_phi[ijet],Jet_pt[ijet]);
	
        
	  if(!isSelectedTracks) continue;
	
	  TLorentzVector thetrack;
          thetrack.SetPtEtaPhiM(Track_pt[jtrack], Track_eta[jtrack], Track_phi[jtrack], 0);
          
        
          if(jet.DeltaR(thetrack) < deltaROpt){ 
            proba_tmp.push_back(Track_Proba[jtrack]);
          }
        }
      }
      if(doProbaTracks && !doDeltaRScan  && !doDeltaRcut){
        for( int itrack=Jet_nFirstTrack[ijet]; itrack< Jet_nLastTrack[ijet]; itrack++){	
	
	  bool isSelectedTracks = passTrackSel(Track_nHitAll[itrack],Track_nHitPixel[itrack],Track_IP2D[itrack],Track_pt[itrack],Track_length[itrack],Track_chi2[itrack],Track_zIP[itrack],Track_dist[itrack],Track_eta[itrack],Jet_eta[ijet],Track_phi[itrack],Jet_phi[ijet],Jet_pt[ijet]);
	  if(!isSelectedTracks) continue;
	
	  double proba=calculTrackProba(Track_p[itrack],Track_eta[itrack],Track_nHitAll[itrack],Track_nHitPixel[itrack],Track_chi2[itrack],Track_IPsig[itrack],vecthistoCatFile, vectTrkProba, vecthistoCatDef);	
	  proba_tmp.push_back(proba);
	}
      }
      
      
      double jetP_tmp = 0;
      if(proba_tmp.size() !=0) jetP_tmp = jetProbability( proba_tmp );
      
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
 	 bool isSelectedTracks = passTrackSel(Track_nHitAll[itrack],Track_nHitPixel[itrack],Track_IP2D[itrack],Track_pt[itrack],Track_length[itrack],Track_chi2[itrack],Track_zIP[itrack],Track_dist[itrack],Track_eta[itrack],Jet_eta[ijet],Track_phi[itrack],Jet_phi[ijet],Jet_pt[ijet]);
	 if(!isSelectedTracks) continue;
	
  	 int cat = Track_history[itrack];
 	 //cout << "cat " << cat  << endl;
	 int catP = 0;
 	
         // Track History information
         if	   ( cat%e1 == 1		 || cat%e1 == 3)     catP = 1; // BWeakDecay
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
	   BDToutput[itrack] = reader->EvaluateMVA( "BDT");
	   BDToutput_btracks_bjets->Fill(BDToutput[itrack]);   
	 }
         else{
	 
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
   	   
	   theouttree_nonbtracks->Fill(); 
	   BDToutput[itrack] = reader->EvaluateMVA( "BDT");
           if(abs(Jet_flavour[ijet]) == 5 ) BDToutput_nonbtracks_bjets->Fill(BDToutput[itrack]); 
           if(abs(Jet_flavour[ijet]) == 4 ) BDToutput_cjets->Fill(BDToutput[itrack]); 
           if(abs(Jet_flavour[ijet]) != 4  && abs(Jet_flavour[ijet]) != 5)BDToutput_ljets->Fill(BDToutput[itrack]); 
	 }
        } //end loops on tracks
	
	
	

      //****************************
      //calculate probabilities with optimized deltaR
      //****************************
      
      std::vector<double > proba_tmp2;
      if(doBDTcut){

        for( int jtrack=Jet_nFirstTrack[ijet]; jtrack< Jet_nLastTrack[ijet]; jtrack++){
	  bool isSelectedTracks = passTrackSel(Track_nHitAll[jtrack],Track_nHitPixel[jtrack],Track_IP2D[jtrack],Track_pt[jtrack],Track_length[jtrack],Track_chi2[jtrack],Track_zIP[jtrack],Track_dist[jtrack],Track_eta[jtrack],Jet_eta[ijet],Track_phi[jtrack],Jet_phi[ijet],Jet_pt[ijet]);
	  if(!isSelectedTracks || BDToutput[jtrack] < 0.0) continue;
	  //if(!isSelectedTracks ) continue;
	  //double BDTproba = (BDToutput[jtrack]+1)/2;
	  
	  //double BDTproba = BDTcalib_ljets->Integral( BDToutput[jtrack], 1);
	  //BDTproba /=BDTcalib_ljets->Integral();
          proba_tmp2.push_back(Track_Proba[jtrack]);
        }
      }
        
      
      double jetP_tmp2 = 0;
      if(proba_tmp2.size() !=0) jetP_tmp2 = jetProbability( proba_tmp2 );
      
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
  CategoryDef cat51;
  CategoryDef cat52;
  CategoryDef cat53;
  CategoryDef cat6;
  CategoryDef cat7;
  CategoryDef cat8;
  CategoryDef cat9;
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
  cat0.pMax          = 5000;
  cat0.pMin          = 0;
  cat0.chiMin        = 0;
  cat0.chiMax        = 5;
  cat0.withFirstPixelHit = 0;  
  cat0.histoCalib    = new TH1D("histoCat0"	  ,"histoCat0"	,nbins,xmin,xmax);
  
  
  //cat 1
  cat1.etaMax	     = 2.5;
  cat1.etaMin	     = 0;
  cat1.nHitsMax      = 50;
  cat1.nHitsMin      = 8;
  cat1.nPixelHitsMax = 8;
  cat1.nPixelHitsMin = 3;
  cat1.pMax	     = 5000;
  cat1.pMin	     = 0;
  cat1.chiMin	     = 2.5;
  cat1.chiMax	     = 5;
  cat1.withFirstPixelHit  = 0;
  cat1.histoCalib    = new TH1D("histoCat11"	 ,"histoCat11" ,nbins,xmin,xmax);  
  
    
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
  cat5.etaMax	     = 2.5;
  cat5.etaMin	     = 0;
  cat5.nHitsMax      = 50;
  cat5.nHitsMin      = 8;
  cat5.nPixelHitsMax = 2;
  cat5.nPixelHitsMin = 2;
  cat5.pMax	     = 8;
  cat5.pMin	     = 0;
  cat5.chiMin	     = 0;
  cat5.chiMax	     = 2.5;  
  cat5.withFirstPixelHit  = 0;
  cat5.histoCalib    = new TH1D("histoCat51"	 ,"histoCat51" ,nbins,xmin,xmax);



  //cat 5
  cat51.etaMax        = 0.8;
  cat51.etaMin        = 0;
  cat51.nHitsMax      = 50;
  cat51.nHitsMin      = 8;
  cat51.nPixelHitsMax = 2;
  cat51.nPixelHitsMin = 2;
  cat51.pMax          = 8;
  cat51.pMin          = 0;
  cat51.chiMin        = 0;
  cat51.chiMax        = 2.5;  
  cat51.withFirstPixelHit  = 0;
  cat51.histoCalib    = new TH1D("histoCat51"	  ,"histoCat51"	,nbins,xmin,xmax);


  //cat 5
  cat52.etaMax        = 1.6;
  cat52.etaMin        = 0.8;
  cat52.nHitsMax      = 50;
  cat52.nHitsMin      = 8;
  cat52.nPixelHitsMax = 2;
  cat52.nPixelHitsMin = 2;
  cat52.pMax          = 8;
  cat52.pMin          = 0;
  cat52.chiMin        = 0;
  cat52.chiMax        = 2.5;  
  cat52.withFirstPixelHit  = 0;
  cat52.histoCalib    = new TH1D("histoCat52"	  ,"histoCat52"	,nbins,xmin,xmax);


  //cat 5
  cat53.etaMax        = 2.6;
  cat53.etaMin        = 1.5;
  cat53.nHitsMax      = 50;
  cat53.nHitsMin      = 8;
  cat53.nPixelHitsMax = 2;
  cat53.nPixelHitsMin = 2;
  cat53.pMax          = 8;
  cat53.pMin          = 0;
  cat53.chiMin        = 0;
  cat53.chiMax        = 2.5;  
  cat53.withFirstPixelHit  = 0;
  cat53.histoCalib    = new TH1D("histoCat5"	  ,"histoCat5"	,nbins,xmin,xmax);



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
  cat9.etaMax	     = 2.5;
  cat9.etaMin	     = 0;
  cat9.nHitsMax      = 50;
  cat9.nHitsMin      = 8;
  cat9.nPixelHitsMax = 2;
  cat9.nPixelHitsMin = 2;
  cat9.pMax	     = 5000;
  cat9.pMin	     = 8;
  cat9.chiMin	     = 0;
  cat9.chiMax	     = 2.5;  
  cat9.withFirstPixelHit  = 0;
  cat9.histoCalib    = new TH1D("histoCat9"	 ,"histoCat9" ,nbins,xmin,xmax);

  //cat 9
  cat91.etaMax        = 0.8;
  cat91.etaMin        = 0;
  cat91.nHitsMax      = 50;
  cat91.nHitsMin      = 8;
  cat91.nPixelHitsMax = 2;
  cat91.nPixelHitsMin = 2;
  cat91.pMax          = 5000;
  cat91.pMin          = 8;
  cat91.chiMin        = 0;
  cat91.chiMax        = 2.5;  
  cat91.withFirstPixelHit  = 0;
  cat91.histoCalib    = new TH1D("histoCat91"	  ,"histoCat91"	,nbins,xmin,xmax);
  
  //cat 9
  cat92.etaMax        = 1.6;
  cat92.etaMin        = 0.8;
  cat92.nHitsMax      = 50;
  cat92.nHitsMin      = 8;
  cat92.nPixelHitsMax = 2;
  cat92.nPixelHitsMin = 2;
  cat92.pMax          = 5000;
  cat92.pMin          = 8;
  cat92.chiMin        = 0;
  cat92.chiMax        = 2.5;  
  cat92.withFirstPixelHit  = 0;
  cat92.histoCalib    = new TH1D("histoCat92"	  ,"histoCat92"	,nbins,xmin,xmax);
  
  
  
  //cat 9
  cat93.etaMax        = 2.5;
  cat93.etaMin        = 1.6;
  cat93.nHitsMax      = 50;
  cat93.nHitsMin      = 8;
  cat93.nPixelHitsMax = 2;
  cat93.nPixelHitsMin = 2;
  cat93.pMax          = 5000;
  cat93.pMin          = 8;
  cat93.chiMin        = 0;
  cat93.chiMax        = 2.5;  
  cat93.withFirstPixelHit  = 0;
  cat93.histoCalib    = new TH1D("histoCat93"	  ,"histoCat93"	,nbins,xmin,xmax);
  
  
  
  
  
  vectCat.push_back(cat0);
  vectCat.push_back(cat1);
  vectCat.push_back(cat2);
  vectCat.push_back(cat3);
  vectCat.push_back(cat4);
  if(!doNewTrackCalib){
    vectCat.push_back(cat5);
  }else{
    vectCat.push_back(cat51);
    vectCat.push_back(cat52);
    vectCat.push_back(cat53);
  }
  vectCat.push_back(cat6);
  vectCat.push_back(cat7);
  vectCat.push_back(cat8);
  if(!doNewTrackCalib){
    vectCat.push_back(cat9);
  }else{
    vectCat.push_back(cat91);
    vectCat.push_back(cat92);
    vectCat.push_back(cat93);
  }
 
   
  //number_of_category=vectCat.size();
  
  return vectCat; 
  
  
  
  
  
  
  
}


//-----------------------------------------------------Find the category of a given track----------------------------------------------------------------------------------------//
bool HighPtStudy::IsInCategory(float trkEta, float trkHTrk, float trkHPix, float trkp, float trkChi2, CategoryDef d){
  
  bool isIn=false;
  
  if (fabs(trkEta)>d.etaMin
      &&fabs(trkEta)<d.etaMax
      &&trkHTrk<=d.nHitsMax
      &&trkHTrk>=d.nHitsMin
      &&trkHPix<=d.nPixelHitsMax
      &&trkHPix>=d.nPixelHitsMin
      &&trkp<d.pMax
      &&trkp>d.pMin
      &&trkChi2>=d.chiMin
      &&trkChi2<=d.chiMax) isIn=true;
  
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
  //if (pix>=0)         passPix=true;
  if (pt>1.0)         passPt=true;
  if (len<5.0)        passLen=true;
  if (chi2<5.0)       passChi2=true;
  if (fabs(dist)<0.07)passDist=true;
  if (fabs(zip)<17.0) passZip=true;
  if (deltaR<0.3)     passDR=true;


  
  //if (passTrk&&passIP&&passPix&&passPt&&passLen&&passChi2&&passDist&&passZip&&passDR) {
  
    passSel=true;

  
  //}
  
  return passSel;
  
}
  

bool HighPtStudy::DeltaRTrackJetCut(double jetpT, double deltaR){
  
  
  double deltaR_vs_jetpt = 10000;
  
  if(jetpT < 100) deltaR_vs_jetpt = 0.3;
  else if(jetpT > 600) deltaR_vs_jetpt = 0.048;
  else{
    deltaR_vs_jetpt = 2.71649e-01 -1.48591e-03*jetpT + 3.25829e-06*jetpT*jetpT -2.35229e-09*jetpT*jetpT*jetpT ;
    
  }
  deltaR_vs_jetpt += deltaR_vs_jetpt;
  //cout << "deltaR  " << deltaR << endl;
  //cout << "deltaR_vs_jetpt " << deltaR_vs_jetpt << endl;
  //cout << "deltaR_vs_jetpt " << deltaR_vs_jetpt << endl;
  if(deltaR < deltaR_vs_jetpt) return true;
  else return false;
  
  
}


bool HighPtStudy::TrackPtCut(double jetpT, double trackpt){
  
  
  double trackpT_vs_jetpt = 10000;
  if(trackpt < trackpT_vs_jetpt) return true;
  else return false;
  
  
  
  
}

std::vector<TH1D* > HighPtStudy::GetCategories(const char* fileInPutName){
  
  
  TFile * myInputFile = new TFile(fileInPutName);
  myInputFile->cd();
  myInputFile->ls();
  std::vector<TH1D* >  vectH;
  vectH.clear();
  
  int imax = 10;
  if(doNewTrackCalib) imax = 14;
  
  for(int i = 0; i < imax; i++){
    
    TH1D* histo ;
    if(doNewTrackCalib){
      if(i == 0) histo= (TH1D*)gROOT->FindObject("histoCat0"); 
      if(i == 1) histo= (TH1D*)gROOT->FindObject("histoCat1"); 
      if(i == 2) histo= (TH1D*)gROOT->FindObject("histoCat2"); 
      if(i == 3) histo= (TH1D*)gROOT->FindObject("histoCat3"); 
      if(i == 4) histo= (TH1D*)gROOT->FindObject("histoCat4"); 
      if(i == 5) histo= (TH1D*)gROOT->FindObject("histoCat51"); 
      if(i == 6) histo= (TH1D*)gROOT->FindObject("histoCat52");
      if(i == 7) histo= (TH1D*)gROOT->FindObject("histoCat53");
      if(i == 8) histo= (TH1D*)gROOT->FindObject("histoCat6"); 
      if(i == 9) histo= (TH1D*)gROOT->FindObject("histoCat7"); 
      if(i == 10) histo= (TH1D*)gROOT->FindObject("histoCat8"); 
      if(i == 11) histo= (TH1D*)gROOT->FindObject("histoCat91"); 
      if(i == 12) histo= (TH1D*)gROOT->FindObject("histoCat92"); 
      if(i == 13) histo= (TH1D*)gROOT->FindObject("histoCat93"); 
      if(i > 40) cout << "WARNING !!! max number of category  == 40 !!! " << endl;
      if(!histo) cout << "WARNING Histo for cat " << i << " is not existing " << endl;
      if(histo)  vectH.push_back(histo);
    }else{
     
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
      if(i > 40) cout << "WARNING !!! max number of category  == 40 !!! " << endl;
      if(!histo) cout << "WARNING Histo for cat " << i << " is not existing " << endl;
      if(histo)  vectH.push_back(histo);
    }
    
    
  }
  
  return vectH;
  
}
  
  
  
  
//-----------------------------------------------------Compute the probability that a track comes from PV ---------------------------------------------------------------------------//
double HighPtStudy::calculTrackProba(float p, float eta,int nhit, int npix, float chi,float ipsig, 
   std::vector<TH1D*> vectHis, std::vector<TH1D*> vectTrkP,std::vector<CategoryDef> vectHisCat){
 //cout << "in track proba " << endl;
 int  nbins=10000;
 int  xmin=0.0;
 int  xmax=20.0;
   
  bool foundCat = false;
  TH1D * myHisto;
  TH1D * myHistoTrk;
  //cout << "vectHisCat.size() " << vectHisCat.size() << endl;
  //cout << "vectHis.size() "    << vectHis.size()    << endl;
  //cout << "vectTrkP.size() "   << vectTrkP.size()   << endl;
  
  
   for(unsigned int i=0; i< vectHisCat.size(); i++){
    //cout << vectD[i].histo << endl;
    if(IsInCategory(eta,nhit ,npix ,p, chi, vectHisCat[i])) {
      foundCat = true;
      myHisto = vectHis[i];
      myHistoTrk= vectTrkP[i];
    }
  }
  //cout << "found categories " << endl;
  double proba= -1000.0;
  double histoIntegral = 1.0;
  if( foundCat == true){
    int nbin = int(fabs(ipsig)*(nbins+1)/xmax);
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
   //vectTrkP[10]->Fill(fabs(proba));
  
  }
  else {
    proba = -100.0; 
    //cout << "no category found !! " << endl;
    //cout <<  "p    " <<  p << endl;
    //cout <<  "eta  " <<  eta << endl;
    //cout <<  "nhit " <<  nhit << endl;
    //cout <<  "npix "  <<  npix << endl;
    //cout <<  "chi  " <<  chi << endl;
    }	
     //cout << "end track proba " << endl;

  return proba;
  
  
  
}


double HighPtStudy::jetProbability( std::vector<double>  v) 

{
  std::vector<double> probabilities;
  int i=0;

  for(std::vector<double>::const_iterator it = v.begin(); it!=v.end(); ++it, i++)
  {
         
      float p;
      //if(*it >=0 ) p=*it; else continue; 
      if (*it >=0){p=*it/2.;}else{p=1.+*it/2.;}
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



double HighPtStudy::optimizedDeltaR(double jetpT){

  double deltaR = 0.3;
  
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










