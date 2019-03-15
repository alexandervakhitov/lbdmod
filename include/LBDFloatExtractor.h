// Copyright (c) 2018 Alexander Vakhitov <alexander.vakhitov@gmail.com>
// Redistribution and use is allowed according to the terms of the 2-clause BSD license.

#ifndef ORB_SLAM2_LBDFLOATEXTRACTOR_H
#define ORB_SLAM2_LBDFLOATEXTRACTOR_H

#include "LineExtractor.h"
#include "StoredLineExtractor.h"
#include <string>
#include <opencv2/core/mat.hpp>

class LBDFloatExtractor : public StoredLineExtractor
{
public:
    void ExtractDescriptorsTrain(cv::Mat* lineDescs);
    void ExtractDescriptorsTest(std::vector<KeyLine> &extrLines, cv::Mat* lineDescs);
    LBDFloatExtractor(const std::string& strDetections, const std::string& strDescriptors, bool isLeft, bool isTest = false);
    void ExtractDescriptors(const cv::Mat& frame, std::vector<KeyLine> &extrLines, cv::Mat *lineDescs) override;

private:
    const std::string strDescriptorsStorage;
};


#endif //ORB_SLAM2_LBDFLOATEXTRACTOR_H
