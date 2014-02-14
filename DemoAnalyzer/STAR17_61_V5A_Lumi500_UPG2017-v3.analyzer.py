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
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6/RelValTTbar_14TeV/GEN-SIM-RECO/STAR17_61_V5A_Lumi500_UPG2017-v3/00000/1A86F2F9-81DF-E211-A7DC-002590593872.root',
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6/RelValTTbar_14TeV/GEN-SIM-RECO/STAR17_61_V5A_Lumi500_UPG2017-v3/00000/10790C6E-83DF-E211-9DF2-00259059642A.root',
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6/RelValTTbar_14TeV/GEN-SIM-RECO/STAR17_61_V5A_Lumi500_UPG2017-v3/00000/14AADFC5-87DF-E211-B0D1-003048679180.root',
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6/RelValTTbar_14TeV/GEN-SIM-RECO/STAR17_61_V5A_Lumi500_UPG2017-v3/00000/90EFF5F3-81DF-E211-8972-00261894385A.root',
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6/RelValTTbar_14TeV/GEN-SIM-RECO/STAR17_61_V5A_Lumi500_UPG2017-v3/00000/F6126365-97DF-E211-839B-0026189438B1.root',
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6/RelValTTbar_14TeV/GEN-SIM-RECO/STAR17_61_V5A_Lumi500_UPG2017-v3/00000/A2E04C61-8DDF-E211-ABAB-003048679182.root',
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6/RelValTTbar_14TeV/GEN-SIM-RECO/STAR17_61_V5A_Lumi500_UPG2017-v3/00000/FCB1EF9C-83DF-E211-BC34-003048678DA2.root',
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6/RelValTTbar_14TeV/GEN-SIM-RECO/STAR17_61_V5A_Lumi500_UPG2017-v3/00000/C2F97D6A-8DDF-E211-849D-0018F3D09630.root',
	'dcache:/pnfs/cms/WAX/11/store/relval/CMSSW_6_1_2_SLHC6/RelValTTbar_14TeV/GEN-SIM-RECO/STAR17_61_V5A_Lumi500_UPG2017-v3/00000/2C8660C6-85DF-E211-B9E5-003048FFCB84.root'
    )
)

process.demo = cms.EDAnalyzer('DemoAnalyzer',
				minTracks=cms.untracked.uint32(0),
				isPatch1 =  cms.bool(False)
)

process.TFileService = cms.Service("TFileService",
                                       fileName = cms.string('STAR17_61_V5A_Lumi500_UPG2017-v3.KinHistos.root')
                                   )

process.p = cms.Path(process.demo)
