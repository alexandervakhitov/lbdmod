// Copyright (c) 2018 Alexander Vakhitov <alexander.vakhitov@gmail.com>
// Redistribution and use is allowed according to the terms of the 2-clause BSD license.

#ifndef ORB_SLAM2_LBDLINEMATCHER_H
#define ORB_SLAM2_LBDLINEMATCHER_H


#include "LineMatcher.h"

class LBDFloatLineMatcher : public LineMatcher
{
public:
    LBDFloatLineMatcher();
    double MatchLineDescriptors(const cv::Mat& desc1, const cv::Mat& desc2) override;
};


#endif //ORB_SLAM2_LBDLINEMATCHER_H
