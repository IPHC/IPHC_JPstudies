//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Sep 24 11:20:16 2013 by ROOT version 5.32/00
// from TTree ttree/ttree
// found on file: TrackTree_mc_54_1_Z04.root
//////////////////////////////////////////////////////////

#ifndef HighPtStudy_h
#define HighPtStudy_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

#include "TLorentzVector.h"

#include "CategoryDef/CategoryDef.h"
#include "CategoryDef/CategoriesDefinition.h"
#include "CategoryDef/CategoryDefCollection.h"


// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.
const Int_t kMaxTrack = 1;

class HighPtStudy {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           BitTrigger;
   Int_t           nJet;
   Int_t           Run;
   Int_t           Evt;
   Int_t           LumiBlock;
   Int_t           nPV;
   Float_t         PVz;
   Float_t         pthat;
   Float_t         PVzSim;
   Int_t           nPUtrue;
   Int_t           nPU; 
   
   Int_t           nbQuarks;
   Float_t         bQuark_pT[10000];   //[nbQuarks]
   Float_t         bQuark_eta[10000];   //[nbQuarks]
   Float_t         bQuark_phi[10000];   //[nbQuarks]
   Int_t           bQuark_pdgID[10000];   //[nbQuarks]
   Int_t           bQuark_status[10000];   //[nbQuarks]
   Int_t           bQuark_fromGSP[10000];   //[nbQuarks]
  
   Int_t           nTrack;
   Float_t         Track_dxy[10000];   //[nTrack]
   Float_t         Track_dz[10000];   //[nTrack]
   Float_t         Track_zIP[10000];   //[nTrack]
   Float_t         Track_length[10000];   //[nTrack]
   Float_t         Track_dist[10000];   //[nTrack]
   Float_t         Track_IP2D[10000];   //[nTrack]
   Float_t         Track_IP2Dsig[10000];   //[nTrack]
   Float_t         Track_IP2Derr[10000];   //[nTrack]
   Float_t         Track_IP[10000];   //[nTrack]
   Float_t         Track_IPsig[10000];   //[nTrack]
   Float_t         Track_IPerr[10000];   //[nTrack]
   Float_t         Track_Proba[10000];   //[nTrack]
   Float_t         Track_p[10000];   //[nTrack]
   Float_t         Track_pt[10000];   //[nTrack]
   Float_t         Track_eta[10000];   //[nTrack]
   Float_t         Track_phi[10000];   //[nTrack]
   Float_t         Track_chi2[10000];   //[nTrack]
   Int_t           Track_charge[10000];   //[nTrack]
   Int_t           Track_history[10000];   //[nTrack]
   Int_t           Track_nHitStrip[10000];   //[nTrack]
   Int_t           Track_nHitPixel[10000];   //[nTrack]
   Int_t           Track_nHitAll[10000];   //[nTrack]
   Int_t           Track_nHitTIB[10000];   //[nTrack]
   Int_t           Track_nHitTID[10000];   //[nTrack]
   Int_t           Track_nHitTOB[10000];   //[nTrack]
   Int_t           Track_nHitTEC[10000];   //[nTrack]
   Int_t           Track_nHitPXB[10000];   //[nTrack]
   Int_t           Track_nHitPXF[10000];   //[nTrack]
   Int_t           Track_isHitL1[10000];   //[nTrack]
   Int_t           Track_PV[10000];   //[nTrack]
   Int_t           Track_SV[10000];   //[nTrack]
   Float_t         Track_PVweight[10000];   //[nTrack]
   Float_t         Track_SVweight[10000];   //[nTrack]
   Int_t           Track_isfromSV[10000];   //[nTrack]
   Int_t           Track_category[10000];   //[nTrack]
   Float_t         PV_x[1000];   //[nPV]
   Float_t         PV_y[1000];   //[nPV]
   Float_t         PV_z[1000];   //[nPV]
   Float_t         PV_ex[1000];   //[nPV]
   Float_t         PV_ey[1000];   //[nPV]
   Float_t         PV_ez[1000];   //[nPV]
   Float_t         PV_chi2[1000];   //[nPV]
   Float_t         PV_ndf[1000];   //[nPV]
   Int_t           PV_isgood[1000];   //[nPV]
   Int_t           PV_isfake[1000];   //[nPV]
   Int_t           nSV;
   Float_t         SV_x[100];   //[nSV]
   Float_t         SV_y[100];   //[nSV]
   Float_t         SV_z[100];   //[nSV]
   Float_t         SV_ex[100];   //[nSV]
   Float_t         SV_ey[100];   //[nSV]
   Float_t         SV_ez[100];   //[nSV]
   Float_t         SV_chi2[100];   //[nSV]
   Float_t         SV_ndf[100];   //[nSV]
   Float_t         SV_flight[100];   //[nSV]
   Float_t         SV_flightErr[100];   //[nSV]
   Float_t         SV_deltaR_jet[100];   //[nSV]
   Float_t         SV_deltaR_sum_jet[100];   //[nSV]
   Float_t         SV_deltaR_sum_dir[100];   //[nSV]
   Float_t         SV_energy_ratio[100];   //[nSV]
   Float_t         SV_aboveC[100];   //[nSV]
   Float_t         SV_vtx_pt[100];   //[nSV]
   Float_t         SV_flight2D[100];   //[nSV]
   Float_t         SV_flight2DErr[100];   //[nSV]
   Float_t         SV_totCharge[100];   //[nSV]
   Float_t         SV_vtxDistJetAxis[100];   //[nSV]
   Int_t           SV_nTrk[100];   //[nSV]
   Int_t           SV_nTrk_firstVxt[100];   //[nSV]
   Float_t         SV_mass[100];   //[nSV]
   Float_t         SV_vtx_eta[100];   //[nSV]
   Float_t         SV_vtx_phi[100];   //[nSV]
   Float_t         Jet_pt[1000];   //[nJet]
   Float_t         Jet_genpt[1000];   //[nJet]
   Float_t         Jet_residual[1000];   //[nJet]
   Float_t         Jet_jes[1000];   //[nJet]
   Float_t         Jet_eta[1000];   //[nJet]
   Float_t         Jet_phi[1000];   //[nJet]
   Int_t           Jet_ntracks[1000];   //[nJet]
   Int_t           Jet_flavour[1000];   //[nJet]
   Float_t         Jet_Ip1N[1000];   //[nJet]
   Float_t         Jet_Ip1P[1000];   //[nJet]
   Float_t         Jet_Ip2N[1000];   //[nJet]
   Float_t         Jet_Ip2P[1000];   //[nJet]
   Float_t         Jet_Ip3N[1000];   //[nJet]
   Float_t         Jet_Ip3P[1000];   //[nJet]
   Float_t         Jet_ProbaN[1000];   //[nJet]
   Float_t         Jet_ProbaP[1000];   //[nJet]
   Float_t         Jet_Proba[1000];   //[nJet]
   Float_t         Jet_BprobN[1000];   //[nJet]
   Float_t         Jet_BprobP[1000];   //[nJet]
   Float_t         Jet_Bprob[1000];   //[nJet]
   Float_t         Jet_SvxN[1000];   //[nJet]
   Float_t         Jet_Svx[1000];   //[nJet]
   Float_t         Jet_SvxNHP[1000];   //[nJet]
   Float_t         Jet_SvxHP[1000];   //[nJet]
   Float_t         Jet_SvxMass[1000];   //[nJet]
   Float_t         Jet_CombSvxN[1000];   //[nJet]
   Float_t         Jet_CombSvxP[1000];   //[nJet]
   Float_t         Jet_CombSvx[1000];   //[nJet]
   Float_t         Jet_SimpIVF_HP[1000];   //[nJet]
   Float_t         Jet_SimpIVF_HE[1000];   //[nJet]
   Float_t         Jet_DoubIVF_HE[1000];   //[nJet]
   Float_t         Jet_CombIVF[1000];   //[nJet]
   Float_t         Jet_CombIVF_P[1000];   //[nJet]
   Float_t         Jet_SoftMuN[1000];   //[nJet]
   Float_t         Jet_SoftMu[1000];   //[nJet]
   Int_t           Jet_hist1[1000];   //[nJet]
   Int_t           Jet_hist2[1000];   //[nJet]
   Int_t           Jet_hist3[1000];   //[nJet]
   Int_t           Jet_histJet[1000];   //[nJet]
   Int_t           Jet_histSvx[1000];   //[nJet]
   Int_t           Jet_nFirstTrack[1000];   //[nJet]
   Int_t           Jet_nLastTrack[1000];   //[nJet]
   Int_t           Jet_nFirstSV[1000];   //[nJet]
   Int_t           Jet_nLastSV[1000];   //[nJet]
   Int_t           Jet_SV_multi[1000];   //[nJet]
   Int_t           Jet_nFirstTrkInc[1000];   //[nJet]
   Int_t           Jet_nLastTrkInc[1000];   //[nJet]
   Int_t           nMuon;
   Int_t           Muon_IdxJet[100];   //[nMuon]
   Int_t           Muon_nMuHit[100];   //[nMuon]
   Int_t           Muon_nTkHit[100];   //[nMuon]
   Int_t           Muon_nPixHit[100];   //[nMuon]
   Int_t           Muon_nOutHit[100];   //[nMuon]
   Int_t           Muon_isGlobal[100];   //[nMuon]
   Int_t           Muon_nMatched[100];   //[nMuon]
   Float_t         Muon_chi2[100];   //[nMuon]
   Float_t         Muon_chi2Tk[100];   //[nMuon]
   Float_t         Muon_pt[100];   //[nMuon]
   Float_t         Muon_eta[100];   //[nMuon]
   Float_t         Muon_phi[100];   //[nMuon]
   Float_t         Muon_ptrel[100];   //[nMuon]
   Float_t         Muon_vz[100];   //[nMuon]
   Int_t           Muon_hist[100];   //[nMuon]
   Float_t         Muon_IPsig[100];   //[nMuon]
   Float_t         Muon_IP[100];   //[nMuon]
   Float_t         Muon_IP2Dsig[100];   //[nMuon]
   Float_t         Muon_IP2D[100];   //[nMuon]
   Float_t         Muon_Proba[100];   //[nMuon]
   Float_t         Muon_deltaR[100];   //[nMuon]
   Float_t         Muon_ratio[100];   //[nMuon]
   Int_t           nTrkInc;
   Float_t         TrkInc_pt[1000];   //[nTrkInc]
   Float_t         TrkInc_eta[1000];   //[nTrkInc]
   Float_t         TrkInc_phi[1000];   //[nTrkInc]
   Float_t         TrkInc_ptrel[1000];   //[nTrkInc]
   Float_t         TrkInc_IPsig[1000];   //[nTrkInc]
   Float_t         TrkInc_IP[1000];   //[nTrkInc]
   Int_t           nCFromGSplit;
   Float_t         cFromGSplit_pT[1000];   //[nCFromGSplit]
   Float_t         cFromGSplit_eta[1000];   //[nCFromGSplit]
   Float_t         cFromGSplit_phi[1000];   //[nCFromGSplit]
   Int_t           nBFromGSplit;
   Float_t         bFromGSplit_pT[1000];   //[nBFromGSplit]
   Float_t         bFromGSplit_eta[1000];   //[nBFromGSplit]
   Float_t         bFromGSplit_phi[1000];   //[nBFromGSplit]
   Float_t         mcweight;
   Int_t           nBHadrons;
   Float_t         BHadron_pT[1000];   //[nBHadrons]
   Float_t         BHadron_eta[1000];   //[nBHadrons]
   Float_t         BHadron_phi[1000];   //[nBHadrons]
   Float_t         BHadron_mass[1000];   //[nBHadrons]
   Int_t           BHadron_pdgID[1000];   //[nBHadrons]
   Float_t         BHadron_SVx[1000];   //[nBHadrons]
   Float_t         BHadron_SVy[1000];   //[nBHadrons]

   // List of branches
   TBranch        *b_BitTrigger;   //!
   TBranch        *b_nJet;   //!
   TBranch        *b_Run;   //!
   TBranch        *b_Evt;   //!
   TBranch        *b_LumiBlock;   //!
   TBranch        *b_nPV;   //!
   TBranch        *b_PVz;   //!
   TBranch        *b_pthat;   //!
   TBranch        *b_PVzSim;   //!
   TBranch        *b_nPUtrue;   //!
   TBranch        *b_nPU;   //!
   
   
   
   TBranch        *b_nbQuarks;   //!
   TBranch        *b_bQuark_pT;   //!
   TBranch        *b_bQuark_eta;   //!
   TBranch        *b_bQuark_phi;   //!
   TBranch        *b_bQuark_pdgID;   //!
   TBranch        *b_bQuark_status;   //!
   TBranch        *b_bQuark_fromGSP;   //!
   
   
   
   TBranch        *b_nTrack;   //!
   TBranch        *b_Track_dxy;   //!
   TBranch        *b_Track_dz;   //!
   TBranch        *b_Track_zIP;   //!
   TBranch        *b_Track_length;   //!
   TBranch        *b_Track_dist;   //!
   TBranch        *b_Track_IP2D;   //!
   TBranch        *b_Track_IP2Dsig;   //!
   TBranch        *b_Track_IP2Derr;   //!
   TBranch        *b_Track_IP;   //!
   TBranch        *b_Track_IPsig;   //!
   TBranch        *b_Track_IPerr;   //!
   TBranch        *b_Track_Proba;   //!
   TBranch        *b_Track_p;   //!
   TBranch        *b_Track_pt;   //!
   TBranch        *b_Track_eta;   //!
   TBranch        *b_Track_phi;   //!
   TBranch        *b_Track_chi2;   //!
   TBranch        *b_Track_charge;   //!
   TBranch        *b_Track_history;   //!
   TBranch        *b_Track_nHitStrip;   //!
   TBranch        *b_Track_nHitPixel;   //!
   TBranch        *b_Track_nHitAll;   //!
   TBranch        *b_Track_nHitTIB;   //!
   TBranch        *b_Track_nHitTID;   //!
   TBranch        *b_Track_nHitTOB;   //!
   TBranch        *b_Track_nHitTEC;   //!
   TBranch        *b_Track_nHitPXB;   //!
   TBranch        *b_Track_nHitPXF;   //!
   TBranch        *b_Track_isHitL1;   //!
   TBranch        *b_Track_PV;   //!
   TBranch        *b_Track_SV;   //!
   TBranch        *b_Track_PVweight;   //!
   TBranch        *b_Track_SVweight;   //!
   TBranch        *b_Track_isfromSV;   //!
   TBranch        *b_Track_category;   //!
   TBranch        *b_PV_x;   //!
   TBranch        *b_PV_y;   //!
   TBranch        *b_PV_z;   //!
   TBranch        *b_PV_ex;   //!
   TBranch        *b_PV_ey;   //!
   TBranch        *b_PV_ez;   //!
   TBranch        *b_PV_chi2;   //!
   TBranch        *b_PV_ndf;   //!
   TBranch        *b_PV_isgood;   //!
   TBranch        *b_PV_isfake;   //!
   TBranch        *b_nSV;   //!
   TBranch        *b_SV_x;   //!
   TBranch        *b_SV_y;   //!
   TBranch        *b_SV_z;   //!
   TBranch        *b_SV_ex;   //!
   TBranch        *b_SV_ey;   //!
   TBranch        *b_SV_ez;   //!
   TBranch        *b_SV_chi2;   //!
   TBranch        *b_SV_ndf;   //!
   TBranch        *b_SV_flight;   //!
   TBranch        *b_SV_flightErr;   //!
   TBranch        *b_SV_deltaR_jet;   //!
   TBranch        *b_SV_deltaR_sum_jet;   //!
   TBranch        *b_SV_deltaR_sum_dir;   //!
   TBranch        *b_SV_energy_ratio;   //!
   TBranch        *b_SV_aboveC;   //!
   TBranch        *b_SV_vtx_pt;   //!
   TBranch        *b_SV_flight2D;   //!
   TBranch        *b_SV_flight2DErr;   //!
   TBranch        *b_SV_totCharge;   //!
   TBranch        *b_SV_vtxDistJetAxis;   //!
   TBranch        *b_SV_nTrk;   //!
   TBranch        *b_SV_nTrk_firstVxt;   //!
   TBranch        *b_SV_mass;   //!
   TBranch        *b_SV_vtx_eta;   //!
   TBranch        *b_SV_vtx_phi;   //!
   TBranch        *b_Jet_pt;   //!
   TBranch        *b_Jet_genpt;   //!
   TBranch        *b_Jet_residual;   //!
   TBranch        *b_Jet_jes;   //!
   TBranch        *b_Jet_eta;   //!
   TBranch        *b_Jet_phi;   //!
   TBranch        *b_Jet_ntracks;   //!
   TBranch        *b_Jet_flavour;   //!
   TBranch        *b_Jet_Ip1N;   //!
   TBranch        *b_Jet_Ip1P;   //!
   TBranch        *b_Jet_Ip2N;   //!
   TBranch        *b_Jet_Ip2P;   //!
   TBranch        *b_Jet_Ip3N;   //!
   TBranch        *b_Jet_Ip3P;   //!
   TBranch        *b_Jet_ProbaN;   //!
   TBranch        *b_Jet_ProbaP;   //!
   TBranch        *b_Jet_Proba;   //!
   TBranch        *b_Jet_BprobN;   //!
   TBranch        *b_Jet_BprobP;   //!
   TBranch        *b_Jet_Bprob;   //!
   TBranch        *b_Jet_SvxN;   //!
   TBranch        *b_Jet_Svx;   //!
   TBranch        *b_Jet_SvxNHP;   //!
   TBranch        *b_Jet_SvxHP;   //!
   TBranch        *b_Jet_SvxMass;   //!
   TBranch        *b_Jet_CombSvxN;   //!
   TBranch        *b_Jet_CombSvxP;   //!
   TBranch        *b_Jet_CombSvx;   //!
   TBranch        *b_Jet_SimpIVF_HP;   //!
   TBranch        *b_Jet_SimpIVF_HE;   //!
   TBranch        *b_Jet_DoubIVF_HE;   //!
   TBranch        *b_Jet_CombIVF;   //!
   TBranch        *b_Jet_CombIVF_P;   //!
   TBranch        *b_Jet_SoftMuN;   //!
   TBranch        *b_Jet_SoftMu;   //!
   TBranch        *b_Jet_hist1;   //!
   TBranch        *b_Jet_hist2;   //!
   TBranch        *b_Jet_hist3;   //!
   TBranch        *b_Jet_histJet;   //!
   TBranch        *b_Jet_histSvx;   //!
   TBranch        *b_Jet_nFirstTrack;   //!
   TBranch        *b_Jet_nLastTrack;   //!
   TBranch        *b_Jet_nFirstSV;   //!
   TBranch        *b_Jet_nLastSV;   //!
   TBranch        *b_Jet_SV_multi;   //!
   TBranch        *b_Jet_nFirstTrkInc;   //!
   TBranch        *b_Jet_nLastTrkInc;   //!
   TBranch        *b_nMuon;   //!
   TBranch        *b_Muon_IdxJet;   //!
   TBranch        *b_Muon_nMuHit;   //!
   TBranch        *b_Muon_nTkHit;   //!
   TBranch        *b_Muon_nPixHit;   //!
   TBranch        *b_Muon_nOutHit;   //!
   TBranch        *b_Muon_isGlobal;   //!
   TBranch        *b_Muon_nMatched;   //!
   TBranch        *b_Muon_chi2;   //!
   TBranch        *b_Muon_chi2Tk;   //!
   TBranch        *b_Muon_pt;   //!
   TBranch        *b_Muon_eta;   //!
   TBranch        *b_Muon_phi;   //!
   TBranch        *b_Muon_ptrel;   //!
   TBranch        *b_Muon_vz;   //!
   TBranch        *b_Muon_hist;   //!
   TBranch        *b_Muon_IPsig;   //!
   TBranch        *b_Muon_IP;   //!
   TBranch        *b_Muon_IP2Dsig;   //!
   TBranch        *b_Muon_IP2D;   //!
   TBranch        *b_Muon_Proba;   //!
   TBranch        *b_Muon_deltaR;   //!
   TBranch        *b_Muon_ratio;   //!
   TBranch        *b_nTrkInc;   //!
   TBranch        *b_TrkInc_pt;   //!
   TBranch        *b_TrkInc_eta;   //!
   TBranch        *b_TrkInc_phi;   //!
   TBranch        *b_TrkInc_ptrel;   //!
   TBranch        *b_TrkInc_IPsig;   //!
   TBranch        *b_TrkInc_IP;   //!
   TBranch        *b_nCFromGSplit;   //!
   TBranch        *b_cFromGSplit_pT;   //!
   TBranch        *b_cFromGSplit_eta;   //!
   TBranch        *b_cFromGSplit_phi;   //!
   TBranch        *b_nBFromGSplit;   //!
   TBranch        *b_bFromGSplit_pT;   //!
   TBranch        *b_bFromGSplit_eta;   //!
   TBranch        *b_bFromGSplit_phi;   //!
   TBranch        *b_mcweight;   //!
   TBranch        *b_nBHadrons;   //!
   TBranch        *b_BHadron_pT;   //!
   TBranch        *b_BHadron_eta;   //!
   TBranch        *b_BHadron_phi;   //!
   TBranch        *b_BHadron_mass;   //!
   TBranch        *b_BHadron_pdgID;   //!
   TBranch        *b_BHadron_SVx;   //!
   TBranch        *b_BHadron_SVy;   //!

   HighPtStudy(TTree *tree=0);
   virtual ~HighPtStudy();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop( const char*fileInPutName );
   //virtual void     plotLoop();
   //virtual void     plot1D(TString histo_name, int whatPlot);
   //virtual void     plot2D(TString histo_name);   
   virtual void     run();   
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
   
   
  
  
  
   virtual int   IsInCategory(float trkEta, float trkHTrk, float trkHPix, float trkp, 
   float trkChi2, std::vector<CategoryDef > d);
   virtual bool  passTrackSel(int trk, int pix, float ip2d, float pt, float len, float chi2, float zip, float dist, float eta, float etaJet, float phi, float phiJet, float ptJet);

   
   virtual double                    jetProbability( std::vector<double>  v, int ipsign) ;
   
   
   bool DeltaRTrackJetCut(double jetpT, double deltaR);
   bool TrackPtCut(double jetpT, double trackpt);
   

   double optimizedDeltaR(double jetpT);
   
   float calculPtRel(TLorentzVector theTrack, TLorentzVector theJet );

};

#endif

#ifdef HighPtStudy_cxx
HighPtStudy::HighPtStudy(TTree *tree) : fChain(0) 
{

 
   
   TChain *superTree = new TChain("btagana/ttree");
   // Data
   if (tree == 0) {
  
   superTree->Add("/opt/sbg/data/data2/cms/cbeluffi/BTag_2013_06_24/DataLegacy/BTagAna/CMSSW_5_3_11_patch5/src/RecoBTag/PerformanceMeasurements/test/mc_calib_confirm2/JetTree_*.root");
// superTree->Add("/opt/sbg/cms/ui8_data1/ccollard/BTAG/MC_Dan_2013April/PythiaQCD/QCD_Pt-30to50_Inclusive_8TeV_pythia6_Summer12_DR53X-PU_S10_AODSIM/TrackTree_*.root");
// superTree->Add("/opt/sbg/cms/ui8_data1/ccollard/BTAG/MC_Dan_2013April/PythiaQCD/QCD_Pt-50to80_Inclusive_8TeV_pythia6_Summer12_DR53X-PU_S10_AODSIM/TrackTree_*.root");
// superTree->Add("/opt/sbg/cms/ui8_data1/ccollard/BTAG/MC_Dan_2013April/PythiaQCD/QCD_Pt-80to120_Inclusive_8TeV_pythia6_Summer12_DR53X-PU_S10_AODSIM/TrackTree_*.root");
// superTree->Add("/opt/sbg/cms/ui8_data2/ccollard/BTAG/MC_Dan_2013April/PythiaQCD/QCD_Pt-120to170_Inclusive_8TeV_pythia6_Summer12_DR53X-PU_S10_AODSIM/TrackTree_*.root");
// superTree->Add("/opt/sbg/cms/ui8_data2/ccollard/BTAG/MC_Dan_2013April/PythiaQCD/QCD_Pt-170to300_Inclusive_8TeV_pythia6_Summer12_DR53X-PU_S10_AODSIM/TrackTree_*.root");
//superTree->Add("/opt/sbg/cms/ui8_data1/ccollard/BTAG/MC_Dan_2013April/PythiaQCD/QCD_Pt-300to470_Inclusive_8TeV_pythia6_Summer12_DR53X-PU_S10_AODSIM/TrackTree_*.root");
//superTree->Add("/opt/sbg/cms/ui8_data1/ccollard/BTAG/MC_Dan_2013April/PythiaQCD/QCD_Pt-470to600_Inclusive_8TeV_pythia6_Summer12_DR53X-PU_S10_AODSIM/TrackTree_*.root");
//superTree->Add("/opt/sbg/cms/ui8_data2/ccollard/BTAG/MC_Dan_2013April/PythiaQCD/QCD_Pt-600to800_Inclusive_8TeV_pythia6_Summer12_DR53X-PU_S10_AODSIM/TrackTree_*.root");
//superTree->Add("/opt/sbg/cms/ui8_data2/ccollard/BTAG/MC_Dan_2013April/PythiaQCD/QCD_Pt-800to1000_Inclusive_8TeV_pythia6_Summer12_DR53X-PU_S10_AODSIM/TrackTree_*.root");
   
   Init(superTree);
   } else Init(tree);
   
   

}

HighPtStudy::~HighPtStudy()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t HighPtStudy::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t HighPtStudy::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void HighPtStudy::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("BitTrigger", &BitTrigger, &b_BitTrigger);
   fChain->SetBranchAddress("nJet", &nJet, &b_nJet);
   fChain->SetBranchAddress("Run", &Run, &b_Run);
   fChain->SetBranchAddress("Evt", &Evt, &b_Evt);
   fChain->SetBranchAddress("LumiBlock", &LumiBlock, &b_LumiBlock);
   fChain->SetBranchAddress("nPV", &nPV, &b_nPV);
   fChain->SetBranchAddress("PVz", &PVz, &b_PVz);
   fChain->SetBranchAddress("pthat", &pthat, &b_pthat);
   //fChain->SetBranchAddress("PVzSim", &PVzSim, &b_PVzSim);
   fChain->SetBranchAddress("nPUtrue", &nPUtrue, &b_nPUtrue);
   fChain->SetBranchAddress("nPU", &nPU, &b_nPU);
   
   
   
   fChain->SetBranchAddress("nbQuarks", &nbQuarks, &b_nbQuarks);
   fChain->SetBranchAddress("bQuark_pT", bQuark_pT, &b_bQuark_pT);
   fChain->SetBranchAddress("bQuark_eta", bQuark_eta, &b_bQuark_eta);
   fChain->SetBranchAddress("bQuark_phi", bQuark_phi, &b_bQuark_phi);
   fChain->SetBranchAddress("bQuark_pdgID", bQuark_pdgID, &b_bQuark_pdgID);
   fChain->SetBranchAddress("bQuark_status", bQuark_status, &b_bQuark_status);
   fChain->SetBranchAddress("bQuark_fromGSP", bQuark_fromGSP, &b_bQuark_fromGSP);
   
   
   
   
   
   
   fChain->SetBranchAddress("nTrack", &nTrack, &b_nTrack);
   fChain->SetBranchAddress("Track_dxy", Track_dxy, &b_Track_dxy);
   fChain->SetBranchAddress("Track_dz", Track_dz, &b_Track_dz);
   fChain->SetBranchAddress("Track_zIP", Track_zIP, &b_Track_zIP);
   fChain->SetBranchAddress("Track_length", Track_length, &b_Track_length);
   fChain->SetBranchAddress("Track_dist", Track_dist, &b_Track_dist);
   fChain->SetBranchAddress("Track_IP2D", Track_IP2D, &b_Track_IP2D);
   fChain->SetBranchAddress("Track_IP2Dsig", Track_IP2Dsig, &b_Track_IP2Dsig);
   fChain->SetBranchAddress("Track_IP2Derr", Track_IP2Derr, &b_Track_IP2Derr);
   fChain->SetBranchAddress("Track_IP", Track_IP, &b_Track_IP);
   fChain->SetBranchAddress("Track_IPsig", Track_IPsig, &b_Track_IPsig);
   fChain->SetBranchAddress("Track_IPerr", Track_IPerr, &b_Track_IPerr);
   fChain->SetBranchAddress("Track_Proba", Track_Proba, &b_Track_Proba);
   fChain->SetBranchAddress("Track_p", Track_p, &b_Track_p);
   fChain->SetBranchAddress("Track_pt", Track_pt, &b_Track_pt);
   fChain->SetBranchAddress("Track_eta", Track_eta, &b_Track_eta);
   fChain->SetBranchAddress("Track_phi", Track_phi, &b_Track_phi);
   fChain->SetBranchAddress("Track_chi2", Track_chi2, &b_Track_chi2);
   fChain->SetBranchAddress("Track_charge", Track_charge, &b_Track_charge);
   fChain->SetBranchAddress("Track_history", Track_history, &b_Track_history);
   fChain->SetBranchAddress("Track_nHitStrip", Track_nHitStrip, &b_Track_nHitStrip);
   fChain->SetBranchAddress("Track_nHitPixel", Track_nHitPixel, &b_Track_nHitPixel);
   fChain->SetBranchAddress("Track_nHitAll", Track_nHitAll, &b_Track_nHitAll);
   fChain->SetBranchAddress("Track_nHitTIB", Track_nHitTIB, &b_Track_nHitTIB);
   fChain->SetBranchAddress("Track_nHitTID", Track_nHitTID, &b_Track_nHitTID);
   fChain->SetBranchAddress("Track_nHitTOB", Track_nHitTOB, &b_Track_nHitTOB);
   fChain->SetBranchAddress("Track_nHitTEC", Track_nHitTEC, &b_Track_nHitTEC);
   fChain->SetBranchAddress("Track_nHitPXB", Track_nHitPXB, &b_Track_nHitPXB);
   fChain->SetBranchAddress("Track_nHitPXF", Track_nHitPXF, &b_Track_nHitPXF);
   fChain->SetBranchAddress("Track_isHitL1", Track_isHitL1, &b_Track_isHitL1);
   fChain->SetBranchAddress("Track_PV", Track_PV, &b_Track_PV);
   fChain->SetBranchAddress("Track_SV", Track_SV, &b_Track_SV);
   fChain->SetBranchAddress("Track_PVweight", Track_PVweight, &b_Track_PVweight);
   fChain->SetBranchAddress("Track_SVweight", Track_SVweight, &b_Track_SVweight);
   fChain->SetBranchAddress("Track_isfromSV", Track_isfromSV, &b_Track_isfromSV);
   fChain->SetBranchAddress("Track_category", Track_category, &b_Track_category);
   fChain->SetBranchAddress("PV_x", PV_x, &b_PV_x);
   fChain->SetBranchAddress("PV_y", PV_y, &b_PV_y);
   fChain->SetBranchAddress("PV_z", PV_z, &b_PV_z);
   fChain->SetBranchAddress("PV_ex", PV_ex, &b_PV_ex);
   fChain->SetBranchAddress("PV_ey", PV_ey, &b_PV_ey);
   fChain->SetBranchAddress("PV_ez", PV_ez, &b_PV_ez);
   fChain->SetBranchAddress("PV_chi2", PV_chi2, &b_PV_chi2);
   fChain->SetBranchAddress("PV_ndf", PV_ndf, &b_PV_ndf);
   fChain->SetBranchAddress("PV_isgood", PV_isgood, &b_PV_isgood);
   fChain->SetBranchAddress("PV_isfake", PV_isfake, &b_PV_isfake);
   fChain->SetBranchAddress("nSV", &nSV, &b_nSV);
   fChain->SetBranchAddress("SV_x", SV_x, &b_SV_x);
   fChain->SetBranchAddress("SV_y", SV_y, &b_SV_y);
   fChain->SetBranchAddress("SV_z", SV_z, &b_SV_z);
   fChain->SetBranchAddress("SV_ex", SV_ex, &b_SV_ex);
   fChain->SetBranchAddress("SV_ey", SV_ey, &b_SV_ey);
   fChain->SetBranchAddress("SV_ez", SV_ez, &b_SV_ez);
   fChain->SetBranchAddress("SV_chi2", SV_chi2, &b_SV_chi2);
   fChain->SetBranchAddress("SV_ndf", SV_ndf, &b_SV_ndf);
   fChain->SetBranchAddress("SV_flight", SV_flight, &b_SV_flight);
   fChain->SetBranchAddress("SV_flightErr", SV_flightErr, &b_SV_flightErr);
   fChain->SetBranchAddress("SV_deltaR_jet", SV_deltaR_jet, &b_SV_deltaR_jet);
   fChain->SetBranchAddress("SV_deltaR_sum_jet", SV_deltaR_sum_jet, &b_SV_deltaR_sum_jet);
   fChain->SetBranchAddress("SV_deltaR_sum_dir", SV_deltaR_sum_dir, &b_SV_deltaR_sum_dir);
   fChain->SetBranchAddress("SV_energy_ratio", SV_energy_ratio, &b_SV_energy_ratio);
   fChain->SetBranchAddress("SV_aboveC", SV_aboveC, &b_SV_aboveC);
   fChain->SetBranchAddress("SV_vtx_pt", SV_vtx_pt, &b_SV_vtx_pt);
   fChain->SetBranchAddress("SV_flight2D", SV_flight2D, &b_SV_flight2D);
   fChain->SetBranchAddress("SV_flight2DErr", SV_flight2DErr, &b_SV_flight2DErr);
   fChain->SetBranchAddress("SV_totCharge", SV_totCharge, &b_SV_totCharge);
   fChain->SetBranchAddress("SV_vtxDistJetAxis", SV_vtxDistJetAxis, &b_SV_vtxDistJetAxis);
   fChain->SetBranchAddress("SV_nTrk", SV_nTrk, &b_SV_nTrk);
   fChain->SetBranchAddress("SV_nTrk_firstVxt", SV_nTrk_firstVxt, &b_SV_nTrk_firstVxt);
   fChain->SetBranchAddress("SV_mass", SV_mass, &b_SV_mass);
   fChain->SetBranchAddress("SV_vtx_eta", SV_vtx_eta, &b_SV_vtx_eta);
   fChain->SetBranchAddress("SV_vtx_phi", SV_vtx_phi, &b_SV_vtx_phi);
   fChain->SetBranchAddress("Jet_pt", Jet_pt, &b_Jet_pt);
   fChain->SetBranchAddress("Jet_genpt", Jet_genpt, &b_Jet_genpt);
   fChain->SetBranchAddress("Jet_residual", Jet_residual, &b_Jet_residual);
   fChain->SetBranchAddress("Jet_jes", Jet_jes, &b_Jet_jes);
   fChain->SetBranchAddress("Jet_eta", Jet_eta, &b_Jet_eta);
   fChain->SetBranchAddress("Jet_phi", Jet_phi, &b_Jet_phi);
   fChain->SetBranchAddress("Jet_ntracks", Jet_ntracks, &b_Jet_ntracks);
   fChain->SetBranchAddress("Jet_flavour", Jet_flavour, &b_Jet_flavour);
   //fChain->SetBranchAddress("Jet_Ip1N", Jet_Ip1N, &b_Jet_Ip1N);
   //fChain->SetBranchAddress("Jet_Ip1P", Jet_Ip1P, &b_Jet_Ip1P);
   fChain->SetBranchAddress("Jet_Ip2N", Jet_Ip2N, &b_Jet_Ip2N);
   fChain->SetBranchAddress("Jet_Ip2P", Jet_Ip2P, &b_Jet_Ip2P);
   fChain->SetBranchAddress("Jet_Ip3N", Jet_Ip3N, &b_Jet_Ip3N);
   fChain->SetBranchAddress("Jet_Ip3P", Jet_Ip3P, &b_Jet_Ip3P);
   fChain->SetBranchAddress("Jet_ProbaN", Jet_ProbaN, &b_Jet_ProbaN);
   fChain->SetBranchAddress("Jet_ProbaP", Jet_ProbaP, &b_Jet_ProbaP);
   fChain->SetBranchAddress("Jet_Proba", Jet_Proba, &b_Jet_Proba);
   fChain->SetBranchAddress("Jet_BprobN", Jet_BprobN, &b_Jet_BprobN);
   fChain->SetBranchAddress("Jet_BprobP", Jet_BprobP, &b_Jet_BprobP);
   fChain->SetBranchAddress("Jet_Bprob", Jet_Bprob, &b_Jet_Bprob);
   fChain->SetBranchAddress("Jet_SvxN", Jet_SvxN, &b_Jet_SvxN);
   fChain->SetBranchAddress("Jet_Svx", Jet_Svx, &b_Jet_Svx);
   fChain->SetBranchAddress("Jet_SvxNHP", Jet_SvxNHP, &b_Jet_SvxNHP);
   fChain->SetBranchAddress("Jet_SvxHP", Jet_SvxHP, &b_Jet_SvxHP);
   //fChain->SetBranchAddress("Jet_SvxMass", Jet_SvxMass, &b_Jet_SvxMass);
   fChain->SetBranchAddress("Jet_CombSvxN", Jet_CombSvxN, &b_Jet_CombSvxN);
   fChain->SetBranchAddress("Jet_CombSvxP", Jet_CombSvxP, &b_Jet_CombSvxP);
   fChain->SetBranchAddress("Jet_CombSvx", Jet_CombSvx, &b_Jet_CombSvx);
   //fChain->SetBranchAddress("Jet_SimpIVF_HP", Jet_SimpIVF_HP, &b_Jet_SimpIVF_HP);
   //fChain->SetBranchAddress("Jet_SimpIVF_HE", Jet_SimpIVF_HE, &b_Jet_SimpIVF_HE);
   //fChain->SetBranchAddress("Jet_DoubIVF_HE", Jet_DoubIVF_HE, &b_Jet_DoubIVF_HE);
   //fChain->SetBranchAddress("Jet_CombIVF", Jet_CombIVF, &b_Jet_CombIVF);
   //fChain->SetBranchAddress("Jet_CombIVF_P", Jet_CombIVF_P, &b_Jet_CombIVF_P);
   fChain->SetBranchAddress("Jet_SoftMuN", Jet_SoftMuN, &b_Jet_SoftMuN);
   fChain->SetBranchAddress("Jet_SoftMu", Jet_SoftMu, &b_Jet_SoftMu);
   fChain->SetBranchAddress("Jet_hist1", Jet_hist1, &b_Jet_hist1);
   fChain->SetBranchAddress("Jet_hist2", Jet_hist2, &b_Jet_hist2);
   fChain->SetBranchAddress("Jet_hist3", Jet_hist3, &b_Jet_hist3);
   fChain->SetBranchAddress("Jet_histJet", Jet_histJet, &b_Jet_histJet);
   fChain->SetBranchAddress("Jet_histSvx", Jet_histSvx, &b_Jet_histSvx);
   fChain->SetBranchAddress("Jet_nFirstTrack", Jet_nFirstTrack, &b_Jet_nFirstTrack);
   fChain->SetBranchAddress("Jet_nLastTrack", Jet_nLastTrack, &b_Jet_nLastTrack);
   fChain->SetBranchAddress("Jet_nFirstSV", Jet_nFirstSV, &b_Jet_nFirstSV);
   fChain->SetBranchAddress("Jet_nLastSV", Jet_nLastSV, &b_Jet_nLastSV);
   fChain->SetBranchAddress("Jet_SV_multi", Jet_SV_multi, &b_Jet_SV_multi);
   fChain->SetBranchAddress("Jet_nFirstTrkInc", Jet_nFirstTrkInc, &b_Jet_nFirstTrkInc);
   fChain->SetBranchAddress("Jet_nLastTrkInc", Jet_nLastTrkInc, &b_Jet_nLastTrkInc);
   fChain->SetBranchAddress("nMuon", &nMuon, &b_nMuon);
   fChain->SetBranchAddress("Muon_IdxJet", Muon_IdxJet, &b_Muon_IdxJet);
   fChain->SetBranchAddress("Muon_nMuHit", Muon_nMuHit, &b_Muon_nMuHit);
   fChain->SetBranchAddress("Muon_nTkHit", Muon_nTkHit, &b_Muon_nTkHit);
   fChain->SetBranchAddress("Muon_nPixHit", Muon_nPixHit, &b_Muon_nPixHit);
   fChain->SetBranchAddress("Muon_nOutHit", Muon_nOutHit, &b_Muon_nOutHit);
   fChain->SetBranchAddress("Muon_isGlobal", Muon_isGlobal, &b_Muon_isGlobal);
   fChain->SetBranchAddress("Muon_nMatched", Muon_nMatched, &b_Muon_nMatched);
   fChain->SetBranchAddress("Muon_chi2", Muon_chi2, &b_Muon_chi2);
   fChain->SetBranchAddress("Muon_chi2Tk", Muon_chi2Tk, &b_Muon_chi2Tk);
   fChain->SetBranchAddress("Muon_pt", Muon_pt, &b_Muon_pt);
   fChain->SetBranchAddress("Muon_eta", Muon_eta, &b_Muon_eta);
   fChain->SetBranchAddress("Muon_phi", Muon_phi, &b_Muon_phi);
   fChain->SetBranchAddress("Muon_ptrel", Muon_ptrel, &b_Muon_ptrel);
   fChain->SetBranchAddress("Muon_vz", Muon_vz, &b_Muon_vz);
   fChain->SetBranchAddress("Muon_hist", Muon_hist, &b_Muon_hist);
   fChain->SetBranchAddress("Muon_IPsig", Muon_IPsig, &b_Muon_IPsig);
   fChain->SetBranchAddress("Muon_IP", Muon_IP, &b_Muon_IP);
   fChain->SetBranchAddress("Muon_IP2Dsig", Muon_IP2Dsig, &b_Muon_IP2Dsig);
   fChain->SetBranchAddress("Muon_IP2D", Muon_IP2D, &b_Muon_IP2D);
   fChain->SetBranchAddress("Muon_Proba", Muon_Proba, &b_Muon_Proba);
   fChain->SetBranchAddress("Muon_deltaR", Muon_deltaR, &b_Muon_deltaR);
   fChain->SetBranchAddress("Muon_ratio", Muon_ratio, &b_Muon_ratio);
   fChain->SetBranchAddress("nTrkInc", &nTrkInc, &b_nTrkInc);
   fChain->SetBranchAddress("TrkInc_pt", &TrkInc_pt, &b_TrkInc_pt);
   fChain->SetBranchAddress("TrkInc_eta", &TrkInc_eta, &b_TrkInc_eta);
   fChain->SetBranchAddress("TrkInc_phi", &TrkInc_phi, &b_TrkInc_phi);
   fChain->SetBranchAddress("TrkInc_ptrel", &TrkInc_ptrel, &b_TrkInc_ptrel);
   fChain->SetBranchAddress("TrkInc_IPsig", &TrkInc_IPsig, &b_TrkInc_IPsig);
   fChain->SetBranchAddress("TrkInc_IP", &TrkInc_IP, &b_TrkInc_IP);
   //fChain->SetBranchAddress("nCFromGSplit", &nCFromGSplit, &b_nCFromGSplit);
   //fChain->SetBranchAddress("cFromGSplit_pT", cFromGSplit_pT, &b_cFromGSplit_pT);
   //fChain->SetBranchAddress("cFromGSplit_eta", cFromGSplit_eta, &b_cFromGSplit_eta);
   //fChain->SetBranchAddress("cFromGSplit_phi", cFromGSplit_phi, &b_cFromGSplit_phi);
   //fChain->SetBranchAddress("nBFromGSplit", &nBFromGSplit, &b_nBFromGSplit);
   //fChain->SetBranchAddress("bFromGSplit_pT", bFromGSplit_pT, &b_bFromGSplit_pT);
   //fChain->SetBranchAddress("bFromGSplit_eta", bFromGSplit_eta, &b_bFromGSplit_eta);
   //fChain->SetBranchAddress("bFromGSplit_phi", bFromGSplit_phi, &b_bFromGSplit_phi);
   //fChain->SetBranchAddress("mcweight", &mcweight, &b_mcweight);
   fChain->SetBranchAddress("nBHadrons", &nBHadrons, &b_nBHadrons);
   fChain->SetBranchAddress("BHadron_pT", BHadron_pT, &b_BHadron_pT);
   fChain->SetBranchAddress("BHadron_eta", BHadron_eta, &b_BHadron_eta);
   fChain->SetBranchAddress("BHadron_phi", BHadron_phi, &b_BHadron_phi);
   fChain->SetBranchAddress("BHadron_mass", BHadron_mass, &b_BHadron_mass);
   fChain->SetBranchAddress("BHadron_pdgID", BHadron_pdgID, &b_BHadron_pdgID);
   fChain->SetBranchAddress("BHadron_SVx", BHadron_SVx, &b_BHadron_SVx);
   fChain->SetBranchAddress("BHadron_SVy", BHadron_SVy, &b_BHadron_SVy);
   
   
   
   Notify();
}

Bool_t HighPtStudy::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void HighPtStudy::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t HighPtStudy::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef HighPtStudy_cxx
