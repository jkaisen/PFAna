// -*- C++ -*-
//
// Package:    PFAnalyzer
// Class:      PFAnalyzer
// 
/**\class PFAnalyzer PFAnalyzer.cc Analyzer/PFAnalyzer/src/PFAnalyzer.cc

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

#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"

#include <boost/foreach.hpp>
#define foreach BOOST_FOREACH

//
// class declaration
//

class PFAnalyzer : public edm::EDAnalyzer {
   public:
      explicit PFAnalyzer(const edm::ParameterSet&);
      ~PFAnalyzer();

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

      TH1D *clustPerEventHist;
      TH1D *cCountHist;
      TH1D *clusterPtHist;
      TH1D *clusterEtaHist;
};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
PFAnalyzer::PFAnalyzer(const edm::ParameterSet& iConfig)

{
   //now do what ever initialization is needed

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

  clustPerEventHist = fs->make<TH1D>("clustPerEventHist", "Clusters per Event", 150, 1, 150);
  cCountHist = fs->make<TH1D>("cCountHist","Clusters per Event",150,1,150);
  clusterPtHist = fs->make<TH1D>("ClusterPt", "Cluster pT", 100, 0, 500);
  clusterEtaHist = fs->make<TH1D>("ClusterEta", "Cluster Eta", 100, -3.5, 3.5);
}


PFAnalyzer::~PFAnalyzer()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
PFAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;

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

   int cCount, clustPerEvent;
   cCount = 0; // cluster size
   clustPerEvent = 0; //clusters per event
   foreach (const reco::PFCluster &recoCluster, *pfClusters) {
	
	cCount++;
        clustPerEvent += recoCluster.size(); 
        clusterPtHist->Fill(recoCluster.pt());
        clusterEtaHist->Fill(recoCluster.eta());

   }

   clustPerEventHist->Fill(clustPerEvent);
   cCountHist->Fill(cCount);

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
PFAnalyzer::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
PFAnalyzer::endJob() 
{
}

// ------------ method called when starting to processes a run  ------------
/*
void 
PFAnalyzer::beginRun(edm::Run const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when ending the processing of a run  ------------
/*
void 
PFAnalyzer::endRun(edm::Run const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when starting to processes a luminosity block  ------------
/*
void 
PFAnalyzer::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when ending the processing of a luminosity block  ------------
/*
void 
PFAnalyzer::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
PFAnalyzer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(PFAnalyzer);
