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
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6/RelValTTbar_14TeV/GEN-SIM-RECO/STAR17_61_V1A_NOAGING_REF_STARTUP_UPG2017-v3/00000/BEC32C62-85DF-E211-B418-002618943961.root',
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6/RelValTTbar_14TeV/GEN-SIM-RECO/STAR17_61_V1A_NOAGING_REF_STARTUP_UPG2017-v3/00000/A0D0466D-85DF-E211-BB61-002618943962.root',
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6/RelValTTbar_14TeV/GEN-SIM-RECO/STAR17_61_V1A_NOAGING_REF_STARTUP_UPG2017-v3/00000/8819AB69-85DF-E211-8A06-00261894393F.root',
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6/RelValTTbar_14TeV/GEN-SIM-RECO/STAR17_61_V1A_NOAGING_REF_STARTUP_UPG2017-v3/00000/36B91C34-83DF-E211-B3A2-003048FFD728.root',
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6/RelValTTbar_14TeV/GEN-SIM-RECO/STAR17_61_V1A_NOAGING_REF_STARTUP_UPG2017-v3/00000/2A6CBE0D-84DF-E211-BA48-0025905964BA.root',
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6/RelValTTbar_14TeV/GEN-SIM-RECO/STAR17_61_V1A_NOAGING_REF_STARTUP_UPG2017-v3/00000/FA398148-89DF-E211-9CD8-002618943922.root',
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6/RelValTTbar_14TeV/GEN-SIM-RECO/STAR17_61_V1A_NOAGING_REF_STARTUP_UPG2017-v3/00000/804C1BDC-86DF-E211-BC79-0025905964B2.root',
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6/RelValTTbar_14TeV/GEN-SIM-RECO/STAR17_61_V1A_NOAGING_REF_STARTUP_UPG2017-v3/00000/7C4B45B2-8BDF-E211-B22E-003048FFD7A2.root',
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6/RelValTTbar_14TeV/GEN-SIM-RECO/STAR17_61_V1A_NOAGING_REF_STARTUP_UPG2017-v3/00000/54994344-8FDF-E211-ADD0-003048FFD736.root',
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6/RelValTTbar_14TeV/GEN-SIM-RECO/STAR17_61_V1A_NOAGING_REF_STARTUP_UPG2017-v3/00000/204F956E-A0DF-E211-9229-003048FFD736.root'
    )
)

process.demo = cms.EDAnalyzer('DemoAnalyzer',
				minTracks=cms.untracked.uint32(0),
				isPatch1 =  cms.bool(False)
)

process.TFileService = cms.Service("TFileService",
                                       fileName = cms.string('STAR17_61_V1A_NOAGING_REF_STARTUP_UPG2017-v3.KinHistos.root')
                                   )

process.p = cms.Path(process.demo)
