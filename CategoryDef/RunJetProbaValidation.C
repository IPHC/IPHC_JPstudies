{


 gROOT->Reset() ;
 
  
 gROOT->ProcessLine(".L CategoryDef.C++");
 gSystem->Load("CategoryDef_C.so");

 gROOT->ProcessLine(".L CategoryDefCollection.C++");
 gSystem->Load("CategoryDefCollection_C.so");

 gROOT->ProcessLine(".L CategoriesDefinition.C++");
 gSystem->Load("CategoriesDefinition_C.so");


 
 cout << "compile JetProbaValidation " << endl;
 gROOT->ProcessLine(".L JetProbaValidation.C+g") ;


 //if (gROOT->GetClass("btagana/ttree")==0) return;
 
 cout << "initialize ttree " << endl;
 TChain c("btagana/ttree");


 cout << "add root files to the ttree" << endl;
 

 //c.Add("/opt/sbg/data/data2/cms/cbeluffi/Btag_HpT/CMSSW_5_3_11/src/RecoBTag/PerformanceMeasurements/test/QCD_15to30Summer12/*.root");
 c.Add("/opt/sbg/data/data2/cms/cbeluffi/Btag_HpT/CMSSW_5_3_11/src/RecoBTag/PerformanceMeasurements/test/QCD_30to50Summer12/*.root");
 c.Add("/opt/sbg/data/data2/cms/cbeluffi/Btag_HpT/CMSSW_5_3_11/src/RecoBTag/PerformanceMeasurements/test/QCD_120to170Summer12/*.root");
 c.Add("/opt/sbg/data/data2/cms/cbeluffi/Btag_HpT/CMSSW_5_3_11/src/RecoBTag/PerformanceMeasurements/test/QCD_170to300Summer12/*.root");
 c.Add("/opt/sbg/data/data2/cms/cbeluffi/Btag_HpT/CMSSW_5_3_11/src/RecoBTag/PerformanceMeasurements/test/QCD_300to470Summer12/*.root");
 c.Add("/opt/sbg/data/data2/cms/cbeluffi/Btag_HpT/CMSSW_5_3_11/src/RecoBTag/PerformanceMeasurements/test/QCD_470to600Summer12/*.root");
 c.Add("/opt/sbg/data/data2/cms/cbeluffi/Btag_HpT/CMSSW_5_3_11/src/RecoBTag/PerformanceMeasurements/test/QCD_600to800Summer12/*.root");
 c.Add("/opt/sbg/data/data2/cms/cbeluffi/Btag_HpT/CMSSW_5_3_11/src/RecoBTag/PerformanceMeasurements/test/QCD_800to1000Summer12/*.root");
 c.Add("/opt/sbg/data/data2/cms/cbeluffi/Btag_HpT/CMSSW_5_3_11/src/RecoBTag/PerformanceMeasurements/test/QCD_80to120Summer12/*.root");
 c.Add("/opt/sbg/data/data2/cms/cbeluffi/Btag_HpT/CMSSW_5_3_11/src/RecoBTag/PerformanceMeasurements/test/QCD_50to80Summer12/*.root");
 


 cout << "construct  JetProbaCalib" << endl;
 JetProbaValidation* theanalyzer = new JetProbaValidation(&c);
 
 cout << "Compute probabilities " << endl;
 
 
 theanalyzer->ComputeProba("calibeHistoWrite.root");
 
 
 
 
}
