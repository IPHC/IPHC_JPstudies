#include "TString.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TH3F.h"
#include "TStyle.h"
#include "TFile.h"
#include "TLegend.h"
#include "TLatex.h"
#include "TCanvas.h"
#include "TGraphErrors.h"
#include "THStack.h"
#include <iostream>
#include "TF1.h"



Int_t stati=0;
Bool_t  fit=1;
Bool_t logy=0;

bool setlogy = 0;

//-------------------------------------------------------------------------------------
//b-tagging efficiencies for light c and b (loose WP jet proba) as a function of jet pT
//-------------------------------------------------------------------------------------

void DoPlots_eff(TString histoname, TString filename){
 
   

  // Change for log plots:
  gStyle->SetOptLogx(0);
  gStyle->SetOptLogy(0);
  gStyle->SetOptLogz(0);
  gStyle->SetOptFit(0);
  gStyle->SetOptFile(0);
  gStyle->SetOptStat(0); // To display the mean and RMS:   SetOptStat("mr");
  gStyle->SetStatColor(0); // kWhite

  gStyle->SetOptTitle(0);
  gStyle->SetTitleFont(42);
  gStyle->SetTitleColor(1);
  gStyle->SetTitleTextColor(1);
  gStyle->SetTitleFillColor(10);
  gStyle->SetTitleFontSize(0.05);

  TCanvas *c1 = new TCanvas("c1","c1", 1000, 800);
  c1->SetLogy(setlogy);
  c1->cd();
  
   TFile * filechannel = new TFile( filename.Data());
  
  
   TH2F * jetPt_vs_JetProba_bjets = (TH2F*)filechannel->Get( (histoname+"_bjets").Data() );
   TH2F * jetPt_vs_JetProba_cjets = (TH2F*)filechannel->Get( (histoname+"_cjets").Data()) ;
   TH2F * jetPt_vs_JetProba_ljets = (TH2F*)filechannel->Get( (histoname+"_ljets").Data() );
   
   if(histoname == "jetPt_vs_SoftMu"){
     jetPt_vs_JetProba_bjets->Rebin2D(5, 1);
     jetPt_vs_JetProba_cjets->Rebin2D(5, 1);
     jetPt_vs_JetProba_ljets->Rebin2D(5, 1);
   }
   
   
   int nbinx           = jetPt_vs_JetProba_bjets->GetNbinsX();
   double low_range_x  = jetPt_vs_JetProba_bjets->GetXaxis()->GetXmin();
   double high_range_x = jetPt_vs_JetProba_bjets->GetXaxis()->GetXmax();
   
   
   int nbiny           = jetPt_vs_JetProba_bjets->GetNbinsY();
   double low_range_y  = jetPt_vs_JetProba_bjets->GetYaxis()->GetXmin();
   double high_range_y = jetPt_vs_JetProba_bjets->GetYaxis()->GetXmax();
   
   
   double x[nbinx], x_e[nbinx];
   double yb[nbinx], yb_e[nbinx];
   double yc[nbinx], yc_e[nbinx];
   double yl[nbinx], yl_e[nbinx];
   
   for(int i=0; i<nbinx; i++){
   
     x[i]   = low_range_x + i*(high_range_x - low_range_x)/nbinx;
     x_e[i] = ((high_range_x - low_range_x)/nbinx)/2;
     
     yb[i]   = 0;
     yb_e[i] = 0;
     double integral_b = 0;
     
     
     yc[i]   = 0;
     yc_e[i] = 0;
     double integral_c = 0;
     
     yl[i]   = 0;
     yl_e[i] = 0;
     double integral_l = 0;
     
     double JPcut = 0.275;
     //double JPcut = 0.790;
     
     for(int j=0; j< nbiny+1; j++){
       
       double they = low_range_y + j*(high_range_y - low_range_y)/nbiny;
       
       integral_b += jetPt_vs_JetProba_bjets->GetBinContent(i+1, j+1);
       if(they > JPcut) yb[i] += jetPt_vs_JetProba_bjets->GetBinContent(i+1, j+1);
       
       integral_c += jetPt_vs_JetProba_cjets->GetBinContent(i+1, j+1);
       if(they > JPcut) yc[i] += jetPt_vs_JetProba_cjets->GetBinContent(i+1, j+1);
       
       integral_l += jetPt_vs_JetProba_ljets->GetBinContent(i+1, j+1);
       if(they > JPcut) yl[i] += jetPt_vs_JetProba_ljets->GetBinContent(i+1, j+1);
       
     }
      
     yb_e[i] = 0.5*pow(   
     	pow(  ((integral_b+yb[i])/(integral_b*integral_b))*pow(yb[i], 0.5) , 2.)+
	pow(   (yb[i]/(integral_b*integral_b))*pow( integral_b, 0.5) , 2.)     
     , 0.5);
     yb[i]   /= integral_b;
     
     
     yc_e[i] = 0.5*pow(   
     	pow(  ((integral_c+yc[i])/(integral_c*integral_c))*pow(yc[i], 0.5) , 2.)+
	pow(   (yc[i]/(integral_c*integral_c))*pow( integral_c, 0.5) , 2.)     
     , 0.5);
     yc[i]   /= integral_c;
     
     
     yl_e[i] = 0.5*pow(   
     	pow(  ((integral_l+yl[i])/(integral_l*integral_l))*pow(yl[i], 0.5) , 2.)+
	pow(   (yl[i]/(integral_l*integral_l))*pow( integral_l, 0.5) , 2.)     
     , 0.5);
     yl[i]   /= integral_l;
     
     
     
     
     
   }
 	   
  
 

   
   TH1F * thehisto = new TH1F("thehisto", "thehisto", nbinx, low_range_x, high_range_x);
   thehisto->SetMaximum(1.1);
   thehisto->GetXaxis()->SetTitle("Jet p_{T} [GeV]");
   thehisto->GetYaxis()->SetTitle("efficiency");
   TGraphErrors * beff = new TGraphErrors(nbinx, x, yb, x_e, yb_e);
   TGraphErrors * ceff = new TGraphErrors(nbinx, x, yc, x_e, yc_e);
   TGraphErrors * leff = new TGraphErrors(nbinx, x, yl, x_e, yl_e);
   
   thehisto->Draw();
   
   beff->SetMarkerStyle(20.);
   ceff->SetMarkerStyle(20.);
   leff->SetMarkerStyle(20.);
   
   beff->SetMarkerColor(2);
   ceff->SetMarkerColor(4);
   leff->SetMarkerColor(6);
   
   beff->SetMarkerSize(1.2);
   ceff->SetMarkerSize(1.2);
   leff->SetMarkerSize(1.2);
   
   
   beff->Draw("epsame");
   ceff->Draw("epsame");
   leff->Draw("epsame");
   
   
   TLegend* qw = new TLegend(.80,.70,.95,.90);
   qw->SetShadowColor(0);
   qw->SetFillColor(0);
   qw->SetLineColor(0);
   qw->AddEntry(beff,         "b-jets" ,                "ep");
   qw->AddEntry(ceff,         "c-jets" ,                "ep");
   qw->AddEntry(leff,         "l-jets" ,                "ep");
 
   
   

}

//-------------------------------------------------------------------------------------
//b-tagging performance plot
//-------------------------------------------------------------------------------------

void DoPlots_perf(TString histoname1, TString histoname2,TString filename1, TString filename2){
 
   

  // Change for log plots:
  gStyle->SetOptLogx(0);
  gStyle->SetOptLogy(0);
  gStyle->SetOptLogz(0);
  gStyle->SetOptFit(0);
  gStyle->SetOptFile(0);
  gStyle->SetOptStat(0); // To display the mean and RMS:   SetOptStat("mr");
  gStyle->SetStatColor(0); // kWhite

  gStyle->SetOptTitle(0);
  gStyle->SetTitleFont(42);
  gStyle->SetTitleColor(1);
  gStyle->SetTitleTextColor(1);
  gStyle->SetTitleFillColor(10);
  gStyle->SetTitleFontSize(0.05);

  TCanvas *c1 = new TCanvas("c1","c1", 1000, 800);
  c1->SetLogy(setlogy);
  c1->cd();
  
   TFile * filechannel1 = new TFile( filename1.Data());
  
  
   TH1F * JetProba_bjets = (TH1F*)filechannel1->Get( (histoname1+"_bjets").Data() );
   TH1F * JetProba_cjets = (TH1F*)filechannel1->Get( (histoname1+"_cjets").Data()) ;
   TH1F * JetProba_ljets = (TH1F*)filechannel1->Get( (histoname1+"_ljets").Data() );

  
   TFile * filechannel2 = new TFile( filename2.Data());
  
   TH1F * JetProbaNew_bjets = (TH1F*)filechannel2->Get( (histoname2+"_bjets").Data() );
   TH1F * JetProbaNew_cjets = (TH1F*)filechannel2->Get( (histoname2+"_cjets").Data() );
   TH1F * JetProbaNew_ljets = (TH1F*)filechannel2->Get( (histoname2+"_ljets").Data() );
   
   
   
   
   int nbinx           = JetProba_bjets->GetNbinsX();
   double low_range_x  = JetProba_bjets->GetXaxis()->GetXmin();
   double high_range_x = JetProba_bjets->GetXaxis()->GetXmax();
   
   
   
   double x[nbinx], x_e[nbinx];
   double yc[nbinx], yc_e[nbinx];
   double yl[nbinx], yl_e[nbinx];
   
   double x_new[nbinx], x_new_e[nbinx];
   double yc_new[nbinx], yc_new_e[nbinx];
   double yl_new[nbinx], yl_new_e[nbinx];
   
   for(int i=1; i<nbinx; i++){
   
     //x[i]   = low_range_x + i*(high_range_x - low_range_x)/nbinx;
     //x_e[i] = ((high_range_x - low_range_x)/nbinx)/2;
     
     
     x[i]   = 0;
     x_e[i] = 0;
     double integral_b = 0;
     
     
     yc[i]   = 0;
     yc_e[i] = 0;
     double integral_c = 0;
     
     yl[i]   = 0;
     yl_e[i] = 0;
     double integral_l = 0;
     
     x_new[i]   = 0;
     x_new_e[i] = 0;
     double integral_new_b = 0;
     
     
     yc_new[i]   = 0;
     yc_new_e[i] = 0;
     double integral_new_c = 0;
     
     yl_new[i]   = 0;
     yl_new_e[i] = 0;
     double integral_new_l = 0;
     
     //double JPcut = 0.275;
     //double JPcut = 0.790;
     double JPcut = low_range_x + i*(high_range_x - low_range_x)/nbinx;
     
     for(int j=0; j< nbinx; j++){
       
       double they = low_range_x + j*(high_range_x - low_range_x)/nbinx;
       
       integral_b += JetProba_bjets->GetBinContent(j+1);
       if(they > JPcut) x[i] += JetProba_bjets->GetBinContent(j+1);
       
       integral_c += JetProba_cjets->GetBinContent(j+1);
       if(they > JPcut) yc[i] += JetProba_cjets->GetBinContent(j+1);
       
       integral_l += JetProba_ljets->GetBinContent(j+1);
       if(they > JPcut) yl[i] += JetProba_ljets->GetBinContent(j+1);
       
       integral_new_b += JetProbaNew_bjets->GetBinContent(j+1);
       if(they > JPcut) x_new[i] += JetProbaNew_bjets->GetBinContent(j+1);
       
       integral_new_c += JetProbaNew_cjets->GetBinContent(j+1);
       if(they > JPcut) yc_new[i] += JetProbaNew_cjets->GetBinContent(j+1);
       
       integral_new_l += JetProbaNew_ljets->GetBinContent(j+1);
       if(they > JPcut) yl_new[i] += JetProbaNew_ljets->GetBinContent(j+1);
       
     }
     x_e[i] = 0.5*pow(   
     	pow(  ((integral_b+x[i])/(integral_b*integral_b))*pow(x[i], 0.5) , 2.)+
	pow(   (x[i]/(integral_b*integral_b))*pow( integral_b, 0.5) , 2.)     
     , 0.5);
     x[i]   /= integral_b;
     
     //cout << "integral_b " << integral_b << endl;
     
     yc_e[i] = 0.5*pow(   
     	pow(  ((integral_c+yc[i])/(integral_c*integral_c))*pow(yc[i], 0.5) , 2.)+
	pow(   (yc[i]/(integral_c*integral_c))*pow( integral_c, 0.5) , 2.)     
     , 0.5);
     yc[i]   /= integral_c;
     
     
     yl_e[i] = 0.5*pow(   
     	pow(  ((integral_l+yl[i])/(integral_l*integral_l))*pow(yl[i], 0.5) , 2.)+
	pow(   (yl[i]/(integral_l*integral_l))*pow( integral_l, 0.5) , 2.)     
     , 0.5);
     yl[i]   /= integral_l;
     
     
     
     x_new_e[i] = 0.5*pow(   
     	pow(  ((integral_new_b+x_new[i])/(integral_new_b*integral_new_b))*pow(x_new[i], 0.5) , 2.)+
	pow(   (x_new[i]/(integral_new_b*integral_new_b))*pow( integral_new_b, 0.5) , 2.)     
     , 0.5);
     x_new[i]   /= integral_new_b;
     
     //cout << "integral_new_b " << integral_new_b << endl;
     
     yc_new_e[i] = 0.5*pow(   
     	pow(  ((integral_new_c+yc_new[i])/(integral_new_c*integral_new_c))*pow(yc_new[i], 0.5) , 2.)+
	pow(   (yc_new[i]/(integral_new_c*integral_new_c))*pow( integral_new_c, 0.5) , 2.)     
     , 0.5);
     yc_new[i]   /= integral_new_c;
     
     
     yl_new_e[i] = 0.5*pow(   
     	pow(  ((integral_new_l+yl_new[i])/(integral_new_l*integral_new_l))*pow(yl_new[i], 0.5) , 2.)+
	pow(   (yl_new[i]/(integral_new_l*integral_new_l))*pow( integral_new_l, 0.5) , 2.)     
     , 0.5);
     yl_new[i]   /= integral_new_l;
     
     
     
   }
 	   
  
 

   
   TH2F * thehisto = new TH2F("thehisto", "thehisto", 10000, 0, 1,  10000, 0, 1);
   thehisto->SetMaximum(1.1);
   thehisto->GetXaxis()->SetTitle("b-tagging efficiency");
   thehisto->GetYaxis()->SetTitle("mistag rate");
   TGraphErrors * ceff = new TGraphErrors(nbinx, x, yc, x_e, yc_e);
   TGraphErrors * leff = new TGraphErrors(nbinx, x, yl, x_e, yl_e);
   
   TGraphErrors * ceff_new = new TGraphErrors(nbinx, x_new, yc_new, x_new_e, yc_new_e);
   TGraphErrors * leff_new = new TGraphErrors(nbinx, x_new, yl_new, x_new_e, yl_new_e);
   
   thehisto->Draw();
   
   ceff->SetMarkerStyle(20.);
   leff->SetMarkerStyle(20.);
   
   ceff_new->SetMarkerStyle(24.);
   leff_new->SetMarkerStyle(24.);
   
   ceff->SetMarkerColor(4);
   leff->SetMarkerColor(6);
   
   ceff->SetMarkerSize(1.2);
   leff->SetMarkerSize(1.2);
   
   
   
   ceff_new->SetMarkerColor(4);
   leff_new->SetMarkerColor(6);
   
   ceff_new->SetMarkerSize(1.2);
   leff_new->SetMarkerSize(1.2);
   
   
   ceff->Draw("epsame");
   leff->Draw("epsame");
   
   
   ceff_new->Draw("epsame");
   leff_new->Draw("epsame");
   
   TLegend* qw = new TLegend(.80,.70,.95,.90);
   qw->SetShadowColor(0);
   qw->SetFillColor(0);
   qw->SetLineColor(0);
   qw->AddEntry(ceff,         "c-jets default" ,                "ep");
   qw->AddEntry(leff,         "l-jets default" ,                "ep");
 
   qw->AddEntry(ceff_new,         "c-jets re-calibrated" ,                "ep");
   qw->AddEntry(leff_new,         "l-jets re-calibrated" ,                "ep");
 
   
   

}

//---------------------------------------------------------------------
//b-tagging efficiency (loose WP jet proba) as a function of jet pT
//---------------------------------------------------------------------

void DoPlots_effQjets(TString histoname, TString filename){
 
   //jetPt_vs_JetProba_bjets_NTrack4

  // Change for log plots:
  gStyle->SetOptLogx(0);
  gStyle->SetOptLogy(0);
  gStyle->SetOptLogz(0);
  gStyle->SetOptFit(1011);
  gStyle->SetOptFile(0);
  gStyle->SetOptStat(0); // To display the mean and RMS:   SetOptStat("mr");
  gStyle->SetStatColor(0); // kWhite

  gStyle->SetOptTitle(0);
  gStyle->SetTitleFont(42);
  gStyle->SetTitleColor(1);
  gStyle->SetTitleTextColor(1);
  gStyle->SetTitleFillColor(10);
  gStyle->SetTitleFontSize(0.05);

  TCanvas *c1 = new TCanvas("c1","c1", 1000, 800);
  c1->SetLogy(setlogy);
  c1->cd();
  
   TFile * filechannel = new TFile( filename.Data());
  
  
   //TH2F * jetPt_vs_JetProba_bjets_NTrack3 = (TH2F*)filechannel->Get( (histoname+"_NTrack3").Data() );
   //TH2F * jetPt_vs_JetProba_bjets_NTrack4 = (TH2F*)filechannel->Get( (histoname+"_NTrack4").Data() );
   //TH2F * jetPt_vs_JetProba_bjets_NTrack5 = (TH2F*)filechannel->Get( (histoname+"_NTrack5").Data() );
   
   TH2F * jetPt_vs_JetProba_bjets_NTrack3 = (TH2F*)filechannel->Get( (histoname+"_NTrack3").Data() );
   TH2F * jetPt_vs_JetProba_bjets_NTrack4 = (TH2F*)filechannel->Get( (histoname+"_NTrack4").Data() );
   TH2F * jetPt_vs_JetProba_bjets_NTrack5 = (TH2F*)filechannel->Get( (histoname+"_NTrack5").Data() );
   
   
   
   jetPt_vs_JetProba_bjets_NTrack3->Rebin2D(7, 1);
   jetPt_vs_JetProba_bjets_NTrack4->Rebin2D(7, 1);
   jetPt_vs_JetProba_bjets_NTrack5->Rebin2D(7, 1);

   
   
   int nbinx           = jetPt_vs_JetProba_bjets_NTrack3->GetNbinsX();
   double low_range_x  = jetPt_vs_JetProba_bjets_NTrack3->GetXaxis()->GetXmin();
   double high_range_x = jetPt_vs_JetProba_bjets_NTrack3->GetXaxis()->GetXmax();
   
   
   int nbiny           = jetPt_vs_JetProba_bjets_NTrack3->GetNbinsY();
   double low_range_y  = jetPt_vs_JetProba_bjets_NTrack3->GetYaxis()->GetXmin();
   double high_range_y = jetPt_vs_JetProba_bjets_NTrack3->GetYaxis()->GetXmax();
   
   
   double x[nbinx], x_e[nbinx];
   double yb_NTrack3[nbinx], yb_NTrack3_e[nbinx];
   double yb_NTrack4[nbinx], yb_NTrack4_e[nbinx];
   double yb_NTrack5[nbinx], yb_NTrack5_e[nbinx];
   
   
   
   for(int i=0; i<nbinx; i++){
   
     x[i]   = low_range_x + i*(high_range_x - low_range_x)/nbinx;
     x_e[i] = ((high_range_x - low_range_x)/nbinx)/2;
     
     yb_NTrack3[i]   = 0;
     yb_NTrack3_e[i] = 0;
     
     yb_NTrack4[i]   = 0;
     yb_NTrack4_e[i] = 0;
     
     yb_NTrack5[i]   = 0;
     yb_NTrack5_e[i] = 0;
     
     double integral_b_NTrack3 = 0;
     double integral_b_NTrack4 = 0;
     double integral_b_NTrack5 = 0;
         
     for(int j=0; j< nbiny+1; j++){
       
       double they = low_range_y + j*(high_range_y - low_range_y)/nbiny;
       
       integral_b_NTrack3 += jetPt_vs_JetProba_bjets_NTrack3->GetBinContent(i+1, j+1);
       if(they > 0.275) yb_NTrack3[i] += jetPt_vs_JetProba_bjets_NTrack3->GetBinContent(i+1, j+1);
       
       integral_b_NTrack4 += jetPt_vs_JetProba_bjets_NTrack4->GetBinContent(i+1, j+1);
       if(they > 0.275) yb_NTrack4[i] += jetPt_vs_JetProba_bjets_NTrack4->GetBinContent(i+1, j+1);
       
       integral_b_NTrack5 += jetPt_vs_JetProba_bjets_NTrack5->GetBinContent(i+1, j+1);
       if(they > 0.275) yb_NTrack5[i] += jetPt_vs_JetProba_bjets_NTrack5->GetBinContent(i+1, j+1);
           
     }
      
     cout << "**********************************" << endl;
     //cout << "**********************************" << endl;
     //cout << "x[i]          " << x[i] << " \pm " << x_e[i] << endl;
     cout << "yb_NTrack3[i] " << yb_NTrack3[i] << " \pm " << yb_NTrack3_e[i] << endl;
     cout << "integral_b_NTrack3 " << integral_b_NTrack3 << endl;
     //cout << "**********************************" << endl;
     
     cout << " e1 " << ((integral_b_NTrack3+yb_NTrack3[i])/(integral_b_NTrack3*integral_b_NTrack3))*pow(yb_NTrack3[i], 0.5) << endl;
     cout << " e2 " << (yb_NTrack3[i]/(integral_b_NTrack3*integral_b_NTrack3))*pow( integral_b_NTrack3, 0.5) << endl;
     
     yb_NTrack3_e[i] = 0.5*pow(   
     	pow(  ((integral_b_NTrack3+yb_NTrack3[i])/(integral_b_NTrack3*integral_b_NTrack3))*pow(yb_NTrack3[i], 0.5) , 2.)+
	pow(   (yb_NTrack3[i]/(integral_b_NTrack3*integral_b_NTrack3))*pow( integral_b_NTrack3, 0.5) , 2.)     
     , 0.5);
     yb_NTrack3[i]   /= integral_b_NTrack3;
      
     yb_NTrack4_e[i] = 0.5*pow(   
     	pow(  ((integral_b_NTrack4+yb_NTrack4[i])/(integral_b_NTrack4*integral_b_NTrack4))*pow(yb_NTrack4[i], 0.5) , 2.)+
	pow(   (yb_NTrack4[i]/(integral_b_NTrack4*integral_b_NTrack4))*pow( integral_b_NTrack4, 0.5) , 2.)     
     , 0.5);
     yb_NTrack4[i]   /= integral_b_NTrack4;
      
     yb_NTrack5_e[i] = 0.5*pow(   
     	pow(  ((integral_b_NTrack5+yb_NTrack5[i])/(integral_b_NTrack5*integral_b_NTrack5))*pow(yb_NTrack5[i], 0.5) , 2.)+
	pow(   (yb_NTrack5[i]/(integral_b_NTrack5*integral_b_NTrack5))*pow( integral_b_NTrack5, 0.5) , 2.)     
     , 0.5);
     yb_NTrack5[i]   /= integral_b_NTrack5;
     
       
     cout << "x[i]          " << x[i] << " \pm " << x_e[i] << endl;
     cout << "yb_NTrack5[i] " << yb_NTrack5[i] << " \pm " << yb_NTrack5_e[i] << endl;
     cout << "nbinx " << nbinx << "  i " << i << endl;
   }
   
   TH1F * thehisto = new TH1F("thehisto", "thehisto", nbinx, low_range_x, high_range_x);
   thehisto->SetMaximum(1.1);
   thehisto->GetXaxis()->SetTitle("Jet p_{T} [GeV]");
   thehisto->GetYaxis()->SetTitle("efficiency");
   
   TGraphErrors * beff_NTrack3 = new TGraphErrors(nbinx, x, yb_NTrack3, x_e, yb_NTrack3_e);
   TGraphErrors * beff_NTrack4 = new TGraphErrors(nbinx, x, yb_NTrack4, x_e, yb_NTrack4_e);
   TGraphErrors * beff_NTrack5 = new TGraphErrors(nbinx, x, yb_NTrack5, x_e, yb_NTrack5_e);
   
   
    thehisto->Draw();
   
   beff_NTrack3->SetMarkerStyle(20.);
   beff_NTrack3->SetMarkerColor(2);
   beff_NTrack3->SetMarkerSize(1.2);
   
   beff_NTrack4->SetMarkerStyle(20.);
   beff_NTrack4->SetMarkerColor(4);
   beff_NTrack4->SetMarkerSize(1.2);
   
   beff_NTrack5->SetMarkerStyle(20.);
   beff_NTrack5->SetMarkerColor(6);
   beff_NTrack5->SetMarkerSize(1.2);
   
   
   beff_NTrack3->Draw("eplsame");
   beff_NTrack4->Draw("eplsame");
   beff_NTrack5->Draw("eplsame");
   
   /*TF1 *myfuncSM_pol_NTrack3   = new TF1("myfuncSM_pol_NTrack3", "pol3",low_range_x,high_range_x);
   myfuncSM_pol_NTrack3->SetLineColor(1);
   beff_NTrack3->Fit("myfuncSM_pol_NTrack3");
   myfuncSM_pol_NTrack3->Draw("same");
   
   
   TF1 *myfuncSM_pol_NTrack4   = new TF1("myfuncSM_pol_NTrack4", "pol3",low_range_x,high_range_x);
   myfuncSM_pol_NTrack4->SetLineColor(1);
   beff_NTrack4->Fit("myfuncSM_pol_NTrack4");
   myfuncSM_pol_NTrack4->Draw("same");
   
   TF1 *myfuncSM_pol_NTrack5   = new TF1("myfuncSM_pol_NTrack5", "pol5", low_range_x, high_range_x);
   myfuncSM_pol_NTrack5->SetLineColor(6);
   beff_NTrack5->Fit("myfuncSM_pol_NTrack5");
   myfuncSM_pol_NTrack5->Draw("same");
   */
   
      
   TLegend* qw = new TLegend(.80,.70,.95,.90);
   qw->SetShadowColor(0);
   qw->SetFillColor(0);
   qw->SetLineColor(0);
   qw->AddEntry(beff_NTrack3,         "n btrack = 3" ,                "ep");
   qw->AddEntry(beff_NTrack4,         "n btrack = 4" ,                "ep");
   qw->AddEntry(beff_NTrack5,         "n btrack = 5" ,                "ep");
   qw->Draw();
 
     

}


//---------------------------------------------------------------------
// plot of IP/sigma for different jet pT range
//---------------------------------------------------------------------

void DoPlots_comp(TString histoname, TString filename, TString xlabel){

  // Change for log plots:
  gStyle->SetOptLogx(0);
  gStyle->SetOptLogy(0);
  gStyle->SetOptLogz(0);
  gStyle->SetOptFit(1011);
  gStyle->SetOptFile(0);
  gStyle->SetOptStat(0); // To display the mean and RMS:   SetOptStat("mr");
  gStyle->SetStatColor(0); // kWhite

  gStyle->SetOptTitle(0);
  gStyle->SetTitleFont(42);
  gStyle->SetTitleColor(1);
  gStyle->SetTitleTextColor(1);
  gStyle->SetTitleFillColor(10);
  gStyle->SetTitleFontSize(0.05);

  TCanvas *c1 = new TCanvas("c1","c1", 1000, 800);
  c1->SetLogy(setlogy);
  c1->cd();
  
   TFile * filechannel = new TFile( filename.Data() );
  
  
   TH2F *jetPt_vs_TrackIPMuon_bjets  = (TH2F*)filechannel->Get( histoname.Data() );
   
   int nbinx           = jetPt_vs_TrackIPMuon_bjets->GetNbinsX();
   double low_range_x  = jetPt_vs_TrackIPMuon_bjets->GetXaxis()->GetXmin();
   double high_range_x = jetPt_vs_TrackIPMuon_bjets->GetXaxis()->GetXmax();
   
   
   int nbiny           = jetPt_vs_TrackIPMuon_bjets->GetNbinsY();
   double low_range_y  = jetPt_vs_TrackIPMuon_bjets->GetYaxis()->GetXmin();
   double high_range_y = jetPt_vs_TrackIPMuon_bjets->GetYaxis()->GetXmax();

  
  
  TH1F * histo_20_40    = new TH1F("histo_20_40",    "histo_20_40", nbiny,    low_range_y, high_range_y);
  TH1F * histo_40_60    = new TH1F("histo_40_60",    "histo_40_60", nbiny,    low_range_y, high_range_y);
  TH1F * histo_60_80    = new TH1F("histo_60_80",    "histo_60_80", nbiny,    low_range_y, high_range_y);
  TH1F * histo_80_100   = new TH1F("histo_80_100",   "histo_80_100", nbiny,   low_range_y, high_range_y);
  TH1F * histo_100_150  = new TH1F("histo_100_150",  "histo_100_150", nbiny,  low_range_y, high_range_y);
  TH1F * histo_150_300  = new TH1F("histo_150_300",  "histo_150_300", nbiny,  low_range_y, high_range_y);
  TH1F * histo_300_500  = new TH1F("histo_300_500",  "histo_300_500", nbiny,  low_range_y, high_range_y);
  TH1F * histo_500_1000 = new TH1F("histo_500_1000", "histo_500_1000", nbiny, low_range_y, high_range_y);
  
     double x[nbinx], x_e[nbinx];

  
   
  for(int i=0; i<nbinx; i++){
   
     x[i]   = low_range_x + i*(high_range_x - low_range_x)/nbinx;
     x_e[i] = (high_range_x - low_range_x)/nbinx;
     
     
     for(int j=1; j<= nbiny; j++){
       
       if(x[i] > 20. && x[i] <= 40.)    histo_20_40->SetBinContent(j,    histo_20_40->GetBinContent(j)    + jetPt_vs_TrackIPMuon_bjets->GetBinContent(i+1, j));
       if(x[i] > 40. && x[i] <= 60.)    histo_40_60->SetBinContent(j,    histo_40_60->GetBinContent(j)    + jetPt_vs_TrackIPMuon_bjets->GetBinContent(i+1, j));
       if(x[i] > 60. && x[i] <= 80.)    histo_60_80->SetBinContent(j,    histo_60_80->GetBinContent(j)    + jetPt_vs_TrackIPMuon_bjets->GetBinContent(i+1, j));
       if(x[i] > 80. && x[i] <= 100.)   histo_80_100->SetBinContent(j,   histo_80_100->GetBinContent(j)   + jetPt_vs_TrackIPMuon_bjets->GetBinContent(i+1, j));
       if(x[i] > 100. && x[i] <= 150.)  histo_100_150->SetBinContent(j,  histo_100_150->GetBinContent(j)  + jetPt_vs_TrackIPMuon_bjets->GetBinContent(i+1, j));
       if(x[i] > 150. && x[i] <= 300.)  histo_150_300->SetBinContent(j,  histo_150_300->GetBinContent(j)  + jetPt_vs_TrackIPMuon_bjets->GetBinContent(i+1, j));
       if(x[i] > 300. && x[i] <= 500.)  histo_300_500->SetBinContent(j,  histo_300_500->GetBinContent(j)  + jetPt_vs_TrackIPMuon_bjets->GetBinContent(i+1, j));
       if(x[i] > 500. && x[i] <= 1000.) histo_500_1000->SetBinContent(j, histo_500_1000->GetBinContent(j) + jetPt_vs_TrackIPMuon_bjets->GetBinContent(i+1, j));
       
     }

  }
  
  histo_20_40->SetLineColor(1);
  histo_40_60->SetLineColor(2);
  histo_60_80->SetLineColor(3);
  histo_80_100->SetLineColor(4);
  histo_100_150->SetLineColor(5);
  histo_150_300->SetLineColor(6);
  histo_300_500->SetLineColor(7);
  histo_500_1000->SetLineColor(8);
  
  
  histo_20_40->SetLineWidth(2);
  histo_40_60->SetLineWidth(2);
  histo_60_80->SetLineWidth(2);
  histo_80_100->SetLineWidth(2);
  histo_100_150->SetLineWidth(2);
  histo_150_300->SetLineWidth(2);
  histo_300_500->SetLineWidth(2);
  histo_500_1000->SetLineWidth(2);


  histo_20_40->Rebin(4);
  histo_40_60->Rebin(4);
  histo_60_80->Rebin(4);
  histo_80_100->Rebin(4);
  histo_100_150->Rebin(4);
  histo_150_300->Rebin(4);
  histo_300_500->Rebin(4);
  histo_500_1000->Rebin(4);
  
  
  histo_20_40->SetMinimum();
  
  histo_500_1000->GetXaxis()->SetTitle(xlabel);
  
  histo_500_1000->DrawNormalized();
  //histo_40_60->DrawNormalized("same");
 // histo_60_80->DrawNormalized("same");
  histo_80_100->DrawNormalized("same");
 // histo_100_150->DrawNormalized("same");
  //histo_150_300->DrawNormalized("same");
 // histo_300_500->DrawNormalized("same");
  histo_20_40->DrawNormalized("same");
  
  cout << "mean histo_20_40    " << histo_20_40->GetMean() << endl;
  cout << "mean histo_80_100   " << histo_80_100->GetMean() << endl;
  cout << "mean histo_500_1000 " << histo_500_1000->GetMean() << endl;
  
  
  TLegend* qw = new TLegend(.80,.70,.95,.90);
  qw->SetShadowColor(0);
  qw->SetFillColor(0);
  qw->SetLineColor(0);
  qw->AddEntry(histo_20_40,         " 20 <p_{T}< 40 " , "l");
  //qw->AddEntry(histo_40_60,         " 40 <p_{T}< 60 " , "l");
  //qw->AddEntry(histo_60_80,         " 60 <p_{T}< 80 " , "l");
  qw->AddEntry(histo_80_100,        " 80 <p_{T}< 100 " , "l");
  //qw->AddEntry(histo_100_150,       " 100 <p_{T}< 150 " , "l");
  //qw->AddEntry(histo_150_300,       " 150 <p_{T}< 300 " , "l");
  //qw->AddEntry(histo_300_500,       " 300 <p_{T}< 500 " , "l");
  qw->AddEntry(histo_500_1000,      " 500 <p_{T}< 1000 " , "l");
 
  qw->Draw();
  
  
  
}

//---------------------------------------------------------------------
// plot of IP/sigma for different jet pT range
//---------------------------------------------------------------------

void DoPlots_comp(int minpT, int maxpT, TString filename){

  // Change for log plots:
  gStyle->SetOptLogx(0);
  gStyle->SetOptLogy(0);
  gStyle->SetOptLogz(0);
  gStyle->SetOptFit(1011);
  gStyle->SetOptFile(0);
  gStyle->SetOptStat(0); // To display the mean and RMS:   SetOptStat("mr");
  gStyle->SetStatColor(0); // kWhite

  gStyle->SetOptTitle(0);
  gStyle->SetTitleFont(42);
  gStyle->SetTitleColor(1);
  gStyle->SetTitleTextColor(1);
  gStyle->SetTitleFillColor(10);
  gStyle->SetTitleFontSize(0.05);

  TCanvas *c1 = new TCanvas("c1","c1", 1000, 800);
  c1->SetLogy(setlogy);
  c1->cd();
  
   TFile * filechannel = new TFile( filename.Data() );
  				   
   TH2F *  jetPt_vs_TrackPtBtrack_GSplit_bjets  = (TH2F*)filechannel->Get("jetPt_vs_TrackPtBtrack_GSplit_bjets"  );
   TH2F *  jetPt_vs_TrackPtBtrack_NoGSplit_bjet = (TH2F*)filechannel->Get("jetPt_vs_TrackPtBtrack_NoGSplit_bjets"  );
   TH2F *  jetPt_vs_TrackPtLtrack_bjets         = (TH2F*)filechannel->Get("jetPt_vs_TrackPtLtrack_bjets"  );
   
   int nbinx           = jetPt_vs_TrackPtBtrack_GSplit_bjets->GetNbinsX();
   double low_range_x  = jetPt_vs_TrackPtBtrack_GSplit_bjets->GetXaxis()->GetXmin();
   double high_range_x = jetPt_vs_TrackPtBtrack_GSplit_bjets->GetXaxis()->GetXmax();
   
   
   int nbiny           = jetPt_vs_TrackPtBtrack_GSplit_bjets->GetNbinsY();
   double low_range_y  = jetPt_vs_TrackPtBtrack_GSplit_bjets->GetYaxis()->GetXmin();
   double high_range_y = jetPt_vs_TrackPtBtrack_GSplit_bjets->GetYaxis()->GetXmax();

  
  TH1F * histo_btracksGS    = new TH1F("histo_btracksGS",    "histo_btracksGS",   nbiny,   low_range_y, high_range_y);
  TH1F * histo_btracksNoGS  = new TH1F("histo_btracksNoGS",  "histo_btracksNoGS", nbiny,   low_range_y, high_range_y);
  TH1F * histo_ltracks      = new TH1F("histo_ltracks",      "histo_ltracks",     nbiny,   low_range_y, high_range_y);
  
  double x[nbinx], x_e[nbinx];

  
   
  for(int i=0; i<nbinx; i++){
   
     x[i]   = low_range_x + i*(high_range_x - low_range_x)/nbinx;
     x_e[i] = (high_range_x - low_range_x)/nbinx;
     
     
     for(int j=1; j<= nbiny; j++){
       
       if(x[i] > minpT && x[i] <= maxpT){
         histo_btracksGS->SetBinContent(j,    histo_btracksGS->GetBinContent(j)     + jetPt_vs_TrackPtBtrack_GSplit_bjets->GetBinContent(i+1, j));
         histo_btracksNoGS->SetBinContent(j,	histo_btracksNoGS->GetBinContent(j) + jetPt_vs_TrackPtBtrack_NoGSplit_bjet->GetBinContent(i+1, j));
         histo_ltracks->SetBinContent(j, histo_ltracks->GetBinContent(j)            + jetPt_vs_TrackPtLtrack_bjets->GetBinContent(i+1, j));
       }
     }

  }
  
  histo_btracksGS->SetLineColor(1);
  histo_btracksNoGS->SetLineColor(4);
  histo_ltracks->SetLineColor(8);
  
  
  histo_btracksGS->SetLineWidth(2);
  histo_btracksNoGS->SetLineWidth(2);
  histo_ltracks->SetLineWidth(2);


  //histo_btracksGS->Rebin(4);
  //histo_btracksNoGS->Rebin(4);
  //histo_ltracks->Rebin(4);
  
  
  histo_btracksGS->SetMinimum();
  histo_ltracks->GetXaxis()->SetTitle("track p_{T} [GeV]");
  histo_ltracks->GetYaxis()->SetTitle("a.u.");
  
  histo_ltracks->DrawNormalized();
  histo_btracksNoGS->DrawNormalized("same");
  histo_btracksGS->DrawNormalized("same");
  
  cout << "mean histo_btracksGS    " << histo_btracksGS->GetMean() << endl;
  cout << "mean histo_btracksNoGS   " << histo_btracksNoGS->GetMean() << endl;
  cout << "mean histo_ltracks " << histo_ltracks->GetMean() << endl;
  
  
  TLegend* qw = new TLegend(.80,.70,.95,.90);
  qw->SetShadowColor(0);
  qw->SetFillColor(0);
  qw->SetLineColor(0);
  qw->AddEntry(histo_btracksGS,    "Tracks from b hadr., Gluons Splitting " , "l");
  qw->AddEntry(histo_btracksNoGS,  "Tracks from b hadr., non Gluons Splitting  " , "l");
  qw->AddEntry(histo_ltracks,      "Tracks not from bhadr. in bjets " , "l");
 
  qw->Draw();
  
  
  
}

//---------------------------------------------------------------------
// plot multicplicity ofr tracks from b hadrons as a function of jet pT
//---------------------------------------------------------------------


void DoPlots_BtackMult(TString histoname, TString filename){

  // Change for log plots:
  gStyle->SetOptLogx(0);
  gStyle->SetOptLogy(0);
  gStyle->SetOptLogz(0);
  gStyle->SetOptFit(1011);
  gStyle->SetOptFile(0);
  gStyle->SetOptStat(0); // To display the mean and RMS:   SetOptStat("mr");
  gStyle->SetStatColor(0); // kWhite

  gStyle->SetOptTitle(0);
  gStyle->SetTitleFont(42);
  gStyle->SetTitleColor(1);
  gStyle->SetTitleTextColor(1);
  gStyle->SetTitleFillColor(10);
  gStyle->SetTitleFontSize(0.05);

  TCanvas *c1 = new TCanvas("c1","c1", 1000, 800);
  c1->SetLogy(setlogy);
  c1->cd();
  
   TFile * filechannel = new TFile( filename.Data() );
  
  
   TH2F *histo2D  = (TH2F*)filechannel->Get( histoname.Data() );
   
   int nbinx           = histo2D->GetNbinsX();
   double low_range_x  = histo2D->GetXaxis()->GetXmin();
   double high_range_x = histo2D->GetXaxis()->GetXmax();
   
   
   int nbiny           = histo2D->GetNbinsY();
   double low_range_y  = histo2D->GetYaxis()->GetXmin();
   double high_range_y = histo2D->GetYaxis()->GetXmax();

  
  
   double x[nbinx], x_e[nbinx];
   double y[nbinx], y_e[nbinx];

  
   
  for(int i=0; i<nbinx; i++){
   
     x[i]   = low_range_x + i*(high_range_x - low_range_x)/nbinx;
     x_e[i] = 0.5*(high_range_x - low_range_x)/nbinx;
     
     TH1F * temp_histo = new TH1F("temp_histo", "temp_histo", nbiny, low_range_y, high_range_y);
     
     for(int j=1; j<= nbiny; j++){
       temp_histo->SetBinContent(j, histo2D->GetBinContent(i+1, j));
     }
     
     y[i]=temp_histo->GetMean();
     y_e[i]=temp_histo->GetMeanError();
     
     delete temp_histo;
  }
  
  TH1F * thehisto = new TH1F("thehisto", "thehisto", nbinx, low_range_x, high_range_x);
  thehisto->SetMaximum(7.);
  thehisto->GetXaxis()->SetTitle("Jet p_{T} [GeV]");
  thehisto->GetYaxis()->SetTitle("mean N track");
  //thehisto->GetYaxis()->SetTitle("mean SV rho");
  TGraphErrors * ntrack = new TGraphErrors(nbinx, x, y, x_e, y_e);

  thehisto->Draw();
  ntrack->SetMarkerStyle(20);
  ntrack->SetMarkerColor(2);
  ntrack->Draw("ep");
  
  
  
  TLegend* qw = new TLegend(.80,.70,.95,.90);
  qw->SetShadowColor(0);
  qw->SetFillColor(0);
  qw->SetLineColor(0);
  //qw->AddEntry(histo_20_40,         " 20 <p_{T}< 40 " , "l");
  //  qw->Draw();
  
  
  
}


void DoPlots_Frac(TString histoname, TString filename){

  // Change for log plots:
  gStyle->SetOptLogx(0);
  gStyle->SetOptLogy(0);
  gStyle->SetOptLogz(0);
  gStyle->SetOptFit(1011);
  gStyle->SetOptFile(0);
  gStyle->SetOptStat(0); // To display the mean and RMS:   SetOptStat("mr");
  gStyle->SetStatColor(0); // kWhite

  gStyle->SetOptTitle(0);
  gStyle->SetTitleFont(42);
  gStyle->SetTitleColor(1);
  gStyle->SetTitleTextColor(1);
  gStyle->SetTitleFillColor(10);
  gStyle->SetTitleFontSize(0.05);

  TCanvas *c1 = new TCanvas("c1","c1", 1000, 800);
  c1->SetLogy(setlogy);
  c1->cd();
  
   TFile * filechannel = new TFile( filename.Data() );
  
  
   TH2F *histo2D  = (TH2F*)filechannel->Get( histoname.Data() );
   
   int nbinx           = histo2D->GetNbinsX();
   double low_range_x  = histo2D->GetXaxis()->GetXmin();
   double high_range_x = histo2D->GetXaxis()->GetXmax();
   
   
   int nbiny           = histo2D->GetNbinsY();
   double low_range_y  = histo2D->GetYaxis()->GetXmin();
   double high_range_y = histo2D->GetYaxis()->GetXmax();

  
  
   double x[nbinx], x_e[nbinx];
   double y[nbinx], y_e[nbinx];

  
   
  for(int i=0; i<nbinx; i++){
   
     x[i]   = low_range_x + i*(high_range_x - low_range_x)/nbinx;
     x_e[i] = 0.5*(high_range_x - low_range_x)/nbinx;
     
     //TH1F * temp_histo = new TH1F("temp_histo", "temp_histo", nbiny, low_range_y, high_range_y);
     double num   = 0;
     double denom = 0;
     for(int j=1; j<= nbiny; j++){
       //temp_histo->SetBinContent(j, histo2D->GetBinContent(i+1, j));
       
       double distance = low_range_y+j*(high_range_y - low_range_y)/nbiny;
       if(distance > 4.1 )num += histo2D->GetBinContent(i+1, j);
       denom+= histo2D->GetBinContent(i+1, j);
     }
     
     y[i]=num/denom;
     y_e[i] = pow(num, 0.5)/denom;
     
     
     //y[i]=temp_histo->GetMean();
     //y_e[i]=temp_histo->GetMeanError();
     
     //delete temp_histo;
  }
  
  TH1F * thehisto = new TH1F("thehisto", "thehisto", nbinx, low_range_x, high_range_x);
  thehisto->SetMaximum(0.3);
  thehisto->GetYaxis()->SetTitleOffset(1.2);
  thehisto->GetXaxis()->SetTitle("Jet p_{T} [GeV]");
  thehisto->GetYaxis()->SetTitle("fraction of b-SV with rho > 4 cm");
  //thehisto->GetYaxis()->SetTitle("mean SV rho");
  TGraphErrors * ntrack = new TGraphErrors(nbinx, x, y, x_e, y_e);

  thehisto->Draw();
  ntrack->SetMarkerStyle(20);
  ntrack->SetMarkerColor(2);
  ntrack->Draw("ep");
  
  
  
  TLegend* qw = new TLegend(.80,.70,.95,.90);
  qw->SetShadowColor(0);
  qw->SetFillColor(0);
  qw->SetLineColor(0);
  //qw->AddEntry(histo_20_40,         " 20 <p_{T}< 40 " , "l");
  //  qw->Draw();
  
  
  
}


void DoPlots_TrackSelOptimization(TString histoname, TString filename){

  // Change for log plots:
  gStyle->SetOptLogx(0);
  gStyle->SetOptLogy(0);
  gStyle->SetOptLogz(0);
  gStyle->SetOptFit(1011);
  gStyle->SetOptFile(0);
  gStyle->SetOptStat(0); // To display the mean and RMS:   SetOptStat("mr");
  gStyle->SetStatColor(0); // kWhite

  gStyle->SetOptTitle(0);
  gStyle->SetTitleFont(42);
  gStyle->SetTitleColor(1);
  gStyle->SetTitleTextColor(1);
  gStyle->SetTitleFillColor(10);
  gStyle->SetTitleFontSize(0.05);

  TCanvas *c1 = new TCanvas("c1","c1", 1000, 800);
  c1->SetLogy(setlogy);
  c1->cd();
  
  TFile * filechannel = new TFile( filename.Data() );
  
  
  TH2F *histo2D_signal  = (TH2F*)filechannel    ->Get( (histoname+"_bTracksNoGSplit_bjets").Data() );
  TH2F *histo2D_background  = (TH2F*)filechannel->Get( (histoname+"_nonbTracks_bjets").Data() );
  
  int nbinx	      = histo2D_signal->GetNbinsX();
  double low_range_x  = histo2D_signal->GetXaxis()->GetXmin();
  double high_range_x = histo2D_signal->GetXaxis()->GetXmax();
  
  
  int nbiny	      = histo2D_signal->GetNbinsY();
  double low_range_y  = histo2D_signal->GetYaxis()->GetXmin();
  double high_range_y = histo2D_signal->GetYaxis()->GetXmax();

  
  
  double x[nbinx], x_e[nbinx];
  double y[nbinx], y_e[nbinx];


  TH1F *histo1D_tmp =  new TH1F("histo1D_tmp", "histo1D_tmp", nbiny, low_range_y, high_range_y);
  
  cout << "nbiny " << nbiny << endl;
  cout << "low_range_y " << low_range_y << endl;
  cout << "high_range_y " << high_range_y << endl;
  
  for(int i=0; i<nbinx; i++){
   
     x[i]   = low_range_x + i*(high_range_x - low_range_x)/nbinx;
     x_e[i] = 0.5*(high_range_x - low_range_x)/nbinx;
     
     //  cout << "***********************" << endl;
     double significance = 0.;
     for(int j=1; j<= nbiny; j++){
     
       double signal     = histo2D_signal    ->GetBinContent(i+1, j);
       double background = histo2D_background->GetBinContent(i+1, j);
       double significance_tmp = signal/sqrt(signal+background);
       
       double term1 = sqrt(signal+background);
       double term2 = 1/(2*term1);
       double term3 = signal+background;
       
       double significance_tmp_uncert = pow(
       				pow((term1+signal*term2)/term3, 2)*signal+
       				pow(signal*term2/term3, 2)*background				
       						,0.5);
       
       //histo1D_tmp->SetBinContent(j, significance_tmp);
       //if( i==20){
         if(signal>=0 && background > 0 ) {
	   histo1D_tmp->SetBinContent(j, significance_tmp);
	   histo1D_tmp->SetBinError(j, significance_tmp_uncert);
	   
	 }
	 if(signal == 0 || background == 0){
	  histo1D_tmp->SetBinContent(j, 0);
	  histo1D_tmp->SetBinError(j, 10000);
	 }
       //}
       if(significance_tmp > significance && signal > 0 && background > 0 ){
         significance = significance_tmp;
         //y[i]   = low_range_y+j*(high_range_y - low_range_y)/nbiny;
	 //y_e[i] = y[i]+i*0.05;
         //y[i]   = 
	 //y_e[i] = 
       }
       //cout << "y[i] " << y[i] << endl;
       
     }
     //if(i==20){
       TF1 * thefit     = new TF1("theplo8",     "[0]+x*[1]+pow(x,2)*[2]+pow(x,3)*[3]+pow(x,4)*[4]+pow(x,5)*[5]+pow(x,6)*[6]+pow(x,7)*[7]+pow(x,8)*[8]");
       TF1 * thefitUp   = new TF1("theplo8Up",   "[0]+x*[1]+pow(x,2)*[2]+pow(x,3)*[3]+pow(x,4)*[4]+pow(x,5)*[5]+pow(x,6)*[6]+pow(x,7)*[7]+pow(x,8)*[8]");
       TF1 * thefitDown = new TF1("theplo8Down", "[0]+x*[1]+pow(x,2)*[2]+pow(x,3)*[3]+pow(x,4)*[4]+pow(x,5)*[5]+pow(x,6)*[6]+pow(x,7)*[7]+pow(x,8)*[8]");
       histo1D_tmp->Draw();
       histo1D_tmp->Fit("theplo8");
       if(histoname == "DeltaRScan") y[i]   = thefit->GetMaximumX(0, 0.3);
       if(histoname == "TrackPtScan") y[i]   = thefit->GetMaximumX(0, 100);
       //y[i]   = thefit->GetMaximumX(0, 0.3);
       y[i]   = thefit->GetMaximumX(0, 0.3);
       //double eval1 = fabs(thefit->Eval(  y[i]  ) + 0.00001*thefit->Eval(  y[i]  ));
       //double eval2 = fabs(thefit->Eval(  y[i]  ) - 0.00001*thefit->Eval(  y[i]  ));
       //cout << "eval1 " << eval1 << endl;
       //cout << "eval2 " << eval2 << endl;
       //cout << "y[i]  " <<  y[i] << endl;
       //cout << "thefit->GetX(eval1) " << thefit->GetX(eval1) << endl;
       //cout << "thefit->GetX(eval2) " << thefit->GetX(eval2) << endl;
       //cout << "thefit->GetX(y[i])  " << thefit->GetX(y[i]) << endl;
       
       //if(eval1>eval2) y_e[i] = thefit->GetX(eval1);
       //else y_e[i] = thefit->GetX(eval2);
      
        y_e[i] = 0.10*y[i];
       
       //thefit->Derivative2(thefit->GetMaximumX(0, 0.3));
       
       
       
       thefitUp->SetParameter(0, thefit->GetParameter(0) +   thefit->GetParError(0));
       thefitUp->SetParameter(1, thefit->GetParameter(1) +   thefit->GetParError(1));
       thefitUp->SetParameter(2, thefit->GetParameter(2) +   thefit->GetParError(2));
       thefitUp->SetParameter(3, thefit->GetParameter(3) +   thefit->GetParError(3));
       thefitUp->SetParameter(4, thefit->GetParameter(4) +   thefit->GetParError(4));
       thefitUp->SetParameter(5, thefit->GetParameter(5) +   thefit->GetParError(5));
       thefitUp->SetParameter(6, thefit->GetParameter(6) +   thefit->GetParError(6));
       thefitUp->SetParameter(7, thefit->GetParameter(7) +   thefit->GetParError(7));
       thefitUp->SetParameter(8, thefit->GetParameter(8) +   thefit->GetParError(8));
       thefitUp->SetParameter(9, thefit->GetParameter(9) +   thefit->GetParError(9));
       
       thefitDown->SetParameter(0, thefit->GetParameter(0) -   thefit->GetParError(0));
       thefitDown->SetParameter(1, thefit->GetParameter(1) -   thefit->GetParError(1));
       thefitDown->SetParameter(2, thefit->GetParameter(2) -   thefit->GetParError(2));
       thefitDown->SetParameter(3, thefit->GetParameter(3) -   thefit->GetParError(3));
       thefitDown->SetParameter(4, thefit->GetParameter(4) -   thefit->GetParError(4));
       thefitDown->SetParameter(5, thefit->GetParameter(5) -   thefit->GetParError(5));
       thefitDown->SetParameter(6, thefit->GetParameter(6) -   thefit->GetParError(6));
       thefitDown->SetParameter(7, thefit->GetParameter(7) -   thefit->GetParError(7));
       thefitDown->SetParameter(8, thefit->GetParameter(8) -   thefit->GetParError(8));
       thefitDown->SetParameter(9, thefit->GetParameter(9) -   thefit->GetParError(9));
       
       //y_e[i] = fabs(thefitUp->GetMaximumX(0, 0.3) -y[i]) ;
       //if(y_e[i] < fabs(thefitDown->GetMaximumX(0, 0.3) -y[i])) y_e[i] = fabs(thefitDown->GetMaximumX(0, 0.3) -y[i]) ;
       //y_e[i] = fabs(thefitDown->GetMaximumX(0, 0.3) -y[i]) ;
       
       //cout << "thefit->GetMaximumX(0, 0.3)  " << thefit->GetMaximumX(0, 0.3) << endl;
       //cout << "thefitUp->GetMaximumX(0, 0.3) " << thefitUp->GetMaximumX(0, 0.3)  << endl;
       //cout << "thefitDown->GetMaximumX(0, 0.3)  " << thefitDown->GetMaximumX(0, 0.3)  << endl;
       
       delete thefit;
       
     
  }

  
  
  for(int i=0; i<nbinx; i++){
    //cout << "y[" << i << "] " << y[i]  << "  +/- " << y_e[i] << endl;
    
  }

  TCanvas *c2 = new TCanvas("c2","c2", 1000, 800);
  c2->SetLogy(setlogy);
  c2->cd();

  TH1F * thehisto = new TH1F("thehisto", "thehisto", nbinx, low_range_x, high_range_x);
  thehisto->SetMaximum(0.3);
  thehisto->GetYaxis()->SetTitleOffset(1.2);
  thehisto->GetXaxis()->SetTitle("Jet p_{T} [GeV]");
  thehisto->GetYaxis()->SetTitle("optimized #Delta R");
  TGraphErrors * tgraph = new TGraphErrors(nbinx, x, y, x_e, y_e);

  thehisto->Draw();
  tgraph->SetMarkerStyle(20);
  tgraph->SetMarkerColor(2);
  tgraph->Draw("ep");
  
  
  
  TLegend* qw = new TLegend(.80,.70,.95,.90);
  qw->SetShadowColor(0);
  qw->SetFillColor(0);
  qw->SetLineColor(0);
  //qw->AddEntry(histo_20_40,         " 20 <p_{T}< 40 " , "l");
  //  qw->Draw();
  

  
  
}





void DoPlots_TrackSelOptJetProba(TString histoname, TString filename){

  // Change for log plots:
  gStyle->SetOptLogx(0);
  gStyle->SetOptLogy(0);
  gStyle->SetOptLogz(0);
  gStyle->SetOptFit(1011);
  gStyle->SetOptFile(0);
  gStyle->SetOptStat(0); // To display the mean and RMS:   SetOptStat("mr");
  gStyle->SetStatColor(0); // kWhite

  gStyle->SetOptTitle(0);
  gStyle->SetTitleFont(42);
  gStyle->SetTitleColor(1);
  gStyle->SetTitleTextColor(1);
  gStyle->SetTitleFillColor(10);
  gStyle->SetTitleFontSize(0.05);

  TCanvas *c1 = new TCanvas("c1","c1", 1000, 800);
  c1->SetLogy(setlogy);
  c1->cd();
  
  TFile * filechannel = new TFile( filename.Data() );
  
  
  //TH3F *histo3D_signal  = (TH3F*)filechannel    ->Get( (histoname+"_bTracksNoGSplit_bjets").Data() );
  //TH3F *histo3D_signal_2= (TH3F*)filechannel    ->Get( "jetPt_vs_DeltaRScan_vs_nTracks_bTracksNoGSplit_bjets" );
  TH3F *histo3D_signal      = (TH3F*)filechannel    ->Get( (histoname+"_bjets").Data() );
  TH3F *histo3D_background  = (TH3F*)filechannel    ->Get( (histoname+"_ljets").Data() );
  
  int nbinx	      = histo3D_signal->GetNbinsX();
  double low_range_x  = histo3D_signal->GetXaxis()->GetXmin();
  double high_range_x = histo3D_signal->GetXaxis()->GetXmax();
  
  
  int nbiny	      = histo3D_signal->GetNbinsY();
  double low_range_y  = histo3D_signal->GetYaxis()->GetXmin();
  double high_range_y = histo3D_signal->GetYaxis()->GetXmax();
  
  int nbinz	      = histo3D_signal->GetNbinsZ();
  double low_range_z  = histo3D_signal->GetZaxis()->GetXmin();
  double high_range_z = histo3D_signal->GetZaxis()->GetXmax();

  
  
  double x[nbinx], x_e[nbinx];
  double y[nbinx], y_e[nbinx];
  double z[nbinx], z_e[nbinx];


  TH1F *histo1D_tmp =  new TH1F("histo1D_tmp", "histo1D_tmp", nbiny, low_range_y, high_range_y);
  
  //*****************
  //loop jet pT
  //*****************
       
  for(int i=1; i<=nbinx; i++){
   
     x[i]   = low_range_x + i*(high_range_x - low_range_x)/nbinx;
     x_e[i] = 0.5*(high_range_x - low_range_x)/nbinx;
     
     
     //cout << "jet pT " << x[i] << endl;
    //*****************
    //loop deltaR
    //*****************
     y[i]=0;
     double jetprobaRatio_temp = 0;
       
     for(int j=1; j<= nbiny; j++){
     
       
       //*****************
       //compute  jet eff
       //*****************
     
       double int_jetproba_bjets   = 0;
       double int_jetproba_ljets   = 0;
       double fract_jetproba_bjets = 0;
       double fract_jetproba_ljets = 0;
       
       for(int k=1; k<= nbinz; k++){
         double zvalue = low_range_z + k*(high_range_z - low_range_z)/nbinz;
         if(  zvalue > 0.275){
	   fract_jetproba_bjets += histo3D_signal->GetBinContent(i, j, k);
	   fract_jetproba_ljets += histo3D_background->GetBinContent(i, j, k);
	 }
	 int_jetproba_bjets += histo3D_signal->GetBinContent(i, j, k);
	 int_jetproba_ljets += histo3D_background->GetBinContent(i, j, k);
         //if(i == 1 && j==1 ) cout << "discri " << zvalue << endl;
       }
       if(int_jetproba_bjets > 0) fract_jetproba_bjets = fract_jetproba_bjets/int_jetproba_bjets;
       if(int_jetproba_ljets > 0) fract_jetproba_ljets = fract_jetproba_ljets/int_jetproba_ljets;
       
       if(fract_jetproba_ljets >0) fract_jetproba_bjets = fract_jetproba_ljets;
       else fract_jetproba_bjets = 0;
       //*****************
       //compute  jet eff
       //*****************
       if(i==80) histo1D_tmp->SetBinContent(j, fract_jetproba_bjets);
       
       //*****************
       //store deltR that maximize ebb
       //*****************
       if(i==5) cout << "***************************** " << endl;
       if(i==5) cout << "fract_jetproba_bjets " << fract_jetproba_bjets << endl;
       if(i==5) cout << "jetprobaRatio_temp   " << jetprobaRatio_temp << endl;
       //cout << "fract_jetproba_bjets " << fract_jetproba_bjets << endl;
       if(fract_jetproba_bjets >  jetprobaRatio_temp ){
         y[i] =  low_range_y + j*(high_range_y - low_range_y)/nbiny;
	 jetprobaRatio_temp = fract_jetproba_bjets;
       }
     }
     cout << "deltaR " << y[i] << endl;
     y_e[i] = y[i]*0.10;
   }
       
     
  //histo1D_tmp->Draw();

  TH1F * thehisto = new TH1F("thehisto", "thehisto", nbinx, low_range_x, high_range_x);
  thehisto->SetMaximum(0.3);
  thehisto->GetYaxis()->SetTitleOffset(1.2);
  thehisto->GetXaxis()->SetTitle("Jet p_{T} [GeV]");
  thehisto->GetYaxis()->SetTitle("optimized #Delta R");
  TGraphErrors * tgraph = new TGraphErrors(nbinx, x, y, x_e, y_e);

  thehisto->Draw();
  tgraph->SetMarkerStyle(20);
  tgraph->SetMarkerColor(2);
  tgraph->Draw("ep");
  
  
  
  TLegend* qw = new TLegend(.80,.70,.95,.90);
  qw->SetShadowColor(0);
  qw->SetFillColor(0);
  qw->SetLineColor(0);
  //qw->AddEntry(histo_20_40,         " 20 <p_{T}< 40 " , "l");
  //  qw->Draw();
  

  //histo1D_tmp->Draw();

  
  
}












//---------------------------------------------------------------------
// Compare b-tracks vs non-tracks  for different jet pT range
//---------------------------------------------------------------------

void DoPlots_comp_Btracks_vs_NonBTrack(TString histoname1, TString histoname2, TString filename, TString xlabel){

  // Change for log plots:
  gStyle->SetOptLogx(0);
  gStyle->SetOptLogy(0);
  gStyle->SetOptLogz(0);
  gStyle->SetOptFit(1011);
  gStyle->SetOptFile(0);
  gStyle->SetOptStat(0); // To display the mean and RMS:   SetOptStat("mr");
  gStyle->SetStatColor(0); // kWhite

  gStyle->SetOptTitle(0);
  gStyle->SetTitleFont(42);
  gStyle->SetTitleColor(1);
  gStyle->SetTitleTextColor(1);
  gStyle->SetTitleFillColor(10);
  gStyle->SetTitleFontSize(0.05);

  TCanvas *c1 = new TCanvas("c1","c1", 1000, 800);
  c1->SetLogy(setlogy);
  c1->cd();
  
   TFile * filechannel = new TFile( filename.Data() );
  
  
   TH2F *Histo_2D_btracks     = (TH2F*)filechannel->Get( histoname1.Data() );
   TH2F *Histo_2D_nonbtracks  = (TH2F*)filechannel->Get( histoname2.Data() );
   
   int nbinx           = Histo_2D_btracks->GetNbinsX();
   double low_range_x  = Histo_2D_btracks->GetXaxis()->GetXmin();
   double high_range_x = Histo_2D_btracks->GetXaxis()->GetXmax();
   
   
   int nbiny           = Histo_2D_btracks->GetNbinsY();
   double low_range_y  = Histo_2D_btracks->GetYaxis()->GetXmin();
   double high_range_y = Histo_2D_btracks->GetYaxis()->GetXmax();

  
  
   TH1F * histo_20_40_btracks    = new TH1F("histo_20_40_btracks",    "histo_20_40_btracks", nbiny,    low_range_y, high_range_y);
   TH1F * histo_40_60_btracks    = new TH1F("histo_40_60_btracks",    "histo_40_60_btracks", nbiny,    low_range_y, high_range_y);
   TH1F * histo_60_80_btracks    = new TH1F("histo_60_80_btracks",    "histo_60_80_btracks", nbiny,    low_range_y, high_range_y);
   TH1F * histo_80_100_btracks   = new TH1F("histo_80_100_btracks",   "histo_80_100_btracks", nbiny,   low_range_y, high_range_y);
   TH1F * histo_100_150_btracks  = new TH1F("histo_100_150_btracks",  "histo_100_150_btracks", nbiny,  low_range_y, high_range_y);
   TH1F * histo_150_300_btracks  = new TH1F("histo_150_300_btracks",  "histo_150_300_btracks", nbiny,  low_range_y, high_range_y);
   TH1F * histo_300_500_btracks  = new TH1F("histo_300_500_btracks",  "histo_300_500_btracks", nbiny,  low_range_y, high_range_y);
   TH1F * histo_500_1000_btracks = new TH1F("histo_500_1000_btracks", "histo_500_1000_btracks", nbiny, low_range_y, high_range_y);
   
   TH1F * histo_20_40_nonbtracks    = new TH1F("histo_20_40_nonbtracks",    "histo_20_40_nonbtracks", nbiny,    low_range_y, high_range_y);
   TH1F * histo_40_60_nonbtracks    = new TH1F("histo_40_60_nonbtracks",    "histo_40_60_nonbtracks", nbiny,    low_range_y, high_range_y);
   TH1F * histo_60_80_nonbtracks    = new TH1F("histo_60_80_nonbtracks",    "histo_60_80_nonbtracks", nbiny,    low_range_y, high_range_y);
   TH1F * histo_80_100_nonbtracks   = new TH1F("histo_80_100_nonbtracks",   "histo_80_100_nonbtracks", nbiny,   low_range_y, high_range_y);
   TH1F * histo_100_150_nonbtracks  = new TH1F("histo_100_150_nonbtracks",  "histo_100_150_nonbtracks", nbiny,  low_range_y, high_range_y);
   TH1F * histo_150_300_nonbtracks  = new TH1F("histo_150_300_nonbtracks",  "histo_150_300_nonbtracks", nbiny,  low_range_y, high_range_y);
   TH1F * histo_300_500_nonbtracks  = new TH1F("histo_300_500_nonbtracks",  "histo_300_500_nonbtracks", nbiny,  low_range_y, high_range_y);
   TH1F * histo_500_1000_nonbtracks = new TH1F("histo_500_1000_nonbtracks", "histo_500_1000_nonbtracks", nbiny, low_range_y, high_range_y);
  
   double x[nbinx], x_e[nbinx];

  
   
  for(int i=0; i<nbinx; i++){
   
     x[i]   = low_range_x + i*(high_range_x - low_range_x)/nbinx;
     x_e[i] = (high_range_x - low_range_x)/nbinx;
     
     
     for(int j=1; j<= nbiny; j++){
       
       if(x[i] > 20. && x[i] <= 40.)    histo_20_40_btracks->SetBinContent(j,    histo_20_40_btracks->GetBinContent(j)    + Histo_2D_btracks->GetBinContent(i+1, j));
       if(x[i] > 40. && x[i] <= 60.)    histo_40_60_btracks->SetBinContent(j,    histo_40_60_btracks->GetBinContent(j)    + Histo_2D_btracks->GetBinContent(i+1, j));
       if(x[i] > 60. && x[i] <= 80.)    histo_60_80_btracks->SetBinContent(j,    histo_60_80_btracks->GetBinContent(j)    + Histo_2D_btracks->GetBinContent(i+1, j));
       if(x[i] > 80. && x[i] <= 100.)   histo_80_100_btracks->SetBinContent(j,   histo_80_100_btracks->GetBinContent(j)   + Histo_2D_btracks->GetBinContent(i+1, j));
       if(x[i] > 100. && x[i] <= 150.)  histo_100_150_btracks->SetBinContent(j,  histo_100_150_btracks->GetBinContent(j)  + Histo_2D_btracks->GetBinContent(i+1, j));
       if(x[i] > 150. && x[i] <= 300.)  histo_150_300_btracks->SetBinContent(j,  histo_150_300_btracks->GetBinContent(j)  + Histo_2D_btracks->GetBinContent(i+1, j));
       if(x[i] > 300. && x[i] <= 500.)  histo_300_500_btracks->SetBinContent(j,  histo_300_500_btracks->GetBinContent(j)  + Histo_2D_btracks->GetBinContent(i+1, j));
       if(x[i] > 500. && x[i] <= 1000.) histo_500_1000_btracks->SetBinContent(j, histo_500_1000_btracks->GetBinContent(j) + Histo_2D_btracks->GetBinContent(i+1, j));
       
       
       if(x[i] > 20. && x[i] <= 40.)    histo_20_40_nonbtracks->SetBinContent(j,    histo_20_40_nonbtracks->GetBinContent(j)    + Histo_2D_nonbtracks->GetBinContent(i+1, j));
       if(x[i] > 40. && x[i] <= 60.)    histo_40_60_nonbtracks->SetBinContent(j,    histo_40_60_nonbtracks->GetBinContent(j)    + Histo_2D_nonbtracks->GetBinContent(i+1, j));
       if(x[i] > 60. && x[i] <= 80.)    histo_60_80_nonbtracks->SetBinContent(j,    histo_60_80_nonbtracks->GetBinContent(j)    + Histo_2D_nonbtracks->GetBinContent(i+1, j));
       if(x[i] > 80. && x[i] <= 100.)   histo_80_100_nonbtracks->SetBinContent(j,   histo_80_100_nonbtracks->GetBinContent(j)   + Histo_2D_nonbtracks->GetBinContent(i+1, j));
       if(x[i] > 100. && x[i] <= 150.)  histo_100_150_nonbtracks->SetBinContent(j,  histo_100_150_nonbtracks->GetBinContent(j)  + Histo_2D_nonbtracks->GetBinContent(i+1, j));
       if(x[i] > 150. && x[i] <= 300.)  histo_150_300_nonbtracks->SetBinContent(j,  histo_150_300_nonbtracks->GetBinContent(j)  + Histo_2D_nonbtracks->GetBinContent(i+1, j));
       if(x[i] > 300. && x[i] <= 500.)  histo_300_500_nonbtracks->SetBinContent(j,  histo_300_500_nonbtracks->GetBinContent(j)  + Histo_2D_nonbtracks->GetBinContent(i+1, j));
       if(x[i] > 500. && x[i] <= 1000.) histo_500_1000_nonbtracks->SetBinContent(j, histo_500_1000_nonbtracks->GetBinContent(j) + Histo_2D_nonbtracks->GetBinContent(i+1, j));
       
     }

  }
  
  histo_20_40_btracks->SetLineColor(1);
  histo_40_60_btracks->SetLineColor(2);
  histo_60_80_btracks->SetLineColor(3);
  histo_80_100_btracks->SetLineColor(4);
  histo_100_150_btracks->SetLineColor(5);
  histo_150_300_btracks->SetLineColor(6);
  histo_300_500_btracks->SetLineColor(7);
  histo_500_1000_btracks->SetLineColor(8);
  
  
  histo_20_40_btracks->SetLineWidth(2);
  histo_40_60_btracks->SetLineWidth(2);
  histo_60_80_btracks->SetLineWidth(2);
  histo_80_100_btracks->SetLineWidth(2);
  histo_100_150_btracks->SetLineWidth(2);
  histo_150_300_btracks->SetLineWidth(2);
  histo_300_500_btracks->SetLineWidth(2);
  histo_500_1000_btracks->SetLineWidth(2);

/*
  histo_20_40_btracks->Rebin(4);
  histo_40_60_btracks->Rebin(4);
  histo_60_80_btracks->Rebin(4);
  histo_80_100_btracks->Rebin(4);
  histo_100_150_btracks->Rebin(4);
  histo_150_300_btracks->Rebin(4);
  histo_300_500_btracks->Rebin(4);
  histo_500_1000_btracks->Rebin(4);
  */
  
  histo_20_40_nonbtracks->SetLineColor(1);
  histo_40_60_nonbtracks->SetLineColor(2);
  histo_60_80_nonbtracks->SetLineColor(3);
  histo_80_100_nonbtracks->SetLineColor(4);
  histo_100_150_nonbtracks->SetLineColor(5);
  histo_150_300_nonbtracks->SetLineColor(6);
  histo_300_500_nonbtracks->SetLineColor(7);
  histo_500_1000_nonbtracks->SetLineColor(8);
  
  
  histo_20_40_nonbtracks  ->SetLineStyle(7);
  histo_40_60_nonbtracks  ->SetLineStyle(7);
  histo_60_80_nonbtracks  ->SetLineStyle(7);
  histo_80_100_nonbtracks ->SetLineStyle(7);
  histo_100_150_nonbtracks->SetLineStyle(7);
  histo_150_300_nonbtracks->SetLineStyle(7);
  histo_300_500_nonbtracks->SetLineStyle(7);
  histo_500_1000_nonbtracks->SetLineStyle(7);
  
  
  histo_20_40_nonbtracks->SetLineWidth(2);
  histo_40_60_nonbtracks->SetLineWidth(2);
  histo_60_80_nonbtracks->SetLineWidth(2);
  histo_80_100_nonbtracks->SetLineWidth(2);
  histo_100_150_nonbtracks->SetLineWidth(2);
  histo_150_300_nonbtracks->SetLineWidth(2);
  histo_300_500_nonbtracks->SetLineWidth(2);
  histo_500_1000_nonbtracks->SetLineWidth(2);

/*
  histo_20_40_nonbtracks->Rebin(4);
  histo_40_60_nonbtracks->Rebin(4);
  histo_60_80_nonbtracks->Rebin(4);
  histo_80_100_nonbtracks->Rebin(4);
  histo_100_150_nonbtracks->Rebin(4);
  histo_150_300_nonbtracks->Rebin(4);
  histo_300_500_nonbtracks->Rebin(4);
  histo_500_1000_nonbtracks->Rebin(4);
  */
  
  histo_20_40_btracks->SetMinimum();
  histo_500_1000_btracks->GetXaxis()->SetTitle(xlabel);
  histo_500_1000_btracks->DrawNormalized();
  //histo_40_60_btracks->DrawNormalized("same");
  // histo_60_80_btracks->DrawNormalized("same");
  histo_80_100_btracks->DrawNormalized("same");
  // histo_100_150_btracks->DrawNormalized("same");
  histo_150_300_btracks->DrawNormalized("same");
  // histo_300_500_btracks->DrawNormalized("same");
  histo_20_40_btracks->DrawNormalized("same");
  
  cout << "mean histo_20_40_btracks    " << histo_20_40_btracks->GetMean() << endl;
  cout << "mean histo_80_100_btracks   " << histo_80_100_btracks->GetMean() << endl;
  cout << "mean histo_500_1000_btracks " << histo_500_1000_btracks->GetMean() << endl;
  
  
  
  histo_20_40_nonbtracks->SetMinimum();
  histo_500_1000_nonbtracks->DrawNormalized("same");
  //histo_40_60_nonbtracks->DrawNormalized("same");
  // histo_60_80_nonbtracks->DrawNormalized("same");
  histo_80_100_nonbtracks->DrawNormalized("same");
  // histo_100_150_nonbtracks->DrawNormalized("same");
  histo_150_300_nonbtracks->DrawNormalized("same");
  // histo_300_500_nonbtracks->DrawNormalized("same");
  histo_20_40_nonbtracks->DrawNormalized("same");
  
  cout << "mean histo_20_40_nonbtracks    " << histo_20_40_nonbtracks->GetMean() << endl;
  cout << "mean histo_80_100_nonbtracks   " << histo_80_100_nonbtracks->GetMean() << endl;
  cout << "mean histo_500_1000_nonbtracks " << histo_500_1000_nonbtracks->GetMean() << endl;
  
  TLegend* qw = new TLegend(.80,.70,.95,.90);
  qw->SetShadowColor(0);
  qw->SetFillColor(0);
  qw->SetLineColor(0);
  qw->AddEntry(histo_20_40_btracks,         " 20 <p_{T}< 40 " , "l");
  qw->AddEntry(histo_80_100_btracks,        " 80 <p_{T}< 100 " , "l");
  qw->AddEntry(histo_150_300_btracks,        " 150 <p_{T}< 300 " , "l");
  qw->AddEntry(histo_500_1000_btracks,      " 500 <p_{T}< 1000 " , "l");
  qw->AddEntry(histo_20_40_nonbtracks,         " 20 <p_{T}< 40 " , "l");
  qw->AddEntry(histo_80_100_nonbtracks,        " 80 <p_{T}< 100 " , "l");
  qw->AddEntry(histo_150_300_nonbtracks,        " 150 <p_{T}< 300 " , "l");
  qw->AddEntry(histo_500_1000_nonbtracks,      " 500 <p_{T}< 1000 " , "l");
 
  qw->Draw();
  
  
  
}




//---------------------------------------------------------------------
// Compare b-tracks vs non-tracks  for different jet pT range
//---------------------------------------------------------------------

void DoPlots_IPsign_vs_other(TString histoname1, TString histoname2, TString filename, TString xlabel){

  // Change for log plots:
  gStyle->SetOptLogx(0);
  gStyle->SetOptLogy(0);
  gStyle->SetOptLogz(0);
  gStyle->SetOptFit(1011);
  gStyle->SetOptFile(0);
  gStyle->SetOptStat(0); // To display the mean and RMS:   SetOptStat("mr");
  gStyle->SetStatColor(0); // kWhite

  gStyle->SetOptTitle(0);
  gStyle->SetTitleFont(42);
  gStyle->SetTitleColor(1);
  gStyle->SetTitleTextColor(1);
  gStyle->SetTitleFillColor(10);
  gStyle->SetTitleFontSize(0.05);

  TCanvas *c1 = new TCanvas("c1","c1", 1000, 800);
  c1->SetLogy(setlogy);
  c1->cd();
  
   TFile * filechannel = new TFile( filename.Data() );
  
  
   TH2F *Histo_2D_btracks     = (TH2F*)filechannel->Get( histoname1.Data() );
   TH2F *Histo_2D_nonbtracks  = (TH2F*)filechannel->Get( histoname2.Data() );
   
   int nbinx           = Histo_2D_btracks->GetNbinsX();
   double low_range_x  = Histo_2D_btracks->GetXaxis()->GetXmin();
   double high_range_x = Histo_2D_btracks->GetXaxis()->GetXmax();
   
   
   int nbiny           = Histo_2D_btracks->GetNbinsY();
   double low_range_y  = Histo_2D_btracks->GetYaxis()->GetXmin();
   double high_range_y = Histo_2D_btracks->GetYaxis()->GetXmax();

  
  
   TH1F * histo_20_40_btracks    = new TH1F("histo_20_40_btracks",    "histo_20_40_btracks", nbinx,    low_range_x, high_range_x);
   TH1F * histo_40_60_btracks    = new TH1F("histo_40_60_btracks",    "histo_40_60_btracks", nbinx,    low_range_x, high_range_x);
   TH1F * histo_60_80_btracks    = new TH1F("histo_60_80_btracks",    "histo_60_80_btracks", nbinx,    low_range_x, high_range_x);
   TH1F * histo_80_100_btracks   = new TH1F("histo_80_100_btracks",   "histo_80_100_btracks", nbinx,   low_range_x, high_range_x);
   TH1F * histo_100_150_btracks  = new TH1F("histo_100_150_btracks",  "histo_100_150_btracks", nbinx,  low_range_x, high_range_x);
   TH1F * histo_150_300_btracks  = new TH1F("histo_150_300_btracks",  "histo_150_300_btracks", nbinx,  low_range_x, high_range_x);
   TH1F * histo_300_500_btracks  = new TH1F("histo_300_500_btracks",  "histo_300_500_btracks", nbinx,  low_range_x, high_range_x);
   TH1F * histo_500_1000_btracks = new TH1F("histo_500_1000_btracks", "histo_500_1000_btracks", nbinx, low_range_x, high_range_x);
   
   TH1F * histo_20_40_nonbtracks    = new TH1F("histo_20_40_nonbtracks",    "histo_20_40_nonbtracks", nbinx,    low_range_x, high_range_x);
   TH1F * histo_40_60_nonbtracks    = new TH1F("histo_40_60_nonbtracks",    "histo_40_60_nonbtracks", nbinx,    low_range_x, high_range_x);
   TH1F * histo_60_80_nonbtracks    = new TH1F("histo_60_80_nonbtracks",    "histo_60_80_nonbtracks", nbinx,    low_range_x, high_range_x);
   TH1F * histo_80_100_nonbtracks   = new TH1F("histo_80_100_nonbtracks",   "histo_80_100_nonbtracks", nbinx,   low_range_x, high_range_x);
   TH1F * histo_100_150_nonbtracks  = new TH1F("histo_100_150_nonbtracks",  "histo_100_150_nonbtracks", nbinx,  low_range_x, high_range_x);
   TH1F * histo_150_300_nonbtracks  = new TH1F("histo_150_300_nonbtracks",  "histo_150_300_nonbtracks", nbinx,  low_range_x, high_range_x);
   TH1F * histo_300_500_nonbtracks  = new TH1F("histo_300_500_nonbtracks",  "histo_300_500_nonbtracks", nbinx,  low_range_x, high_range_x);
   TH1F * histo_500_1000_nonbtracks = new TH1F("histo_500_1000_nonbtracks", "histo_500_1000_nonbtracks", nbinx, low_range_x, high_range_x);
  
   double x[nbiny], x_e[nbiny];

  
   
  for(int i=0; i<nbiny; i++){
   
     x[i]   = low_range_y + i*(high_range_y - low_range_y)/nbinx;
     x_e[i] = (high_range_y - low_range_y)/nbinx;
     
     
     for(int j=1; j<= nbinx; j++){
       
       if(x[i] > 20. && x[i] <= 40.)    histo_20_40_btracks->SetBinContent(j,    histo_20_40_btracks->GetBinContent(j)    + Histo_2D_btracks->GetBinContent(j, i));
       if(x[i] > 40. && x[i] <= 60.)    histo_40_60_btracks->SetBinContent(j,    histo_40_60_btracks->GetBinContent(j)    + Histo_2D_btracks->GetBinContent(j, i));
       if(x[i] > 60. && x[i] <= 80.)    histo_60_80_btracks->SetBinContent(j,    histo_60_80_btracks->GetBinContent(j)    + Histo_2D_btracks->GetBinContent(j, i));
       if(x[i] > 80. && x[i] <= 100.)   histo_80_100_btracks->SetBinContent(j,   histo_80_100_btracks->GetBinContent(j)   + Histo_2D_btracks->GetBinContent(j, i));
       if(x[i] > 100. && x[i] <= 150.)  histo_100_150_btracks->SetBinContent(j,  histo_100_150_btracks->GetBinContent(j)  + Histo_2D_btracks->GetBinContent(j, i));
       if(x[i] > 150. && x[i] <= 300.)  histo_150_300_btracks->SetBinContent(j,  histo_150_300_btracks->GetBinContent(j)  + Histo_2D_btracks->GetBinContent(j, i));
       if(x[i] > 300. && x[i] <= 500.)  histo_300_500_btracks->SetBinContent(j,  histo_300_500_btracks->GetBinContent(j)  + Histo_2D_btracks->GetBinContent(j, i));
       if(x[i] > 500. && x[i] <= 1000.) histo_500_1000_btracks->SetBinContent(j, histo_500_1000_btracks->GetBinContent(j) + Histo_2D_btracks->GetBinContent(j, i));
       
       
       if(x[i] > 20. && x[i] <= 40.)    histo_20_40_nonbtracks->SetBinContent(j,    histo_20_40_nonbtracks->GetBinContent(j)    + Histo_2D_nonbtracks->GetBinContent(j, i));
       if(x[i] > 40. && x[i] <= 60.)    histo_40_60_nonbtracks->SetBinContent(j,    histo_40_60_nonbtracks->GetBinContent(j)    + Histo_2D_nonbtracks->GetBinContent(j, i));
       if(x[i] > 60. && x[i] <= 80.)    histo_60_80_nonbtracks->SetBinContent(j,    histo_60_80_nonbtracks->GetBinContent(j)    + Histo_2D_nonbtracks->GetBinContent(j, i));
       if(x[i] > 80. && x[i] <= 100.)   histo_80_100_nonbtracks->SetBinContent(j,   histo_80_100_nonbtracks->GetBinContent(j)   + Histo_2D_nonbtracks->GetBinContent(j, i));
       if(x[i] > 100. && x[i] <= 150.)  histo_100_150_nonbtracks->SetBinContent(j,  histo_100_150_nonbtracks->GetBinContent(j)  + Histo_2D_nonbtracks->GetBinContent(j, i));
       if(x[i] > 150. && x[i] <= 300.)  histo_150_300_nonbtracks->SetBinContent(j,  histo_150_300_nonbtracks->GetBinContent(j)  + Histo_2D_nonbtracks->GetBinContent(j, i));
       if(x[i] > 300. && x[i] <= 500.)  histo_300_500_nonbtracks->SetBinContent(j,  histo_300_500_nonbtracks->GetBinContent(j)  + Histo_2D_nonbtracks->GetBinContent(j, i));
       if(x[i] > 500. && x[i] <= 1000.) histo_500_1000_nonbtracks->SetBinContent(j, histo_500_1000_nonbtracks->GetBinContent(j) + Histo_2D_nonbtracks->GetBinContent(j, i));
       
     }

  }
  
  histo_20_40_btracks->SetLineColor(1);
  histo_40_60_btracks->SetLineColor(2);
  histo_60_80_btracks->SetLineColor(3);
  histo_80_100_btracks->SetLineColor(4);
  histo_100_150_btracks->SetLineColor(5);
  histo_150_300_btracks->SetLineColor(6);
  histo_300_500_btracks->SetLineColor(7);
  histo_500_1000_btracks->SetLineColor(8);
  
  
  histo_20_40_btracks->SetLineWidth(2);
  histo_40_60_btracks->SetLineWidth(2);
  histo_60_80_btracks->SetLineWidth(2);
  histo_80_100_btracks->SetLineWidth(2);
  histo_100_150_btracks->SetLineWidth(2);
  histo_150_300_btracks->SetLineWidth(2);
  histo_300_500_btracks->SetLineWidth(2);
  histo_500_1000_btracks->SetLineWidth(2);


  histo_20_40_btracks->Rebin(4);
  histo_40_60_btracks->Rebin(4);
  histo_60_80_btracks->Rebin(4);
  histo_80_100_btracks->Rebin(4);
  histo_100_150_btracks->Rebin(4);
  histo_150_300_btracks->Rebin(4);
  histo_300_500_btracks->Rebin(4);
  histo_500_1000_btracks->Rebin(4);
  
  
  histo_20_40_nonbtracks->SetLineColor(1);
  histo_40_60_nonbtracks->SetLineColor(2);
  histo_60_80_nonbtracks->SetLineColor(3);
  histo_80_100_nonbtracks->SetLineColor(4);
  histo_100_150_nonbtracks->SetLineColor(5);
  histo_150_300_nonbtracks->SetLineColor(6);
  histo_300_500_nonbtracks->SetLineColor(7);
  histo_500_1000_nonbtracks->SetLineColor(8);
  
  
  histo_20_40_nonbtracks  ->SetLineStyle(7);
  histo_40_60_nonbtracks  ->SetLineStyle(7);
  histo_60_80_nonbtracks  ->SetLineStyle(7);
  histo_80_100_nonbtracks ->SetLineStyle(7);
  histo_100_150_nonbtracks->SetLineStyle(7);
  histo_150_300_nonbtracks->SetLineStyle(7);
  histo_300_500_nonbtracks->SetLineStyle(7);
  histo_500_1000_nonbtracks->SetLineStyle(7);
  
  
  histo_20_40_nonbtracks->SetLineWidth(2);
  histo_40_60_nonbtracks->SetLineWidth(2);
  histo_60_80_nonbtracks->SetLineWidth(2);
  histo_80_100_nonbtracks->SetLineWidth(2);
  histo_100_150_nonbtracks->SetLineWidth(2);
  histo_150_300_nonbtracks->SetLineWidth(2);
  histo_300_500_nonbtracks->SetLineWidth(2);
  histo_500_1000_nonbtracks->SetLineWidth(2);


  histo_20_40_nonbtracks->Rebin(4);
  histo_40_60_nonbtracks->Rebin(4);
  histo_60_80_nonbtracks->Rebin(4);
  histo_80_100_nonbtracks->Rebin(4);
  histo_100_150_nonbtracks->Rebin(4);
  histo_150_300_nonbtracks->Rebin(4);
  histo_300_500_nonbtracks->Rebin(4);
  histo_500_1000_nonbtracks->Rebin(4);
  
  
  histo_20_40_btracks->SetMinimum();
  histo_500_1000_btracks->GetXaxis()->SetTitle(xlabel);
  histo_500_1000_btracks->DrawNormalized();
  //histo_40_60_btracks->DrawNormalized("same");
  // histo_60_80_btracks->DrawNormalized("same");
  histo_80_100_btracks->DrawNormalized("same");
  // histo_100_150_btracks->DrawNormalized("same");
  histo_150_300_btracks->DrawNormalized("same");
  // histo_300_500_btracks->DrawNormalized("same");
  histo_20_40_btracks->DrawNormalized("same");
  
  cout << "mean histo_20_40_btracks    " << histo_20_40_btracks->GetMean() << endl;
  cout << "mean histo_80_100_btracks   " << histo_80_100_btracks->GetMean() << endl;
  cout << "mean histo_500_1000_btracks " << histo_500_1000_btracks->GetMean() << endl;
  
  
  
  histo_20_40_nonbtracks->SetMinimum();
  histo_500_1000_nonbtracks->DrawNormalized("same");
  //histo_40_60_nonbtracks->DrawNormalized("same");
  // histo_60_80_nonbtracks->DrawNormalized("same");
  histo_80_100_nonbtracks->DrawNormalized("same");
  // histo_100_150_nonbtracks->DrawNormalized("same");
  histo_150_300_nonbtracks->DrawNormalized("same");
  // histo_300_500_nonbtracks->DrawNormalized("same");
  histo_20_40_nonbtracks->DrawNormalized("same");
  
  cout << "mean histo_20_40_nonbtracks    " << histo_20_40_nonbtracks->GetMean() << endl;
  cout << "mean histo_80_100_nonbtracks   " << histo_80_100_nonbtracks->GetMean() << endl;
  cout << "mean histo_500_1000_nonbtracks " << histo_500_1000_nonbtracks->GetMean() << endl;
  
  TLegend* qw = new TLegend(.80,.70,.95,.90);
  qw->SetShadowColor(0);
  qw->SetFillColor(0);
  qw->SetLineColor(0);
  qw->AddEntry(histo_20_40_btracks,         " 20 <p_{}< 40, btracks " , "l");
  qw->AddEntry(histo_80_100_btracks,        " 80 <p_{}< 100, btracks " , "l");
  qw->AddEntry(histo_150_300_btracks,        " 150 <p_{}< 300, btracks " , "l");
  qw->AddEntry(histo_500_1000_btracks,      " 500 <p_{}< 1000, btracks " , "l");
  qw->AddEntry(histo_20_40_nonbtracks,         " 20 <p_{}< 40, non btracks " , "l");
  qw->AddEntry(histo_80_100_nonbtracks,        " 80 <p_{}< 100, non btracks " , "l");
  qw->AddEntry(histo_150_300_nonbtracks,        " 150 <p_{}< 300, non btracks " , "l");
  qw->AddEntry(histo_500_1000_nonbtracks,      " 500 <p_{}< 1000, non btracks " , "l");
 
  qw->Draw();
  
  
  
}




void DoPlots(){

  //DoPlots_eff("jetPt_vs_SoftMu", "study_histo.root");
  
  //DoPlots_eff("jetPt_vs_JetProba", "study_histo.root");
  //DoPlots_eff("jetPt_vs_JetProbaNew2", "study_histo.root");
  
  //DoPlots_effQjets("jetPt_vs_JetProba_bjets", "study_histo.root");
  
  //DoPlots_comp("jetPt_vs_TrackIPMuon_bjets", "study_histo130_pt.root");
  
  
  
  //DoPlots_comp("jetPt_vs_TrackIP_bhadrons", "study_histo130_pt.root", "IP/#sigma");
  
  //DoPlots_comp("jetPt_vs_TrackIP_bjets", "study_histo130_pt.root", "IP/#sigma");
  
  //DoPlots_comp("jetPt_vs_bhardSVrho_bjets", "study_histo.root", "b-SV rho");
  
  
  //DoPlots_comp("jetPt_vs_DeltaR_bhadTrack_bjets", "study_histo.root", "#DeltaR(b track-closest track)");
  //DoPlots_comp("jetPt_vs_DeltaR_allTrack_bjets", "study_histo.root", "#DeltaR( all tracks-closest track)");
  //DoPlots_comp("jetPt_vs_DeltaR_bTrackJet_NoGSplit_bjets", "study_histo.root", "#DeltaR(nonbtrack-jet)");
  //DoPlots_comp("jetPt_vs_DeltaR_bTrackJet_GSplit_bjets", "study_histo.root", "#DeltaR(nonbtrack-jet)");
  //DoPlots_comp("jetPt_vs_DeltaR_nonbTrackJet_bjets", "study_histo.root", "#DeltaR(nonbtrack-jet)");
  
  
  
  
  
  
  
  
  //DoPlots_comp("jetPt_vs_TrackPt_bjets", "study_histo.root", "Track p_{T} [GeV]");
  //DoPlots_comp("jetPt_vs_TrackPtBtrack_NoGSplit_bjets", "study_histo.root", "Track p_{T} [GeV]");
  //DoPlots_comp("jetPt_vs_TrackPtBtrack_GSplit_bjets", "study_histo.root", "Track p_{T} [GeV]");
  //DoPlots_comp("jetPt_vs_TrackPtLtrack_bjets", "study_histo.root", "Track p_{T} [GeV]");
  
  //DoPlots_comp(80, 100, "study_histo.root");
  //DoPlots_comp("
  
  //DoPlots_BtackMult("jetPt_vs_NTbhadrons_bjets", "study_histo.root");
  //DoPlots_BtackMult("jetPt_vs_NTbhadronsNoGsplit_bjets", "study_histo.root");
  //DoPlots_BtackMult("jetPt_vs_NTbhadronsGsplit_bjets", "study_histo.root");
  //DoPlots_BtackMult("", "study_histo.root");
  
  //DoPlots_BtackMult("jetPt_vs_NStripHit_NoGSplit_bjets", "study_histo.root");
  //DoPlots_BtackMult("jetPt_vs_NPixHit_NoGSplit_bjets", "study_histo.root");
  //DoPlots_BtackMult("jetPt_vs_bhardSVrho_bjets", "study_histo.root");
  
  //DoPlots_BtackMult("jetPt_vs_NTfake_bjets", "study_histo.root");
  //DoPlots_BtackMult("jetPt_vs_NTInteraction_bjets", "study_histo.root");
  
  //DoPlots_Frac("jetPt_vs_bhardSVrho_bjets", "study_histo.root");
  
  //DoPlots_TrackSelOptimization("jetPt_vs_TrackPtScan" , "study_histo.root");
  //DoPlots_TrackSelOptimization("jetPt_vs_DeltaRScan" , "study_histo.root");
  
  //DoPlots_TrackSelOptJetProba("jetPt_vs_DeltaR_vs_JetProba" , "study_histo.root");
  
  
  
  DoPlots_perf("JetProba", "JetProbaNew","study_histo.root","study_histo.root");
  //DoPlots_perf("JetProba", "JetProbaNew","study_histo_std-AllTracksNPix2.root","study_histo_std-AllTracksNPix2.root");
  
  //DoPlots_comp_Btracks_vs_NonBTrack("jetPt_vs_trackPt_btracks_noGS_bjets", "jetPt_vs_trackPt_nonbtracks_noGS_bjets","study_histo.root", "Track p_{T} [GeV]");
  //DoPlots_comp_Btracks_vs_NonBTrack("jetPt_vs_DeltaRJet_btracks_noGS_bjets", "jetPt_vs_DeltaRJet_nonbtracks_noGS_bjets","study_histo.root", "#Delta R(track-jet)");
  //DoPlots_comp_Btracks_vs_NonBTrack("jetPt_vs_NPixHit_btracks_noGS_bjets", "jetPt_vs_NPixHit_nonbtracks_noGS_bjets","study_histo.root", "N pix hit");
  //DoPlots_comp_Btracks_vs_NonBTrack("jetPt_vs_InvMtrtr_btracks_noGS_bjets", "jetPt_vs_InvMtrtr_nonbtracks_noGS_bjets","study_histo.root", "inv. mass track-closest track");
  //DoPlots_comp_Btracks_vs_NonBTrack("jetPt_vs_PtRel_btracks_noGS_bjets", "jetPt_vs_PtRel_nonbtracks_noGS_bjets","study_histo.root", "pT rel");
  //DoPlots_comp_Btracks_vs_NonBTrack("jetPt_vs_NormChi2_btracks_noGS_bjets", "jetPt_vs_NormChi2_nonbtracks_noGS_bjets","study_histo.root", "norm. #chi^{2}");
  //DoPlots_comp_Btracks_vs_NonBTrack("jetPt_vs_dxy_btracks_noGS_bjets",       "jetPt_vs_dxy_nonbtracks_noGS_bjets",      "study_histo.root", "");
  //DoPlots_comp_Btracks_vs_NonBTrack("jetPt_vs_dz_btracks_noGS_bjets",        "jetPt_vs_dz_nonbtracks_noGS_bjets",       "study_histo.root", "");
  //DoPlots_comp_Btracks_vs_NonBTrack("jetPt_vs_length_btracks_noGS_bjets",    "jetPt_vs_length_nonbtracks_noGS_bjets",   "study_histo.root", "");
  //DoPlots_comp_Btracks_vs_NonBTrack("jetPt_vs_dist_btracks_noGS_bjets",      "jetPt_vs_dist_nonbtracks_noGS_bjets",     "study_histo.root", "");
  //DoPlots_comp_Btracks_vs_NonBTrack("jetPt_vs_nHitStrip_btracks_noGS_bjets", "jetPt_vs_nHitStrip_nonbtracks_noGS_bjets","study_histo.root", "");
  
  
  
  //DoPlots_IPsign_vs_other("IPsign_vs_trackP_btracks_noGS_bjets", "IPsign_vs_trackP_ltracks_ljets", "study_histo_tmp.root", "");
  
  
  
}



















