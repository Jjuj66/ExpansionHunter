add_library(sample_analysis
        GenomeMask.hh GenomeMask.cpp
        HtsFileSeeker.hh HtsFileSeeker.cpp
        HtsFileStreamer.hh HtsFileStreamer.cpp
        HtsSeekingSampleAnalysis.hh HtsSeekingSampleAnalysis.cpp
        IndexBasedDepthEstimate.hh IndexBasedDepthEstimate.cpp
        ModelFinder.hh ModelFinder.cpp
        DepthNormalization.hh DepthNormalization.cpp
        GenomeQueryCollection.hh GenomeQueryCollection.cpp
        HtsStreamingSampleAnalysis.hh HtsStreamingSampleAnalysis.cpp
        MateExtractor.hh MateExtractor.cpp
        ReadDispatch.cpp ReadDispatch.hh CatalogAnalyzer.cpp CatalogAnalyzer.hh HtsReadRecord.cpp HtsReadRecord.hh)
target_link_libraries(sample_analysis workflow common)
add_subdirectory(tests)
