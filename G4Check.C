#define G4Check_cxx
#include "G4Check.h"
#include "TRandom.h"
#include <TProfile.h>
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TProfile2D.h>
#include <iostream>

double parGirder(double x)
{

  double p0 = -1.02877e-01;
  double p1 = -2.74322e-02;
  double p2 = 8.12989e-02;
  double p3 = 9.73551e-01;

  double fun = 0.;

  double pi = acos(-1.);
  if (x > pi / 64.)
    x = pi / 32. - x;

  if (x < 0.005)
  {
    fun = p0 * (1 - x / 0.005) + p1 + p3;
    ;
  }
  else if (x < 0.017)
  {
    fun = p1 + p3;
  }
  else if (x < 0.028)
  {
    fun = p2 + p3;
  }
  else
  {
    fun = p3;
  }
  return fun;
}

double parX0Calo(double eta)
{

  // 45k stats
  Double_t cor[60] = {1.03178, 1.03178, 1.03178, 1.03178, 1.01512, 1.01456, 1.01266, 1.02299, 1.01437, 1.01561, 1.01731, 1.02502, 1.01171, 0.987469, 0.979134, 1.01018, 1.01813, 0.986147, 0.973686, 0.983771, 0.960334, 0.967629, 0.982935, 0.993162, 1.00241, 1.00012, 0.9814, 0.937632, 0.927918, 0.93491, 0.934184, 0.921438, 0.933788, 0.954208, 0.973684, 0.977765, 1.00697, 1.01779, 1.02017, 1.01604, 1.02121, 1.02344, 1.02888, 1.02278, 1.03096, 1.02409, 1.03149, 1.03797, 1.04254, 1.04943, 1.02433, 1.02379, 1.02177, 1.02271, 1.02011, 1.02414, 1.03649, 1.03739, 1.03739, 1.03739};

  // mig5 20 k stats
  //   Double_t cor[60] = {1.02124 ,1.02124 ,1.02124 ,1.02124 ,1.01721 ,1.01407 ,1.0136 ,1.0253 ,1.01365 ,1.01821 ,1.01543 ,1.02871 ,1.01219 ,0.98993 ,0.977229 ,1.00835 ,1.01718 ,0.98492 ,0.975327 ,0.98352 ,0.960929 ,0.965488 ,0.982056 ,0.994551 ,1.00359 ,1.00165 ,0.98382 ,0.942448 ,0.922154 ,0.931234 ,0.930522 ,0.916653 ,0.936608 ,0.959158 ,0.976214 ,0.974339 ,1.01317 ,1.01818 ,1.02007 ,1.01665 ,1.01576 ,1.02323 ,1.02534 ,1.02737 ,1.03222 ,1.02983 ,1.02885 ,1.03859 ,1.04651 ,1.04611 ,1.02823 ,1.02675 ,1.01476 ,1.02293 ,1.02541 ,1.02888 ,1.0244 ,1.03027 ,1.03027 ,1.03027} ;

  int i = fabs(eta) * 20.;
  if (i < 0)
    i = 0;
  if (i > 59)
    i = 59;
  //   if(debug) std::cout << " eta " << eta << " i " << i << " cor " << cor[i] << std::endl;

  return cor[i];
}

double parECalo(double eta)
{

  // 0.75 Radiative term with 45k
  Double_t cor[30] = {1.03504, 1.03504, 1.03504, 1.02631, 1.04258, 1.03506, 1.05307, 1.02399, 1.04237, 1.04368, 1.04043, 1.05899, 1.07933, 1.08604, 1.08984, 1.03564, 1.04158, 1.05983, 1.06291, 1.06853, 1.0674, 1.05427, 1.06466, 1.06274, 1.06141, 1.06314, 1.06868, 1.07242, 1.07242, 1.07242};
  // mig5

  int i = fabs(eta) * 10.;
  if (i > 29)
    i = 29;
  // if(debug) std::cout << " parECalo eta " << eta << " i " << i << " cor " << cor[i] << std::endl;
  double nfactor = 0.982124 / 1.05471;
  //  return 1.;
  return nfactor * cor[i];
}

double parX0Muon(double eta)
{

  // GEO20 45k

  Double_t cor[60] = {-0.0320612, -0.0320612, -0.0320612, -0.0320612, -0.0693796, -0.0389677, -0.0860891, -0.124606, -0.0882329, -0.100014, -0.0790912, -0.0745538, -0.099088, -0.0933711, -0.0618782, -0.0619762, -0.0658361, -0.109704, -0.129547, -0.143364, -0.0774768, -0.0739859, -0.0417835, -0.022119, 0.00308797, 0.0197657, -0.0137871, -0.036848, -0.0643794, -0.0514949, -0.0317105, 0.016539, 0.0308435, -0.00056883, -0.00756813, -0.00760612, -0.0234571, -0.0980915, -0.101175, -0.102354, -0.0920337, -0.100337, -0.0887628, 0.0660931, 0.228999, 0.260675, 0.266301, 0.267907, 0.281668, 0.194433, 0.132954, 0.20707, 0.220466, 0.20936, 0.191441, 0.191441, 0.191441, 0.191441, 0.191441, 0.191441};

  // Geo18 Endcap
  // Double_t cor[60] = {-0.0524448 ,-0.0524448 ,-0.0524448 ,-0.0524448 ,-0.0506929 ,-0.0491576 ,-0.0955434 ,-0.125063 ,-0.0863253 ,-0.127847 ,-0.0826005 ,-0.0895255 ,-0.0954147 ,-0.112146 ,-0.0646774 ,-0.0636472 ,-0.0771456 ,-0.0919958 ,-0.138729 ,-0.115886 ,-0.0968916 ,-0.0682437 ,-0.0503603 ,-0.0238543 ,0.0377708 ,0.0338091 ,-0.0187157 ,-0.0581091 ,-0.104531 ,-0.109987 ,-0.0971831 ,-0.113634 ,-0.121449 ,-0.133594 ,-0.141091 ,-0.153444 ,-0.144693 ,-0.135383 ,-0.129588 ,-0.143546 ,-0.123658 ,-0.119543 ,-0.0861694 ,0.12975 ,0.482569 ,0.498103 ,0.463044 ,0.514416 ,0.638068 ,0.833333 ,0.557735 ,0.467615 ,0.451027 ,0.443173 ,0.453267 ,0.453267 ,0.453267 ,0.453267 ,0.453267 ,0.453267} ;

  // mig5 20k
  //  Double_t cor[60] = {-0.0289854 ,-0.0289854 ,-0.0289854 ,-0.0289854 ,-0.0581383 ,-0.0376326 ,-0.0795213 ,-0.114683 ,-0.0744858 ,-0.0938796 ,-0.0695401 ,-0.0662197 ,-0.0775049 ,-0.0757817 ,-0.063343 ,-0.054818 ,-0.0573428 ,-0.107035 ,-0.116168 ,-0.108666 ,-0.0803247 ,-0.0608293 ,-0.0380377 ,-0.0206689 ,-0.00324253 ,0.00607113 ,-0.0101428 ,-0.0457239 ,-0.0580899 ,-0.0426557 ,-0.033946 ,0.0183286 ,0.00977019 ,0.002858 ,-0.0179787 ,-0.0200432 ,-0.0162646 ,-0.0841223 ,-0.106476 ,-0.0977252 ,-0.0986742 ,-0.103055 ,-0.0826538 ,0.0321556 ,0.175617 ,0.208 ,0.203943 ,0.211631 ,0.195508 ,0.134583 ,0.110726 ,0.147949 ,0.174634 ,0.170799 ,0.161477 ,0.161477 ,0.161477 ,0.161477 ,0.161477 ,0.1614779} ;

  int i = fabs(eta) * 20.;
  if (i < 0)
    i = 0;
  if (i > 59)
    i = 59;
  // if(debug) std::cout << " eta " << eta << " i " << i << " cor scale " << (1+cor[i]) << std::endl;

  // No correction anymore
  return 1.;
  //  return (1+cor[i]);
}

void G4Check::Loop()
{
  if (fChain == 0)
    return;

  //  TString fname = "G4MC16ValidationTest.root";

  //  TString fname = "G4_ATLAS-R3S-2021-03-02-00_ChargedGeantino_25GeV_eta13_25_histos.root";
  //  TString fname = "G4_ATLAS-R2-2016-01-00-01_ChargedGeantino_25GeV_eta0_3_inclCalo_Legacy_histos.root";
  //  TString fname = "G4_ATLAS-R2-2016-01-00-01_ChargedGeantino_25GeV_eta0_3_noCalo_CA_histos.root";
  TString fname = "G4_ATLAS-R3S-2021-03-02-00_ChargedGeantino_25GeV_eta0_3_noCalo_CA_histos_selectedEvents.root";
  TFile *file = new TFile(fname, "recreate");

  // special case
  TH1D *hdX0XG4Trk = new TH1D("hdX0XG4Trk", " ", 1000, -1., 1.);

  TH1D *hresizBACK_B = new TH1D("hresizBACK_B", " ", 1000, -0.1, 0.1);
  TH1D *hphiBACK_B = new TH1D("hphiBACK_B", " ", 1000, -3.142, 3.142);
  TH1D *hdpBACK_B = new TH1D("hdpBACK_B", " ", 1000, -5000., 5000.);
  TH1D *hdX0BACK_B = new TH1D("hdX0BACK_B", " ", 1000, -100., 100.);
  TH1D *hdX0G4BACK_B = new TH1D("hdX0G4BACK_B", " ", 1000, -100., 100.);
  TH1D *hdX0XBACK_B = new TH1D("hdX0XBACK_B", " ", 1000, -1., 1.);
  TH1D *hdX0XBACKOK_B = new TH1D("hdX0XBACKOK_B", " ", 1000, -1., 1.);
  TH1D *hdX0XBACKBAD_B = new TH1D("hdX0XBACKBAD_B", " ", 1000, -1., 1.);
  TH1D *hetaBAD_B = new TH1D("hetaBAD_B", " ", 300, -3.0, 3.0);
  TH1D *hphiBAD_B = new TH1D("hphiBAD_B", " ", 1000, -3.142, 3.142);
  TH1D *hetaBAD_E = new TH1D("hetaBAD_E", " ", 300, -3.0, 3.0);
  TH1D *hphiBAD_E = new TH1D("hphiBAD_E", " ", 1000, -3.142, 3.142);

  TH1D *hresizG4Trk_B = new TH1D("hresizG4Trk_B", " ", 1000, -100., 100.);
  TH1D *hdpG4Trk_B = new TH1D("hdpG4Trk_B", " ", 1000, -5000., 5000.);
  TH1D *hphiG4Trk_B = new TH1D("hphiG4Trk_B", " ", 1000, -3.142, 3.142);
  TH1D *hdX0G4Trk_B = new TH1D("hdX0G4Trk_B", " ", 1000, -10., 10.);
  TH1D *hdX0XG4Trk_B = new TH1D("hdX0XG4Trk_B", " ", 1000, -1., 1.);
  TH1D *hX0Trk_B = new TH1D("hX0Trk_B", " ", 1000, 0., 200.);
  TH1D *hX0G4_B = new TH1D("hX0G4_B", " ", 1000, 0., 200.);

  TH1D *hresizBACK_E = new TH1D("hresizBACK_E", " ", 1000, -25., 25.);
  TH1D *hphiBACK_E = new TH1D("hphiBACK_E", " ", 1000, -3.142, 3.142);
  TH1D *hdpBACK_E = new TH1D("hdpBACK_E", " ", 1000, -5000., 5000.);
  TH1D *hdX0BACK_E = new TH1D("hdX0BACK_E", " ", 1000, -100., 100.);
  TH1D *hdX0XBACK_E = new TH1D("hdX0XBACK_E", " ", 1000, -1., 1.);
  TH1D *hdX0G4BACK_E = new TH1D("hdX0G4BACK_E", " ", 1000, -100., 100.);
  TH1D *hdX0XBACKOK_E = new TH1D("hdX0XBACKOK_E", " ", 1000, -1., 1.);
  TH1D *hdX0XBACKBAD_E = new TH1D("hdX0XBACKBAD_E", " ", 1000, -1., 1.);
  TH1D *heta_B = new TH1D("heta_B", " ", 300, -3.0, 3.0);
  TH1D *hphi_B = new TH1D("hphi_B", " ", 1000, -3.142, 3.142);
  TH1D *heta_E = new TH1D("heta_E", " ", 300, -3.0, 3.0);
  TH1D *hphi_E = new TH1D("hphi_E", " ", 1000, -3.142, 3.142);

  TH1D *hresizG4Trk_E = new TH1D("hresizG4Trk_E", " ", 1000, -100., 100.);
  TH1D *hdpG4Trk_E = new TH1D("hdpG4Trk_E", " ", 1000, -5000., 5000.);
  TH1D *hphiG4Trk_E = new TH1D("hphiG4Trk_E", " ", 1000, -3.142, 3.142);
  TH1D *hdX0G4Trk_E = new TH1D("hdX0G4Trk_E", " ", 1000, -100., 100.);
  TH1D *hdX0XG4Trk_E = new TH1D("hdX0XG4Trk_E", " ", 1000, -1., 1.);
  TH1D *hX0Trk_E = new TH1D("hX0Trk_E", " ", 1000, 0., 200.);
  TH1D *hX0G4_E = new TH1D("hX0G4_E", " ", 1000, 0., 200.);

  TH1D *hdElossTrk = new TH1D("hdElossTrk", " ", 1000, -100., 100.);
  TH2D *hdEEG4Trk = new TH2D("hdEEG4Trk", " ", 100, -1., 1., 100, 0., 5000.);
  TH2D *hetaEloss = new TH2D("hetaEloss", " ", 300, -3., 3., 100, 0., 5000.);
  TH2D *hetarz = new TH2D("hetarz", " ", 300, -3., 3., 100, -100., 100.);
  TH2D *hetad0 = new TH2D("hetad0", " ", 300, -3., 3., 100, -100., 100.);
  TH2D *hetarzp = new TH2D("hetarzp", " ", 300, -3., 3., 1000, -1, 1);
  TH2D *hetad0p = new TH2D("hetad0p", " ", 300, -3., 3., 1000, -1, 1);
  TH2D *hphiEloss_B = new TH2D("hphiEloss_B", " ", 20, 0., 3.14 / 4., 100, 0., 5000.);
  TH2D *h2etaEloss = new TH2D("h2etaEloss", " ", 300, -3.0, 3.0, 100, 0., 2.5);
  TH2D *h2etadX0X = new TH2D("h2etadX0X", " ", 60, .0, 3.0, 100, -1.0, 1.0);
  TH2D *h2phidX0XB = new TH2D("h2phidX0XB", " ", 64, -3.1415, 3.1415, 100, -1.0, 1.0);
  TH2D *h2phidX0B = new TH2D("h2phidX0B", " ", 64, -3.1415, 3.1415, 200, -20.0, 20.0);
  TH2D *h2phidX0XE = new TH2D("h2phidX0XE", " ", 64, -3.1415, 3.1415, 100, -1.0, 1.0);
  TH2D *h2phidX0E = new TH2D("h2phidX0E", " ", 64, -3.1415, 3.1415, 200, -20.0, 20.0);
  TProfile *hetadX0X = new TProfile("hetadX0X", " ", 60, .0, 3.0, -1.0, 1.0);
  TProfile *hetadX0XF = new TProfile("hetadX0XF", " ", 60, .0, 3.0, -1.0, 1.0);
  TH2D *h2etadX0XF = new TH2D("h2etadX0XF", " ", 60, 0., 3.0, 100, -1.0, 1.0);
  TH2D *h2etadX0F = new TH2D("h2etadX0F", " ", 60, 0., 3.0, 200, -20.0, 20.0);
  TH2D *h2etadX0 = new TH2D("h2etadX0", " ", 60, 0., 3.0, 200, -20.0, 20.0);

  TH2D *h2etaMOP = new TH2D("h2etaMOP", " ", 60, 0., 3.0, 700, -2000., 5000.);
  TH2D *h2etapMOP = new TH2D("h2etapMOP", " ", 60, 0., 3.0, 700, -20., 50.);
  TH2D *h2etarMOP = new TH2D("h2etarMOP", " ", 60, 0., 3.0, 100, -1., 2.5);
  TProfile *hetaMOP = new TProfile("hetaMOP", " ", 30, 0., 3.0, -500., 1000.);
  TProfile *hetarMOP = new TProfile("hetarMOP", " ", 60, 0., 3.0, -1., 2.5);
  TProfile *hetaSigIoni = new TProfile("hetaSigIoni", " ", 60, 0., 3., 0., 1000.);
  TProfile *hetaElossTG = new TProfile("hetaElossTG", " ", 30, 0., 3.0, 1000., 10000.);

  TH1D *hpullzG4Trk_B = new TH1D("hpullzG4Trk_B", " ", 100, -10., 10.);
  TH1D *hpulld0G4Trk_B = new TH1D("hpulld0G4Trk_B", " ", 100, -10., 10.);
  TH1D *hpullphiG4Trk_B = new TH1D("hpullphiG4Trk_B", " ", 100, -10., 10.);
  TH1D *hpullthetaG4Trk_B = new TH1D("hpullthetaG4Trk_B", " ", 100, -10., 10.);
  TH1D *hpullthetaG4Trk_BScat = new TH1D("hpullthetaG4Trk_BScat", " ", 100, -10., 10.);
  TH1D *hpullphiG4Trk_BScat = new TH1D("hpullphiG4Trk_BScat", " ", 100, -10., 10.);
  TH1D *hpullthetaG4Trk_BScatO = new TH1D("hpullthetaG4Trk_BScatO", " ", 100, -10., 10.);
  TH1D *hpullphiG4Trk_BScatO = new TH1D("hpullphiG4Trk_BScatO", " ", 100, -10., 10.);
  TH1D *hpullpG4Trk_B = new TH1D("hpullpG4Trk_B", " ", 100, -10., 10.);

  TH1D *hpullzG4Trk_E = new TH1D("hpullzG4Trk_E", " ", 100, -10., 10.);
  TH1D *hpulld0G4Trk_E = new TH1D("hpulld0G4Trk_E", " ", 100, -10., 10.);
  TH1D *hpullphiG4Trk_E = new TH1D("hpullphiG4Trk_E", " ", 100, -10., 10.);
  TH1D *hpullthetaG4Trk_E = new TH1D("hpullthetaG4Trk_E", " ", 100, -10., 10.);
  TH1D *hpullpG4Trk_E = new TH1D("hpullpG4Trk_E", " ", 100, -10., 10.);

  TH1D *hdX0XL5_B = new TH1D("hdX0XL5_B", " ", 1000, -10., 10.);
  TH1D *hdX0XG5_B = new TH1D("hdX0XG5_B", " ", 1000, -10., 10.);
  TH1D *hdX0X_E = new TH1D("hdX0X_E", " ", 1000, -10., 10.);

  TProfile *hetaX0 = new TProfile("hetaX0", " ", 300, -3.0, 3.0, 0., 2.5);
  TProfile *hetaX0Bef = new TProfile("hetaX0Bef", " ", 300, -3.0, 3.0, 0., 2.5);
  TProfile *hetaX0I = new TProfile("hetaX0I", " ", 300, -3.0, 3.0, 0., 2.5);
  TProfile *hetaX0M = new TProfile("hetaX0M", " ", 300, -3.0, 3.0, 0., 2.5);
  TProfile *hetaX0T = new TProfile("hetaX0T", " ", 300, -3.0, 3.0, 0., 2.5);
  TProfile *hetaX0O = new TProfile("hetaX0O", " ", 300, -3.0, 3.0, 0., 2.5);

  TProfile *hetaX0Trk = new TProfile("hetaX0Trk", " ", 300, -3.0, 3.0, 0., 500.);
  TProfile *hetaX0TrkBef = new TProfile("hetaX0TrkBef", " ", 300, -3.0, 3.0, 0., 500.);
  TProfile *hetaX0TrkI = new TProfile("hetaX0TrkI", " ", 300, -3.0, 3.0, 0., 500.);
  TProfile *hetaX0TrkM = new TProfile("hetaX0TrkM", " ", 300, -3.0, 3.0, 0., 500.);
  TProfile *hetaX0TrkT = new TProfile("hetaX0TrkT", " ", 300, -3.0, 3.0, 0., 500.);
  TProfile *hetaX0TrkO = new TProfile("hetaX0TrkO", " ", 300, -3.0, 3.0, 0., 500.);

  TProfile *hetaX0G4 = new TProfile("hetaX0G4", " ", 300, -3.0, 3.0, 0., 500.);
  TProfile *hetaX0G4Bef = new TProfile("hetaX0G4Bef", " ", 300, -3.0, 3.0, 0., 500.);
  TProfile *hetaX0G4I = new TProfile("hetaX0G4I", " ", 300, -3.0, 3.0, 0., 500.);
  TProfile *hetaX0G4M = new TProfile("hetaX0G4M", " ", 300, -3.0, 3.0, 0., 500.);
  TProfile *hetaX0G4T = new TProfile("hetaX0G4T", " ", 300, -3.0, 3.0, 0., 500.);
  TProfile *hetaX0G4O = new TProfile("hetaX0G4O", " ", 300, -3.0, 3.0, 0., 500.);

  TProfile *hphiX0_B = new TProfile("hphiX0_B", " ", 20, 0., 3.14 / 4., 0., 2.5);
  TH2D *hphiX0G4_B = new TH2D("hphiX0G4_B", " ", 20, 0., 3.14 / 4., 100, 0., 100.);
  TProfile *hphiX0_E = new TProfile("hphiX0_E", " ", 20, 0., 3.14 / 4., 0., 2.5);
  TProfile *hphiX0Bef = new TProfile("hphiX0Bef", " ", 20, 0, 3.14 / 4., 0., 2.5);
  TProfile *hphiX0T = new TProfile("hphiX0T", " ", 20, 0., 3.14 / 4., 0., 2.5);
  TProfile *hphiX0I_B = new TProfile("hphiX0I_B", " ", 20, 0., 3.14 / 4., 0., 2.5);
  TProfile *hphiX0I_E = new TProfile("hphiX0I_E", " ", 20, 0., 3.14 / 4., 0., 2.5);
  TProfile *hphiX0M_B = new TProfile("hphiX0M_B", " ", 20, 0., 3.14 / 4., 0., 2.5);
  TProfile *hphiX0M_E = new TProfile("hphiX0M_E", " ", 20, 0., 3.14 / 4., 0., 2.5);
  TProfile *hphiX0O_B = new TProfile("hphiX0O_B", " ", 20, 0., 3.14 / 4., 0., 2.5);
  TProfile *hphiX0O_E = new TProfile("hphiX0O_E", " ", 20, 0., 3.14 / 4., 0., 2.5);

  TH1D *hcdElossTrk = new TH1D("hcdElossTrk", " ", 1000, -100., 100.);
  TH1D *hcX0G4 = new TH1D("hcX0G4", " ", 1000, 0., 200.);
  TH1D *hcX0G42 = new TH1D("hcX0G42", " ", 1000, 0., 200.);
  TH1D *hcX0Trk = new TH1D("hcX0Trk", " ", 1000, 0., 200.);
  TH1D *hcX0TrkG = new TH1D("hcX0TrkG", " ", 1000, 0., 200.);
  TH1D *hcX0TrkF = new TH1D("hcX0TrkF", " ", 1000, 0., 200.);
  TH1D *hcX0TrkF2 = new TH1D("hcX0TrkF2", " ", 1000, 0., 200.);
  TH1D *hcElossG4 = new TH1D("hcElossG4", " ", 5000, 0., 1000.);
  TH1D *hcEmop = new TH1D("hcEmop", " ", 1000, 0., 10.);
  TH1D *hcErad = new TH1D("hcErad", " ", 5000, 0., 50.);
  TH1D *hcErad0 = new TH1D("hcErad0", " ", 5000, 0., 50.);
  TH1D *hcErad1 = new TH1D("hcErad1", " ", 5000, 0., 50.);

  TH1D *hcsigmaL = new TH1D("hcsigmaL", " ", 5000, 0., 1000.);
  TH1D *hcsigmaLtot = new TH1D("hcsigmaLtot", " ", 5000, 0., 1000.);
  TH1D *hcsigmaLratio = new TH1D("hcsigmaLratio", " ", 5000, 0., 1.);
  TH1D *hcsigmaR = new TH1D("hcsigmaR", " ", 5000, 0., 1000.);

  TH1D *hcresirzG4Trk_B = new TH1D("hcresirzG4Trk_B", " ", 100, -100., 100.);
  TH1D *hcresid0G4Trk_B = new TH1D("hcresid0G4Trk_B", " ", 100, -100., 100.);
  TH1D *hcresiphiG4Trk_B = new TH1D("hcresiphiG4Trk_B", " ", 100, -0.1, 0.1);
  TH1D *hcresithetaG4Trk_B = new TH1D("hcresithetaG4Trk_B", " ", 100, -0.1, 0.1);
  TH1D *hcresipG4Trk_B = new TH1D("hcresipG4Trk_B", " ", 100, -10000., 10000.);

  TH1D *hcpullzG4Trk_B = new TH1D("hcpullzG4Trk_B", " ", 100, -10., 10.);
  TH1D *hcpulld0G4Trk_B = new TH1D("hcpulld0G4Trk_B", " ", 100, -10., 10.);
  TH1D *hcpullphiG4Trk_B = new TH1D("hcpullphiG4Trk_B", " ", 100, -10., 10.);
  TH1D *hcpullthetaG4Trk_B = new TH1D("hcpullthetaG4Trk_B", " ", 100, -10., 10.);
  TH1D *hcpullthetaG4Trk_BScat = new TH1D("hcpullthetaG4Trk_BScat", " ", 100, -10., 10.);
  TH1D *hcpullphiG4Trk_BScat = new TH1D("hcpullphiG4Trk_BScat", " ", 100, -10., 10.);
  TH1D *hcpullthetaG4Trk_BScatO = new TH1D("hcpullthetaG4Trk_BScatO", " ", 100, -10., 10.);
  TH1D *hcpullphiG4Trk_BScatO = new TH1D("hcpullphiG4Trk_BScatO", " ", 100, -10., 10.);
  TH1D *hcpullpG4Trk_B = new TH1D("hcpullpG4Trk_B", " ", 100, -10., 10.);

  TH1D *hcresirzG4Trk_E = new TH1D("hcresirzG4Trk_E", " ", 100, -100., 100.);
  TH1D *hcresid0G4Trk_E = new TH1D("hcresid0G4Trk_E", " ", 100, -100., 100.);
  TH1D *hcresiphiG4Trk_E = new TH1D("hcresiphiG4Trk_E", " ", 100, -0.1, 0.1);
  TH1D *hcresithetaG4Trk_E = new TH1D("hcresithetaG4Trk_E", " ", 100, -0.1, 0.1);
  TH1D *hcresipG4Trk_E = new TH1D("hcresipG4Trk_E", " ", 100, -10000., 10000.);

  TH1D *hcpullzG4Trk_E = new TH1D("hcpullzG4Trk_E", " ", 100, -10., 10.);
  TH1D *hcpulld0G4Trk_E = new TH1D("hcpulld0G4Trk_E", " ", 100, -10., 10.);
  TH1D *hcpullphiG4Trk_E = new TH1D("hcpullphiG4Trk_E", " ", 100, -10., 10.);
  TH1D *hcpullthetaG4Trk_E = new TH1D("hcpullthetaG4Trk_E", " ", 100, -10., 10.);
  TH1D *hcpullpG4Trk_E = new TH1D("hcpullpG4Trk_E", " ", 100, -10., 10.);

  TH1D *hcdpG4Trk = new TH1D("hcdpG4Trk", " ", 1000, -5000., 5000.);

  TProfile *hcdphiX0 = new TProfile("hcdphiX0", " ", 100, 0., 3.14 / 8., 0., 1.5);
  TProfile *hcdphi32X0 = new TProfile("hcdphi32X0", " ", 100, 0., 3.14 / 32., 0., 1.5);
  TProfile *hcdphi32X0B = new TProfile("hcdphi32X0B", " ", 100, 0., 3.14 / 32., 0., 1.5);
  TProfile *hcphiX0 = new TProfile("hcphiX0", " ", 100, -3.14, 3.14, 0., 1.5);
  TProfile *hcetaX0 = new TProfile("hcetaX0", " ", 300, -3.0, 3.0, 0., 1.5);
  TProfile *hcdphiEloss = new TProfile("hcdphiEloss", " ", 100, 0., 3.14 / 8., 0., 1.5);
  TProfile *hcphiEloss = new TProfile("hcphiEloss", " ", 100, -3.14, 3.14, 0., 1.5);
  TProfile *hcphi2Eloss = new TProfile("hcphi2Eloss", " ", 100, -3.14, 3.14, 0., 1.5);
  TProfile *hcphi2X0 = new TProfile("hcphi2X0", " ", 100, -3.14, 3.14, 0., 1.5);
  TProfile *hcetaEloss = new TProfile("hcetaEloss", " ", 300, -3.0, 3.0, 0., 1.5);
  TProfile *hcetaX0F = new TProfile("hcetaX0F", " ", 60, 0., 3., 0., 1.5);
  TProfile *hcetaX0FF = new TProfile("hcetaX0FF", " ", 60, 0., 3., 0., 1.5);
  TProfile *hcetaSigIoni = new TProfile("hcetaSigIoni", " ", 60, 0., 3., 0., 1000.);

  TH2D *h2cdphiX0 = new TH2D("h2cdphiX0", " ", 100, 0., 3.14 / 8., 100, 0., 1.5);
  TH2D *h2cdphi32X0 = new TH2D("h2cdphi32X0", " ", 100, 0., 3.14 / 32., 100, 0., 1.5);
  TH2D *h2cdphi32X0B = new TH2D("h2cdphi32X0B", " ", 100, 0., 3.14 / 32., 100, 0., 1.5);
  TH2D *h2cdphi32X0T = new TH2D("h2cdphi32X0T", " ", 100, 0., 3.14 / 32., 100, 0., 1.5);
  TH2D *h2cdphi32X0TE = new TH2D("h2cdphi32X0TE", " ", 100, 0., 3.14 / 32., 100, 0., 1.5);
  TH2D *h2cetaX0 = new TH2D("h2cetaX0", " ", 300, -3.0, 3.0, 100, 0., 1.5);
  TH2D *h2cphiX0 = new TH2D("h2cphiX0", " ", 100, -3.14, 3.14, 100, 0., 1.5);
  TH2D *h2cdphiEloss = new TH2D("h2cdphiEloss", " ", 100, 0., 3.14 / 8., 100, 0., 2.5);
  TH2D *h2cetaEloss = new TH2D("h2cetaEloss", " ", 300, -3.0, 3.0, 100, 0., 2.5);

  TH2D *h2cdphiX0F = new TH2D("h2cdphiX0F", " ", 100, 0., 3.14 / 8., 100, 0., 1.5);
  TH2D *h2cdphi32X0F = new TH2D("h2cdphi32X0F", " ", 100, 0., 3.14 / 32., 100, 0., 1.5);
  TH2D *h2cetaX0F = new TH2D("h2cetaX0F", " ", 60, 0., 3., 100, 0., 1.5);
  TH2D *h2cetadX0F = new TH2D("h2cetadX0F", " ", 60, 0., 3., 200, -20., 20.);
  TH2D *h2cetaX0FF = new TH2D("h2cetaX0FF", " ", 60, 0., 3., 100, 0., 1.5);
  TH2D *h2cetadX0FF = new TH2D("h2cetadX0FF", " ", 60, 0., 3., 200, -20., 20.);

  TH1D *hcdX0G4Trk = new TH1D("hcdX0G4Trk", " ", 1000, -10., 10.);
  TH1D *hcdX0XG4Trk = new TH1D("hcdX0XG4Trk", " ", 1000, -1., 1.);

  TH2D *h2cetaG4X0 = new TH2D("h2cetaG4X0", " ", 300, -3.0, 3.0, 100, 0., 250.);
  TH2D *h2cetaTrkX0 = new TH2D("h2cetaTrkX0", " ", 300, -3.0, 3.0, 100, 0., 250.);
  TH2D *h2cetaTrkX0_HEC = new TH2D("h2cetaTrkX0_HEC", " ", 3000, 0, 3.0, 1000, 0., 250.);
  TH2D *h2cetaTrkX0_preHEC0 = new TH2D("h2cetaTrkX0_preHEC0", " ", 3000, 0, 3.0, 1000, 0., 250.);
  TH2D *h2cetaTrkX0_preHEC1 = new TH2D("h2cetaTrkX0_preHEC1", " ", 3000, .0, 3.0, 1000, 0., 250.);
  TH2D *h2cetaTrkX0_noHEC = new TH2D("h2cetaTrkX0_noHEC", " ", 300, .0, 3.0, 1000, 0., 250.);
  TH2D *h2cetadX0 = new TH2D("h2cetadX0", " ", 300, -3.0, 3.0, 200, -25., 25.);
  TH2D *h2cetadX0X = new TH2D("h2cetadX0X", " ", 300, -3.0, 3.0, 200, -0.5, 0.5);

  TProfile2D *h2cscat = new TProfile2D("h2cscat", " ", 200, 0., 7000., 200, 0., 4500., 0.0001, 1000.);
  TProfile2D *h2mfscat = new TProfile2D("h2mfscat", " ", 1000, 0., 22000., 1000, 0., 13000., 0.0001, 1000.);
  TProfile2D *h2mbscat = new TProfile2D("h2mbscat", " ", 1000, 0., 22000., 1000, 0., 13000., 0.0001, 1000.);
  TProfile2D *h2mg4scat = new TProfile2D("h2mg4scat", " ", 1000, 0., 22000., 1000, 0., 13000., 0.0001, 1000.);
  TProfile2D *h2mg4dscat = new TProfile2D("h2mg4dscat", " ", 1000, 0., 22000., 1000, 0., 13000., -1000., 1000.);

  TProfile2D *h2cg4dscat = new TProfile2D("h2cg4dscat", " ", 1000, 0., 7000., 1000, 0., 5000., -1000., 1000.);
  TProfile2D *h2cg4rscat = new TProfile2D("h2cg4rscat", " ", 1000, 0., 7000., 1000, 0., 5000., -1000., 1000.);
  TProfile2D *h2cg4rrscat = new TProfile2D("h2cg4rrscat", " ", 100, 0., 7000., 100, 0., 5000., -1000., 1000.);

  TProfile2D *h2muong4scat = new TProfile2D("h2muong4scat", " ", 1000, 0., 22000., 1000, 0., 13000., 0.0001, 1000.);
  TProfile2D *h2muonscat = new TProfile2D("h2muonscat", " ", 1000, 0., 22000., 1000, 0., 13000., 0.0001, 1000.);

  TH2D *h2cg4Eloss = new TH2D("h2cg4Eloss", " ", 1000, 0., 5000., 1000., 0., 10000.);
  TH2D *h2cTrkEloss = new TH2D("h2cTrkEloss", " ", 1000, 0., 5000., 1000., 0., 10000.);
  TH2D *h2cg4ElossX0 = new TH2D("h2cg4ElossX0", " ", 1000, 0., 5000., 1000., 0., 100.);
  TH2D *h2cTrkElossX0 = new TH2D("h2cTrkElossX0", " ", 1000, 0., 5000., 1000., 0., 100.);
  TH2D *h2cg4X0 = new TH2D("h2cg4X0", " ", 1000, 0., 5000., 1000., 0., 500.);
  TH2D *h2cTrkX0 = new TH2D("h2cTrkX0", " ", 1000, 0., 5000., 1000., 0., 500.);

  TH2D *h2cg4zEloss = new TH2D("h2cg4zEloss", " ", 1000, 0., 7000., 1000., 0., 10000.);
  TH2D *h2cTrkzEloss = new TH2D("h2cTrkzEloss", " ", 1000, 0., 7000., 1000., 0., 10000.);
  TH2D *h2cg4zElossX0 = new TH2D("h2cg4zElossX0", " ", 1000, 0., 7000., 1000., 0., 100.);
  TH2D *h2cTrkzElossX0 = new TH2D("h2cTrkzElossX0", " ", 1000, 0., 7000., 1000., 0., 100.);
  TH2D *h2cg4zX0 = new TH2D("h2cg4zX0", " ", 1000, 0., 7000., 1000., 0., 500.);
  TH2D *h2cTrkzX0 = new TH2D("h2cTrkzX0", " ", 1000, 0., 7000., 1000., 0., 500.);
  TH2D *h2cTrkzdX0 = new TH2D("h2cTrkzdX0", " ", 1000, 0., 7000., 1000., -50., 50.);
  TH2D *h2cTrkrdX0 = new TH2D("h2cTrkrdX0", " ", 1000, 0., 5000., 1000., -50., 50.);
  TProfile2D *h2cTrkdX0 = new TProfile2D("h2cTrkdX0", " ", 200, 0., 7000., 200, 0., 4500., -25., 25.);

  TH2D *h2cg4eEloss = new TH2D("h2cg4eEloss", " ", 1000, 0., 7000., 1000., 0., 10000.);
  TH2D *h2cTrkeEloss = new TH2D("h2cTrkeEloss", " ", 1000, 0., 7000., 1000., 0., 10000.);
  TH2D *h2cg4eElossX0 = new TH2D("h2cg4eElossX0", " ", 1000, 0., 7000., 1000., 0., 100.);
  TH2D *h2cTrkeElossX0 = new TH2D("h2cTrkeElossX0", " ", 1000, 0., 7000., 1000., 0., 100.);
  TH2D *h2cg4eX0 = new TH2D("h2cg4eX0", " ", 1000, 0., 7000., 1000., 0., 500.);
  TH2D *h2cTrkeX0 = new TH2D("h2cTrkeX0", " ", 1000, 0., 7000., 1000., 0., 500.);

  TH2D *h2cdphiGirder = new TH2D("h2cdphiGirder", " ", 20, 0., 3.14 / 32., 100, 0., 2.);

  TH2D *h2cetaMOP = new TH2D("h2cetaMOP", " ", 60, 0., 3.0, 100, -2000., 5000.);
  TH2D *h2cetaMOPF = new TH2D("h2cetaMOPF", " ", 60, 0., 3.0, 100, -2000., 5000.);
  TH2D *h2cetaMOPFS5 = new TH2D("h2cetaMOPFS5", " ", 60, 0., 3.0, 2000, -200000., 500000.);
  TH2D *h2cetaMOPFS10 = new TH2D("h2cetaMOPFS10", " ", 60, 0., 3.0, 2000, -200000., 500000.);
  TH2D *h2cetaMOPFN = new TH2D("h2cetaMOPFN", " ", 60, 0., 3.0, 100, -2000., 5000.);
  TH2D *h2cetaMOPFS5N = new TH2D("h2cetaMOPFS5N", " ", 60, 0., 3.0, 2000, -200000., 500000.);
  TH2D *h2cetaMOPFS10N = new TH2D("h2cetaMOPFS10N", " ", 60, 0., 3.0, 2000, -200000., 500000.);
  TH2D *h2cetapMOP = new TH2D("h2cetapMOP", " ", 60, 0., 3.0, 700, -20., 50.);
  TH2D *h2cetarMOP = new TH2D("h2cetarMOP", " ", 60, 0., 3.0, 100, -1., 2.5);
  TProfile *hcetaMOP = new TProfile("hcetaMOP", " ", 30, 0., 3.0, -1000., 2000.);
  TProfile *hcetaMOPF = new TProfile("hcetaMOPF", " ", 30, 0., 3.0, -1000., 2000.);
  TProfile *hcetarMOP = new TProfile("hcetarMOP", " ", 60, 0., 3.0, -1., 2.5);
  TProfile *hcetaElossTG = new TProfile("hcetaElossTG", " ", 30, 0., 3.0, 1000., 10000.);
  TH1D *h1cetadMOPFN = new TH1D("h1cetadMOPFN", " ", 100, -1000., 1000.);
  TH2D *h2cetadMOPFN = new TH2D("h2cetadMOPFN", " ", 30, 0., 3.0, 100, -1000., 1000.);
  TH2D *h2cetadScaleX0 = new TH2D("h2cetadScaleX0", " ", 30, 0., 3.0, 100, -0.2, 0.2);
  TH2D *h2cetadScaleEloss = new TH2D("h2cetadScaleEloss", " ", 30, 0., 3.0, 100, -0.2, 0.2);

  TH2D *hcetarzp = new TH2D("hcetarzp", " ", 300, -3., 3., 10000, -1, 1);
  TH2D *hcetad0p = new TH2D("hcetad0p", " ", 300, -3., 3., 10000, -1, 1);

  double scaleErrorIoni = 0.45;

  TRandom rnd;

  Long64_t nentries = fChain->GetEntries();

  bool debug = false;

  //   nentries = 10;
  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry = 0; jentry < nentries; jentry++)
  {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0)
      break;
    nb = fChain->GetEntry(jentry);
    nbytes += nb;
    //
    // Loop over G4 steps
    //

    // Smear momentum by 5%
    //

    int j1000 = 0;
    for (int i = 0; i < G4Steps; i++)
    {
      if (TrkStepStatus[i] == 1000)
      {
        j1000 = i;
        break;
      }
    }
    if (j1000 == 0)
      j1000 = G4Steps - 1;
    double x0g4 = G4AccumTX0[j1000];
    double x0Trk = TrkStepX0[j1000];

    if (debug)
      std::cout << " Muon eta " << MEntryEta << " X0 g4  MuonSystem " << x0g4 << " X0 Tracking Geo " << x0Trk << std::endl;

    int j10 = 0;
    for (int i = 0; i < G4Steps; i++)
    {
      if (TrkStepStatus[i] == 10)
      {
        j10 = i;
        break;
      }
    }
    double x0g4c = G4AccumTX0[j10];
    double x0Trkc = TrkStepX0[j10];
    if (j10 == 0)
      x0g4c = 0.;
    if (j10 == 0)
      x0Trkc = 0.;

    if (debug)
      std::cout << " Muon eta " << MEntryEta << " X0 g4 calorimeter " << x0g4c << " X0 Tracking Geo " << x0Trkc << std::endl;
    //       if(debug) std::cout << " jentry " << jentry << " TrkStepScats " << TrkStepScats << std::endl;
    //

    double ertheta10 = 0.;
    double erphi10 = 0.;
    double ertheta1000 = 0.;
    double erphi1000 = 0.;
    double X010 = 0;
    double X010_HEC = 0;
    double X010_preHEC0 = 0;
    double X010_preHEC1 = 0;
    double Eloss10 = 0;
    double EIoniMean10 = 0;
    double ESigIoni10 = 0;
    double ERad10 = 0;
    double ESigRad10 = 0;
    double X01000 = 0;
    double Eloss1000 = 0;
    double EIoniMean1000 = 0;
    double ESigIoni1000 = 0;
    double ERad1000 = 0;
    double ESigRad1000 = 0;

    for (int i = 0; i < TrkStepScats; i++)
    {
      if (i > 499)
        continue;
      double rr = sqrt(TrkStepScatX[i] * TrkStepScatX[i] + TrkStepScatY[i] * TrkStepScatY[i]);
      if (TrkStepScatStatus[i] == 10)
        ertheta10 += TrkStepScatSigTheta[i] * TrkStepScatSigTheta[i];
      if (TrkStepScatStatus[i] == 10)
        erphi10 += TrkStepScatSigPhi[i] * TrkStepScatSigPhi[i];
      if (TrkStepScatStatus[i] == 1000)
        ertheta1000 += TrkStepScatSigTheta[i] * TrkStepScatSigTheta[i];
      if (TrkStepScatStatus[i] == 1000)
        erphi1000 += TrkStepScatSigPhi[i] * TrkStepScatSigPhi[i];
      if (TrkStepScatStatus[i] == 10)
        X010 += TrkStepScatX0[i];
      if (TrkStepScatStatus[i] == 10 && fabs(TrkStepScatZ[i]) > 5000.)
      {
        X010_HEC += TrkStepScatX0[i];
      }
      else if (TrkStepScatStatus[i] == 10 && fabs(TrkStepScatZ[i]) > 4500.)
      {
        X010_preHEC0 += TrkStepScatX0[i];
      }
      else if (TrkStepScatStatus[i] == 10 && fabs(TrkStepScatZ[i]) > 4000.)
      {
        X010_preHEC1 += TrkStepScatX0[i];
      }
      if (TrkStepScatStatus[i] == 10)
        Eloss10 += TrkStepScatEloss[i];
      if (TrkStepScatStatus[i] == 10)
        EIoniMean10 += TrkStepScatMeanIoni[i];
      if (TrkStepScatStatus[i] == 10)
        ESigIoni10 += TrkStepScatSigIoni[i];
      if (TrkStepScatStatus[i] == 10)
        ERad10 += TrkStepScatMeanRad[i];
      if (TrkStepScatStatus[i] == 10)
        ESigRad10 += TrkStepScatSigRad[i];
      if (TrkStepScatStatus[i] == 1000)
        X01000 += TrkStepScatX0[i];
      if (TrkStepScatStatus[i] == 1000)
        Eloss1000 += TrkStepScatEloss[i];
      if (TrkStepScatStatus[i] == 1000)
        EIoniMean1000 += TrkStepScatMeanIoni[i];
      if (TrkStepScatStatus[i] == 1000)
        ESigIoni1000 += TrkStepScatSigIoni[i];
      if (TrkStepScatStatus[i] == 1000)
        ERad1000 += TrkStepScatMeanRad[i];
      if (TrkStepScatStatus[i] == 1000)
        ESigRad1000 += TrkStepScatSigRad[i];
      if (TrkStepScatStatus[i] == 10)
        if (debug)
          std::cout << " Calo TrkStepScatEloss[i] " << TrkStepScatEloss[i] << " TrkStepScatMeanIoni[i] " << TrkStepScatMeanIoni[i] << " TrkStepScatSigIoni[i] " << TrkStepScatSigIoni[i] << " TrkStepScatMeanRad[i] " << TrkStepScatMeanRad[i] << " TrkStepScatSigRad[i] " << TrkStepScatSigRad[i] << " X0 " << TrkStepScatX0[i] << " radius " << rr << " z " << TrkStepScatZ[i] << std::endl;
      if (TrkStepScatStatus[i] == 1000)
        if (debug)
          std::cout << " MS TrkStepScatEloss[i] " << TrkStepScatEloss[i] << " TrkStepScatMeanIoni[i] " << TrkStepScatMeanIoni[i] << " TrkStepScatSigIoni[i] " << TrkStepScatSigIoni[i] << " TrkStepScatMeanRad[i] " << TrkStepScatMeanRad[i] << " TrkStepScatSigRad[i] " << TrkStepScatSigRad[i] << " X0 " << TrkStepScatX0[i] << std::endl;
      // check MS
      //
      if ((TrkStepScatStatus[i] == 10 || TrkStepScatStatus[i] == 1000) && TrkStepScatX0[i] > 1.)
      {
        double p = TrkStepP[j10] - TrkStepScatEloss[i] / 2.;
        double theta = TrkStepTheta[j10];
        if (TrkStepScatStatus[i] == 1000)
          p = TrkStepP[j1000];
        if (TrkStepScatStatus[i] == 1000)
          theta = TrkStepTheta[j1000];
        double beta = p / sqrt(p * p + 140. * 140.);
        double sigScat = 13.6 * sqrt(TrkStepScatX0[i]) * (1 + 0.038 * log(TrkStepScatX0[i] / beta / beta)) / beta / p;
        double sigMol = 15. * sqrt(TrkStepScatX0[i]) / beta / p;
        //          sigScat = sigMol;
        double sigThetaMS = sigScat;
        double sigPhiMS = sigScat / sin(theta);
        if (TrkStepScatStatus[i] == 10)
          if (debug)
            std::cout << "Calo X0 " << TrkStepScatX0[i] << " error phi " << TrkStepScatSigPhi[i] << " ratio " << TrkStepScatSigPhi[i] / sigPhiMS << " error theta " << TrkStepScatSigTheta[i] << " ratio " << TrkStepScatSigTheta[i] / sigThetaMS << std::endl;
        if (TrkStepScatStatus[i] == 1000)
          if (debug)
            std::cout << "MS X0 " << TrkStepScatX0[i] << " error phi " << TrkStepScatSigPhi[i] << " ratio " << TrkStepScatSigPhi[i] / sigPhiMS << " error theta " << TrkStepScatSigTheta[i] << " ratio " << TrkStepScatSigTheta[i] / sigThetaMS << std::endl;
      }
    }
    //      double p = InitP-(InitP-TrkStepP[j10])/2.;
    // Calorimeter
    double p = InitP;
    if (debug)
      std::cout << " InitP " << InitP << " TrkStepP[j10] " << TrkStepP[j10] << " p " << p << std::endl;
    double beta = p / sqrt(p * p + 140. * 140.);
    double theta = TrkStepTheta[j10];
    double sigScattheta10 = 13.6 * sqrt(X010) * (1 + 0.038 * log(X010 / beta / beta)) / beta / p;
    double sigScatphi10 = sigScattheta10 / sin(theta);
    // Muon System
    p = TrkStepP[j10];
    beta = p / sqrt(p * p + 140. * 140.);
    double sigScattheta1000 = 13.6 * sqrt(X01000) * (1 + 0.038 * log(X01000 / beta / beta)) / beta / p;
    double sigScatphi1000 = sigScattheta1000 / sin(theta);

    ertheta10 = sqrt(ertheta10);
    //      ertheta10 = sigScat10;
    erphi10 = sqrt(erphi10);
    ertheta1000 = sqrt(ertheta1000);
    erphi1000 = sqrt(erphi1000);

    if (debug)
      std::cout << " Calorimeter  error theta " << TrkStepErtheta[j10] << " From scat centers " << ertheta10 << " sigScattheta10 " << sigScattheta10 << " ratio " << sigScattheta10 / ertheta10 << std::endl;
    if (debug)
      std::cout << " Calorimeter  error phi " << TrkStepErphi[j10] << " From scat centers " << erphi10 << std::endl;
    if (debug)
      std::cout << " Muon error theta " << TrkStepErtheta[j1000] << " From scat centers " << ertheta1000 << std::endl;
    if (debug)
      std::cout << " Muon error phi " << TrkStepErphi[j1000] << " From scat centers " << erphi1000 << std::endl;

    std::cout << " Calorimeter X0 " << TrkStepX0[j10] << " From scat centers " << X010 << std::endl;
    if (debug)
      std::cout << " Calorimeter X0 " << TrkStepX0[j10] << " From scat centers " << X010 << std::endl;
    if (debug)
      std::cout << " Calorimeter Eloss " << TrkStepEloss[j10] << " From scat centers " << Eloss10 << std::endl;
    if (debug)
      std::cout << " Calorimeter EMeanIoni " << EIoniMean10 << " EIoniMeanRad " << ERad10 << " Total Eloss " << (EIoniMean10 + ERad10) << std::endl;
    if (debug)
      std::cout << " Calorimeter ESigIoni " << ESigIoni10 << " ESigIoniRad " << ESigRad10 << std::endl;
    if (debug)
      std::cout << " Calorimeter Eloss STEP p " << (TrkStepP[j10] - InitP) << " G4 " << (G4StepP[j10] - InitP) << std::endl;
    std::cout << " Muon X0 " << TrkStepX0[j1000] << " From scat centers " << X01000 << std::endl;
    if (debug)
      std::cout << " Muon X0 " << TrkStepX0[j1000] << " From scat centers " << X01000 << std::endl;
    if (debug)
      std::cout << " Muon Eloss " << TrkStepEloss[j1000] << " From scat centers " << Eloss1000 << std::endl;
    if (debug)
      std::cout << " Muon Eloss STEP p " << (TrkStepP[j1000] - MEntryP) << " G4 " << (G4StepP[j1000] - MEntryP) << std::endl;

    //      continue;

    double x0min = 0.2;

    double x0Bef = 0.;
    double x0I = 0.;
    double x0M = 0.;
    double x0T = 0.;
    double x0O = 0.;

    bool dumpMS = true;
    bool dumpCalo = false;

    if (fabs(InitEta) > 1.3)
      dumpCalo = false;
    for (int i = 1; i < TrkStepScats; i++)
    {
      if (i > 499)
        continue;
      double z = fabs(TrkStepScatZ[i]);
      double r = sqrt(TrkStepScatX[i] * TrkStepScatX[i] + TrkStepScatY[i] * TrkStepScatY[i]);
      double zmin = z / 2. + fabs(TrkStepScatZ[i - 1]) / 2.;
      double rmin = r / 2. + sqrt(TrkStepScatX[i - 1] * TrkStepScatX[i - 1] + TrkStepScatY[i - 1] * TrkStepScatY[i - 1]) / 2.;
      double zmax = z / 2. + fabs(TrkStepScatZ[i + 1]) / 2.;
      double rmax = r / 2. + sqrt(TrkStepScatX[i + 1] * TrkStepScatX[i + 1] + TrkStepScatY[i + 1] * TrkStepScatY[i + 1]) / 2.;
      double zminp = 0.01 * z + 0.99 * fabs(TrkStepScatZ[i - 1]);
      double rminp = 0.01 * r + 0.99 * sqrt(TrkStepScatX[i - 1] * TrkStepScatX[i - 1] + TrkStepScatY[i - 1] * TrkStepScatY[i - 1]);
      double zmaxp = 0.99 * z + 0.01 * fabs(TrkStepScatZ[i + 1]);
      double rmaxp = 0.99 * r + 0.01 * sqrt(TrkStepScatX[i + 1] * TrkStepScatX[i + 1] + TrkStepScatY[i + 1] * TrkStepScatY[i + 1]);

      if (TrkStepScatStatus[i] == 10)
        h2cscat->Fill(z, r, TrkStepScatX0[i]);
      if (TrkStepScatStatus[i] == -1000)
        h2mbscat->Fill(z, r, TrkStepScatX0[i]);

      // MS
      if (TrkStepScatStatus[i] == 1000)
      {

        if (fabs(MEntryEta) < 1.)
        {
          //            std::cout << " Barrel r " << r << " z " << z << " TrkStepScatX0[i] " << TrkStepScatX0[i] << std::endl;
          if (r < 6500)
          {
            x0I += TrkStepScatX0[i];
            //              std::cout << " x0 I " << x0I << std::endl;
          }
          else if (r < 9000)
          {
            x0M += TrkStepScatX0[i];
            //              std::cout << " x0 M " << x0M << std::endl;
          }
          else
          {
            x0O += TrkStepScatX0[i];
            //              std::cout << " x0 O " << x0O << std::endl;
          }
        }
        else
        {
          //            std::cout << " Endcap r " << r << " z " << z << " TrkStepScatX0[i] " << TrkStepScatX0[i] << std::endl;
          if (z < 7170)
          { // 7100
            x0Bef += TrkStepScatX0[i];
            //              std::cout << " x0 Before " << x0Bef << std::endl;
          }
          else if (z < 7920)
          {
            x0I += TrkStepScatX0[i];
            //              std::cout << " x0 I " << x0I << std::endl;
          }
          else if (z < 12900)
          {
            x0T += TrkStepScatX0[i];
            //              std::cout << " x0 Toroid " << x0T << std::endl;
          }
          else if (z < 17000)
          {
            x0M += TrkStepScatX0[i];
            //              std::cout << " x0 M " << x0M << std::endl;
          }
          else
          {
            x0O += TrkStepScatX0[i];
            //              std::cout << " x0 O " << x0O << std::endl;
          }
        }

        std::cout << "VALUE !!! " << (G4AccumTX0[i] - TrkStepX0[i]) / (1 + G4AccumTX0[i]) << std::endl;
        // if((G4AccumTX0[i]-TrkStepX0[i])/(1+G4AccumTX0[i])<-2) { //&& MEntryEta > 1.2 && MEntryEta < 1.35
        //   h2mfscat->Fill(z,r,TrkStepScatX0[i]);
        //   std::cout << "filles " << std::endl;
        // }

        double x0g40 = 0.;
        double x0g4p = 0.;
        for (int j = 1; j < G4Steps; j++)
        {
          if (TrkStepStatus[j] == 10)
            continue;
          if (TrkStepStatus[j - 1] == 10)
            continue;
          double dx0 = G4AccumTX0[j] - G4AccumTX0[j - 1];
          double zg4 = fabs(TrkStepZ[j]);
          double rg4 = sqrt(TrkStepX[j] * TrkStepX[j] + TrkStepY[j] * TrkStepY[j]);
          h2muong4scat->Fill(zg4, rg4, dx0);
          h2muonscat->Fill(zg4, rg4, TrkStepX0[j]);
          //            std::cout << " G4  x0 at radius " << rg4 << " z " << zg4 << " G4 dx0 " << dx0 << " Trk X0 " << TrkStepX0[j] << std::endl;

          if (dx0 < 0.0)
            continue;
          if (zg4 > zmin || rg4 > rmin)
          {
            if (zg4 < zmax || rg4 < rmax)
            {
              x0g40 += dx0;
              //                  if(debug) std::cout << " G4  x0 at radius " << rg4 << " z " << zg4 << " sum X0 " << x0g4 << std::endl;
            }
          }
          if (zg4 > zminp || rg4 > rminp)
          {
            if (zg4 < zmaxp || rg4 < rmaxp)
            {
              x0g4p += dx0;
              //                  if(debug) std::cout << " G4  x0 at radius " << rg4 << " z " << zg4 << " sum X0 " << x0g4 << std::endl;
            }
          }
          if (fabs(TrkStepZ[j]) > 1.1 * zmax && sqrt(TrkStepX[j] * TrkStepX[j] + TrkStepY[j] * TrkStepY[j]) > 1.1 * rmax)
            break;
        }
        double x0g4Best = x0g40;

        if (fabs(x0g40 - TrkStepScatX0[i]) > fabs(x0g4p - TrkStepScatX0[i]))
          x0g4Best = x0g4p;
        double difx0 = (x0g4Best - TrkStepScatX0[i]);

        if (dumpMS)
          if (debug)
            std::cout << " eta " << MEntryEta << " Scatterer radius " << r << " z " << z << " X0 " << TrkStepScatX0[i] << std::endl;
        if (dumpMS)
          if (debug)
            std::cout << " radius min " << rmin << " max " << rmax << " zmin " << zmin << " zmax  " << zmax << " x0G4 " << x0g40 << " x0g4 previous " << x0g4p << " X0 Best " << x0g4Best << " difference " << difx0 << std::endl;
        h2mg4dscat->Fill(z, r, x0g4Best - TrkStepScatX0[i]);
      }

      if (TrkStepScatStatus[i] == 10)
      {
        // calo radius 4250  z = 6500
        // ID   radius 1148    z = 3475
        //          if(z<3470) continue;
        //          if(r<1140) continue;

        double x0g40 = 0.;
        double x0g4p = 0.;
        double elossg4p = 0.;
        int jg4 = 0;
        for (int j = 1; j < G4Steps; j++)
        {
          if (TrkStepStatus[j] == 1000)
            continue;
          if (TrkStepStatus[j - 1] == 1000)
            continue;
          if (TrkStepStatus[j] == -1000)
            continue;
          if (TrkStepStatus[j - 1] == -1000)
            continue;
          double dx0 = G4AccumTX0[j] - G4AccumTX0[j - 1];
          if (dx0 < 0.0)
            continue;
          double zg4 = fabs(TrkStepZ[j]);
          double rg4 = sqrt(TrkStepX[j] * TrkStepX[j] + TrkStepY[j] * TrkStepY[j]);
          if (zg4 > zmin || rg4 > rmin)
          {
            if (zg4 < zmax || rg4 < rmax)
            {
              x0g40 += dx0;
              //                  if(debug) std::cout << " G4  x0 at radius " << rg4 << " z " << zg4 << " sum X0 " << x0g4 << std::endl;
              jg4 = j;
            }
          }
          if (zg4 > zminp || rg4 > rminp)
          {
            if (zg4 < zmaxp || rg4 < rmaxp)
            {
              elossg4p += G4StepP[j] - G4StepP[j - 1];
              x0g4p += dx0;
              //                  if(debug) std::cout << " G4  x0 at radius " << rg4 << " z " << zg4 << " sum X0 " << x0g4 << std::endl;
              jg4 = j;
            }
          }
          if (fabs(TrkStepZ[j]) > 1.1 * zmax && sqrt(TrkStepX[j] * TrkStepX[j] + TrkStepY[j] * TrkStepY[j]) > 1.1 * rmax)
            break;
        }
        double x0g4Best = x0g40;

        if (fabs(x0g40 - TrkStepScatX0[i]) > fabs(x0g4p - TrkStepScatX0[i]))
          x0g4Best = x0g4p;
        double difx0 = (x0g4Best - TrkStepScatX0[i]);

        if (dumpCalo)
          if (debug)
            std::cout << " Calorimeter eta " << MEntryEta << " Scatterer radius " << r << " z " << z << " X0 " << TrkStepScatX0[i] << std::endl;
        if (dumpCalo)
          if (debug)
            std::cout << " radius min " << rmin << " max " << rmax << " zmin " << zmin << " zmax  " << zmax << " x0G4 " << x0g40 << " x0g4 previous " << x0g4p << " X0 Best " << x0g4Best << " difference " << difx0 << std::endl;

        if (dumpCalo)
          if (debug)
            std::cout << " Eloss Scatter " << TrkStepScatEloss[i] << " Eloss G4 " << elossg4p << std::endl;
        double rScatElossX0 = TrkStepScatEloss[i] / TrkStepScatX0[i];
        double rG4ElossX0 = elossg4p / x0g4p;
        double phi = G4StepPhi[jg4];
        double dphic = phi + 3.141 - 3.141 / 32. * int((3.141 + phi) / (3.141 / 32.));

        if (dumpCalo && x0g4p > 1.5 && TrkStepScatX0[i] > 1.5)
          if (debug)
            std::cout << " rScatElossX0 " << rScatElossX0 << " rG4ElossX0 " << rG4ElossX0 << std::endl;

        if (x0g4p > 1.5 && TrkStepScatX0[i] > 1.5)
        {
          h2cg4rrscat->Fill(z, r, rG4ElossX0 / rScatElossX0);
          h2cg4rscat->Fill(z, r, rG4ElossX0);

          if (fabs(InitEta) < 1.)
          {
            h2cg4Eloss->Fill(r, -elossg4p);
            h2cTrkEloss->Fill(r, -TrkStepScatEloss[i]);
            h2cg4ElossX0->Fill(r, -elossg4p / x0g4p);
            h2cTrkElossX0->Fill(r, -TrkStepScatEloss[i] / TrkStepScatX0[i]);
            h2cg4X0->Fill(r, x0g4p);
            h2cTrkX0->Fill(r, TrkStepScatX0[i]);
            if (r > 4230)
              h2cdphiGirder->Fill(dphic, x0g4Best / TrkStepScatX0[i]);
          }
          else if (fabs(InitEta) < 2.)
          {
            h2cg4zEloss->Fill(z, -elossg4p);
            h2cTrkzEloss->Fill(z, -TrkStepScatEloss[i]);
            h2cg4zElossX0->Fill(z, -elossg4p / x0g4p);
            h2cTrkzElossX0->Fill(z, -TrkStepScatEloss[i] / TrkStepScatX0[i]);
            h2cg4zX0->Fill(z, x0g4p);
            h2cTrkzX0->Fill(z, TrkStepScatX0[i]);
            h2cTrkzdX0->Fill(z, x0g4p - TrkStepScatX0[i]);
            h2cTrkrdX0->Fill(r, x0g4p - TrkStepScatX0[i]);
            h2cTrkdX0->Fill(z, r, x0g4p - TrkStepScatX0[i]);
          }
          else
          {
            h2cg4eEloss->Fill(z, -elossg4p);
            h2cTrkeEloss->Fill(z, -TrkStepScatEloss[i]);
            h2cg4eElossX0->Fill(z, -elossg4p / x0g4p);
            h2cTrkeElossX0->Fill(z, -TrkStepScatEloss[i] / TrkStepScatX0[i]);
            h2cg4eX0->Fill(z, x0g4p);
            h2cTrkeX0->Fill(z, TrkStepScatX0[i]);
          }
        }

        h2cg4dscat->Fill(z, r, x0g4Best - TrkStepScatX0[i]);
      }
    }

    double x0tot = 0.;
    int istart = -1;
    int iend = 1;

    double x0Befg4 = 0.;
    double x0Ig4 = 0.;
    double x0Mg4 = 0.;
    double x0Tg4 = 0.;
    double x0Og4 = 0.;

    for (int i = j10; i < G4Steps; i++)
    {
      if (TrkStepStatus[i] == 10)
        continue;
      double dx0 = G4AccumTX0[i] - G4AccumTX0[i - 1];
      if (i == j10)
        dx0 = G4AccumTX0[i];
      if (i == j10 + 1)
        dx0 = G4AccumTX0[i];
      double z = fabs(TrkStepZ[i]);
      double r = sqrt(TrkStepX[i] * TrkStepX[i] + TrkStepY[i] * TrkStepY[i]);
      if (fabs(MEntryEta) < 1.)
      {
        if (r < 6500)
        {
          x0Ig4 += dx0;
        }
        else if (r < 9000)
        {
          x0Mg4 += dx0;
        }
        else
        {
          x0Og4 += dx0;
        }
      }
      else
      {
        if (z < 7170)
        {
          x0Befg4 += dx0;
        }
        else if (z < 7920)
        {
          x0Ig4 += dx0;
        }
        else if (z < 12900)
        {
          x0Tg4 += dx0;
        }
        else if (z < 17000)
        {
          x0Mg4 += dx0;
        }
        else
        {
          x0Og4 += dx0;
        }
      }
      if (istart == -1)
      {
        istart = iend;
        iend = i + 1;
        x0tot += dx0;
      }
      else
      {
        iend = i + 1;
        x0tot += dx0;
        //           if(debug) std::cout << " istart " << istart << " iend " << iend << " dx0 " << dx0 << " x0tot " << x0tot << std::endl;
      }

      if (x0tot > x0min)
      {
        double zav = 0.;
        double rav = 0.;
        double wav = 0.;
        for (int j = istart; j < iend; j++)
        {
          if (TrkStepStatus[j] == 10)
            continue;
          if (TrkStepStatus[j - 1] == 10)
            continue;
          double wx0 = G4AccumTX0[j] - G4AccumTX0[j - 1];
          wav += wx0;
          zav += wx0 * fabs(TrkStepZ[j]);
          rav += wx0 * sqrt(TrkStepX[j] * TrkStepX[j] + TrkStepY[j] * TrkStepY[j]);
        }
        zav = zav / wav;
        rav = rav / wav;
        //           if(debug) std::cout << " Large x0 entry nr " << jentry << " istart " << istart << " iend " << iend << " wav " << wav << " x0tot " << x0tot << " rav " << rav << " zav " << zav << std::endl;
        h2mg4scat->Fill(zav, rav, wav);
        istart = -1;
        x0tot = 0.;
      }

      // Muon System plots
      if (TrkStepStatus[i] == 1000)
        break;
    }
    double x0check = x0Befg4 + x0Ig4 + x0Mg4 + x0Tg4 + x0Og4;

    if (fabs(x0g4 - x0check) > 0.1)
      std::cout << " PROBLEM "
                << " x0g4 " << x0g4 << " x0check " << x0check << " Accum " << G4AccumTX0[j1000] << " last X0 " << G4AccumTX0[G4Steps - 1] << std::endl;

    double dphi = 3.1415 + MEntryPhi - 3.1415 / 4. * int((3.1415 + MEntryPhi) / (3.1415 / 4.));

    for (int i = 0; i < G4Steps; i++)
    {
      if (TrkStepStatus[i] == 10 || TrkStepStatus[i] == 1000)
      {
        if (debug)
          std::cout << " eta " << G4StepEta[i] << " status " << TrkStepStatus[i] << " er d0 " << TrkStepErd0[i] << " er z0 " << TrkStepErz0[i] << " err phi " << TrkStepErphi[i] << " err theta " << TrkStepErtheta[i] << " err qover P " << TrkStepErqoverp[i] << " error on p " << TrkStepErqoverp[i] * TrkStepP[i] * TrkStepP[i] << std::endl;
      }
      if (TrkStepStatus[i] == 1000)
      {
        double rtrk = sqrt(TrkStepX[i] * TrkStepX[i] + TrkStepY[i] * TrkStepY[i]);
        double rg4 = sqrt(G4StepX[i] * G4StepX[i] + G4StepY[i] * G4StepY[i]);
        double rz = (G4StepZ[i] - TrkStepZ[i]) * sin(G4StepTheta[i]) - (rg4 - rtrk) * cos(G4StepTheta[i]);
        double d0 = (G4StepX[i] - TrkStepX[i]) * sin(G4StepPhi[i]) - (G4StepY[i] - TrkStepY[i]) * cos(G4StepPhi[i]);
        if (debug)
          std::cout << " Muon eta " << MEntryEta << " rtrk " << rtrk << " rg4 " << rg4 << " delta R " << rtrk - rg4 << " d0 " << d0 << " z " << TrkStepZ[i] << " zg4 " << G4StepZ[i] << " delta z " << TrkStepZ[i] - G4StepZ[i] << " rz0 " << rz << std::endl;

        hetarz->Fill(G4StepEta[i], rz);
        hetad0->Fill(G4StepEta[i], d0);
        hetarzp->Fill(G4StepEta[i], rz);
        hetad0p->Fill(G4StepEta[i], d0);
        hetaEloss->Fill(G4StepEta[i], -TrkStepEloss[i]);
        if (fabs(MEntryEta) < 1.)
          hphiEloss_B->Fill(dphi, -TrkStepEloss[i]);

        hdElossTrk->Fill(-MEntryP + TrkStepP[i] - TrkStepEloss[i]);
        bool bad = false;
        if (fabs(G4AccumTX0[i] - TrkStepX0[i]) > 0.2 * (1 + G4AccumTX0[i]))
          bad = true;
        double rEloss = (G4StepP[i] - MEntryP) / (TrkStepP[i] - MEntryP);

        double scale = parX0Muon(MEntryEta);
        // Scale Eloss of TG wrt X0
        double scaleMuonEloss = 0.93;
        double ElossTG = scaleMuonEloss * scale * (EIoniMean1000 + 3.59524 * scaleErrorIoni * ESigIoni1000 - 0.75 * sqrt(scaleErrorIoni * ESigIoni1000 * ESigRad1000));

        std::cout << " i " << i << " G4Steps " << G4Steps << " G4StepZ " << G4StepZ[i] << " Muons system eta " << MEntryEta << " nscat " << TrkStepScats << " Eloss1000 " << Eloss1000 << " TrkStepEloss " << -MEntryP + TrkStepP[i] << " X01000 " << X01000 << " TrkStepX0 " << TrkStepX0[i] << std::endl;
        // TrkStepEloss0[i] == ElossTG
        double dMOP1000 = (MEntryP - G4StepP[i]) + ElossTG;

        double dratioMOP1000 = -dMOP1000 / (ElossTG - 100.);
        double pullMOP1000 = dMOP1000 / (scaleErrorIoni * ESigIoni1000);
        //           if(debug) std::cout << " MS EIoniMean1000 " << EIoniMean1000 << " dMOP1000 " << dMOP1000 << std::endl;
        h2etaMOP->Fill(fabs(MEntryEta), dMOP1000);
        h2etapMOP->Fill(fabs(MEntryEta), pullMOP1000);
        h2etarMOP->Fill(fabs(MEntryEta), dratioMOP1000);
        hetaMOP->Fill(fabs(MEntryEta), dMOP1000);
        hetarMOP->Fill(fabs(MEntryEta), dratioMOP1000);
        hetaSigIoni->Fill(fabs(MEntryEta), scaleErrorIoni * ESigIoni1000);
        hetaElossTG->Fill(fabs(MEntryEta), -ElossTG);

        h2etaEloss->Fill(MEntryEta, rEloss);
        h2etadX0X->Fill(MEntryEta, (G4AccumTX0[i] - TrkStepX0[i]) / (1 + G4AccumTX0[i]));
        if (fabs(MEntryEta) < 1.)
          h2phidX0XB->Fill(MEntryPhi, (G4AccumTX0[i] - TrkStepX0[i]) / (1 + G4AccumTX0[i]));
        if (fabs(MEntryEta) > 1.)
          h2phidX0XE->Fill(MEntryPhi, (G4AccumTX0[i] - TrkStepX0[i]) / (1 + G4AccumTX0[i]));
        hetadX0X->Fill(fabs(MEntryEta), (G4AccumTX0[i] - TrkStepX0[i]) / (1 + G4AccumTX0[i]));
        hetadX0XF->Fill(fabs(MEntryEta), (G4AccumTX0[i] - scale * TrkStepX0[i]) / (1 + G4AccumTX0[i]));
        h2etadX0XF->Fill(fabs(MEntryEta), (G4AccumTX0[i] - scale * TrkStepX0[i]) / (1 + G4AccumTX0[i]));
        h2etadX0F->Fill(fabs(MEntryEta), (G4AccumTX0[i] - scale * TrkStepX0[i]));
        h2etadX0->Fill(fabs(MEntryEta), (G4AccumTX0[i] - TrkStepX0[i]));
        if (fabs(MEntryEta) < 1.)
          h2phidX0B->Fill(MEntryPhi, (G4AccumTX0[i] - TrkStepX0[i]));
        if (fabs(MEntryEta) > 1.)
          h2phidX0E->Fill(MEntryPhi, (G4AccumTX0[i] - TrkStepX0[i]));
        if (!bad)
        {
          hdEEG4Trk->Fill((G4StepP[i] - TrkStepP[i]) / TrkStepEloss[i], -TrkStepEloss[i]);
        }
        hdX0XG4Trk->Fill((G4AccumTX0[i] - TrkStepX0[i]) / (1 + G4AccumTX0[i]));
        if (fabs(TrkStepEta[i]) < 1.1)
        {
          hpulld0G4Trk_B->Fill(d0 / TrkStepErd0[i]);
          hpullzG4Trk_B->Fill((G4StepZ[i] - TrkStepZ[i]) / TrkStepErz0[i] / sin(G4StepTheta[i]));
          //    hpullzG4Trk_B->Fill(rz0/erz0);
          hpullphiG4Trk_B->Fill((G4StepPhi[i] - TrkStepPhi[i]) / TrkStepErphi[i]);
          hpullphiG4Trk_BScat->Fill((G4StepPhi[i] - TrkStepPhi[i]) / erphi1000);
          hpullphiG4Trk_BScatO->Fill((G4StepPhi[i] - TrkStepPhi[i]) / sigScatphi1000);
          hpullthetaG4Trk_B->Fill((G4StepTheta[i] - TrkStepTheta[i]) / TrkStepErtheta[i]);
          hpullthetaG4Trk_BScat->Fill((G4StepTheta[i] - TrkStepTheta[i]) / ertheta1000);
          hpullthetaG4Trk_BScatO->Fill((G4StepTheta[i] - TrkStepTheta[i]) / sigScattheta1000);
          hpullpG4Trk_B->Fill((1. / G4StepP[i] - 1. / TrkStepP[i]) / TrkStepErqoverp[i]);

          hdpG4Trk_B->Fill(G4StepP[i] - TrkStepP[i]);
          hresizG4Trk_B->Fill(G4StepZ[i] - TrkStepZ[i]);
          if (bad)
            hphiG4Trk_B->Fill(MEntryPhi);
          hdX0G4Trk_B->Fill(G4AccumTX0[i] - TrkStepX0[i]);
          hdX0XG4Trk_B->Fill((G4AccumTX0[i] - TrkStepX0[i]) / (1 + G4AccumTX0[i]));
          hX0Trk_B->Fill(TrkStepX0[i]);
          hX0G4_B->Fill(G4AccumTX0[i]);
          // backtracking
          hdpBACK_B->Fill(MEntryP - BackP);
          hdX0BACK_B->Fill(TrkStepX0[i] - BackX0);
          hdX0XBACK_B->Fill((TrkStepX0[i] - BackX0) / (1 + G4AccumTX0[i]));
          hdX0G4BACK_B->Fill(G4AccumTX0[i] - BackX0);
          hresizBACK_B->Fill(MEntryZ - BackZ);
          //            if(fabs(TrkStepX0[i]-BackX0)<0.2) {
          if (fabs(TrkStepX0[i] - BackX0) < 0.2 + 0.025 * (BackX0 + TrkStepX0[i] + G4AccumTX0[i]))
          {
            hdX0XBACKOK_B->Fill((TrkStepX0[i] - G4AccumTX0[i]) / (1 + G4AccumTX0[i]));
            if ((TrkStepX0[i] - G4AccumTX0[i]) / (1 + G4AccumTX0[i]) < -0.15)
            {
              //                 if(debug) std::cout << " Barrel x0 " << TrkStepX0[i] << " G4 " << G4AccumTX0[i] << " eta " << TrkStepEta[i] << " Phi " << TrkStepPhi[i] << std::endl;
              heta_B->Fill(TrkStepEta[i]);
              hphi_B->Fill(TrkStepPhi[i]);
            }
          }
          else
          {
            hdX0XBACKBAD_B->Fill((TrkStepX0[i] - G4AccumTX0[i]) / (1 + G4AccumTX0[i]));
            hetaBAD_B->Fill(TrkStepEta[i]);
            hphiBAD_B->Fill(TrkStepPhi[i]);
          }
        }
        else
        {
          hpulld0G4Trk_E->Fill(d0 / TrkStepErd0[i]);
          hpullzG4Trk_E->Fill((G4StepZ[i] - TrkStepZ[i]) / TrkStepErz0[i] / sin(G4StepTheta[i]));
          //    hpullzG4Trk_E->Fill(rz0/erz0);
          hpullphiG4Trk_E->Fill((G4StepPhi[i] - TrkStepPhi[i]) / TrkStepErphi[i]);
          hpullthetaG4Trk_E->Fill((G4StepTheta[i] - TrkStepTheta[i]) / TrkStepErtheta[i]);
          hpullpG4Trk_E->Fill((1. / G4StepP[i] - 1. / TrkStepP[i]) / TrkStepErqoverp[i]);

          hdpG4Trk_E->Fill(G4StepP[i] - TrkStepP[i]);
          hresizG4Trk_E->Fill(G4StepZ[i] - TrkStepZ[i]);
          if (bad)
            hphiG4Trk_E->Fill(MEntryPhi);
          hdX0G4Trk_E->Fill(G4AccumTX0[i] - TrkStepX0[i]);
          hdX0XG4Trk_E->Fill((G4AccumTX0[i] - TrkStepX0[i]) / (1 + G4AccumTX0[i]));
          hX0Trk_E->Fill(TrkStepX0[i]);
          hX0G4_E->Fill(G4AccumTX0[i]);
          // backtracking
          hdpBACK_E->Fill(MEntryP - BackP);
          hdX0BACK_E->Fill(TrkStepX0[i] - BackX0);
          hdX0XBACK_E->Fill((TrkStepX0[i] - BackX0) / (1 + G4AccumTX0[i]));
          hdX0G4BACK_E->Fill(G4AccumTX0[i] - BackX0);
          hresizBACK_E->Fill(MEntryZ - BackZ);
          //            if(fabs(TrkStepX0[i]-BackX0)<0.2) {
          if (fabs(TrkStepX0[i] - BackX0) < 0.2 + 0.025 * (BackX0 + TrkStepX0[i] + G4AccumTX0[i]))
          {
            hdX0XBACKOK_E->Fill((TrkStepX0[i] - G4AccumTX0[i]) / (1 + G4AccumTX0[i]));
            if ((TrkStepX0[i] - G4AccumTX0[i]) / (1 + G4AccumTX0[i]) < -0.25)
            {
              //                 if(debug) std::cout << " Endcap x0 " << TrkStepX0[i] << " G4 " << G4AccumTX0[i] << " eta " << TrkStepEta[i] << " Phi " << TrkStepPhi[i] << std::endl;
              heta_E->Fill(TrkStepEta[i]);
              hphi_E->Fill(TrkStepPhi[i]);
            }
          }
          else
          {
            hdX0XBACKBAD_E->Fill((TrkStepX0[i] - G4AccumTX0[i]) / (1 + G4AccumTX0[i]));
            hetaBAD_E->Fill(TrkStepEta[i]);
            hphiBAD_E->Fill(TrkStepPhi[i]);
          }
        }
      }

      double r = (0.1 + x0Trk) / (0.1 + x0g4);
      double rBef = (0.1 + x0Bef) / (0.1 + x0Befg4);
      double rI = (0.1 + x0I) / (0.1 + x0Ig4);
      double rM = (0.1 + x0M) / (0.1 + x0Mg4);
      double rT = (0.1 + x0T) / (0.1 + x0Tg4);
      double rO = (0.1 + x0O) / (0.1 + x0Og4);

      if (TrkStepStatus[i] == 1000)
      {
        double x0check = x0Befg4 + x0Ig4 + x0Mg4 + x0Tg4 + x0Og4;
        //          std::cout << " x0g4 " << x0g4 << " x0check " << x0check << std::endl;
        //          std::cout << " x0g4Bef " << x0Befg4  << " x0Ig4 " << x0Ig4  << " x0Mg4 " << x0Mg4 << " x0Tg4 " << x0Tg4 << " x0Og4 " << x0Og4 << std::endl;
        //          std::cout << " x0Bef   " << x0Bef    << " x0I   " << x0I  << " x0M   " << x0M << " x0T   " << x0T << " x0O   " << x0O << std::endl;

        if (debug)
          std::cout << " MEntryEta " << MEntryEta << " r "
                    << " rI " << rI << " x0I " << x0I << " x0Ig4 " << x0Ig4 << " x0Mg4 " << x0Mg4 << " x0Og4 " << x0Og4 << std::endl;
        if (fabs(MEntryEta) < 1.2 && x0g4 < 5.)
          hdX0XL5_B->Fill(r - 1);
        if (fabs(MEntryEta) < 1.2 && x0g4 > 5.)
          hdX0XG5_B->Fill(r - 1);
        if (fabs(MEntryEta) > 1.2)
          hdX0X_E->Fill(r - 1);
        hetaX0->Fill(MEntryEta, r);
        if (fabs(MEntryEta) < 1.1)
          std::cout << " jentry " << jentry << " MEntryEta " << MEntryEta << " Phi " << MEntryPhi << " x0Trk " << x0Trk << " x0g4 " << x0g4 << " ratio " << r << std::endl;
        hetaX0Bef->Fill(MEntryEta, rBef);
        hetaX0I->Fill(MEntryEta, rI);
        hetaX0M->Fill(MEntryEta, rM);
        hetaX0T->Fill(MEntryEta, rT);
        hetaX0O->Fill(MEntryEta, rO);

        hetaX0Trk->Fill(MEntryEta, x0Trk);
        hetaX0TrkBef->Fill(MEntryEta, x0Bef);
        hetaX0TrkI->Fill(MEntryEta, x0I);
        hetaX0TrkM->Fill(MEntryEta, x0M);
        hetaX0TrkT->Fill(MEntryEta, x0T);
        hetaX0TrkO->Fill(MEntryEta, x0O);

        hetaX0G4->Fill(MEntryEta, x0g4);
        hetaX0G4Bef->Fill(MEntryEta, x0Befg4);
        hetaX0G4I->Fill(MEntryEta, x0Ig4);
        hetaX0G4M->Fill(MEntryEta, x0Mg4);
        hetaX0G4T->Fill(MEntryEta, x0Tg4);
        hetaX0G4O->Fill(MEntryEta, x0Og4);

        hphiX0Bef->Fill(dphi, rBef);
        hphiX0T->Fill(dphi, rT);
        if (fabs(MEntryEta) < 1.)
        {
          hphiX0G4_B->Fill(dphi, x0g4);
          hphiX0_B->Fill(dphi, r);
          hphiX0I_B->Fill(dphi, rI);
          hphiX0M_B->Fill(dphi, rM);
          hphiX0O_B->Fill(dphi, rO);
        }
        else
        {
          hphiX0_E->Fill(dphi, r);
          hphiX0I_E->Fill(dphi, rI);
          hphiX0M_E->Fill(dphi, rM);
          hphiX0O_E->Fill(dphi, rO);
        }
      }
      // Calorimeter plots

      if (TrkStepStatus[i] == 10)
      {
        hcdElossTrk->Fill(-InitP + TrkStepP[i] - TrkStepEloss[i]);
        hcElossG4->Fill((InitP - G4StepP[i]) / 1000.);
        hcEmop->Fill(-EIoniMean10 / 1000.);
        hcErad->Fill(-ERad10 / 1000.);
        double frac = 548.579 / 105.658 / 1000.;
        double ERad10_0 = InitP * (1 - exp(-frac * frac * X010));
        hcErad0->Fill(ERad10_0 / 1000.);
        hcErad1->Fill(ESigRad10 / 1000.);

        hcdpG4Trk->Fill(G4StepP[i] - TrkStepP[i]);
        double d0 = (G4StepX[i] - TrkStepX[i]) * sin(G4StepPhi[i]) - (G4StepY[i] - TrkStepY[i]) * cos(G4StepPhi[i]);
        double r = sqrt(TrkStepX[i] * TrkStepX[i] + TrkStepY[i] * TrkStepY[i]);
        double rg4 = sqrt(G4StepX[i] * G4StepX[i] + G4StepY[i] * G4StepY[i]);
        double rz0 = (G4StepZ[i] - TrkStepZ[i]) * sin(G4StepTheta[i]) - (r - rg4) * cos(G4StepTheta[i]);
        //            double erz0 = sqrt(TrkStepErz0[i]*TrkStepErz0[i]*sin(G4StepTheta[i])*sin(G4StepTheta[i]) +
        //                               TrkStepErd0[i]*TrkStepErd0[i]*cos(G4StepTheta[i])*cos(G4StepTheta[i]));
        double erz0 = TrkStepErz0[i] / sin(G4StepTheta[i]);
        double etac = (InitEta + MEntryEta) / 2.;
        if (debug)
          std::cout << " etac " << etac << " r " << r << " rg4 " << rg4 << " delta R " << r - rg4 << " d0 " << d0 << " dx " << G4StepX[i] - TrkStepX[i] << " dy " << G4StepY[i] - TrkStepY[i] << " cos phi " << cos(G4StepPhi[i]) << " sin phi " << sin(G4StepPhi[i]) << " phi G4 " << G4StepPhi[i] << " phi trk " << TrkStepPhi[i] << " z " << TrkStepZ[i] << " zg4 " << G4StepZ[i] << " delta z " << TrkStepZ[i] - G4StepZ[i] << " rz0 " << rz0 << std::endl;

        hcetarzp->Fill(etac, rz0);
        hcetad0p->Fill(etac, d0);

        if (fabs(InitEta) < 1.)
        {
          hcresid0G4Trk_B->Fill(d0);
          hcresirzG4Trk_B->Fill(rz0);
          hcresiphiG4Trk_B->Fill(G4StepPhi[i] - TrkStepPhi[i]);
          hcresithetaG4Trk_B->Fill(G4StepTheta[i] - TrkStepTheta[i]);
          hcresipG4Trk_B->Fill(G4StepP[i] - TrkStepP[i]);
          hcpulld0G4Trk_B->Fill(d0 / TrkStepErd0[i]);
          hcpullzG4Trk_B->Fill((G4StepZ[i] - TrkStepZ[i]) / TrkStepErz0[i] / sin(G4StepTheta[i]));
          //    hcpullzG4Trk_B->Fill(rz0/erz0);
          hcpullphiG4Trk_B->Fill((G4StepPhi[i] - TrkStepPhi[i]) / TrkStepErphi[i]);
          hcpullphiG4Trk_BScat->Fill((G4StepPhi[i] - TrkStepPhi[i]) / erphi10);
          hcpullphiG4Trk_BScatO->Fill((G4StepPhi[i] - TrkStepPhi[i]) / sigScatphi10);
          hcpullthetaG4Trk_B->Fill((G4StepTheta[i] - TrkStepTheta[i]) / TrkStepErtheta[i]);
          hcpullthetaG4Trk_BScat->Fill((G4StepTheta[i] - TrkStepTheta[i]) / ertheta10);
          hcpullthetaG4Trk_BScatO->Fill((G4StepTheta[i] - TrkStepTheta[i]) / sigScattheta10);
          hcpullpG4Trk_B->Fill((1. / G4StepP[i] - 1. / TrkStepP[i]) / TrkStepErqoverp[i]);
        }
        else
        {
          hcresid0G4Trk_E->Fill(d0);
          hcresirzG4Trk_E->Fill(rz0);
          hcresiphiG4Trk_E->Fill(G4StepPhi[i] - TrkStepPhi[i]);
          hcresithetaG4Trk_E->Fill(G4StepTheta[i] - TrkStepTheta[i]);
          hcresipG4Trk_E->Fill(G4StepP[i] - TrkStepP[i]);
          hcpulld0G4Trk_E->Fill(d0 / TrkStepErd0[i]);
          hcpullzG4Trk_E->Fill((G4StepZ[i] - TrkStepZ[i]) / TrkStepErz0[i] / sin(G4StepTheta[i]));
          //    hcpullzG4Trk_E->Fill(rz0/erz0);
          hcpullphiG4Trk_E->Fill((G4StepPhi[i] - TrkStepPhi[i]) / TrkStepErphi[i]);
          hcpullthetaG4Trk_E->Fill((G4StepTheta[i] - TrkStepTheta[i]) / TrkStepErtheta[i]);
          hcpullpG4Trk_E->Fill((1. / G4StepP[i] - 1. / TrkStepP[i]) / TrkStepErqoverp[i]);
        }

        hcdX0G4Trk->Fill(G4AccumTX0[i] - TrkStepX0[i]);
        hcdX0XG4Trk->Fill((G4AccumTX0[i] - TrkStepX0[i]) / (1 + G4AccumTX0[i]));

        // Profiles and 2D
        //            double phi = G4StepPhi[i];
        double phi = atan2(G4StepY[i], G4StepX[i]);
        //             if(debug) std::cout << " calo phi " << G4StepPhi[i] << " phipos " <<  phi << " radius " << sqrt(G4StepX[i]*G4StepX[i]+G4StepY[i]*G4StepY[i]) << std::endl;
        double dphic = phi + 3.1416 - 3.1416 / 8. * int((3.1416 + phi) / (3.1416 / 8.));
        double dphic32 = phi + 3.1416 - 3.1416 / 32. * int((3.1416 + phi) / (3.1416 / 32.));
        double rX0 = G4AccumTX0[i] / TrkStepX0[i];
        double rEloss = (G4StepP[i] - InitP) / (TrkStepP[i] - InitP);

        double scale = 1.;
        if (fabs(etac) < 1.3)
          scale = parGirder(dphic32);
        double scalef = scale * parX0Calo(etac);

        hcX0G4->Fill(G4AccumTX0[i]);
        hcX0Trk->Fill(TrkStepX0[i]);
        hcX0TrkG->Fill(scale * TrkStepX0[i]);
        hcX0TrkF->Fill(scalef * TrkStepX0[i]);
        if (fabs(etac) > 2.0)
          hcX0G42->Fill(G4AccumTX0[i]);
        if (fabs(etac) > 2.0)
          hcX0TrkF2->Fill(scalef * TrkStepX0[i]);

        if (fabs(etac) < 1.8)
          hcdphiX0->Fill(dphic, rX0);
        if (fabs(etac) < 1.3)
          hcdphi32X0->Fill(dphic32, rX0);
        hcphiX0->Fill(phi, rX0);
        hcetaX0->Fill(etac, rX0);

        hcdphiEloss->Fill(dphic, rEloss);
        hcphiEloss->Fill(phi, rEloss);
        hcetaEloss->Fill(etac, rEloss);
        if (fabs(etac) > 2 && G4AccumTX0[i] > 140 && G4AccumTX0[i] < 170)
        {
          hcphi2Eloss->Fill(phi, rEloss);
          hcphi2X0->Fill(phi, rX0);
        }

        if (fabs(etac) < 1.8)
          h2cdphiX0->Fill(dphic, rX0);
        if (fabs(etac) < 1.8)
          h2cdphi32X0->Fill(dphic32, rX0);
        if (fabs(etac) < 1.3)
        {
          h2cdphi32X0B->Fill(dphic32, rX0);
        }
        else if (fabs(etac) < 1.35)
        {
          h2cdphi32X0T->Fill(dphic32, rX0);
        }
        else if (fabs(etac) < 1.4)
        {
          h2cdphi32X0TE->Fill(dphic32, rX0);
        }
        h2cphiX0->Fill(phi, rX0);
        h2cetaX0->Fill(etac, rX0);
        h2cdphiEloss->Fill(dphic, rEloss);
        h2cetaEloss->Fill(etac, rEloss);

        h2cetaG4X0->Fill(etac, G4AccumTX0[i]);
        h2cetaTrkX0->Fill(etac, TrkStepX0[i]);
        h2cetaTrkX0_HEC->Fill(etac, X010_HEC);
        h2cetaTrkX0_preHEC0->Fill(etac, X010_preHEC0);
        h2cetaTrkX0_preHEC1->Fill(etac, X010_preHEC1);
        h2cetaTrkX0_noHEC->Fill(etac, X010 - X010_HEC - X010_preHEC0 - X010_preHEC1);
        h2cetadX0->Fill(etac, G4AccumTX0[i] - TrkStepX0[i]);
        h2cetadX0X->Fill(etac, (G4AccumTX0[i] - TrkStepX0[i]) / G4AccumTX0[i]);

        if (fabs(etac) < 1.8)
          h2cdphiX0F->Fill(dphic, rX0 / scale);
        if (fabs(etac) < 1.3)
          h2cdphi32X0F->Fill(dphic32, rX0 / scale);
        h2cetaX0F->Fill(fabs(etac), rX0 / scale);
        hcetaX0F->Fill(fabs(etac), rX0 / scale);
        h2cetadX0F->Fill(fabs(etac), G4AccumTX0[i] - scale * TrkStepX0[i]);
        h2cetaX0FF->Fill(fabs(etac), rX0 / scalef);
        hcetaX0FF->Fill(fabs(etac), rX0 / scalef);
        h2cetadX0FF->Fill(fabs(etac), G4AccumTX0[i] - scalef * TrkStepX0[i]);

        double scaleCaloEloss = 1.0;
        double ElossTG = scaleCaloEloss * scalef * (-50. * 10000. / InitP + EIoniMean10 + 3.59524 * scaleErrorIoni * ESigIoni10 - 0.75 * sqrt(scaleErrorIoni * ESigIoni10 * ESigRad10));
        double dMOP10 = (InitP - G4StepP[i]) + ElossTG;
        double dMOP10F = (InitP - G4StepP[i]) + ElossTG * parECalo(etac);
        double dMOP10FN = (InitP - G4StepP[i]) + TrkStepEloss0[i];
        //            double dMOP10FN = (InitP-G4StepP[i])+TrkStepEloss0[i]/parECalo(etac);
        ////            std::cout << " dMOP10F " << dMOP10F << " scalef*EIoniMean10 " << scalef*EIoniMean10 << " 3.59524*scaleErrorIoni*ESigIoni10 " << 3.59524*scaleErrorIoni*ESigIoni10 << " -0.75*sqrt(scaleErrorIoni*ESigIoni10*ESigRad10)) " << -0.75*sqrt(scaleErrorIoni*ESigIoni10*ESigRad10) << std::endl;

        double difMOP10F = ElossTG * parECalo(etac) - TrkStepEloss0[i];
        ////            std::cout << " **** difMOP10F " << difMOP10F << " ElossTG*parECalo(etac) " << ElossTG*parECalo(etac) << " etac " << etac << " TrkStepEloss0[i] " << TrkStepEloss0[i] << " scale f " << scalef << " TrkStepScaleX0[i] " << TrkStepScaleX0[i] <<" scalef*parECalo(etac) " << scalef*parECalo(etac) <<" TrkStepScaleEloss[i] " << TrkStepScaleEloss[i] << std::endl;
        // smearing formulae for 5%
        ////            std::cout << " " << std::endl;
        ////            std::cout << " X0 check eta " << etac << " phi " << phi << " dphic32 " << dphic32  << " scalef/TrkStepScaleX0[i] " << scalef/TrkStepScaleX0[i] << std::endl;
        ////            std::cout << " Eloss scale check scalef*parECalo(etac)/TrkStepScaleEloss[i] " << scalef*parECalo(etac)/TrkStepScaleEloss[i] << std::endl;

        double scale_xc = 2.3;
        double momentumError = 0.05 * MEntryP;
        double fracERad = ESigRad10 + (MEntryP * fabs(ERad10) / (800000. + MEntryP));
        double sigmaL = scaleErrorIoni * ESigIoni10 + fracERad / 3.59524;
        double xc = scale_xc * 0.87388 * momentumError / (3.59524 * sigmaL);

        double correction = (1.747 * xc * xc + 0.97 * 0.938 * xc * xc * xc) / (1 + 4.346 * xc + 5.371 * xc * xc + 0.938 * xc * xc * xc); // correction ranges from 0 to 0.97
        double MOPreso5 = 3.59524 * sigmaL * correction;
        // MOPreso5 = TrkStepEloss5[i] - TrkStepEloss0[i];
        // with 10% smearing
        xc = 2 * xc;
        correction = (1.747 * xc * xc + 0.97 * 0.938 * xc * xc * xc) / (1 + 4.346 * xc + 5.371 * xc * xc + 0.938 * xc * xc * xc); // correction ranges from 0 to 0.97
        double MOPreso10 = 3.59524 * sigmaL * correction;
        // MOPreso10 = TrkStepEloss10[i] - TrkStepEloss0[i];
        ////            std::cout << " MOPreso5 " << MOPreso5 << " sigmaL " << sigmaL << " ESigRad10/3.59524 " << ESigRad10/3.59524 << " MOPreso10 " << MOPreso10 << " fracRad " << fracERad/(ESigRad10+1) << " fracERad/3.59524 " << fracERad/3.59524 << " ESigRad10 " << ESigRad10 << std::endl;

        double deltaP = rnd.Gaus(0, 0.05 * MEntryP);
        double dMOP10FS5 = (InitP - G4StepP[i] - deltaP) + ElossTG * parECalo(etac) - MOPreso5;
        double dMOP10FS10 = (InitP - G4StepP[i] - 2 * deltaP) + ElossTG * parECalo(etac) - MOPreso10;
        double dMOP10FS5N = (InitP - G4StepP[i] - deltaP) + TrkStepEloss5[i];
        double dMOP10FS10N = (InitP - G4StepP[i] - 2 * deltaP) + TrkStepEloss10[i];

        int isMax = 10 * InitP / 25000.;
        if (isMax > 100)
          isMax = 100;
        if (isMax < 1)
          isMax = 1;
        // smear many times... 10 times at 25 GeV etc.
        for (int is = 0; is < isMax; is++)
        {
          deltaP = rnd.Gaus(0, 0.05 * MEntryP);
          dMOP10FS5 = (InitP - G4StepP[i] - deltaP) + ElossTG * parECalo(etac) - MOPreso5;
          dMOP10FS10 = (InitP - G4StepP[i] - 2 * deltaP) + ElossTG * parECalo(etac) - MOPreso10;
          h2cetaMOPFS5->Fill(fabs(etac), dMOP10FS5);
          h2cetaMOPFS10->Fill(fabs(etac), dMOP10FS10);
          dMOP10FS5N = (InitP - G4StepP[i] - deltaP) + TrkStepEloss5[i];
          dMOP10FS10N = (InitP - G4StepP[i] - 2 * deltaP) + TrkStepEloss10[i];
          h2cetaMOPFS5N->Fill(fabs(etac), dMOP10FS5N);
          h2cetaMOPFS10N->Fill(fabs(etac), dMOP10FS10N);
        }

        double pullMOP10 = dMOP10 / (scaleErrorIoni * ESigIoni10);
        double dratioMOP10 = -dMOP10 / (ElossTG);
        //             if(debug) std::cout << " Calo EIoniMean10 " << EIoniMean10 << " dMOP10 " << dMOP10 << std::endl;
        if (debug)
          std::cout << " (InitP-G4StepP[i]) " << (InitP - G4StepP[i]) << " InitP - TrkStepP[i] " << InitP - TrkStepP[i] << " EIoniMean10 " << EIoniMean10 << " ERad10 " << ERad10 << " ESigIoni10 " << ESigIoni10 << " ElossTG " << ElossTG << " dMOP10 " << dMOP10 << " scalef " << scalef << std::endl;
        if (debug)
          std::cout << " Calorimeter sigmaLandau " << ESigIoni10 / 3.59524 << " sigma Rad " << ESigRad10 << std::endl;
        if (fabs(etac) < 1.)
          hcsigmaL->Fill(scaleErrorIoni * ESigIoni10);
        if (fabs(etac) < 1.)
          hcsigmaLtot->Fill(scaleErrorIoni * ESigIoni10 + fracERad / 3.59524);
        if (fabs(etac) < 1.)
          hcsigmaLratio->Fill(scaleErrorIoni * ESigIoni10 / fabs(ElossTG * parECalo(etac)));
        if (fabs(etac) < 1.)
          hcsigmaR->Fill(ESigRad10);
        h2cetaMOP->Fill(fabs(etac), dMOP10);
        h2cetaMOPF->Fill(fabs(etac), dMOP10F);
        h2cetaMOPFN->Fill(fabs(etac), dMOP10FN);
        h1cetadMOPFN->Fill(dMOP10FN - dMOP10F);
        h2cetadMOPFN->Fill(fabs(etac), dMOP10FN - dMOP10F);
        double difScaleX0 = scalef / TrkStepScaleX0[i] - 1;
        double difScaleEloss = scalef * parECalo(etac) / TrkStepScaleEloss[i] - 1;
        h2cetadScaleX0->Fill(fabs(etac), difScaleX0);
        h2cetadScaleEloss->Fill(fabs(etac), difScaleEloss);

        h2cetapMOP->Fill(fabs(etac), pullMOP10);
        h2cetarMOP->Fill(fabs(etac), dratioMOP10);
        hcetaMOP->Fill(fabs(etac), dMOP10);
        hcetaMOPF->Fill(fabs(etac), dMOP10F);
        hcetarMOP->Fill(fabs(etac), dratioMOP10);
        hcetaSigIoni->Fill(fabs(etac), scaleErrorIoni * ESigIoni10);
        hcetaElossTG->Fill(fabs(etac), -ElossTG);
      }
    } // end G4 steps loop
  }   // end event loop

  file->Write();
  file->Close();
}