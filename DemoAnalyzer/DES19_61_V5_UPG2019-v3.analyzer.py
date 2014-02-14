import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.cerr.threshold = 'INFO'
process.MessageLogger.categories.append('Demo')
process.MessageLogger.cerr.INFO = cms.untracked.PSet(
        limit = cms.untracked.int32(-1)
        )

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.options = cms.untracked.PSet( wantSummary = cms.untracked.bool(True) )

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring(
       # 'file:/uscms_data/d3/aoliver/PF_Service/CMSSW_6_1_2_SLHC4/src/3400_FourMuPt1_200_UPG2019+FourMuPt1_200_UPG2019+DIGIUP19+RECOUP19+HARVESTUP19/step3.root'
        #'file:/uscms_data/d3/aoliver/PF_Service/ntuples/10435A51-D9E8-E211-B8FA-003048FFCB8C.root'
        #'file:/uscms_data/d3/aoliver/PF_Service/ntuples/STAR19_61_V5A_Lumi500_UPG2019_09Jul2013-v1/3AD5E66B-DAE8-E211-934C-0025905964C4.root'
	#'file:/uscms_data/d3/aoliver/PF_Service/ntuples/STAR19_61_V6A_Lumi300_UPG2019_09Jul2013-v1/26925702-DAE8-E211-B45C-002590593876.root'
	#'file:/uscms_data/d3/aoliver/PF_Service/ntuples/DES19_61_V5_PFlow_hcal19_09Jul2013-v1/AC5E814D-DBE8-E211-93FC-002590596484.root'
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6/RelValTTbar_14TeV/GEN-SIM-RECO/DES19_61_V5_UPG2019-v3/00000/E4D94A63-84DF-E211-8E98-003048FFD796.root',
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6/RelValTTbar_14TeV/GEN-SIM-RECO/DES19_61_V5_UPG2019-v3/00000/8008BD92-86DF-E211-BFC7-0025905938A8.root',
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6/RelValTTbar_14TeV/GEN-SIM-RECO/DES19_61_V5_UPG2019-v3/00000/1CAA3C9E-8BDF-E211-8D73-00248C55CC7F.root',
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6/RelValTTbar_14TeV/GEN-SIM-RECO/DES19_61_V5_UPG2019-v3/00000/2E013C04-86DF-E211-92C3-0025905964C0.root',
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6/RelValTTbar_14TeV/GEN-SIM-RECO/DES19_61_V5_UPG2019-v3/00000/22DB6160-86DF-E211-8B86-003048FFD7C2.root',
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6/RelValTTbar_14TeV/GEN-SIM-RECO/DES19_61_V5_UPG2019-v3/00000/A495D686-8BDF-E211-ACDD-003048FFCC0A.root',
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6/RelValTTbar_14TeV/GEN-SIM-RECO/DES19_61_V5_UPG2019-v3/00000/A274DAE5-8CDF-E211-B0BD-002590593872.root',
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6/RelValTTbar_14TeV/GEN-SIM-RECO/DES19_61_V5_UPG2019-v3/00000/80CD3E86-8DDF-E211-B8A7-002590596486.root',
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6/RelValTTbar_14TeV/GEN-SIM-RECO/DES19_61_V5_UPG2019-v3/00000/EE2B46B0-94DF-E211-B729-0026189438EB.root',
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6/RelValTTbar_14TeV/GEN-SIM-RECO/DES19_61_V5_UPG2019-v3/00000/E4CE16A4-A0DF-E211-B7FB-0026189438EB.root'
    )
)

process.demo = cms.EDAnalyzer('DemoAnalyzer',
				minTracks=cms.untracked.uint32(0),
				isPatch1 =  cms.bool(False)
)

process.TFileService = cms.Service("TFileService",
                                       fileName = cms.string('DES19_61_V5_UPG2019-v3.KinHistos.root')
                                   )

process.p = cms.Path(process.demo)
