// Copyright (c) 2018 Alexander Vakhitov <alexander.vakhitov@gmail.com>
// Redistribution and use is allowed according to the terms of the 2-clause BSD license.

#ifndef LINEDESCDATACOLLECTOR_LBDFLOATONLINEEXTRACTOR_H
#define LINEDESCDATACOLLECTOR_LBDFLOATONLINEEXTRACTOR_H


#include "LineExtractor.h"

class LBDFLoatOnlineExtractor : public LineExtractor {
public:
    LBDFLoatOnlineExtractor();
    void ExtractDescriptors(const cv::Mat& frame, std::vector<KeyLine>& keyLines, cv::Mat* lineDescs) override;
    void ExtractDetections(const cv::Mat& frame, std::vector<KeyLine>* extrLines) override;

    int n_octaves = 4;
    double pyramid_factor = 1.2*1.2;
    cv::line_descriptor::BinaryDescriptor bd;
};


#endif //LINEDESCDATACOLLECTOR_LBDFLOATONLINEEXTRACTOR_H
