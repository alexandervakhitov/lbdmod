// Copyright (c) 2018 Alexander Vakhitov <alexander.vakhitov@gmail.com>
// Redistribution and use is allowed according to the terms of the 2-clause BSD license.

#ifndef ORB_SLAM2_EMPTYEXTRACTOR_H
#define ORB_SLAM2_EMPTYEXTRACTOR_H


#include <opencv2/core/mat.hpp>
#include "StoredLineExtractor.h"

class EmptyExtractor : public LineExtractor
{
public:
    EmptyExtractor();
    void ExtractLines(const cv::Mat& frame, std::vector<KeyLine>* extrLines, cv::Mat* lineDescs);
    void ExtractDescriptors(const cv::Mat& frame, std::vector<KeyLine>& keyLines, cv::Mat* lineDescs) override;
    void ExtractDetections(const cv::Mat& frame, std::vector<KeyLine>* extrLines) override;
};


#endif //ORB_SLAM2_EMPTYEXTRACTOR_H
