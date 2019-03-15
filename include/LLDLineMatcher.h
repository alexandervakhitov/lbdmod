// Copyright (c) 2018 Alexander Vakhitov <alexander.vakhitov@gmail.com>
// Redistribution and use is allowed according to the terms of the 2-clause BSD license.

#ifndef ORB_SLAM2_LLDLINEMATCHER_H
#define ORB_SLAM2_LLDLINEMATCHER_H


#include "LineMatcher.h"

class LLDLineMatcher : public LineMatcher {
public:
    LLDLineMatcher();
    double MatchLineDescriptors(const cv::Mat& desc1, const cv::Mat& desc2) override;
    ~LLDLineMatcher() {};
};


#endif //ORB_SLAM2_LLDLINEMATCHER_H
