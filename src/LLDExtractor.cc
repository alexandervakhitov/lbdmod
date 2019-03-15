// Copyright (c) 2018 Alexander Vakhitov <alexander.vakhitov@gmail.com>
// Redistribution and use is allowed according to the terms of the 2-clause BSD license.

#include <fstream>
#include <opencv2/core/mat.hpp>
#include "LLDExtractor.h"

LLDExtractor::LLDExtractor(const std::string &strDetections, const std::string &strDescriptors, bool isLeft, bool isTest) :
        StoredLineExtractor(strDetections, isLeft, isTest), strDescriptorsStorage(strDescriptors)
{}

void LLDExtractor::ExtractDescriptors(const cv::Mat& frame, std::vector<KeyLine> &extrLines, cv::Mat *lineDescs)
{
    ReadTXTDescriptors(extrLines, strDescriptorsStorage, lineDescs);
}