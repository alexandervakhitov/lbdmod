//
// Created by alexander on 24.08.18.
//

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
