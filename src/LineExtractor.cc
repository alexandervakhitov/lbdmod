//
// Created by alexander on 23.08.18.
//

#include "LineExtractor.h"

void LineExtractor::ExtractLines(const cv::Mat& frame, std::vector<KeyLine>* extrLines, cv::Mat* lineDescs)
{
    ExtractDetections(frame, extrLines);
    ExtractDescriptors(frame, *extrLines, lineDescs);
}