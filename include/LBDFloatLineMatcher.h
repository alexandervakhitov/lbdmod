//
// Created by alexander on 24.08.18.
//

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
