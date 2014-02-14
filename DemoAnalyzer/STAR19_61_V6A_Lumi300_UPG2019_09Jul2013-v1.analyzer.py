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
  	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6_patch1/RelValTTbar_14TeV/GEN-SIM-RECO/STAR19_61_V6A_Lumi300_UPG2019_09Jul2013-v1/00000/26925702-DAE8-E211-B45C-002590593876.root',
  	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6_patch1/RelValTTbar_14TeV/GEN-SIM-RECO/STAR19_61_V6A_Lumi300_UPG2019_09Jul2013-v1/00000/2EA81670-DAE8-E211-A262-00259059642A.root',
  	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6_patch1/RelValTTbar_14TeV/GEN-SIM-RECO/STAR19_61_V6A_Lumi300_UPG2019_09Jul2013-v1/00000/A6330038-DAE8-E211-93F3-003048FFCB8C.root',
  	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6_patch1/RelValTTbar_14TeV/GEN-SIM-RECO/STAR19_61_V6A_Lumi300_UPG2019_09Jul2013-v1/00000/403086EE-D9E8-E211-8CC7-003048FFD76E.root',
  	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6_patch1/RelValTTbar_14TeV/GEN-SIM-RECO/STAR19_61_V6A_Lumi300_UPG2019_09Jul2013-v1/00000/2C38084E-DCE8-E211-887A-0025905964C4.root',
  	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6_patch1/RelValTTbar_14TeV/GEN-SIM-RECO/STAR19_61_V6A_Lumi300_UPG2019_09Jul2013-v1/00000/4CEF376A-DCE8-E211-90DA-0025905964BE.root',
  	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6_patch1/RelValTTbar_14TeV/GEN-SIM-RECO/STAR19_61_V6A_Lumi300_UPG2019_09Jul2013-v1/00000/424221CE-DCE8-E211-AEDE-002590593920.root',
  	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6_patch1/RelValTTbar_14TeV/GEN-SIM-RECO/STAR19_61_V6A_Lumi300_UPG2019_09Jul2013-v1/00000/E4B53156-1FE9-E211-8EE5-00304867916E.root',
  	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6_patch1/RelValTTbar_14TeV/GEN-SIM-RECO/STAR19_61_V6A_Lumi300_UPG2019_09Jul2013-v1/00000/8E94DA6E-20E9-E211-AF2E-003048FFD720.root'
    )
)

process.demo = cms.EDAnalyzer('DemoAnalyzer',
				minTracks=cms.untracked.uint32(0),
				isPatch1 =  cms.bool(True)
)

process.TFileService = cms.Service("TFileService",
                                       fileName = cms.string('STAR19_61_patch1_V6A_Lumi300_UPG2019_09Jul2013-v1.KinHistos.root')
                                   )

process.p = cms.Path(process.demo)
