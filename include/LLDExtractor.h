// Copyright (c) 2018 Alexander Vakhitov <alexander.vakhitov@gmail.com>
// Redistribution and use is allowed according to the terms of the 2-clause BSD license.

#ifndef ORB_SLAM2_LLDEXTRACTOR_H
#define ORB_SLAM2_LLDEXTRACTOR_H

#include <opencv2/core/mat.hpp>
#include "LineExtractor.h"
#include "StoredLineExtractor.h"

class LLDExtractor : public StoredLineExtractor
{
public:
    LLDExtractor(const std::string& strDetections, const std::string& strDescriptors, bool isLeft, bool isTest=false);
    void ExtractDescriptors(const cv::Mat& frame, std::vector<KeyLine>& extrLines, cv::Mat* lineDescs) override;
    ~LLDExtractor() {};
private:
    const std::string strDescriptorsStorage;
};


#endif //ORB_SLAM2_LLDEXTRACTOR_H
