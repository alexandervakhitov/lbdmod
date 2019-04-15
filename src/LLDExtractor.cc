//
// Created by alexander on 23.08.18.
//

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