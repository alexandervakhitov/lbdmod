// Copyright (c) 2018 Alexander Vakhitov <alexander.vakhitov@gmail.com>
// Redistribution and use is allowed according to the terms of the 2-clause BSD license.

#include "LineExtractor.h"

void LineExtractor::ExtractLines(const cv::Mat& frame, std::vector<KeyLine>* extrLines, cv::Mat* lineDescs)
{
    ExtractDetections(frame, extrLines);
    ExtractDescriptors(frame, *extrLines, lineDescs);
}