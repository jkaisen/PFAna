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
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6/RelValTTbar_14TeV/GEN-SIM-RECO/STAR19_61_V5A_Lumi500_UPG2019-v4/00000/EAF64121-CAE4-E211-832E-C860001BD84C.root',
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6/RelValTTbar_14TeV/GEN-SIM-RECO/STAR19_61_V5A_Lumi500_UPG2019-v4/00000/AE1BC150-D8E4-E211-AEFC-003048F01084.root',
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6/RelValTTbar_14TeV/GEN-SIM-RECO/STAR19_61_V5A_Lumi500_UPG2019-v4/00000/D6E3F3B9-F1E4-E211-8A68-02163E008EB4.root',
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6/RelValTTbar_14TeV/GEN-SIM-RECO/STAR19_61_V5A_Lumi500_UPG2019-v4/00000/EE627D15-D5E4-E211-A817-003048D3C992.root',
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6/RelValTTbar_14TeV/GEN-SIM-RECO/STAR19_61_V5A_Lumi500_UPG2019-v4/00000/AACD3A83-D3E4-E211-A47E-003048D2BAB8.root',
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6/RelValTTbar_14TeV/GEN-SIM-RECO/STAR19_61_V5A_Lumi500_UPG2019-v4/00000/BAA26DC6-E1E4-E211-9094-BCAEC5329701.root',
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6/RelValTTbar_14TeV/GEN-SIM-RECO/STAR19_61_V5A_Lumi500_UPG2019-v4/00000/6A89BADB-CFE4-E211-9326-003048F23842.root',
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6/RelValTTbar_14TeV/GEN-SIM-RECO/STAR19_61_V5A_Lumi500_UPG2019-v4/00000/5E636B73-CDE4-E211-9B9E-BCAEC532971B.root',
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6/RelValTTbar_14TeV/GEN-SIM-RECO/STAR19_61_V5A_Lumi500_UPG2019-v4/00000/522C1E9F-D2E4-E211-B991-003048D374E8.root'
    )
)

process.demo = cms.EDAnalyzer('DemoAnalyzer',
				minTracks=cms.untracked.uint32(0),
				isPatch1=cms.bool(False)
)

process.TFileService = cms.Service("TFileService",
                                       fileName = cms.string('STAR19_61_V5A_Lumi500_UPG2019-v4.KinHistos.root')
                                   )

process.p = cms.Path(process.demo)
