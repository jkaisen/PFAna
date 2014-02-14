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
	'file:/uscms_data/d3/aoliver/PF_Service/ntuples/pion/New_Geometry/SinglePiPt100RECO.root'
    )
)

process.demo = cms.EDAnalyzer('DemoAnalyzer',
				minTracks=cms.untracked.uint32(0),
				isPatch1 = cms.bool(True)
)

process.TFileService = cms.Service("TFileService",
                                       fileName = cms.string('SinglePiPt100RECO.root.KinHistos.root')
                                   )

process.p = cms.Path(process.demo)
