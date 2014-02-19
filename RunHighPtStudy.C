{


 gROOT->Reset() ; 
 
 
 //gROOT->ProcessLine(".L CategoryDef/CategoryDef.C++");
 gSystem->Load("CategoryDef/CategoryDef_C.so");

 //gROOT->ProcessLine(".L CategoryDef/CategoryDefCollection.C++");
 gSystem->Load("CategoryDef/CategoryDefCollection_C.so");

 //gROOT->ProcessLine(".L CategoryDef/CategoriesDefinition.C++");
 gSystem->Load("CategoryDef/CategoriesDefinition_C.so");

 
 
 
 
 
 cout << "compile HighPtStudy " << endl;
 gROOT->ProcessLine(".L HighPtStudy.C++") ;


 //if (gROOT->GetClass("btagana/ttree")==0) return;
 
 cout << "initialize ttree " << endl;
 TChain c("btagana/ttree");


 cout << "add root files to the ttree" << endl;
 //c.Add("/opt/sbg/data/data2/cms/cbeluffi/BTag_2013_06_24/DataLegacy/BTagAna/CMSSW_5_3_11_patch5/src/RecoBTag/PerformanceMeasurements/test/mc_calib_confirm2/JetTree_*.root");
 //c.Add("/opt/sbg/cms/ui8_data1/ccollard/BTAG/MC_Dan_2013April/PythiaQCD/QCD_Pt-30to50_Inclusive_8TeV_pythia6_Summer12_DR53X-PU_S10_AODSIM/TrackTree_*.root");
 //c.Add("/opt/sbg/cms/ui8_data1/ccollard/BTAG/MC_Dan_2013April/PythiaQCD/QCD_Pt-50to80_Inclusive_8TeV_pythia6_Summer12_DR53X-PU_S10_AODSIM/TrackTree_*.root");
 //c.Add("/opt/sbg/cms/ui8_data1/ccollard/BTAG/MC_Dan_2013April/PythiaQCD/QCD_Pt-80to120_Inclusive_8TeV_pythia6_Summer12_DR53X-PU_S10_AODSIM/TrackTree_*.root");
 //c.Add("/opt/sbg/cms/ui8_data2/ccollard/BTAG/MC_Dan_2013April/PythiaQCD/QCD_Pt-120to170_Inclusive_8TeV_pythia6_Summer12_DR53X-PU_S10_AODSIM/TrackTree_*.root");
 //c.Add("/opt/sbg/cms/ui8_data2/ccollard/BTAG/MC_Dan_2013April/PythiaQCD/QCD_Pt-170to300_Inclusive_8TeV_pythia6_Summer12_DR53X-PU_S10_AODSIM/TrackTree_*.root");
 //c.Add("/opt/sbg/cms/ui8_data1/ccollard/BTAG/MC_Dan_2013April/PythiaQCD/QCD_Pt-300to470_Inclusive_8TeV_pythia6_Summer12_DR53X-PU_S10_AODSIM/TrackTree_*.root");
 //c.Add("/opt/sbg/cms/ui8_data1/ccollard/BTAG/MC_Dan_2013April/PythiaQCD/QCD_Pt-470to600_Inclusive_8TeV_pythia6_Summer12_DR53X-PU_S10_AODSIM/TrackTree_*.root");
 //c.Add("/opt/sbg/cms/ui8_data2/ccollard/BTAG/MC_Dan_2013April/PythiaQCD/QCD_Pt-600to800_Inclusive_8TeV_pythia6_Summer12_DR53X-PU_S10_AODSIM/TrackTree_*.root");
 //c.Add("/opt/sbg/cms/ui8_data2/ccollard/BTAG/MC_Dan_2013April/PythiaQCD/QCD_Pt-800to1000_Inclusive_8TeV_pythia6_Summer12_DR53X-PU_S10_AODSIM/TrackTree_*.root");


 //c.Add("/opt/sbg/data/data2/cms/cbeluffi/Btag_HpT/CMSSW_5_3_11/src/RecoBTag/PerformanceMeasurements/test/QCD_15to30Summer12/*.root");
 //c.Add("/opt/sbg/data/data2/cms/cbeluffi/Btag_HpT/CMSSW_5_3_11/src/RecoBTag/PerformanceMeasurements/test/QCD_30to50Summer12/*.root");
 //c.Add("/opt/sbg/data/data2/cms/cbeluffi/Btag_HpT/CMSSW_5_3_11/src/RecoBTag/PerformanceMeasurements/test/QCD_120to170Summer12/*.root");
 
 //c.Add("/opt/sbg/data/data2/cms/cbeluffi/Btag_HpT/CMSSW_5_3_11/src/RecoBTag/PerformanceMeasurements/test/QCD_170to300Summer12/*.root");
 c.Add("/opt/sbg/data/data2/cms/cbeluffi/Btag_HpT/CMSSW_5_3_11/src/RecoBTag/PerformanceMeasurements/test/QCD_300to470Summer12/*.root");
 //c.Add("/opt/sbg/data/data2/cms/cbeluffi/Btag_HpT/CMSSW_5_3_11/src/RecoBTag/PerformanceMeasurements/test/QCD_470to600Summer12/*.root");
 //c.Add("/opt/sbg/data/data2/cms/cbeluffi/Btag_HpT/CMSSW_5_3_11/src/RecoBTag/PerformanceMeasurements/test/QCD_600to800Summer12/*.root");
 //c.Add("/opt/sbg/data/data2/cms/cbeluffi/Btag_HpT/CMSSW_5_3_11/src/RecoBTag/PerformanceMeasurements/test/QCD_800to1000Summer12/*.root");
 
 //c.Add("/opt/sbg/data/data2/cms/cbeluffi/Btag_HpT/CMSSW_5_3_11/src/RecoBTag/PerformanceMeasurements/test/QCD_80to120Summer12/*.root");
 //c.Add("/opt/sbg/data/data2/cms/cbeluffi/Btag_HpT/CMSSW_5_3_11/src/RecoBTag/PerformanceMeasurements/test/QCD_50to80Summer12/*.root");
 
 //samples without track selection
 
 //c.Add("/opt/sbg/cms/ui6_data1/ccollard/sl6/prod_trackhist/AllTracks/qcd30/*.root");  
 //c.Add("/opt/sbg/cms/ui6_data1/ccollard/sl6/prod_trackhist/AllTracks/qcd50/*.root");   
 //c.Add("/opt/sbg/cms/ui6_data1/ccollard/sl6/prod_trackhist/AllTracks/qcd80/*.root"); 
 ////c.Add("/opt/sbg/cms/ui6_data1/ccollard/sl6/prod_trackhist/AllTracks/qcd120/*.root");   
 ////c.Add("/opt/sbg/cms/ui6_data1/ccollard/sl6/prod_trackhist/AllTracks/qcd170/*.root");       
 //c.Add("/opt/sbg/cms/ui6_data1/ccollard/sl6/prod_trackhist/AllTracks/qcd300/*.root");    
 ////c.Add("/opt/sbg/cms/ui6_data1/ccollard/sl6/prod_trackhist/AllTracks/qcd470/*.root");    
 //c.Add("/opt/sbg/cms/ui6_data1/ccollard/sl6/prod_trackhist/AllTracks/qcd600/*.root");    
 //c.Add("/opt/sbg/cms/ui6_data1/ccollard/sl6/prod_trackhist/AllTracks/qcd800/*.root");  
 //c.Add("/opt/sbg/cms/ui6_data1/ccollard/sl6/prod_trackhist/AllTracks/qcd1000/*.root"); 
 
 
 cout << "construct HighPtStudy " << endl;
 HighPtStudy* theanalyzer = new HighPtStudy(&c);
 
 cout << "loop on events " << endl;
 //theanalyzer->Loop(cut, type);
 //cut is the cut, type is corresponds to the variable plotted
 // type == 0 is DeltaR
 // type == 1  is pT
 // type esle is IP_sig
 
 theanalyzer->Loop("CategoryDef/CalibrationFiles/calibeHistoWrite_std.root");
 
 
 
 
}
