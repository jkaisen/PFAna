// -*- C++ -*-
//
// Package:    DemoAnalyzer
// Class:      DemoAnalyzer
// 
/**\class DemoAnalyzer DemoAnalyzer.cc Analyzer/DemoAnalyzer/src/DemoAnalyzer.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  aiken oliver
//         Created:  Thu Jun 27 11:17:00 CDT 2013
// $Id$
//
//


// system include files
#include <memory>
#include <map>
#include <utility>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>

#include <TLorentzVector.h>
#include <TROOT.h>
#include <TSystem.h>
#include <TFile.h>
#include <TParameter.h>
#include <math.h>
#include <TRandom3.h>
#include <TMath.h>
#include <TObject.h>
#include <TProfile.h>
//New Include files
#include "TH2F.h"
#include "RecoParticleFlow/PFClusterProducer/interface/PFHcalSuperClusterAlgo.h"
#include "DataFormats/ParticleFlowReco/interface/PFRecHit.h"
#include "DataFormats/DetId/interface/DetId.h"
#include "RecoParticleFlow/PFClusterProducer/interface/PFHcalSuperClusterInit.h"
#include "DataFormats/HcalDetId/interface/HcalDetId.h"


// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"

#include "DataFormats/PatCandidates/interface/Electron.h"
#include "DataFormats/PatCandidates/interface/Jet.h"
#include "DataFormats/PatCandidates/interface/MET.h"
#include "DataFormats/PatCandidates/interface/Muon.h"
#include "DataFormats/PatCandidates/interface/PATObject.h"
#include "DataFormats/PatCandidates/interface/TriggerEvent.h"
#include "DataFormats/PatCandidates/interface/TriggerFilter.h"
#include "DataFormats/PatCandidates/interface/TriggerObject.h"
#include "DataFormats/ParticleFlowReco/interface/PFCluster.h"
#include "DataFormats/ParticleFlowReco/interface/PFSuperCluster.h"


#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DataFormats/ParticleFlowReco/interface/PFLayer.h"

#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"

#include <boost/foreach.hpp>
#define foreach BOOST_FOREACH

//
// class declaration
//

class DemoAnalyzer : public edm::EDAnalyzer {
public:
  explicit DemoAnalyzer(const edm::ParameterSet&);
  ~DemoAnalyzer();

  static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);


private:
  virtual void beginJob() ;
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void endJob() ;

  //virtual void beginRun(edm::Run const&, edm::EventSetup const&);
  //virtual void endRun(edm::Run const&, edm::EventSetup const&);
  //virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&);
  //virtual void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&);

  // ----------member data ---------------------------

  unsigned int minTracks_;

  bool isPatch1_;

  TH1D *trackNumHist;

  TH1D *muPHist;
  TH1D *muPtHist;
  TH1D *muNumHist;
  TH1D *muEtaHist;
  TH1D *muPhiHist;
  TH1D *muChargeHist;
  TH1D *muQPHist;
  TH1D *muQPtHist;

  TH1D *elPHist;
  TH1D *elPtHist;
  TH1D *elNumHist;
  TH1D *elEtaHist;
  TH1D *elPhiHist;
  TH1D *elChargeHist;
  TH1D *elQPHist;
  TH1D *elQPtHist;

  TH1D *jetNumHist;

  TH1D *pfJetPHist;
  TH1D *pfJetPtHist;
  TH1D *pfJetNumHist;
  TH1D *pfJetEtaHist;
  TH1D *pfJetPhiHist;
  TH1D *pfJetChargeHist;
  TH1D *pfJetQPHist;
  TH1D *pfJetQPtHist;

  TH1D *caloJetPHist;
  TH1D *caloJetPtHist;
  TH1D *caloJetNumHist;
  TH1D *caloJetEtaHist;
  TH1D *caloJetPhiHist;
  TH1D *caloJetChargeHist;
  TH1D *caloJetQPHist;
  TH1D *caloJetQPtHist;

  TH1D *genMuPHist;
  TH1D *genMuPtHist;
  TH1D *genMuNumHist;
  TH1D *genMuEtaHist;
  TH1D *genMuPhiHist;
  TH1D *genMuChargeHist;
  TH1D *genMuQPHist;
  TH1D *genMuQPtHist;

  TH1D *genElPHist;
  TH1D *genElPtHist;
  TH1D *genElNumHist;
  TH1D *genElEtaHist;
  TH1D *genElPhiHist;
  TH1D *genElChargeHist;
  TH1D *genElQPHist;
  TH1D *genElQPtHist;

  TH1D *genJetPHist;
  TH1D *genJetPtHist;
  TH1D *genJetNumHist;
  TH1D *genJetEtaHist;
  TH1D *genJetPhiHist;
  TH1D *genJetChargeHist;
  TH1D *genJetQPHist;
  TH1D *genJetQPtHist;

  TH1D *sClusterPtHist;
  TH1D *sClusterEtaHist;
  TH1D *sClusterHaFSize;
  TH1D *sClusterClustSize;
  TH1D *clustPerSCHist;
  TH1D *sClustPerEventHist;
  TH1D *scCountHist;

  TH1D *cCountHist;
  TH1D *clusterPtHist;
  TH1D *clusterEtaHist;
  TH1D *cClustPerEventHist;

  TH1D *BarrelSClusterPtHist;
  TH1D *BarrelSClusterEtaHist;
  TH1D *BarrelSClusterHaFSize;
  TH1D *BarrelSClusterClustSize;
  TH1D *BarrelClustPerSCHist;
  TH1D *BarrelSClustPerEventHist;
  TH1D *BarrelScCountHist;

  TH1D *BarrelCCountHist;
  TH1D *BarrelClusterPtHist;
  TH1D *BarrelClusterEtaHist;
  TH1D *BarrelCClustPerEventHist;

  TH1D *EcapSClusterPtHist;
  TH1D *EcapSClusterEtaHist;
  TH1D *EcapSClusterHaFSize;
  TH1D *EcapSClusterClustSize;
  TH1D *EcapClustPerSCHist;
  TH1D *EcapSClustPerEventHist;
  TH1D *EcapScCountHist;

  TH1D *EcapCCountHist;
  TH1D *EcapClusterPtHist;
  TH1D *EcapClusterEtaHist;
  TH1D *EcapCClustPerEventHist;

  TH1D *hitTime1HB;
  TH1D *hitTime2HB; 
  TH1D *hitTime3HB;
  TH1D *hitTime1HE; 
  TH1D *hitTime2HE; 
  TH1D *hitTime3HE; 
  TH1D *hitTime4HE; 
  TH1D *hitTime5HE; 


  TH2F *energy_vs_tdc_1HB;
  TH2F *energy_vs_tdc_2HB;
  TH2F *energy_vs_tdc_3HB;
  TH2F *energy_vs_tdc_1HE;
  TH2F *energy_vs_tdc_2HE;
  TH2F *energy_vs_tdc_3HE;
  TH2F *energy_vs_tdc_4HE;
  TH2F *energy_vs_tdc_5HE;
  TH2F *energy_vs_tdc5_1HB;
  TH2F *energy_vs_tdc5_2HB;
  TH2F *energy_vs_tdc5_3HB;
  TH2F *energy_vs_tdc5_1HE;
  TH2F *energy_vs_tdc5_2HE;
  TH2F *energy_vs_tdc5_3HE;
  TH2F *energy_vs_tdc5_4HE;
  TH2F *energy_vs_tdc5_5HE;
  TH2F *energy_vs_tdc10_1HB;
  TH2F *energy_vs_tdc10_2HB;
  TH2F *energy_vs_tdc10_3HB;
  TH2F *energy_vs_tdc10_1HE;
  TH2F *energy_vs_tdc10_2HE;
  TH2F *energy_vs_tdc10_3HE;
  TH2F *energy_vs_tdc10_4HE;
  TH2F *energy_vs_tdc10_5HE;

  TH2F *energy_vs_ctdc_1HB;
  TH2F *energy_vs_ctdc_2HB;
  TH2F *energy_vs_ctdc_3HB;
  TH2F *energy_vs_ctdc_1HE;
  TH2F *energy_vs_ctdc_2HE;
  TH2F *energy_vs_ctdc_3HE;
  TH2F *energy_vs_ctdc_4HE;
  TH2F *energy_vs_ctdc_5HE;
  TH2F *energy_vs_ctdc5_1HB;
  TH2F *energy_vs_ctdc5_2HB;
  TH2F *energy_vs_ctdc5_3HB;
  TH2F *energy_vs_ctdc5_1HE;
  TH2F *energy_vs_ctdc5_2HE;
  TH2F *energy_vs_ctdc5_3HE;
  TH2F *energy_vs_ctdc5_4HE;
  TH2F *energy_vs_ctdc5_5HE;
  TH2F *energy_vs_ctdc10_1HB;
  TH2F *energy_vs_ctdc10_2HB;
  TH2F *energy_vs_ctdc10_3HB;
  TH2F *energy_vs_ctdc10_1HE;
  TH2F *energy_vs_ctdc10_2HE;
  TH2F *energy_vs_ctdc10_3HE;
  TH2F *energy_vs_ctdc10_4HE;
  TH2F *energy_vs_ctdc10_5HE;  

};

//
// constants, enums and typedefs
//

//
// static data member definitions
//
using namespace std;
using namespace reco;
//
// constructors and destructor
//
DemoAnalyzer::DemoAnalyzer(const edm::ParameterSet& iConfig)

{
   //now do what ever initialization is needed

  isPatch1_ = iConfig.getParameter<bool>	("isPatch1");

  edm::Service<TFileService> fs;
  trackNumHist = fs->make<TH1D>("tracks" , "Tracks" , 100 , 0 , 50 );

  muNumHist = fs->make<TH1D>("muons" , "Number of Muons" , 100, 0, 50 );
  muPHist = fs->make<TH1D>("Mu_P", "Muon P" , 100, 0, 500);
  muPtHist = fs->make<TH1D>("Mu_pT" , "Muon pT" , 100, 0, 500 );
  muEtaHist = fs->make<TH1D>("Mu_eta", "Muon Eta", 100, -3.5, 3.5);
  muPhiHist = fs->make<TH1D>("Mu_phi", "Muon Phi", 100, -3.5, 3.5);
  muChargeHist = fs->make<TH1D>("Mu_Charge", "Muon Charge", 100, -1.5, 1.5);
  muQPHist = fs->make<TH1D>("Mu_QP", "Muon Q*P", 200, -500, 500);
  muQPtHist = fs->make<TH1D>("Mu_QPt", "Muon Q*pT", 200, -500, 500);

  elNumHist = fs->make<TH1D>("electrons" , "Number of Electrons" , 100, 0, 50 );
  elPHist = fs->make<TH1D>("El_P", "Electron P" , 100, 0, 500);
  elPtHist = fs->make<TH1D>("El_pT" , "Electron pT" , 100, 0, 500 );
  elEtaHist = fs->make<TH1D>("El_eta", "Electron Eta", 100, -3.5, 3.5);
  elPhiHist = fs->make<TH1D>("El_phi", "Electron Phi", 100, -3.5, 3.5);
  elChargeHist = fs->make<TH1D>("El_Charge", "Electron Charge", 100, -1.5, 1.5);
  elQPHist = fs->make<TH1D>("El_QP", "Electron Q*P", 200, -500, 500);
  elQPtHist = fs->make<TH1D>("El_QPt", "Electron Q*pT", 200, -500, 500);

  pfJetNumHist = fs->make<TH1D>("pfJets" , "Number of pfJets" , 100, 0, 50 );
  pfJetPHist = fs->make<TH1D>("pfJets_P", "pfJets P" , 100, 0, 500);
  pfJetPtHist = fs->make<TH1D>("pfJets_pT" , "pfJets pT" , 100, 0, 500 );
  pfJetEtaHist = fs->make<TH1D>("pfJets_eta", "pfJets Eta", 100, -3.5, 3.5);
  pfJetPhiHist = fs->make<TH1D>("pfJets_phi", "pfJets Phi", 100, -3.5, 3.5);
  pfJetChargeHist = fs->make<TH1D>("pfJets_Charge", "pfJets Charge", 100, -1.5, 1.5);
  pfJetQPHist = fs->make<TH1D>("pfJets_QP", "pfJets Q*P", 200, -500, 500);
  pfJetQPtHist = fs->make<TH1D>("pfJets_QPt", "pfJets Q*pT", 200, -500, 500);

  caloJetNumHist = fs->make<TH1D>("caloJets" , "Number of caloJets" , 100, 0, 50 );
  caloJetPHist = fs->make<TH1D>("caloJets_P", "caloJets P" , 100, 0, 500);
  caloJetPtHist = fs->make<TH1D>("caloJets_pT" , "caloJets pT" , 100, 0, 500 );
  caloJetEtaHist = fs->make<TH1D>("caloJets_eta", "caloJets Eta", 100, -3.5, 3.5);
  caloJetPhiHist = fs->make<TH1D>("caloJets_phi", "caloJets Phi", 100, -3.5, 3.5);
  caloJetChargeHist = fs->make<TH1D>("caloJets_Charge", "caloJets Charge", 100, -1.5, 1.5);
  caloJetQPHist = fs->make<TH1D>("caloJets_QP", "caloJets Q*P", 200, -500, 500);
  caloJetQPtHist = fs->make<TH1D>("caloJets_QPt", "caloJets Q*pT", 200, -500, 500);

  genMuNumHist = fs->make<TH1D>("genMuons" , "Number of genMuons" , 100, 0, 50 );
  genMuPHist = fs->make<TH1D>("genMu_P", "genMuon P" , 100, 0, 500);
  genMuPtHist = fs->make<TH1D>("genMu_pT" , "genMuon pT" , 100, 0, 500 );
  genMuEtaHist = fs->make<TH1D>("genMu_eta", "genMuon Eta", 100, -3.5, 3.5);
  genMuPhiHist = fs->make<TH1D>("genMu_phi", "genMuon Phi", 100, -3.5, 3.5);
  genMuChargeHist = fs->make<TH1D>("genMu_Charge", "genMuon Charge", 100, -1.5, 1.5);
  genMuQPHist = fs->make<TH1D>("genMu_QP", "genMuon Q*P", 200, -500, 500);
  genMuQPtHist = fs->make<TH1D>("genMu_QPt", "genMuon Q*pT", 200, -500, 500);

  genElNumHist = fs->make<TH1D>("genElectrons" , "Number of genElectrons" , 100, 0, 50 );
  genElPHist = fs->make<TH1D>("genEl_P", "genElectron P" , 100, 0, 500);
  genElPtHist = fs->make<TH1D>("genEl_pT" , "genElectron pT" , 100, 0, 500 );
  genElEtaHist = fs->make<TH1D>("genEl_eta", "genElectron Eta", 100, -3.5, 3.5);
  genElPhiHist = fs->make<TH1D>("genEl_phi", "genElectron Phi", 100, -3.5, 3.5);
  genElChargeHist = fs->make<TH1D>("genEl_Charge", "genElectron Charge", 100, -1.5, 1.5);
  genElQPHist = fs->make<TH1D>("genEl_QP", "genElectron Q*P", 200, -500, 500);
  genElQPtHist = fs->make<TH1D>("genEl_QPt", "genElectron Q*pT", 200, -500, 500);

  genJetNumHist = fs->make<TH1D>("genJets" , "Number of genJets" , 100, 0, 50 );
  genJetPHist = fs->make<TH1D>("genJets_P", "genJets P" , 100, 0, 500);
  genJetPtHist = fs->make<TH1D>("genJets_pT" , "genJets pT" , 100, 0, 500 );
  genJetEtaHist = fs->make<TH1D>("genJets_eta", "genJets Eta", 100, -3.5, 3.5);
  genJetPhiHist = fs->make<TH1D>("genJets_phi", "genJets Phi", 100, -3.5, 3.5);
  genJetChargeHist = fs->make<TH1D>("genJets_Charge", "genJets Charge", 100, -1.5, 1.5);
  genJetQPHist = fs->make<TH1D>("genJets_QP", "genJets Q*P", 200, -500, 500);
  genJetQPtHist = fs->make<TH1D>("genJets_QPt", "genJets Q*pT", 200, -500, 500);

  jetNumHist = fs->make<TH1D>("jets" , "Number of Jets" , 100, 0, 50 );
  
  sClusterPtHist = fs->make<TH1D>("sClusterPt", "SuperCluster pT", 100, 0, 500);
  sClusterEtaHist = fs->make<TH1D>("sClusterEta", "SuperCluster Eta", 100, -3.5, 3.5);
  sClusterHaFSize = fs->make<TH1D>("sClusterHaFSize", "SuperCluster Hits and Fracs Size", 200, 1, 200);
  sClusterClustSize = fs->make<TH1D>("sClusterClustSize", "SuperCluster Cluster Size", 25, 1, 25);
  scCountHist = fs->make<TH1D>("scCountHist","Superclusters per Event",150,1,150);
  clustPerSCHist = fs->make<TH1D>("clustPerSCHist", "Clusters per Supercluster", 25, 1, 25);
  sClustPerEventHist = fs->make<TH1D>("sClustPerEventHist", "Clusters per Event from SC", 150, 1, 150);

  BarrelSClusterPtHist = fs->make<TH1D>("BarrelSClusterPtHist", "SuperCluster pT - Barrel", 100, 0, 500);
  BarrelSClusterEtaHist = fs->make<TH1D>("BarrelSClusterEtaHist", "SuperCluster Eta - Barrel", 100, -3.5, 3.5);
  BarrelSClusterHaFSize = fs->make<TH1D>("BarrelSClusterHaFSize", "SuperCluster Hits and Fracs Size - Barrel", 200, 1, 200);
  BarrelSClusterClustSize = fs->make<TH1D>("BarrelSClusterClustSize", "SuperCluster Cluster Size - Barrel", 25, 1, 25);
  BarrelScCountHist = fs->make<TH1D>("BarrelScCountHist","Superclusters per Event - Barrel",150,1,150);
  BarrelClustPerSCHist = fs->make<TH1D>("BarrelClustPerSCHist", "Clusters per Supercluster - Barrel", 25, 1, 25);
  BarrelSClustPerEventHist = fs->make<TH1D>("BarrelSClustPerEventHist", "Clusters per Event from SC - Barrel", 150, 1, 150);

  EcapSClusterPtHist = fs->make<TH1D>("EcapSClusterPtHist", "SuperCluster pT - EndCap", 100, 0, 500);
  EcapSClusterEtaHist = fs->make<TH1D>("EcapSClusterEtaHist", "SuperCluster Eta - EndCap", 100, -3.5, 3.5);
  EcapSClusterHaFSize = fs->make<TH1D>("EcapSClusterHaFSize", "SuperCluster Hits and Fracs Size - EndCap", 200, 1, 200);
  EcapSClusterClustSize = fs->make<TH1D>("EcapSClusterClustSize", "SuperCluster Cluster Size - EndCap", 25, 1, 25);
  EcapScCountHist = fs->make<TH1D>("EcapScCountHist","Superclusters per Event - EndCap",150,1,150);
  EcapClustPerSCHist = fs->make<TH1D>("EcapClustPerSCHist", "Clusters per Supercluster - EndCap", 25, 1, 25);
  EcapSClustPerEventHist = fs->make<TH1D>("EcapSClustPerEventHist", "Clusters per Event from SC - EndCap", 150, 1, 150);

   hitTime1HB = fs->make<TH1D>("hitTime1HB", "arrival time of hits in HB depth-1 clusters", 400, -78.4, 77.6);
    hitTime2HB = fs->make<TH1D>("hitTime2HB", "arrival time of hits in HB depth-2 clusters", 400, -78.4, 77.6);
    hitTime3HB = fs->make<TH1D>("hitTime3HB", "arrival time of hits in HB depth-3 clusters", 400, -78.4, 77.6);
    hitTime1HE = fs->make<TH1D>("hitTime1HE", "arrival time of hits in HE depth-1 clusters", 400, -78.4, 77.6);
    hitTime2HE = fs->make<TH1D>("hitTime2HE", "arrival time of hits in HE depth-2 clusters", 400, -78.4, 77.6);
    hitTime3HE = fs->make<TH1D>("hitTime3HE", "arrival time of hits in HE depth-3 clusters", 400, -78.4, 77.6);
    hitTime4HE = fs->make<TH1D>("hitTime4HE", "arrival time of hits in HE depth-4 clusters", 400, -78.4, 77.6);
    hitTime5HE =fs->make<TH1D>("hitTime5HE", "arrival time of hits in HE depth-5 clusters", 400, -78.4, 77.6);

    energy_vs_tdc_1HB= fs->make<TH2F>("energy_vs_tdc_1HB", "Rechit energy versus tdc",256, 0, 50, 256, -50, 50);
  energy_vs_tdc_2HB=fs->make<TH2F>("energy_vs_tdc_2HB", "Rechit energy versus tdc"  ,256, 0, 50, 256, -50, 50);
  energy_vs_tdc_3HB=fs->make<TH2F>("energy_vs_tdc_3HB", "Rechit energy versus tdc" ,256, 0, 50, 256, -50, 50);
  energy_vs_tdc_1HE=fs->make<TH2F>("energy_vs_tdc_1HE", "Rechit energy versus tdc",256, 0, 50, 256, -50, 50);
  energy_vs_tdc_2HE=fs->make<TH2F>("energy_vs_tdc_2HE", "Rechit energy versus tdc",256, 0, 50, 256, -50, 50);
  energy_vs_tdc_3HE=fs->make<TH2F>("energy_vs_tdc_3HE", "Rechit energy versus tdc" ,256, 0, 50, 256, -50, 50);
  energy_vs_tdc_4HE=fs->make<TH2F>("energy_vs_tdc_4HE", "Rechit energy versus tdc",256, 0, 50, 256, -50, 50);
  energy_vs_tdc_5HE=fs->make<TH2F>("energy_vs_tdc_5HE", "Rechit energy versus tdc" ,256, 0, 50, 256, -50, 50);
  energy_vs_tdc5_1HB=fs->make<TH2F>("energy_vs_tdc5_1HB", "Rechit energy versus tdc (energy>5 GeV)" ,256, 0, 50, 256, -50, 50);
  energy_vs_tdc5_2HB=fs->make<TH2F>("energy_vs_tdc5_2HB", "Rechit energy versus tdc (energy>5 GeV)" ,256, 0, 50, 256, -50, 50);
  energy_vs_tdc5_3HB  =fs->make<TH2F>("energy_vs_tdc5_3HB", "Rechit energy versus tdc (energy>5 GeV)" ,256, 0, 50, 256, -50, 50);
  energy_vs_tdc5_1HE  =fs->make<TH2F>("energy_vs_tdc5_1HE", "Rechit energy versus tdc (energy>5 GeV)" ,256, 0, 50, 256, -50, 50);
  energy_vs_tdc5_2HE =fs->make<TH2F>("energy_vs_tdc5_2HE", "Rechit energy versus tdc (energy>5 GeV)" ,256, 0, 50, 256, -50, 50);
  energy_vs_tdc5_3HE =fs->make<TH2F>("energy_vs_tdc5_3HE", "Rechit energy versus tdc (energy>5 GeV)" ,256, 0, 50, 256, -50, 50);
  energy_vs_tdc5_4HE=fs->make<TH2F>("energy_vs_tdc5_4HE", "Rechit energy versus tdc (energy>5 GeV)" ,256, 0, 50, 256, -50, 50);
  energy_vs_tdc5_5HE =fs->make<TH2F>("energy_vs_tdc5_5HE", "Rechit energy versus tdc (energy>5 GeV)" ,256, 0, 50, 256, -50, 50);  
  energy_vs_tdc10_1HB =fs->make<TH2F>("energy_vs_tdc10_1HB", "Rechit energy versus tdc (energy>10 GeV)" ,256, 0, 50, 256, -50, 50);
  energy_vs_tdc10_2HB =fs->make<TH2F>("energy_vs_tdc10_2HB", "Rechit energy versus tdc (energy>10 GeV)" ,256, 0, 50, 256, -50, 50);
  energy_vs_tdc10_3HB =fs->make<TH2F>("energy_vs_tdc10_3HB", "Rechit energy versus tdc (energy>10 GeV)" ,256, 0, 50, 256, -50, 50);
  energy_vs_tdc10_1HE=fs->make<TH2F>("energy_vs_tdc10_1HE", "Rechit energy versus tdc (energy>10 GeV)" ,256, 0, 50, 256, -50, 50);
  energy_vs_tdc10_2HE =fs->make<TH2F>("energy_vs_tdc10_2HE", "Rechit energy versus tdc (energy>10 GeV)" ,256, 0, 50, 256, -50, 10);
  energy_vs_tdc10_3HE =fs->make<TH2F>("energy_vs_tdc10_3HE", "Rechit energy versus tdc (energy>10 GeV)" ,256, 0, 50, 256, -50, 50);
  energy_vs_tdc10_4HE=fs->make<TH2F>("energy_vs_tdc10_4HE", "Rechit energy versus tdc (energy>10 GeV)" ,256, 0, 50, 256, -50, 50);
  energy_vs_tdc10_5HE =fs->make<TH2F>("energy_vs_tdc10_5HE", "Rechit energy versus tdc (energy>10 GeV)",256, 0, 50, 256, -50, 50);

  energy_vs_ctdc_1HB= fs->make<TH2F>("energy_vs_ctdc_1HB", "Rechit energy versus tdc",256, 0, 50, 256, -50, 50);
  energy_vs_ctdc_2HB=fs->make<TH2F>("energy_vs_ctdc_2HB", "Rechit energy versus tdc"  ,256, 0, 50, 256, -50, 50);
  energy_vs_ctdc_3HB=fs->make<TH2F>("energy_vs_ctdc_3HB", "Rechit energy versus tdc" ,256, 0, 50, 256, -50, 50);
  energy_vs_ctdc_1HE=fs->make<TH2F>("energy_vs_ctdc_1HE", "Rechit energy versus tdc",256, 0, 50, 256, -50, 50);
  energy_vs_ctdc_2HE=fs->make<TH2F>("energy_vs_ctdc_2HE", "Rechit energy versus tdc",256, 0, 50, 256, -50, 50);
  energy_vs_ctdc_3HE=fs->make<TH2F>("energy_vs_ctdc_3HE", "Rechit energy versus tdc" ,256, 0, 50, 256, -50, 50);
  energy_vs_ctdc_4HE=fs->make<TH2F>("energy_vs_ctdc_4HE", "Rechit energy versus tdc",256, 0, 50, 256, -50, 50);
  energy_vs_ctdc_5HE=fs->make<TH2F>("energy_vs_ctdc_5HE", "Rechit energy versus tdc" ,256, 0, 50, 256, -50, 50);
  energy_vs_ctdc5_1HB=fs->make<TH2F>("energy_vs_ctdc5_1HB", "Rechit energy versus tdc (energy>5 GeV)" ,256, 0, 50, 256, -50, 50);
  energy_vs_ctdc5_2HB=fs->make<TH2F>("energy_vs_ctdc5_2HB", "Rechit energy versus tdc (energy>5 GeV)" ,256, 0, 50, 256, -50, 50);
  energy_vs_ctdc5_3HB  =fs->make<TH2F>("energy_vs_ctdc5_3HB", "Rechit energy versus tdc (energy>5 GeV)" ,256, 0, 50, 256, -50, 50);
  energy_vs_ctdc5_1HE  =fs->make<TH2F>("energy_vs_ctdc5_1HE", "Rechit energy versus tdc (energy>5 GeV)" ,256, 0, 50, 256, -50, 50);
  energy_vs_ctdc5_2HE =fs->make<TH2F>("energy_vs_ctdc5_2HE", "Rechit energy versus tdc (energy>5 GeV)" ,256, 0, 50, 256, -50, 50);
  energy_vs_ctdc5_3HE =fs->make<TH2F>("energy_vs_ctdc5_3HE", "Rechit energy versus tdc (energy>5 GeV)" ,256, 0, 50, 256, -50, 50);
  energy_vs_ctdc5_4HE=fs->make<TH2F>("energy_vs_ctdc5_4HE", "Rechit energy versus tdc (energy>5 GeV)" ,256, 0, 50, 256, -50, 50);
  energy_vs_ctdc5_5HE =fs->make<TH2F>("energy_vs_ctdc5_5HE", "Rechit energy versus tdc (energy>5 GeV)" ,256, 0, 50, 256, -50, 50);
  energy_vs_ctdc10_1HB =fs->make<TH2F>("energy_vs_ctdc10_1HB", "Rechit energy versus tdc (energy>10 GeV)" ,256, 0, 50, 256, -50, 50);
  energy_vs_ctdc10_2HB =fs->make<TH2F>("energy_vs_ctdc10_2HB", "Rechit energy versus tdc (energy>10 GeV)" ,256, 0, 50, 256, -50, 50);
  energy_vs_ctdc10_3HB =fs->make<TH2F>("energy_vs_ctdc10_3HB", "Rechit energy versus tdc (energy>10 GeV)" ,256, 0, 50, 256, -50, 50);
  energy_vs_ctdc10_1HE=fs->make<TH2F>("energy_vs_ctdc10_1HE", "Rechit energy versus tdc (energy>10 GeV)" ,256, 0, 50, 256, -50, 50);
  energy_vs_ctdc10_2HE =fs->make<TH2F>("energy_vs_ctdc10_2HE", "Rechit energy versus tdc (energy>10 GeV)" ,256, 0, 50, 256, -50, 10);
  energy_vs_ctdc10_3HE =fs->make<TH2F>("energy_vs_ctdc10_3HE", "Rechit energy versus tdc (energy>10 GeV)" ,256, 0, 50, 256, -50, 50);
  energy_vs_ctdc10_4HE=fs->make<TH2F>("energy_vs_ctdc10_4HE", "Rechit energy versus tdc (energy>10 GeV)" ,256, 0, 50, 256, -50, 50);
  energy_vs_ctdc10_5HE =fs->make<TH2F>("energy_vs_ctdc10_5HE", "Rechit energy versus tdc (energy>10 GeV)",256, 0, 50, 256, -50, 50);

  cClustPerEventHist = fs->make<TH1D>("cClustPerEventHist", "Cluster size", 200, 1, 200);
  cCountHist = fs->make<TH1D>("cCountHist","Clusters per Event from pfcluster",150,1,150);
  clusterPtHist = fs->make<TH1D>("ClusterPt", "Cluster pT", 100, 0, 500);
  clusterEtaHist = fs->make<TH1D>("ClusterEta", "Cluster Eta", 100, -3.5, 3.5);

  BarrelCClustPerEventHist = fs->make<TH1D>("BarrelCClustPerEventHist", "Cluster size - Barrel", 200, 1, 200);
  BarrelCCountHist = fs->make<TH1D>("BarrelCCountHist","Clusters per Event from pfcluster - Barrel",150,1,150);
  BarrelClusterPtHist = fs->make<TH1D>("BarrelClusterPtHist", "Cluster pT - Barrel", 100, 0, 500);
  BarrelClusterEtaHist = fs->make<TH1D>("BarrelClusterEtaHist", "Cluster Eta - Barrel", 100, -3.5, 3.5);

  EcapCClustPerEventHist = fs->make<TH1D>("EcapCClustPerEventHist", "Cluster size - Endcap", 200, 1, 200);
  EcapCCountHist = fs->make<TH1D>("EcapCCountHist","Clusters per Event from pfcluster - Endcap",150,1,150);
  EcapClusterPtHist = fs->make<TH1D>("EcapClusterPtHist", "Cluster pT - Endcap", 100, 0, 500);
  EcapClusterEtaHist = fs->make<TH1D>("EcapClusterEtaHist", "Cluster Eta - Endcap", 100, -3.5, 3.5);

}


DemoAnalyzer::~DemoAnalyzer()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
DemoAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;

   //if (isPatch1_) { cout << "Using patch 1 histos." << endl; }
   //else { cout << "Not using patch 1 histos." << endl; }

   Handle<reco::TrackCollection> tracks;
   iEvent.getByLabel("generalTracks", tracks); 
   trackNumHist->Fill(tracks->size());

   Handle<reco::MuonCollection> muons;
   iEvent.getByLabel("muons", muons);
   muNumHist->Fill(muons->size());

   Handle<reco::GsfElectronCollection> els;
   iEvent.getByLabel("gsfElectrons", els);
   elNumHist->Fill(els->size());

   Handle<reco::CaloJetCollection> calojets;
   iEvent.getByLabel("ak5CaloJets", calojets);

   Handle<reco::PFJetCollection> pfjets;
   iEvent.getByLabel("ak5PFJets", pfjets);
   jetNumHist->Fill(pfjets->size());

   Handle<reco::GenJetCollection> genjets;
   iEvent.getByLabel("ak5GenJets", genjets);

   Handle<std::vector <reco::PFCluster>> pfClusters;
   iEvent.getByLabel("particleFlowClusterHCAL",pfClusters);

   int cCount, barrelCCount, ecapCCount;
   int cClustPerEvent, barrelCClustPerEvent, ecapCClustPerEvent;
   cCount = 0; // cluster size
   barrelCCount = 0;
   ecapCCount = 0;
   cClustPerEvent = 0;
   barrelCClustPerEvent = 0;
   ecapCClustPerEvent = 0;
   //cout << "WORKING ON NEW CODE!" << endl;
   foreach (const reco::PFCluster &recoCluster, *pfClusters) {
	
     cCount++;
     cClustPerEvent += recoCluster.size();
     clusterPtHist->Fill(recoCluster.pt());
     clusterEtaHist->Fill(recoCluster.eta());

     const reco::PFRecHitRef& RecHit = (recoCluster.recHitFractions().begin())->recHitRef();
     int depth = ((HcalDetId)(RecHit->detId())).depth();
     //unsigned depth = 1;
 float p0 = 0.0;
  float p1 = 0.0;
  float p2 = 0.0;
  float p3 = 0.0;
  float p4 = 0.0;
  
  switch (detDepth) {
    case 1:
    p0 = 3.44969e+000;
    p1 = -7.74797e-001;
    p2 = 7.07454e+000;
    p3 = -1.75267e-001;
    p4 = 2.08585e-003;
    break;
    
    case 2:
    p0 = 3.42694e+000;
    p1 = -7.38052e-001;
    p2 = 7.32696e+000;
    p3 = -2.14835e-001;
    p4 = 2.98468e-003;
    break;
    
    case 3:
    p0 = 3.44122e+000;
    p1 = -7.32644e-001;
    p2 = 6.68813e+000;
    p3 = -2.13227e-001;
    p4 = 2.89048e-003;
    break;
    
    case 4:
    p0 = 3.44769e+000;
    p1 = -7.36780e-001;
    p2 = 5.77368e+000;
    p3 = -2.06017e-001;
    p4 = 2.72580e-003;
    break;
    
    case 5:
    p0 = 3.45880e+000;
    p1 = -7.49052e-001;
    p2 = 4.39402e+000;
    p3 = -2.16175e-001;
    p4 = 2.65140e-003;

     if ( recoCluster.layer() == PFLayer::HCAL_ENDCAP) { 
       ecapCCount++;
       ecapCClustPerEvent += recoCluster.size();
       EcapClusterPtHist->Fill(recoCluster.pt());
       EcapClusterEtaHist->Fill(recoCluster.eta());
    if( depth == 1 ){
	 const std::vector< reco::PFRecHitFraction >& pfhitsandfracs = recoCluster.recHitFractions();
	 for (std::vector<reco::PFRecHitFraction>::const_iterator it = pfhitsandfracs.begin(); it != pfhitsandfracs.end(); ++it) {
	   const reco::PFRecHitRef rechit = it->recHitRef();
	   p0 = 3.44969e+000;
	   p1 = -7.74797e-001;
	   p2 = 7.07454e+000;
	   p3 = -1.75267e-001;
	   p4 = 2.08585e-003;	
	   double energy  = rechit->energy();
	   double time = rechit->time();
	   double hittime = time - (exp(p0*p1*energy)+ p2 + p3*energy + p4*energy*energy);
	    
	   /*if(rechit->energy()>1.0)*/ hitTime1HE->Fill(time);
	   /*if(rechit->energy()>1.0)*/ {
	     energy_vs_tdc_1HE->Fill(energy, hittime);
	   }
	   if(rechit->energy()>5.0) {
	     energy_vs_tdc5_1HE->Fill(energy, hittime);
	   }
	   if(rechit->energy()>10.0) {
	     energy_vs_tdc10_1HE->Fill(energy, hittime);
	   }
	 }
       }
       else if ( depth == 2){
	 const std::vector< reco::PFRecHitFraction >& pfhitsandfracs = recoCluster.recHitFractions();          for (std::vector<reco::PFRecHitFraction>::const_iterator it = pfhitsandfracs.begin(); it != pfhitsandfracs.end(); ++it) {                        const reco::PFRecHitRef rechit = it->recHitRef();
	   double time  = rechit->time();
	   double energy = rechit->energy();
	   double hittime  = time - 47.1677/(2.06485+rechit->energy());            
          
	   /*if(rechit->energy()>1.0)*/ hitTime2HE->Fill(time);
	   /*if(rechit->energy()>1.0)*/ {
	     energy_vs_tdc_2HE->Fill(energy, hittime);
	   }
	   if(rechit->energy()>5.0) {
	     energy_vs_tdc5_2HE->Fill(energy, hittime);
	   }
	   if(rechit->energy()>10.0) {
	     energy_vs_tdc10_2HE->Fill(energy, hittime);
	   }
	 }
       }
       else if (depth ==3){
	 const std::vector< reco::PFRecHitFraction >& pfhitsandfracs = recoCluster.recHitFractions();
	 for (std::vector<reco::PFRecHitFraction>::const_iterator it = pfhitsandfracs.begin(); it != pfhitsandfracs.end(); ++it) {
	   const reco::PFRecHitRef rechit = it->recHitRef();
	   double time  = rechit->time();
	   double energy = rechit->energy();
	   double hittime = time - 37.1941/(1.53790+rechit->energy());
           
	   /*if(rechit->energy()>1.0)*/ hitTime3HE->Fill(time);
	   /*if(rechit->energy()>1.0)*/ {
	     energy_vs_tdc_3HE->Fill(energy, hittime);
	   }
	   if(rechit->energy()>5.0) {
	     energy_vs_tdc5_3HE->Fill(energy, hittime);
	   }
	   if(rechit->energy()>10.0) {
	     energy_vs_tdc10_3HE->Fill(energy, hittime);
	   }
	 }
       }
       else if ( depth == 4){
	 const std::vector< reco::PFRecHitFraction >& pfhitsandfracs = recoCluster.recHitFractions();
	 for (std::vector<reco::PFRecHitFraction>::const_iterator it = pfhitsandfracs.begin(); it != pfhitsandfracs.end(); ++it) {
	   const reco::PFRecHitRef rechit = it->recHitRef();
	   double time  = rechit->time();
	   double energy = rechit->energy();
	   double hittime = time - 42.9898/(1.92969+rechit->energy());
            
	   /*if(rechit->energy()>1.0)*/ hitTime4HE->Fill(time);
	   /*if(rechit->energy()>1.0)*/ {
	     energy_vs_tdc_4HE->Fill(energy, hittime);
	   }
	   if(rechit->energy()>5.0) {
	     energy_vs_tdc5_4HE->Fill(energy, hittime);
	   }
	   if(rechit->energy()>10.0) {
	     energy_vs_tdc10_4HE->Fill(energy, hittime);
	   }
	 }
       }
       else if( depth == 5){
	 const std::vector< reco::PFRecHitFraction >& pfhitsandfracs = recoCluster.recHitFractions();
	 for (std::vector<reco::PFRecHitFraction>::const_iterator it = pfhitsandfracs.begin(); it != pfhitsandfracs.end(); ++it) {
	   const reco::PFRecHitRef rechit = it->recHitRef();
	   double time  = rechit->time();
	   double energy = rechit->energy();
	   double hittime = time - 48.3157/(2.29903+rechit->energy());
           
	   /*if(rechit->energy()>1.0)*/ hitTime5HE->Fill(time);
	   /*if(rechit->energy()>1.0)*/ {
	     energy_vs_tdc_5HE->Fill(energy, hittime);
	   }
	   if(rechit->energy()>5.0) {
	     energy_vs_tdc5_5HE->Fill(energy, hittime);
	   }
	   if(rechit->energy()>10.0) {
	     energy_vs_tdc10_5HE->Fill(energy, hittime);
	   }
	 }
       }
     
     }
     if ( recoCluster.layer() == PFLayer::HCAL_BARREL1) {
       barrelCCount++;
       barrelCClustPerEvent += recoCluster.size();
       BarrelClusterPtHist->Fill(recoCluster.pt());
       BarrelClusterEtaHist->Fill(recoCluster.eta());
       if(depth == 1 ){
	 const std::vector< reco::PFRecHitFraction >& pfhitsandfracs = recoCluster.recHitFractions();
	 for (std::vector<reco::PFRecHitFraction>::const_iterator it = pfhitsandfracs.begin(); it != pfhitsandfracs.end(); ++it) {
	   const reco::PFRecHitRef rechit = it->recHitRef();
	   double energy  = rechit->energy();
	   double time = rechit->time();
	   double hittime = time - 48.9580/(2.16078+rechit->energy());
           
	   /*if (rechit->energy()>1.0)*/ hitTime1HB->Fill(time);
	   /*if(rechit->energy()>1.0)*/ {
	     energy_vs_tdc_1HB->Fill(energy, hittime);
	   }
	   if(rechit->energy()>5.0) {
	     energy_vs_tdc5_1HB->Fill(energy, hittime);
	   }
	   if(rechit->energy()>10.0) {
	     energy_vs_tdc10_1HB->Fill(energy, hittime);
	   }
	 }
       }
       else if(depth == 2){
	 const std::vector< reco::PFRecHitFraction >& pfhitsandfracs = recoCluster.recHitFractions();
	 for (std::vector<reco::PFRecHitFraction>::const_iterator it = pfhitsandfracs.begin(); it != pfhitsandfracs.end(); ++it) {
	   const reco::PFRecHitRef rechit = it->recHitRef();
	   double time  = rechit->time();
	   double energy = rechit->energy();
	   double hittime = time - 34.2860/(1.23746+rechit->energy());
         
	   /*if(rechit->energy()>1.0)*/ hitTime2HB->Fill(time);
	   /*if(rechit->energy()>1.0)*/ {
	     energy_vs_tdc_2HB->Fill(energy, hittime);
	   }
	   if(rechit->energy()>5.0) {
	     energy_vs_tdc5_2HB->Fill(energy, hittime);
	   }
	   if(rechit->energy()>10.0) {
	     energy_vs_tdc10_2HB->Fill(energy, hittime);
	   }
	 }
       }
       else if (depth == 3){
	 const std::vector< reco::PFRecHitFraction >& pfhitsandfracs = recoCluster.recHitFractions();
	 for (std::vector<reco::PFRecHitFraction>::const_iterator it = pfhitsandfracs.begin(); it != pfhitsandfracs.end(); ++it) {
	   const reco::PFRecHitRef rechit = it->recHitRef();
	   double time  = rechit->time();
	   double energy = rechit->energy();
	   double hittime = time - 38.6872/(1.48051+rechit->energy());
            
	   /*if(rechit->energy()>1.0)*/ hitTime3HB->Fill(time);
	   /*if(rechit->energy()>1.0)*/ {
	     energy_vs_tdc_3HB->Fill(energy, hittime);
	   }
	   if(rechit->energy()>5.0) {
	     energy_vs_tdc5_3HB->Fill(energy, hittime);
	   }
	   if(rechit->energy()>10.0) {
	     energy_vs_tdc10_3HB->Fill(energy, hittime);
	   }            
	 }
       }
     }

   }

   cClustPerEventHist->Fill(cClustPerEvent); 
   cCountHist->Fill(cCount);
   EcapCClustPerEventHist->Fill(ecapCClustPerEvent);
   EcapCCountHist->Fill(ecapCCount);
   BarrelCClustPerEventHist->Fill(barrelCClustPerEvent);
   BarrelCCountHist->Fill(barrelCCount);
   //cout << "Cluster count! " << cCount << " = " << ecapCCount << " + " << barrelCCount << endl;
   
 
   Handle<std::vector <reco::PFSuperCluster>> pfSClusters;
   iEvent.getByLabel("particleFlowHCALSuperClusterDualTime",pfSClusters);

   int scCount, barrelSCCount, ecapSCCount;
   int sClustPerEvent, barrelSClustPerEvent, ecapSClustPerEvent;
   int clustPerSC, barrelClustPerSC, ecapClustPerSC;

   scCount = 0;
   barrelSCCount = 0;
   ecapSCCount = 0;
   sClustPerEvent = 0;
   barrelSClustPerEvent = 0;
   ecapSClustPerEvent = 0;
   clustPerSC = 0;
   barrelClustPerSC = 0;
   ecapClustPerSC = 0;

   //cout << "Clusters Per Supercluster:" << endl;
   foreach (const reco::PFSuperCluster &recoSCluster, *pfSClusters) {
	
     clustPerSC = 0;
     barrelClustPerSC = 0;
     ecapClustPerSC = 0;

     scCount++; //count of superclusters per event
     clustPerSC += recoSCluster.clusters().size(); //count of clusters per supercluster
     sClustPerEvent += recoSCluster.clusters().size(); //count of clusters per event

	
     if ( recoSCluster.layer() == PFLayer::HCAL_ENDCAP) { 
       ecapSCCount++;
       ecapClustPerSC += recoSCluster.clusters().size();
       ecapSClustPerEvent += recoSCluster.clusters().size();
       EcapSClusterPtHist->Fill(recoSCluster.pt());
       EcapSClusterEtaHist->Fill(recoSCluster.eta());
       EcapSClusterHaFSize->Fill(recoSCluster.hitsAndFractions().size());
       EcapSClusterClustSize->Fill(recoSCluster.clusters().size());
     }
        if ( recoSCluster.layer() == PFLayer::HCAL_BARREL1) { 
       barrelSCCount++;
       barrelClustPerSC += recoSCluster.clusters().size();
       barrelSClustPerEvent += recoSCluster.clusters().size();
       BarrelSClusterPtHist->Fill(recoSCluster.pt());
       BarrelSClusterEtaHist->Fill(recoSCluster.eta());
       BarrelSClusterHaFSize->Fill(recoSCluster.hitsAndFractions().size());
       BarrelSClusterClustSize->Fill(recoSCluster.clusters().size());
       sClusterPtHist->Fill(recoSCluster.pt());
       sClusterEtaHist->Fill(recoSCluster.eta());
       sClusterHaFSize->Fill(recoSCluster.hitsAndFractions().size());
       sClusterClustSize->Fill(recoSCluster.clusters().size());
	
       clustPerSCHist->Fill(clustPerSC);
       //cout << clustPerSC << endl;
     }

     //cout << "Total over all SCs: " << sClustPerEvent << endl;
     //cout << "In # of SCs: " << scCount << endl;
     sClustPerEventHist->Fill(sClustPerEvent);
     BarrelSClustPerEventHist->Fill(barrelSClustPerEvent);
     EcapSClustPerEventHist->Fill(ecapSClustPerEvent);
     scCountHist->Fill(scCount);
     BarrelScCountHist->Fill(barrelSCCount);
     EcapScCountHist->Fill(ecapSCCount);
   }
	  
   
   foreach (const reco::Muon &recomu, *muons) {
     muPHist->Fill(recomu.p());
     muPtHist->Fill(recomu.pt());
     muEtaHist->Fill(recomu.eta());
     muPhiHist->Fill(recomu.phi());
     muChargeHist->Fill(recomu.charge());
     muQPHist->Fill(recomu.p()*recomu.charge());
     muQPtHist->Fill(recomu.pt()*recomu.charge());
   }

   foreach (const reco::GsfElectron &recoel, *els) {
     elPHist->Fill(recoel.p());
     elPtHist->Fill(recoel.pt());
     elEtaHist->Fill(recoel.eta());
     elPhiHist->Fill(recoel.phi());
     elChargeHist->Fill(recoel.charge());
     elQPHist->Fill(recoel.p()*recoel.charge());
     elQPtHist->Fill(recoel.pt()*recoel.charge());
   }

   foreach (const reco::CaloJet &caloJet, *calojets) {
     caloJetPHist->Fill(caloJet.p());
     caloJetPtHist->Fill(caloJet.pt());
     caloJetEtaHist->Fill(caloJet.eta());
     caloJetPhiHist->Fill(caloJet.phi());
     caloJetChargeHist->Fill(caloJet.charge());
     caloJetQPHist->Fill(caloJet.p()*caloJet.charge());
     caloJetQPtHist->Fill(caloJet.pt()*caloJet.charge());
   }

   foreach (const reco::PFJet &PFJet, *pfjets) {
     pfJetPHist->Fill(PFJet.p());
     pfJetPtHist->Fill(PFJet.pt());
        pfJetEtaHist->Fill(PFJet.eta());
        pfJetPhiHist->Fill(PFJet.phi());
        pfJetChargeHist->Fill(PFJet.charge());
        pfJetQPHist->Fill(PFJet.p()*PFJet.charge());
        pfJetQPtHist->Fill(PFJet.pt()*PFJet.charge());
   }

   foreach (const reco::GenJet &GenJet, *genjets) {
        genJetPHist->Fill(GenJet.p());
        genJetPtHist->Fill(GenJet.pt());
        genJetEtaHist->Fill(GenJet.eta());
        genJetPhiHist->Fill(GenJet.phi());
        genJetChargeHist->Fill(GenJet.charge());
        genJetQPHist->Fill(GenJet.p()*GenJet.charge());
        genJetQPtHist->Fill(GenJet.pt()*GenJet.charge());
   }

   
   Handle<reco::GenParticleCollection> genParticles;
   iEvent.getByLabel("genParticles",genParticles);
   foreach (const reco::GenParticle &genParticle, *genParticles) {
	//cout << "Gen Particle: " << genParticle.pdgId() << " Status: " << genParticle.status() << endl;
 	Int_t id = genParticle.pdgId();
	//Int_t status = genParticle.status();
	double p = genParticle.p();
	double pt = genParticle.pt();
	double eta = genParticle.eta();
	double phi = genParticle.phi();
	double charge = genParticle.charge();
	double qp = genParticle.p()*genParticle.charge();
	double qpt = genParticle.pt()*genParticle.charge();

   switch (id) {
	case 11:
	case -11:
		genElPHist->Fill(p);
		genElPtHist->Fill(pt);
		genElEtaHist->Fill(eta);
		genElPhiHist->Fill(phi);
		genElChargeHist->Fill(charge);
		genElQPHist->Fill(qp);
		genElQPtHist->Fill(qpt);
		break;
	case 12:
	case -12:
		break;
	case 13:
	case -13:
		genMuPHist->Fill(p);
		genMuPtHist->Fill(pt);
		genMuEtaHist->Fill(eta);
		genMuPhiHist->Fill(phi);
		genMuChargeHist->Fill(charge);
		genMuQPHist->Fill(qp);
		genMuQPtHist->Fill(qpt);
		break;
	case 14:
	case -14:
		break;
	case 15:
	case -15:
		break;
	case 16:
	case -16:
		break;
	}
   }
 
//cout << "***********************************************************************************************************************************" << endl;
#ifdef THIS_IS_AN_EVENT_EXAMPLE
   Handle<ExampleData> pIn;
   iEvent.getByLabel("example",pIn);
#endif
   
#ifdef THIS_IS_AN_EVENTSETUP_EXAMPLE
   ESHandle<SetupData> pSetup;
   iSetup.get<SetupRecord>().get(pSetup);
#endif
}


// ------------ method called once each job just before starting event loop  ------------
void 
DemoAnalyzer::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
DemoAnalyzer::endJob() 
{
}

// ------------ method called when starting to processes a run  ------------
/*
void 
DemoAnalyzer::beginRun(edm::Run const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when ending the processing of a run  ------------
/*
void 
DemoAnalyzer::endRun(edm::Run const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when starting to processes a luminosity block  ------------
/*
void 
DemoAnalyzer::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when ending the processing of a luminosity block  ------------
/*
void 
DemoAnalyzer::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
DemoAnalyzer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(DemoAnalyzer);
