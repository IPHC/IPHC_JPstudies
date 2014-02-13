//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Jul  4 14:09:09 2013 by ROOT version 5.32/00
// from TTree ttree/ttree
// found on file: JetTree_mc.root
//////////////////////////////////////////////////////////

#ifndef JetProbaCalib_h
#define JetProbaCalib_h

#include "CategoryDef.h"
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <iostream>
#include <fstream>
#include <TH1.h>


// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class JetProbaCalib {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   //Int_t           nBitTrigger;
   Int_t           BitTrigger[10000];   //[nBitTrigger]
   Int_t           Run;
   Int_t           Evt;
   Int_t           LumiBlock;
   Float_t         pthat;
   Float_t         mcweight;
   Int_t           nPV;
   Float_t         PVz;
   Float_t         nPUtrue;
   Int_t           nPU;
//    Int_t           ncQuarks;
//    Float_t         cQuark_pT[10000];   //[ncQuarks]
//    Float_t         cQuark_eta[10000];   //[ncQuarks]
//    Float_t         cQuark_phi[10000];   //[ncQuarks]
//    Int_t           cQuark_pdgID[10000];   //[ncQuarks]
//    Int_t           cQuark_status[10000];   //[ncQuarks]
//    Int_t           cQuark_fromGSP[10000];   //[ncQuarks]
//    Int_t           nbQuarks;
//    Float_t         bQuark_pT[10000];   //[nbQuarks]
//    Float_t         bQuark_eta[10000];   //[nbQuarks]
//    Float_t         bQuark_phi[10000];   //[nbQuarks]
//    Int_t           bQuark_pdgID[10000];   //[nbQuarks]
//    Int_t           bQuark_status[10000];   //[nbQuarks]
//    Int_t           bQuark_fromGSP[10000];   //[nbQuarks]
//    Int_t           nBHadrons;
   Float_t         BHadron_pT[10000];   //[nBHadrons]
   Float_t         BHadron_eta[10000];   //[nBHadrons]
   Float_t         BHadron_phi[10000];   //[nBHadrons]
   Float_t         BHadron_mass[10000];   //[nBHadrons]
   Int_t           BHadron_pdgID[10000];   //[nBHadrons]
//    Int_t           BHadron_status[10000];   //[nBHadrons]
//    Int_t           BHadron_mother[10000];   //[nBHadrons]
//    Int_t           BHadron_hasBdaughter[10000];   //[nBHadrons]
//    Int_t           nGenlep;
//    Float_t         Genlep_pT[10000];   //[nGenlep]
//    Float_t         Genlep_eta[10000];   //[nGenlep]
//    Float_t         Genlep_phi[10000];   //[nGenlep]
//    Int_t           Genlep_pdgID[10000];   //[nGenlep]
//    Int_t           Genlep_status[10000];   //[nGenlep]
//    Int_t           Genlep_mother[10000];   //[nGenlep]
//    Int_t           nGenquark;
//    Float_t         Genquark_pT[10000];   //[nGenquark]
//    Float_t         Genquark_eta[10000];   //[nGenquark]
//    Float_t         Genquark_phi[10000];   //[nGenquark]
//    Int_t           Genquark_pdgID[10000];   //[nGenquark]
//    Int_t           Genquark_mother[10000];   //[nGenquark]
   Float_t         PV_x[10000];   //[nPV]
   Float_t         PV_y[10000];   //[nPV]
   Float_t         PV_z[10000];   //[nPV]
   Float_t         PV_ex[10000];   //[nPV]
   Float_t         PV_ey[10000];   //[nPV]
   Float_t         PV_ez[10000];   //[nPV]
   Float_t         PV_chi2[10000];   //[nPV]
   Float_t         PV_ndf[10000];   //[nPV]
   Int_t           PV_isgood[10000];   //[nPV]
   Int_t           PV_isfake[10000];   //[nPV]
   Int_t           nJet;
   Float_t         Jet_pt[10000];   //[nJet]
   Float_t         Jet_genpt[10000];   //[nJet]
   Float_t         Jet_residual[10000];   //[nJet]
   Float_t         Jet_jes[10000];   //[nJet]
   Float_t         Jet_eta[10000];   //[nJet]
   Float_t         Jet_phi[10000];   //[nJet]
   //Float_t         Jet_mass[10000];   //[nJet]
   Int_t           Jet_ntracks[10000];   //[nJet]
   Int_t           Jet_flavour[10000];   //[nJet]
   Float_t         Jet_Ip2N[10000];   //[nJet]
   Float_t         Jet_Ip2P[10000];   //[nJet]
   Float_t         Jet_Ip3N[10000];   //[nJet]
   Float_t         Jet_Ip3P[10000];   //[nJet]
   Float_t         Jet_ProbaN[10000];   //[nJet]
   Float_t         Jet_ProbaP[10000];   //[nJet]
   Float_t         Jet_Proba[10000];   //[nJet]
   Float_t         Jet_BprobN[10000];   //[nJet]
   Float_t         Jet_BprobP[10000];   //[nJet]
   Float_t         Jet_Bprob[10000];   //[nJet]
   Float_t         Jet_SvxN[10000];   //[nJet]
   Float_t         Jet_Svx[10000];   //[nJet]
   Float_t         Jet_SvxNHP[10000];   //[nJet]
   Float_t         Jet_SvxHP[10000];   //[nJet]
   Float_t         Jet_SvxMass[10000];   //[nJet]
   Float_t         Jet_CombSvxN[10000];   //[nJet]
   Float_t         Jet_CombSvxP[10000];   //[nJet]
   Float_t         Jet_CombSvx[10000];   //[nJet]
//    Float_t         Jet_RetCombSvxN[10000];   //[nJet]
//    Float_t         Jet_RetCombSvxP[10000];   //[nJet]
//    Float_t         Jet_RetCombSvx[10000];   //[nJet]
//    Float_t         Jet_CombCSVJP_N[10000];   //[nJet]
//    Float_t         Jet_CombCSVJP_P[10000];   //[nJet]
//    Float_t         Jet_CombCSVJP[10000];   //[nJet]
//    Float_t         Jet_CombCSVSL_N[10000];   //[nJet]
//    Float_t         Jet_CombCSVSL_P[10000];   //[nJet]
//    Float_t         Jet_CombCSVSL[10000];   //[nJet]
//    Float_t         Jet_CombCSVJPSL_N[10000];   //[nJet]
//    Float_t         Jet_CombCSVJPSL_P[10000];   //[nJet]
//    Float_t         Jet_CombCSVJPSL[10000];   //[nJet]
   Float_t         Jet_SimpIVF_HP[10000];   //[nJet]
   Float_t         Jet_SimpIVF_HE[10000];   //[nJet]
   Float_t         Jet_DoubIVF_HE[10000];   //[nJet]
   Float_t         Jet_CombIVF[10000];   //[nJet]
   Float_t         Jet_CombIVF_P[10000];   //[nJet]
//    Float_t         Jet_SoftMuN[10000];   //[nJet]
//    Float_t         Jet_SoftMuP[10000];   //[nJet]
//    Float_t         Jet_SoftMu[10000];   //[nJet]
//    Float_t         Jet_SoftElN[10000];   //[nJet]
//    Float_t         Jet_SoftElP[10000];   //[nJet]
//    Float_t         Jet_SoftEl[10000];   //[nJet]
   Int_t           Jet_hist1[10000];   //[nJet]
   Int_t           Jet_hist2[10000];   //[nJet]
   Int_t           Jet_hist3[10000];   //[nJet]
   Int_t           Jet_histJet[10000];   //[nJet]
   Int_t           Jet_histSvx[10000];   //[nJet]
   Int_t           Jet_nFirstTrack[10000];   //[nJet]
   Int_t           Jet_nLastTrack[10000];   //[nJet]
   Int_t           Jet_nFirstSV[10000];   //[nJet]
   Int_t           Jet_nLastSV[10000];   //[nJet]
   Int_t           Jet_SV_multi[10000];   //[nJet]
   Int_t           Jet_nFirstTrkInc[10000];   //[nJet]
   Int_t           Jet_nLastTrkInc[10000];   //[nJet]
//    Int_t           Jet_VtxCat[10000];   //[nJet]
//    Int_t           Jet_looseID[10000];   //[nJet]
//    Int_t           Jet_tightID[10000];   //[nJet]
   Int_t           nTrkInc;
   Float_t         TrkInc_pt[10000];   //[nTrkInc]
   Float_t         TrkInc_eta[10000];   //[nTrkInc]
   Float_t         TrkInc_phi[10000];   //[nTrkInc]
   Float_t         TrkInc_ptrel[10000];   //[nTrkInc]
   Float_t         TrkInc_IPsig[10000];   //[nTrkInc]
   Float_t         TrkInc_IP[10000];   //[nTrkInc]
   Int_t           nMuon;
   Int_t           Muon_IdxJet[10000];   //[nMuon]
   Int_t           Muon_nMuHit[10000];   //[nMuon]
   Int_t           Muon_nTkHit[10000];   //[nMuon]
   Int_t           Muon_nPixHit[10000];   //[nMuon]
   Int_t           Muon_nOutHit[10000];   //[nMuon]
   Int_t           Muon_isGlobal[10000];   //[nMuon]
   Int_t           Muon_nMatched[10000];   //[nMuon]
   Float_t         Muon_chi10000[10000];   //[nMuon]
   Float_t         Muon_chi10000Tk[10000];   //[nMuon]
   Float_t         Muon_pt[10000];   //[nMuon]
   Float_t         Muon_eta[10000];   //[nMuon]
   Float_t         Muon_phi[10000];   //[nMuon]
   Float_t         Muon_ptrel[10000];   //[nMuon]
   Float_t         Muon_vz[10000];   //[nMuon]
   Int_t           Muon_hist[10000];   //[nMuon]
   Int_t           Muon_TrackIdx[10000];   //[nMuon]
   Float_t         Muon_IPsig[10000];   //[nMuon]
   Float_t         Muon_IP[10000];   //[nMuon]
   Float_t         Muon_IP10000Dsig[10000];   //[nMuon]
   Float_t         Muon_IP10000D[10000];   //[nMuon]
   Float_t         Muon_Proba[10000];   //[nMuon]
   Float_t         Muon_deltaR[10000];   //[nMuon]
   Float_t         Muon_ratio[10000];   //[nMuon]
   Float_t         Muon_ratioRel[10000];   //[nMuon]
   Int_t           nPFElectron;
   Int_t           PFElectron_IdxJet[10000];   //[nPFElectron]
   Float_t         PFElectron_pt[10000];   //[nPFElectron]
   Float_t         PFElectron_eta[10000];   //[nPFElectron]
   Float_t         PFElectron_phi[10000];   //[nPFElectron]
   Float_t         PFElectron_ptrel[10000];   //[nPFElectron]
   Float_t         PFElectron_deltaR[10000];   //[nPFElectron]
   Float_t         PFElectron_ratio[10000];   //[nPFElectron]
   Float_t         PFElectron_ratioRel[10000];   //[nPFElectron]
   Float_t         PFElectron_IP[10000];   //[nPFElectron]
   Float_t         PFElectron_IP10000D[10000];   //[nPFElectron]
   Int_t           nPFMuon;
   Int_t           PFMuon_IdxJet[10000];   //[nPFMuon]
   Float_t         PFMuon_pt[10000];   //[nPFMuon]
   Float_t         PFMuon_eta[10000];   //[nPFMuon]
   Float_t         PFMuon_phi[10000];   //[nPFMuon]
   Float_t         PFMuon_ptrel[10000];   //[nPFMuon]
   Float_t         PFMuon_deltaR[10000];   //[nPFMuon]
   Float_t         PFMuon_ratio[10000];   //[nPFMuon]
   Float_t         PFMuon_ratioRel[10000];   //[nPFMuon]
   Float_t         PFMuon_IP[10000];   //[nPFMuon]
   Float_t         PFMuon_IP10000D[10000];   //[nPFMuon]
   Int_t           PFMuon_GoodQuality[10000];   //[nPFMuon]
   Int_t           nTrack;
   Float_t         Track_dxy[100000];   //[nTrack]
   Float_t         Track_dz[100000];   //[nTrack]
   Float_t         Track_zIP[100000];   //[nTrack]
   Float_t         Track_length[100000];   //[nTrack]
   Float_t         Track_dist[100000];   //[nTrack]
   Float_t         Track_IP2D[100000];   //[nTrack]
   Float_t         Track_IP2Dsig[100000];   //[nTrack]
   Float_t         Track_IP2Derr[100000];   //[nTrack]
   Float_t         Track_IP[100000];   //[nTrack]
   Float_t         Track_IPsig[100000];   //[nTrack]
   Float_t         Track_IPerr[100000];   //[nTrack]
   Float_t         Track_Proba[100000];   //[nTrack]
   Float_t         Track_p[100000];   //[nTrack]
   Float_t         Track_pt[100000];   //[nTrack]
   Float_t         Track_eta[100000];   //[nTrack]
   Float_t         Track_phi[100000];   //[nTrack]
   Float_t         Track_chi2[100000];   //[nTrack]
   Int_t           Track_charge[100000];   //[nTrack]
   Int_t           Track_history[100000];   //[nTrack]
   Int_t           Track_nHitStrip[100000];   //[nTrack]
   Int_t           Track_nHitPixel[100000];   //[nTrack]
   Int_t           Track_nHitAll[100000];   //[nTrack]
   Int_t           Track_nHitTIB[100000];   //[nTrack]
   Int_t           Track_nHitTID[100000];   //[nTrack]
   Int_t           Track_nHitTOB[100000];   //[nTrack]
   Int_t           Track_nHitTEC[100000];   //[nTrack]
   Int_t           Track_nHitPXB[100000];   //[nTrack]
   Int_t           Track_nHitPXF[100000];   //[nTrack]
   Int_t           Track_isHitL1[100000];   //[nTrack]
   Int_t           Track_PV[100000];   //[nTrack]
   Int_t           Track_SV[100000];   //[nTrack]
   Float_t         Track_PVweight[100000];   //[nTrack]
   Float_t         Track_SVweight[100000];   //[nTrack]
   Int_t           Track_isfromSV[100000];   //[nTrack]
   Int_t           Track_category[100000];   //[nTrack]
   Int_t           nSV;
   Float_t         SV_x[10000];   //[nSV]
   Float_t         SV_y[10000];   //[nSV]
   Float_t         SV_z[10000];   //[nSV]
   Float_t         SV_ex[10000];   //[nSV]
   Float_t         SV_ey[10000];   //[nSV]
   Float_t         SV_ez[10000];   //[nSV]
   Float_t         SV_chi2[10000];   //[nSV]
   Float_t         SV_ndf[10000];   //[nSV]
   Float_t         SV_flight[10000];   //[nSV]
   Float_t         SV_flightErr[10000];   //[nSV]
   Float_t         SV_deltaR_jet[10000];   //[nSV]
   Float_t         SV_deltaR_sum_jet[10000];   //[nSV]
   Float_t         SV_deltaR_sum_dir[10000];   //[nSV]
   Float_t         SV_energy_ratio[10000];   //[nSV]
   Float_t         SV_aboveC[10000];   //[nSV]
   Float_t         SV_vtx_pt[10000];   //[nSV]
   Float_t         SV_flight2D[10000];   //[nSV]
   Float_t         SV_flight2DErr[10000];   //[nSV]
   Float_t         SV_totCharge[10000];   //[nSV]
   Float_t         SV_vtxDistJetAxis[10000];   //[nSV]
   Int_t           SV_nTrk[10000];   //[nSV]
   Int_t           SV_nTrk_firstVxt[10000];   //[nSV]
   Float_t         SV_mass[10000];   //[nSV]
   Float_t         SV_vtx_eta[10000];   //[nSV]
   Float_t         SV_vtx_phi[10000];   //[nSV]
   
   
   int number_of_category;
   int nbins;
   float xmin;
   float xmax;
      
   // List of branches
   //TBranch        *b_nBitTrigger;   //!
   TBranch        *b_BitTrigger;   //!
   TBranch        *b_Run;   //!
   TBranch        *b_Evt;   //!
   TBranch        *b_LumiBlock;   //!
   TBranch        *b_pthat;   //!
   TBranch        *b_mcweight;   //!
   TBranch        *b_nPV;   //!
   TBranch        *b_PVz;   //!
   TBranch        *b_nPUtrue;   //!
   TBranch        *b_nPU;   //!
//    TBranch        *b_ncQuarks;   //!
//    TBranch        *b_cQuark_pT;   //!
//    TBranch        *b_cQuark_eta;   //!
//    TBranch        *b_cQuark_phi;   //!
//    TBranch        *b_cQuark_pdgID;   //!
//    TBranch        *b_cQuark_status;   //!
//    TBranch        *b_cQuark_fromGSP;   //!
//    TBranch        *b_nbQuarks;   //!
//    TBranch        *b_bQuark_pT;   //!
//    TBranch        *b_bQuark_eta;   //!
//    TBranch        *b_bQuark_phi;   //!
//    TBranch        *b_bQuark_pdgID;   //!
//    TBranch        *b_bQuark_status;   //!
//    TBranch        *b_bQuark_fromGSP;   //!
//    TBranch        *b_nBHadrons;   //!
   TBranch        *b_BHadron_pT;   //!
   TBranch        *b_BHadron_eta;   //!
   TBranch        *b_BHadron_phi;   //!
   TBranch        *b_BHadron_mass;   //!
   TBranch        *b_BHadron_pdgID;   //!
//    TBranch        *b_BHadron_status;   //!
//    TBranch        *b_BHadron_mother;   //!
//    TBranch        *b_BHadron_hasBdaughter;   //!
//    TBranch        *b_nGenlep;   //!
//    TBranch        *b_Genlep_pT;   //!
//    TBranch        *b_Genlep_eta;   //!
//    TBranch        *b_Genlep_phi;   //!
//    TBranch        *b_Genlep_pdgID;   //!
//    TBranch        *b_Genlep_status;   //!
//    TBranch        *b_Genlep_mother;   //!
//    TBranch        *b_nGenquark;   //!
//    TBranch        *b_Genquark_pT;   //!
//    TBranch        *b_Genquark_eta;   //!
//    TBranch        *b_Genquark_phi;   //!
//    TBranch        *b_Genquark_pdgID;   //!
//    TBranch        *b_Genquark_mother;   //!
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
   TBranch        *b_nJet;   //!
   TBranch        *b_Jet_pt;   //!
   TBranch        *b_Jet_genpt;   //!
   TBranch        *b_Jet_residual;   //!
   TBranch        *b_Jet_jes;   //!
   TBranch        *b_Jet_eta;   //!
   TBranch        *b_Jet_phi;   //!
   //TBranch        *b_Jet_mass;   //!
   TBranch        *b_Jet_ntracks;   //!
   TBranch        *b_Jet_flavour;   //!
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
//    TBranch        *b_Jet_RetCombSvxN;   //!
//    TBranch        *b_Jet_RetCombSvxP;   //!
//    TBranch        *b_Jet_RetCombSvx;   //!
//    TBranch        *b_Jet_CombCSVJP_N;   //!
//    TBranch        *b_Jet_CombCSVJP_P;   //!
//    TBranch        *b_Jet_CombCSVJP;   //!
//    TBranch        *b_Jet_CombCSVSL_N;   //!
//    TBranch        *b_Jet_CombCSVSL_P;   //!
//    TBranch        *b_Jet_CombCSVSL;   //!
//    TBranch        *b_Jet_CombCSVJPSL_N;   //!
//    TBranch        *b_Jet_CombCSVJPSL_P;   //!
//    TBranch        *b_Jet_CombCSVJPSL;   //!
   TBranch        *b_Jet_SimpIVF_HP;   //!
   TBranch        *b_Jet_SimpIVF_HE;   //!
   TBranch        *b_Jet_DoubIVF_HE;   //!
   TBranch        *b_Jet_CombIVF;   //!
   TBranch        *b_Jet_CombIVF_P;   //!
//    TBranch        *b_Jet_SoftMuN;   //!
//    TBranch        *b_Jet_SoftMuP;   //!
//    TBranch        *b_Jet_SoftMu;   //!
//    TBranch        *b_Jet_SoftElN;   //!
//    TBranch        *b_Jet_SoftElP;   //!
//    TBranch        *b_Jet_SoftEl;   //!
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
//    TBranch        *b_Jet_VtxCat;   //!
//    TBranch        *b_Jet_looseID;   //!
//    TBranch        *b_Jet_tightID;   //!
   TBranch        *b_nTrkInc;   //!
   TBranch        *b_TrkInc_pt;   //!
   TBranch        *b_TrkInc_eta;   //!
   TBranch        *b_TrkInc_phi;   //!
   TBranch        *b_TrkInc_ptrel;   //!
   TBranch        *b_TrkInc_IPsig;   //!
   TBranch        *b_TrkInc_IP;   //!
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
   TBranch        *b_Muon_TrackIdx;   //!
   TBranch        *b_Muon_IPsig;   //!
   TBranch        *b_Muon_IP;   //!
   TBranch        *b_Muon_IP2Dsig;   //!
   TBranch        *b_Muon_IP2D;   //!
   TBranch        *b_Muon_Proba;   //!
   TBranch        *b_Muon_deltaR;   //!
   TBranch        *b_Muon_ratio;   //!
   TBranch        *b_Muon_ratioRel;   //!
   TBranch        *b_nPFElectron;   //!
   TBranch        *b_PFElectron_IdxJet;   //!
   TBranch        *b_PFElectron_pt;   //!
   TBranch        *b_PFElectron_eta;   //!
   TBranch        *b_PFElectron_phi;   //!
   TBranch        *b_PFElectron_ptrel;   //!
   TBranch        *b_PFElectron_deltaR;   //!
   TBranch        *b_PFElectron_ratio;   //!
   TBranch        *b_PFElectron_ratioRel;   //!
   TBranch        *b_PFElectron_IP;   //!
   TBranch        *b_PFElectron_IP2D;   //!
   TBranch        *b_nPFMuon;   //!
   TBranch        *b_PFMuon_IdxJet;   //!
   TBranch        *b_PFMuon_pt;   //!
   TBranch        *b_PFMuon_eta;   //!
   TBranch        *b_PFMuon_phi;   //!
   TBranch        *b_PFMuon_ptrel;   //!
   TBranch        *b_PFMuon_deltaR;   //!
   TBranch        *b_PFMuon_ratio;   //!
   TBranch        *b_PFMuon_ratioRel;   //!
   TBranch        *b_PFMuon_IP;   //!
   TBranch        *b_PFMuon_IP2D;   //!
   TBranch        *b_PFMuon_GoodQuality;   //!
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

   JetProbaCalib(TTree *tree=0);
   virtual ~JetProbaCalib();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(int choice);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
   
   
   
   virtual double                    jetProbability( std::vector<double>  v) ;
   //virtual double                    JetProbability(std::vector<double>  vectTrk );
   virtual std::vector<TH1D* >       GetCategories(const char* fileInPutName);
   virtual bool                      IsInCategory(float trkEta, float trkHTrk, float trkHPix, float trkp, float trkChi2, CategoryDef d);
   virtual void                      ComputeProba(const char*fileInPutName);
   virtual std::vector<CategoryDef > DefCategories();
   virtual double                    calculTrackProba(float p, float eta,int nhit, int npix, float chi,float ipsig,std::vector<TH1D*> vectHis, std::vector<TH1D*> vectTrkP,std::vector<CategoryDef> vectHisCat);
   virtual bool                      passTrackSel(int trk, int pix, float ip2d, float pt, float len, float chi2, float zip, float dist, float eta, float etaJet, float phi, float phiJet, float ptJet);
   virtual void                      rootxmlLast_newFormat();
   virtual void                      rootxmlFirst_newFormat();
   virtual void                      rootxml_newFormat( CategoryDef cat ); 
   virtual void                      plotPerf();



};

#endif

#ifdef JetProbaCalib_cxx
JetProbaCalib::JetProbaCalib(TTree *tree) : fChain(0) 
{
// // if parameter tree is not specified (or zero), connect the file
// // used to generate this class and read the Tree.
//    if (tree == 0) {
//       TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject(".root");
//       if (!f || !f->IsOpen()) {
//          f = new TFile("TrackTree_mc_8_1_AL0.root");
//       }
//       TDirectory * dir = (TDirectory*)f->Get(".root:/btagana");
//       dir->GetObject("ttree",tree);
// 
//    }   
   
   TChain *superTree = new TChain("btagana/ttree");
   // Data
   
   //superTree->Add("/opt/sbg/data/data2/cms/cbeluffi/BTag_2013_06_24/DataLegacy/BTagAna/CMSSW_5_3_11_patch5/src/RecoBTag/PerformanceMeasurements/test/mc_calib_confirm2/JetTree_*.root");

   //superTree->Add("/home/fynu/cbeluffi/scratch/CMSSW_5_3_11_patch5/src/RecoBTag/PerformanceMeasurements/test/RelValQCD_Pt_80_120_CMSSW_5_3_11_JPCalib_01Jul2013_testCalib_final1/JetTree_mc_*.root");
   superTree->Add("JetTree_mc.root");
   //superTree->Add("/opt/sbg/cms/ui8_data1/ccollard/BTAG/MC_Dan_2013April/PythiaMuEnrichedQCD/QCD_Pt-170to300_MuEnrichedPt5_8TeV_pythia6_Summer12_DR53X-PU_S10_AODSIM/TrackTree_*.root");
   //superTree->Add("/opt/sbg/cms/ui8_data1/ccollard/BTAG/MC_Dan_2013April/PythiaQCD/QCD_Pt-30to50_Inclusive_8TeV_pythia6_Summer12_DR53X-PU_S10_AODSIM/TrackTree_*.root");
   //superTree->Add("/opt/sbg/cms/ui8_data1/ccollard/BTAG/MC_Dan_2013April/PythiaQCD/QCD_Pt-50to80_Inclusive_8TeV_pythia6_Summer12_DR53X-PU_S10_AODSIM/TrackTree_*.root");
   //superTree->Add("/opt/sbg/cms/ui8_data1/ccollard/BTAG/MC_Dan_2013April/PythiaQCD/QCD_Pt-80to120_Inclusive_8TeV_pythia6_Summer12_DR53X-PU_S10_AODSIM/TrackTree_*.root");
   //superTree->Add("/opt/sbg/cms/ui8_data2/ccollard/BTAG/MC_Dan_2013April/PythiaQCD/QCD_Pt-120to170_Inclusive_8TeV_pythia6_Summer12_DR53X-PU_S10_AODSIM/TrackTree_*.root");
   //superTree->Add("/opt/sbg/cms/ui8_data2/ccollard/BTAG/MC_Dan_2013April/PythiaQCD/QCD_Pt-170to300_Inclusive_8TeV_pythia6_Summer12_DR53X-PU_S10_AODSIM/TrackTree_*.root");
   //superTree->Add("/opt/sbg/cms/ui8_data1/ccollard/BTAG/MC_Dan_2013April/PythiaQCD/QCD_Pt-300to470_Inclusive_8TeV_pythia6_Summer12_DR53X-PU_S10_AODSIM/TrackTree_*.root");
   //superTree->Add("/opt/sbg/cms/ui8_data1/ccollard/BTAG/MC_Dan_2013April/PythiaQCD/QCD_Pt-470to600_Inclusive_8TeV_pythia6_Summer12_DR53X-PU_S10_AODSIM/TrackTree_*.root");
   //superTree->Add("/opt/sbg/cms/ui8_data2/ccollard/BTAG/MC_Dan_2013April/PythiaQCD/QCD_Pt-600to800_Inclusive_8TeV_pythia6_Summer12_DR53X-PU_S10_AODSIM/TrackTree_*.root");
   //superTree->Add("/opt/sbg/cms/ui8_data2/ccollard/BTAG/MC_Dan_2013April/PythiaQCD/QCD_Pt-800to1000_Inclusive_8TeV_pythia6_Summer12_DR53X-PU_S10_AODSIM/TrackTree_*.root");

   Init(superTree);
}

JetProbaCalib::~JetProbaCalib()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t JetProbaCalib::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t JetProbaCalib::LoadTree(Long64_t entry)
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

void JetProbaCalib::Init(TTree *tree)
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

   //fChain->SetBranchAddress("nBitTrigger", &nBitTrigger, &b_nBitTrigger);
   fChain->SetBranchAddress("BitTrigger", BitTrigger, &b_BitTrigger);
   fChain->SetBranchAddress("Run", &Run, &b_Run);
   fChain->SetBranchAddress("Evt", &Evt, &b_Evt);
   fChain->SetBranchAddress("LumiBlock", &LumiBlock, &b_LumiBlock);
   fChain->SetBranchAddress("pthat", &pthat, &b_pthat);
   fChain->SetBranchAddress("mcweight", &mcweight, &b_mcweight);
   fChain->SetBranchAddress("nPV", &nPV, &b_nPV);
   fChain->SetBranchAddress("PVz", &PVz, &b_PVz);
   fChain->SetBranchAddress("nPUtrue", &nPUtrue, &b_nPUtrue);
   fChain->SetBranchAddress("nPU", &nPU, &b_nPU);
 //   fChain->SetBranchAddress("ncQuarks", &ncQuarks, &b_ncQuarks);
//    fChain->SetBranchAddress("cQuark_pT", cQuark_pT, &b_cQuark_pT);
//    fChain->SetBranchAddress("cQuark_eta", cQuark_eta, &b_cQuark_eta);
//    fChain->SetBranchAddress("cQuark_phi", cQuark_phi, &b_cQuark_phi);
//    fChain->SetBranchAddress("cQuark_pdgID", cQuark_pdgID, &b_cQuark_pdgID);
//    fChain->SetBranchAddress("cQuark_status", cQuark_status, &b_cQuark_status);
//    fChain->SetBranchAddress("cQuark_fromGSP", cQuark_fromGSP, &b_cQuark_fromGSP);
//    fChain->SetBranchAddress("nbQuarks", &nbQuarks, &b_nbQuarks);
//    fChain->SetBranchAddress("bQuark_pT", bQuark_pT, &b_bQuark_pT);
//    fChain->SetBranchAddress("bQuark_eta", bQuark_eta, &b_bQuark_eta);
//    fChain->SetBranchAddress("bQuark_phi", bQuark_phi, &b_bQuark_phi);
//    fChain->SetBranchAddress("bQuark_pdgID", bQuark_pdgID, &b_bQuark_pdgID);
//    fChain->SetBranchAddress("bQuark_status", bQuark_status, &b_bQuark_status);
//    fChain->SetBranchAddress("bQuark_fromGSP", bQuark_fromGSP, &b_bQuark_fromGSP);
//    fChain->SetBranchAddress("nBHadrons", &nBHadrons, &b_nBHadrons);
   fChain->SetBranchAddress("BHadron_pT", BHadron_pT, &b_BHadron_pT);
   fChain->SetBranchAddress("BHadron_eta", BHadron_eta, &b_BHadron_eta);
   fChain->SetBranchAddress("BHadron_phi", BHadron_phi, &b_BHadron_phi);
   fChain->SetBranchAddress("BHadron_mass", BHadron_mass, &b_BHadron_mass);
   fChain->SetBranchAddress("BHadron_pdgID", BHadron_pdgID, &b_BHadron_pdgID);
//    fChain->SetBranchAddress("BHadron_status", BHadron_status, &b_BHadron_status);
//    fChain->SetBranchAddress("BHadron_mother", BHadron_mother, &b_BHadron_mother);
//    fChain->SetBranchAddress("BHadron_hasBdaughter", BHadron_hasBdaughter, &b_BHadron_hasBdaughter);
//    fChain->SetBranchAddress("nGenlep", &nGenlep, &b_nGenlep);
//    fChain->SetBranchAddress("Genlep_pT", Genlep_pT, &b_Genlep_pT);
//    fChain->SetBranchAddress("Genlep_eta", Genlep_eta, &b_Genlep_eta);
//    fChain->SetBranchAddress("Genlep_phi", Genlep_phi, &b_Genlep_phi);
//    fChain->SetBranchAddress("Genlep_pdgID", Genlep_pdgID, &b_Genlep_pdgID);
//    fChain->SetBranchAddress("Genlep_status", Genlep_status, &b_Genlep_status);
//    fChain->SetBranchAddress("Genlep_mother", Genlep_mother, &b_Genlep_mother);
//    fChain->SetBranchAddress("nGenquark", &nGenquark, &b_nGenquark);
//    fChain->SetBranchAddress("Genquark_pT", Genquark_pT, &b_Genquark_pT);
//    fChain->SetBranchAddress("Genquark_eta", Genquark_eta, &b_Genquark_eta);
//    fChain->SetBranchAddress("Genquark_phi", Genquark_phi, &b_Genquark_phi);
//    fChain->SetBranchAddress("Genquark_pdgID", Genquark_pdgID, &b_Genquark_pdgID);
//    fChain->SetBranchAddress("Genquark_mother", Genquark_mother, &b_Genquark_mother);
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
   fChain->SetBranchAddress("nJet", &nJet, &b_nJet);
   fChain->SetBranchAddress("Jet_pt", Jet_pt, &b_Jet_pt);
   fChain->SetBranchAddress("Jet_genpt", Jet_genpt, &b_Jet_genpt);
   fChain->SetBranchAddress("Jet_residual", Jet_residual, &b_Jet_residual);
   fChain->SetBranchAddress("Jet_jes", Jet_jes, &b_Jet_jes);
   fChain->SetBranchAddress("Jet_eta", Jet_eta, &b_Jet_eta);
   fChain->SetBranchAddress("Jet_phi", Jet_phi, &b_Jet_phi);
   //fChain->SetBranchAddress("Jet_mass", Jet_mass, &b_Jet_mass);
   fChain->SetBranchAddress("Jet_ntracks", Jet_ntracks, &b_Jet_ntracks);
   fChain->SetBranchAddress("Jet_flavour", Jet_flavour, &b_Jet_flavour);
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
   fChain->SetBranchAddress("Jet_SvxMass", Jet_SvxMass, &b_Jet_SvxMass);
   fChain->SetBranchAddress("Jet_CombSvxN", Jet_CombSvxN, &b_Jet_CombSvxN);
   fChain->SetBranchAddress("Jet_CombSvxP", Jet_CombSvxP, &b_Jet_CombSvxP);
   fChain->SetBranchAddress("Jet_CombSvx", Jet_CombSvx, &b_Jet_CombSvx);
//    fChain->SetBranchAddress("Jet_RetCombSvxN", Jet_RetCombSvxN, &b_Jet_RetCombSvxN);
//    fChain->SetBranchAddress("Jet_RetCombSvxP", Jet_RetCombSvxP, &b_Jet_RetCombSvxP);
//    fChain->SetBranchAddress("Jet_RetCombSvx", Jet_RetCombSvx, &b_Jet_RetCombSvx);
//    fChain->SetBranchAddress("Jet_CombCSVJP_N", Jet_CombCSVJP_N, &b_Jet_CombCSVJP_N);
//    fChain->SetBranchAddress("Jet_CombCSVJP_P", Jet_CombCSVJP_P, &b_Jet_CombCSVJP_P);
//    fChain->SetBranchAddress("Jet_CombCSVJP", Jet_CombCSVJP, &b_Jet_CombCSVJP);
//    fChain->SetBranchAddress("Jet_CombCSVSL_N", Jet_CombCSVSL_N, &b_Jet_CombCSVSL_N);
//    fChain->SetBranchAddress("Jet_CombCSVSL_P", Jet_CombCSVSL_P, &b_Jet_CombCSVSL_P);
//    fChain->SetBranchAddress("Jet_CombCSVSL", Jet_CombCSVSL, &b_Jet_CombCSVSL);
//    fChain->SetBranchAddress("Jet_CombCSVJPSL_N", Jet_CombCSVJPSL_N, &b_Jet_CombCSVJPSL_N);
//    fChain->SetBranchAddress("Jet_CombCSVJPSL_P", Jet_CombCSVJPSL_P, &b_Jet_CombCSVJPSL_P);
//    fChain->SetBranchAddress("Jet_CombCSVJPSL", Jet_CombCSVJPSL, &b_Jet_CombCSVJPSL);
   fChain->SetBranchAddress("Jet_SimpIVF_HP", Jet_SimpIVF_HP, &b_Jet_SimpIVF_HP);
   fChain->SetBranchAddress("Jet_SimpIVF_HE", Jet_SimpIVF_HE, &b_Jet_SimpIVF_HE);
   fChain->SetBranchAddress("Jet_DoubIVF_HE", Jet_DoubIVF_HE, &b_Jet_DoubIVF_HE);
   fChain->SetBranchAddress("Jet_CombIVF", Jet_CombIVF, &b_Jet_CombIVF);
   fChain->SetBranchAddress("Jet_CombIVF_P", Jet_CombIVF_P, &b_Jet_CombIVF_P);
//    fChain->SetBranchAddress("Jet_SoftMuN", Jet_SoftMuN, &b_Jet_SoftMuN);
//    fChain->SetBranchAddress("Jet_SoftMuP", Jet_SoftMuP, &b_Jet_SoftMuP);
//    fChain->SetBranchAddress("Jet_SoftMu", Jet_SoftMu, &b_Jet_SoftMu);
//    fChain->SetBranchAddress("Jet_SoftElN", Jet_SoftElN, &b_Jet_SoftElN);
//    fChain->SetBranchAddress("Jet_SoftElP", Jet_SoftElP, &b_Jet_SoftElP);
//    fChain->SetBranchAddress("Jet_SoftEl", Jet_SoftEl, &b_Jet_SoftEl);
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
//    fChain->SetBranchAddress("Jet_VtxCat", Jet_VtxCat, &b_Jet_VtxCat);
//    fChain->SetBranchAddress("Jet_looseID", Jet_looseID, &b_Jet_looseID);
//    fChain->SetBranchAddress("Jet_tightID", Jet_tightID, &b_Jet_tightID);
   fChain->SetBranchAddress("nTrkInc", &nTrkInc, &b_nTrkInc);
   fChain->SetBranchAddress("TrkInc_pt", TrkInc_pt, &b_TrkInc_pt);
   fChain->SetBranchAddress("TrkInc_eta", TrkInc_eta, &b_TrkInc_eta);
   fChain->SetBranchAddress("TrkInc_phi", TrkInc_phi, &b_TrkInc_phi);
   fChain->SetBranchAddress("TrkInc_ptrel", TrkInc_ptrel, &b_TrkInc_ptrel);
   fChain->SetBranchAddress("TrkInc_IPsig", TrkInc_IPsig, &b_TrkInc_IPsig);
   fChain->SetBranchAddress("TrkInc_IP", TrkInc_IP, &b_TrkInc_IP);
   fChain->SetBranchAddress("nMuon", &nMuon, &b_nMuon);
//    fChain->SetBranchAddress("Muon_IdxJet", Muon_IdxJet, &b_Muon_IdxJet);
//    fChain->SetBranchAddress("Muon_nMuHit", Muon_nMuHit, &b_Muon_nMuHit);
//    fChain->SetBranchAddress("Muon_nTkHit", Muon_nTkHit, &b_Muon_nTkHit);
//    fChain->SetBranchAddress("Muon_nPixHit", Muon_nPixHit, &b_Muon_nPixHit);
//    fChain->SetBranchAddress("Muon_nOutHit", Muon_nOutHit, &b_Muon_nOutHit);
//    fChain->SetBranchAddress("Muon_isGlobal", Muon_isGlobal, &b_Muon_isGlobal);
//    fChain->SetBranchAddress("Muon_nMatched", Muon_nMatched, &b_Muon_nMatched);
//    fChain->SetBranchAddress("Muon_chi2", Muon_chi2, &b_Muon_chi2);
//    fChain->SetBranchAddress("Muon_chi2Tk", Muon_chi2Tk, &b_Muon_chi2Tk);
//    fChain->SetBranchAddress("Muon_pt", Muon_pt, &b_Muon_pt);
//    fChain->SetBranchAddress("Muon_eta", Muon_eta, &b_Muon_eta);
//    fChain->SetBranchAddress("Muon_phi", Muon_phi, &b_Muon_phi);
//    fChain->SetBranchAddress("Muon_ptrel", Muon_ptrel, &b_Muon_ptrel);
//    fChain->SetBranchAddress("Muon_vz", Muon_vz, &b_Muon_vz);
//    fChain->SetBranchAddress("Muon_hist", Muon_hist, &b_Muon_hist);
//    fChain->SetBranchAddress("Muon_TrackIdx", Muon_TrackIdx, &b_Muon_TrackIdx);
//    fChain->SetBranchAddress("Muon_IPsig", Muon_IPsig, &b_Muon_IPsig);
//    fChain->SetBranchAddress("Muon_IP", Muon_IP, &b_Muon_IP);
//    fChain->SetBranchAddress("Muon_IP2Dsig", Muon_IP2Dsig, &b_Muon_IP2Dsig);
//    fChain->SetBranchAddress("Muon_IP2D", Muon_IP2D, &b_Muon_IP2D);
//    fChain->SetBranchAddress("Muon_Proba", Muon_Proba, &b_Muon_Proba);
//    fChain->SetBranchAddress("Muon_deltaR", Muon_deltaR, &b_Muon_deltaR);
//    fChain->SetBranchAddress("Muon_ratio", Muon_ratio, &b_Muon_ratio);
//    fChain->SetBranchAddress("Muon_ratioRel", Muon_ratioRel, &b_Muon_ratioRel);
//    fChain->SetBranchAddress("nPFElectron", &nPFElectron, &b_nPFElectron);
//    fChain->SetBranchAddress("PFElectron_IdxJet", PFElectron_IdxJet, &b_PFElectron_IdxJet);
//    fChain->SetBranchAddress("PFElectron_pt", PFElectron_pt, &b_PFElectron_pt);
//    fChain->SetBranchAddress("PFElectron_eta", PFElectron_eta, &b_PFElectron_eta);
//    fChain->SetBranchAddress("PFElectron_phi", PFElectron_phi, &b_PFElectron_phi);
//    fChain->SetBranchAddress("PFElectron_ptrel", PFElectron_ptrel, &b_PFElectron_ptrel);
//    fChain->SetBranchAddress("PFElectron_deltaR", PFElectron_deltaR, &b_PFElectron_deltaR);
//    fChain->SetBranchAddress("PFElectron_ratio", PFElectron_ratio, &b_PFElectron_ratio);
//    fChain->SetBranchAddress("PFElectron_ratioRel", PFElectron_ratioRel, &b_PFElectron_ratioRel);
//    fChain->SetBranchAddress("PFElectron_IP", PFElectron_IP, &b_PFElectron_IP);
//    fChain->SetBranchAddress("PFElectron_IP2D", PFElectron_IP2D, &b_PFElectron_IP2D);
//    fChain->SetBranchAddress("nPFMuon", &nPFMuon, &b_nPFMuon);
//    fChain->SetBranchAddress("PFMuon_IdxJet", PFMuon_IdxJet, &b_PFMuon_IdxJet);
//    fChain->SetBranchAddress("PFMuon_pt", PFMuon_pt, &b_PFMuon_pt);
//    fChain->SetBranchAddress("PFMuon_eta", PFMuon_eta, &b_PFMuon_eta);
//    fChain->SetBranchAddress("PFMuon_phi", PFMuon_phi, &b_PFMuon_phi);
//    fChain->SetBranchAddress("PFMuon_ptrel", PFMuon_ptrel, &b_PFMuon_ptrel);
//    fChain->SetBranchAddress("PFMuon_deltaR", PFMuon_deltaR, &b_PFMuon_deltaR);
//    fChain->SetBranchAddress("PFMuon_ratio", PFMuon_ratio, &b_PFMuon_ratio);
//    fChain->SetBranchAddress("PFMuon_ratioRel", PFMuon_ratioRel, &b_PFMuon_ratioRel);
//    fChain->SetBranchAddress("PFMuon_IP", PFMuon_IP, &b_PFMuon_IP);
//    fChain->SetBranchAddress("PFMuon_IP2D", PFMuon_IP2D, &b_PFMuon_IP2D);
//    fChain->SetBranchAddress("PFMuon_GoodQuality", PFMuon_GoodQuality, &b_PFMuon_GoodQuality);
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
   Notify();
   
}

Bool_t JetProbaCalib::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void JetProbaCalib::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t JetProbaCalib::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef JetProbaCalib_cxx
