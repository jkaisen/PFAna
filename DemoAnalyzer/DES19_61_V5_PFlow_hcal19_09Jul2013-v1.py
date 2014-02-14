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
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6_patch1/RelValTTbar_14TeV/GEN-SIM-RECO/DES19_61_V5_PFlow_hcal19_09Jul2013-v1/00000/AC5E814D-DBE8-E211-93FC-002590596484.root',
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6_patch1/RelValTTbar_14TeV/GEN-SIM-RECO/DES19_61_V5_PFlow_hcal19_09Jul2013-v1/00000/10435A51-D9E8-E211-B8FA-003048FFCB8C.root',
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6_patch1/RelValTTbar_14TeV/GEN-SIM-RECO/DES19_61_V5_PFlow_hcal19_09Jul2013-v1/00000/C807B95C-D9E8-E211-8937-003048FFD744.root',
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6_patch1/RelValTTbar_14TeV/GEN-SIM-RECO/DES19_61_V5_PFlow_hcal19_09Jul2013-v1/00000/9215FA2E-DAE8-E211-8944-003048FFD730.root',
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6_patch1/RelValTTbar_14TeV/GEN-SIM-RECO/DES19_61_V5_PFlow_hcal19_09Jul2013-v1/00000/200F7D50-DBE8-E211-BE91-0025905964C4.root',
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6_patch1/RelValTTbar_14TeV/GEN-SIM-RECO/DES19_61_V5_PFlow_hcal19_09Jul2013-v1/00000/1E0E2D45-DAE8-E211-9808-003048FFCB74.root',
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6_patch1/RelValTTbar_14TeV/GEN-SIM-RECO/DES19_61_V5_PFlow_hcal19_09Jul2013-v1/00000/287E3B52-DBE8-E211-B630-00259059642A.root',
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6_patch1/RelValTTbar_14TeV/GEN-SIM-RECO/DES19_61_V5_PFlow_hcal19_09Jul2013-v1/00000/D67B74EF-DBE8-E211-AF09-002590596486.root',
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6_patch1/RelValTTbar_14TeV/GEN-SIM-RECO/DES19_61_V5_PFlow_hcal19_09Jul2013-v1/00000/AA8BB1A9-32E9-E211-943A-002590596490.root'
    )
)

process.demo = cms.EDAnalyzer('DemoAnalyzer',
				minTracks=cms.untracked.uint32(0),
				isPatch1 =  cms.bool(True)
)

process.TFileService = cms.Service("TFileService",
                                       fileName = cms.string('DES19_61_patch1_V5_PFlow_hcal19_09Jul2013-v1.KinHistos.root')
                                   )

process.p = cms.Path(process.demo)
