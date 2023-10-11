//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Feb  6 11:22:41 2014 by ROOT version 5.34/09
// from TTree G4FollowerFollowerNTuple/Output of the G4FollowerFollowerNTuple_
// found on file: GeantFollowing_1000.root
//////////////////////////////////////////////////////////

#ifndef G4Check_h
#define G4Check_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class G4Check {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Float_t         InitX;
   Float_t         InitY;
   Float_t         InitZ;
   Float_t         InitTheta;
   Float_t         InitEta;
   Float_t         InitPhi;
   Float_t         InitP;
   Int_t           InitPdg;
   Float_t         InitCharge;
   Float_t         MEntryX;
   Float_t         MEntryY;
   Float_t         MEntryZ;
   Float_t         MEntryTheta;
   Float_t         MEntryEta;
   Float_t         MEntryPhi;
   Float_t         MEntryP;
   Float_t         BackX;
   Float_t         BackY;
   Float_t         BackZ;
   Float_t         BackTheta;
   Float_t         BackEta;
   Float_t         BackPhi;
   Float_t         BackP;
   Float_t         BackX0;                                         
   Float_t         BackEloss;
   Int_t           G4Steps;
   Int_t           TrkStepScats;  
   Float_t         G4StepP[9999];   //[g4steps]
   Float_t         G4StepEta[9999];   //[g4steps]
   Float_t         G4StepTheta[9999];   //[g4steps]
   Float_t         G4StepPhi[9999];   //[g4steps]
   Float_t         G4StepX[9999];   //[g4steps]
   Float_t         G4StepY[9999];   //[g4steps]
   Float_t         G4StepZ[9999];   //[g4steps]
   Float_t         G4AccumTX0[9999];   //[g4steps]
   Float_t         G4StepT[9999];   //[g4steps]
   Float_t         G4StepX0[9999];   //[g4steps]
   Int_t           TrkStepStatus[9999];   //[g4steps]
   Float_t         TrkStepP[9999];   //[g4steps]
   Float_t         TrkStepEta[9999];   //[g4steps]
   Float_t         TrkStepTheta[9999];   //[g4steps]
   Float_t         TrkStepPhi[9999];   //[g4steps]
   Float_t         TrkStepX[9999];   //[g4steps]
   Float_t         TrkStepY[9999];   //[g4steps]
   Float_t         TrkStepZ[9999];   //[g4steps]
   Float_t         TrkStepLocX[9999];   //[g4steps]
   Float_t         TrkStepLocY[9999];   //[g4steps]
   Float_t         TrkStepEloss[9999];   //[g4steps]
   Float_t         TrkStepEloss1[9999];   //[g4steps]
   Float_t         TrkStepEloss0[9999];   //[g4steps]
   Float_t         TrkStepEloss5[9999];   //[g4steps]
   Float_t         TrkStepEloss10[9999];   //[g4steps]
   Float_t         TrkStepScaleEloss[9999];   //[g4steps]
   Float_t         TrkStepScaleX0[9999];   //[g4steps]
   Float_t         TrkStepX0[9999];   //[g4steps]
   Float_t         TrkStepErd0[9999];   //[g4steps]                 
   Float_t         TrkStepErz0[9999];   //[g4steps]                 
   Float_t         TrkStepErphi[9999];   //[g4steps]                
   Float_t         TrkStepErtheta[9999];   //[g4steps]              
   Float_t         TrkStepErqoverp[9999];   //[g4steps]             
   Int_t           TrkStepScatStatus[500];   //[trkscats]                 
   Float_t         TrkStepScatX[500];   //[trkscats]                      
   Float_t         TrkStepScatY[500];   //[trkscats]                      
   Float_t         TrkStepScatZ[500];   //[trkscats]                      
   Float_t         TrkStepScatX0[500];   //[trkscats]                     
   Float_t         TrkStepScatEloss[500];   //[trkscats]                  
   Float_t         TrkStepScatMeanIoni[500];   //[trkscats]                
   Float_t         TrkStepScatSigIoni[500];   //[trkscats]                
   Float_t         TrkStepScatMeanRad[500];   //[trkscats]                
   Float_t         TrkStepScatSigRad[500];   //[trkscats]                 
   Float_t         TrkStepScatSigTheta[500];   //[trkscats]                 
   Float_t         TrkStepScatSigPhi[500];   //[trkscats]                 



   // List of branches
   TBranch        *b_initX;   //!
   TBranch        *b_initY;   //!
   TBranch        *b_initZ;   //!
   TBranch        *b_initTheta;   //!
   TBranch        *b_initEta;   //!
   TBranch        *b_initPhi;   //!
   TBranch        *b_initP;   //!
   TBranch        *b_initPdg;   //!
   TBranch        *b_initQ;   //!
   TBranch        *b_mentryX;   //!
   TBranch        *b_mentryY;   //!
   TBranch        *b_mentryZ;   //!
   TBranch        *b_mentryTheta;   //!
   TBranch        *b_mentryEta;   //!
   TBranch        *b_mentryPhi;   //!
   TBranch        *b_mentryP;   //!
   TBranch        *b_backX;   //!
   TBranch        *b_backY;   //!
   TBranch        *b_backZ;   //!
   TBranch        *b_backTheta;   //!
   TBranch        *b_backEta;   //!
   TBranch        *b_backPhi;   //!
   TBranch        *b_backP;   //!
   TBranch        *b_backX0;   //!                                 
   TBranch        *b_backEloss; //!
   TBranch        *b_g4steps;   //!
   TBranch        *b_trkscats;   //!
   TBranch        *b_G4StepP;   //!
   TBranch        *b_G4StepEta;   //!
   TBranch        *b_G4StepTheta;   //!
   TBranch        *b_G4StepPhi;   //!
   TBranch        *b_G4StepX;   //!
   TBranch        *b_G4StepY;   //!
   TBranch        *b_G4StepZ;   //!
   TBranch        *b_G4AccumTX0;   //!
   TBranch        *b_G4StepT;   //!
   TBranch        *b_G4StepX0;   //!
   TBranch        *b_TrkStepStatus;   //!
   TBranch        *b_TrkStepP;   //!
   TBranch        *b_TrkStepEta;   //!
   TBranch        *b_TrkStepTheta;   //!
   TBranch        *b_TrkStepPhi;   //!
   TBranch        *b_TrkStepX;   //!
   TBranch        *b_TrkStepY;   //!
   TBranch        *b_TrkStepZ;   //!
   TBranch        *b_TrkStepLocX;   //!
   TBranch        *b_TrkStepLocY;   //!
   TBranch        *b_TrkStepEloss;   //!
   TBranch        *b_TrkStepEloss1;   //!
   TBranch        *b_TrkStepEloss0;   //!
   TBranch        *b_TrkStepEloss5;   //!
   TBranch        *b_TrkStepEloss10;   //!
   TBranch        *b_TrkStepScaleEloss;   //!
   TBranch        *b_TrkStepScaleX0;   //!
   TBranch        *b_TrkStepX0;   //!
   TBranch        *b_TrkStepErd0;   //!                            
   TBranch        *b_TrkStepErz0;   //!                            
   TBranch        *b_TrkStepErphi;   //!                           
   TBranch        *b_TrkStepErtheta;   //!                         
   TBranch        *b_TrkStepErqoverp;   //!                        
   TBranch        *b_TrkStepScatStatus;   //!                             
   TBranch        *b_TrkStepScatX;   //!                                  
   TBranch        *b_TrkStepScatY;   //!                                  
   TBranch        *b_TrkStepScatZ;   //!                                  
   TBranch        *b_TrkStepScatX0;   //!                                 
   TBranch        *b_TrkStepScatEloss;   //!                              
   TBranch        *b_TrkStepScatMeanIoni;   //!                            
   TBranch        *b_TrkStepScatSigIoni;   //!                            
   TBranch        *b_TrkStepScatMeanRad;   //!                            
   TBranch        *b_TrkStepScatSigRad;   //!                             
   TBranch        *b_TrkStepScatSigTheta;   //!                             
   TBranch        *b_TrkStepScatSigPhi;   //!                             
 
   G4Check();
   virtual ~G4Check();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef G4Check_cxx
G4Check::G4Check() : fChain(0) 
{
   TChain* chain = new TChain("G4FollowerFollower") ;
   
   // chain->Add("GeantFollowingR2015_B.root"); 
   // chain->Add("GeantFollowingR2015_T.root"); 
   // chain->Add("GeantFollowingR2015_E.root"); 
   
   // chain->Add("10022023_vers_1_0_ChargedGeantino_25GeV_eta0_10.root"); 
   // chain->Add("10022023_vers_1_0_ChargedGeantino_25GeV_eta10_18.root"); 
   // chain->Add("10022023_vers_1_0_ChargedGeantino_25GeV_eta18_25.root");  
   
   // chain->Add("GeantFollowerFollowerNTuple/G4_ATLAS-R3S-2021-03-02-00_ChargedGeantino_25GeV_eta13_25.root"); 
   // chain->Add("GeantFollowerFollowerNTuple/G4_ATLAS-R2-2016-01-00-01_ChargedGeantino_25GeV_eta0_3_inclCalo_Legacy.root"); 
   // chain->Add("GeantFollowerFollowerNTuple/G4_ATLAS-R2-2016-01-00-01_ChargedGeantino_25GeV_eta0_3_noCalo_CA.root"); 
   chain->Add("GeantFollowerFollowerNTuple/G4_ATLAS-R3S-2021-03-02-00_ChargedGeantino_25GeV_eta0_3_noCalo_CA.root"); 
   
   Init(chain);
}

G4Check::~G4Check()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t G4Check::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t G4Check::LoadTree(Long64_t entry)
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

void G4Check::Init(TTree *tree)
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

   fChain->SetBranchAddress("InitX", &InitX, &b_initX);
   fChain->SetBranchAddress("InitY", &InitY, &b_initY);
   fChain->SetBranchAddress("InitZ", &InitZ, &b_initZ);
   fChain->SetBranchAddress("InitTheta", &InitTheta, &b_initTheta);
   fChain->SetBranchAddress("InitEta", &InitEta, &b_initEta);
   fChain->SetBranchAddress("InitPhi", &InitPhi, &b_initPhi);
   fChain->SetBranchAddress("InitP", &InitP, &b_initP);
   fChain->SetBranchAddress("InitPdg", &InitPdg, &b_initPdg);
   fChain->SetBranchAddress("InitCharge", &InitCharge, &b_initQ);
   fChain->SetBranchAddress("MEntryX", &MEntryX, &b_mentryX);
   fChain->SetBranchAddress("MEntryY", &MEntryY, &b_mentryY);
   fChain->SetBranchAddress("MEntryZ", &MEntryZ, &b_mentryZ);
   fChain->SetBranchAddress("MEntryTheta", &MEntryTheta, &b_mentryTheta);
   fChain->SetBranchAddress("MEntryEta", &MEntryEta, &b_mentryEta);
   fChain->SetBranchAddress("MEntryPhi", &MEntryPhi, &b_mentryPhi);
   fChain->SetBranchAddress("MEntryP", &MEntryP, &b_mentryP);
   fChain->SetBranchAddress("BackX", &BackX, &b_backX);
   fChain->SetBranchAddress("BackY", &BackY, &b_backY);
   fChain->SetBranchAddress("BackZ", &BackZ, &b_backZ);
   fChain->SetBranchAddress("BackTheta", &BackTheta, &b_backTheta);
   fChain->SetBranchAddress("BackEta", &BackEta, &b_backEta);
   fChain->SetBranchAddress("BackPhi", &BackPhi, &b_backPhi);
   fChain->SetBranchAddress("BackP", &BackP, &b_backP);
   fChain->SetBranchAddress("BackX0", &BackX0, &b_backX0);
   fChain->SetBranchAddress("BackEloss", &BackEloss, &b_backEloss);
   fChain->SetBranchAddress("G4Steps", &G4Steps, &b_g4steps);
   fChain->SetBranchAddress("TrkStepScats", &TrkStepScats, &b_trkscats);
   fChain->SetBranchAddress("G4StepP", G4StepP, &b_G4StepP);
   fChain->SetBranchAddress("G4StepEta", G4StepEta, &b_G4StepEta);
   fChain->SetBranchAddress("G4StepTheta", G4StepTheta, &b_G4StepTheta);
   fChain->SetBranchAddress("G4StepPhi", G4StepPhi, &b_G4StepPhi);
   fChain->SetBranchAddress("G4StepX", G4StepX, &b_G4StepX);
   fChain->SetBranchAddress("G4StepY", G4StepY, &b_G4StepY);
   fChain->SetBranchAddress("G4StepZ", G4StepZ, &b_G4StepZ);
   fChain->SetBranchAddress("G4AccumTX0", G4AccumTX0, &b_G4AccumTX0);
   fChain->SetBranchAddress("G4StepT", G4StepT, &b_G4StepT);
   fChain->SetBranchAddress("G4StepX0", G4StepX0, &b_G4StepX0);
   fChain->SetBranchAddress("TrkStepStatus", TrkStepStatus, &b_TrkStepStatus);
   fChain->SetBranchAddress("TrkStepP", TrkStepP, &b_TrkStepP);
   fChain->SetBranchAddress("TrkStepEta", TrkStepEta, &b_TrkStepEta);
   fChain->SetBranchAddress("TrkStepTheta", TrkStepTheta, &b_TrkStepTheta);
   fChain->SetBranchAddress("TrkStepPhi", TrkStepPhi, &b_TrkStepPhi);
   fChain->SetBranchAddress("TrkStepX", TrkStepX, &b_TrkStepX);
   fChain->SetBranchAddress("TrkStepY", TrkStepY, &b_TrkStepY);
   fChain->SetBranchAddress("TrkStepZ", TrkStepZ, &b_TrkStepZ);
   fChain->SetBranchAddress("TrkStepLocX", TrkStepLocX, &b_TrkStepLocX);
   fChain->SetBranchAddress("TrkStepLocY", TrkStepLocY, &b_TrkStepLocY);
   fChain->SetBranchAddress("TrkStepEloss", TrkStepEloss, &b_TrkStepEloss);
   fChain->SetBranchAddress("TrkStepEloss1", TrkStepEloss1, &b_TrkStepEloss1);
   fChain->SetBranchAddress("TrkStepEloss0", TrkStepEloss0, &b_TrkStepEloss0);
   fChain->SetBranchAddress("TrkStepEloss5", TrkStepEloss5, &b_TrkStepEloss5);
   fChain->SetBranchAddress("TrkStepEloss10", TrkStepEloss10, &b_TrkStepEloss10);
   fChain->SetBranchAddress("TrkStepScaleEloss", TrkStepScaleEloss, &b_TrkStepScaleEloss);
   fChain->SetBranchAddress("TrkStepScaleX0", TrkStepScaleX0, &b_TrkStepScaleX0);
   fChain->SetBranchAddress("TrkStepX0", TrkStepX0, &b_TrkStepX0);
   fChain->SetBranchAddress("TrkStepErd0", TrkStepErd0, &b_TrkStepErd0);
   fChain->SetBranchAddress("TrkStepErz0", TrkStepErz0, &b_TrkStepErz0);
   fChain->SetBranchAddress("TrkStepErphi", TrkStepErphi, &b_TrkStepErphi);
   fChain->SetBranchAddress("TrkStepErtheta", TrkStepErtheta, &b_TrkStepErtheta);
   fChain->SetBranchAddress("TrkStepErqoverp", TrkStepErqoverp, &b_TrkStepErqoverp);
   fChain->SetBranchAddress("TrkStepScatStatus", TrkStepScatStatus, &b_TrkStepScatStatus);
   fChain->SetBranchAddress("TrkStepScatX", TrkStepScatX, &b_TrkStepScatX);
   fChain->SetBranchAddress("TrkStepScatY", TrkStepScatY, &b_TrkStepScatY);
   fChain->SetBranchAddress("TrkStepScatZ", TrkStepScatZ, &b_TrkStepScatZ);
   fChain->SetBranchAddress("TrkStepScatX0", TrkStepScatX0, &b_TrkStepScatX0);
   fChain->SetBranchAddress("TrkStepScatEloss", TrkStepScatEloss, &b_TrkStepScatEloss);
   fChain->SetBranchAddress("TrkStepScatMeanIoni", TrkStepScatMeanIoni, &b_TrkStepScatMeanIoni);
   fChain->SetBranchAddress("TrkStepScatSigIoni", TrkStepScatSigIoni, &b_TrkStepScatSigIoni);
   fChain->SetBranchAddress("TrkStepScatMeanRad", TrkStepScatMeanRad, &b_TrkStepScatMeanRad);
   fChain->SetBranchAddress("TrkStepScatSigRad", TrkStepScatSigRad, &b_TrkStepScatSigRad);
   fChain->SetBranchAddress("TrkStepScatSigTheta", TrkStepScatSigTheta, &b_TrkStepScatSigTheta);
   fChain->SetBranchAddress("TrkStepScatSigPhi", TrkStepScatSigPhi, &b_TrkStepScatSigPhi);
 
   Notify();
}

Bool_t G4Check::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void G4Check::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t G4Check::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef G4Check_cxx
