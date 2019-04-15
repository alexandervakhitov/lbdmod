//
// Created by alexander on 24.08.18.
//

#ifndef ORB_SLAM2_EMPTYMATCHER_H
#define ORB_SLAM2_EMPTYMATCHER_H


#include <LineMatcher.h>

class EmptyMatcher : public LineMatcher {
    double MatchLineDescriptors(const cv::Mat& desc1, const cv::Mat& desc2);

};


#endif //ORB_SLAM2_EMPTYMATCHER_H
