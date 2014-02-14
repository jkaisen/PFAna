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
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6/RelValTTbar_14TeV/GEN-SIM-RECO/STAR19_61_V1A_NOAGING_REF_STARTUP_UPG2019-v3/00000/3246F5D0-89DF-E211-9EF3-003048678B5E.root',
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6/RelValTTbar_14TeV/GEN-SIM-RECO/STAR19_61_V1A_NOAGING_REF_STARTUP_UPG2019-v3/00000/14A5033A-8BDF-E211-AA00-003048678B26.root',
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6/RelValTTbar_14TeV/GEN-SIM-RECO/STAR19_61_V1A_NOAGING_REF_STARTUP_UPG2019-v3/00000/CC1BCEDD-89DF-E211-8FD6-00259059642E.root',
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6/RelValTTbar_14TeV/GEN-SIM-RECO/STAR19_61_V1A_NOAGING_REF_STARTUP_UPG2019-v3/00000/7A3508CC-8FDF-E211-A79A-003048679244.root',
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6/RelValTTbar_14TeV/GEN-SIM-RECO/STAR19_61_V1A_NOAGING_REF_STARTUP_UPG2019-v3/00000/940FF1B6-8BDF-E211-9706-003048FFCB74.root',
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6/RelValTTbar_14TeV/GEN-SIM-RECO/STAR19_61_V1A_NOAGING_REF_STARTUP_UPG2019-v3/00000/5C43D51A-9DDF-E211-9712-0025905964C2.root',
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6/RelValTTbar_14TeV/GEN-SIM-RECO/STAR19_61_V1A_NOAGING_REF_STARTUP_UPG2019-v3/00000/D80F07AB-92DF-E211-926A-003048D15E24.root',
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6/RelValTTbar_14TeV/GEN-SIM-RECO/STAR19_61_V1A_NOAGING_REF_STARTUP_UPG2019-v3/00000/2E32968E-93DF-E211-92C2-003048678FA0.root',
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6/RelValTTbar_14TeV/GEN-SIM-RECO/STAR19_61_V1A_NOAGING_REF_STARTUP_UPG2019-v3/00000/8A6F6B22-96DF-E211-8778-003048678E6E.root'
    )
)

process.demo = cms.EDAnalyzer('DemoAnalyzer',
				minTracks=cms.untracked.uint32(0),
				isPatch1 =  cms.bool(False)
)

process.TFileService = cms.Service("TFileService",
                                       fileName = cms.string('STAR19_61_V1A_NOAGING_REF_STARTUP_UPG2019-v3.KinHistos.root')
                                   )

process.p = cms.Path(process.demo)
