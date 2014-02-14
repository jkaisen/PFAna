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
        'file:/uscms_data/d3/jk323209/TimingImplementation/CMSSW_6_1_2_SLHC6_patch1/src/SinglePiPt100RECO.root'
    )
)

process.demo = cms.EDAnalyzer('DemoAnalyzer',
				minTracks=cms.untracked.uint32(0),
				isPatch1 =  cms.bool(False)
)

process.TFileService = cms.Service("TFileService",
                                       fileName = cms.string('STAR19_61_V6A_Lumi300_UPG2019-v4.KinHistos.root')
                                   )

process.p = cms.Path(process.demo)
