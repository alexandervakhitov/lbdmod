// Copyright (c) 2018 Alexander Vakhitov <alexander.vakhitov@gmail.com>
// Redistribution and use is allowed according to the terms of the 2-clause BSD license.

#include <opencv2/core/persistence.hpp>
#include "LBDFloatLineMatcher.h"
#include "LLDLineMatcher.h"
#include "LinesConfigurator.h"
#include "LBDFloatExtractor.h"
#include "LLDExtractor.h"

#include "EmptyExtractor.h"
#include "EmptyMatcher.h"

StoredLineExtractor* LinesConfigurator::CreateLineExtractor(const std::string &strSettings, bool isLeft)
{
    cv::FileStorage fSettings(strSettings, cv::FileStorage::READ);
    StoredLineExtractor* extractor = NULL;
    bool isTest = (int)fSettings["test"];
    if (fSettings["ldType"] == "LBDFloat")
    {
        std::cout << "Using LBD Float stored, test = " << isTest << std::endl;
        extractor = new LBDFloatExtractor(fSettings["lineDetectionsPath"], fSettings["lineDescriptorsPath"], isLeft, isTest);
    }
    if (fSettings["ldType"] == "LLD")
    {
        std::cout << " Using learned line descriptor " << (std::string) fSettings["lineDetectionsPath"] << std::endl;
        std::cout << "   " << (std::string) fSettings["lineDescriptorsPath"] << std::endl;
        extractor = new LLDExtractor(fSettings["lineDetectionsPath"], fSettings["lineDescriptorsPath"], isLeft, isTest);
    }
    if (!extractor)
    {
        extractor = NULL;
    }
    return extractor;
}

LineMatcher* LinesConfigurator::CreateLineMatcher(const cv::FileStorage& fSettings) {
    LineMatcher* matcher = static_cast<LineMatcher*> (NULL);
    std::cout << " creating LM " << std::endl;
    if (fSettings["ldType"] == "LBDFloat")
    {
        matcher = new LBDFloatLineMatcher();
        std::cout << " LBD LM " << std::endl;
    }
    if (fSettings["ldType"] == "LLD")
    {
        matcher = new LLDLineMatcher();
        std::cout << " LLD LM " << std::endl;
    }
    if (!matcher)
    {
        matcher = new EmptyMatcher();
        std::cout << " Empty LM " << std::endl;
    }
    return matcher;
}