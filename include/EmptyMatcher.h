// Copyright (c) 2018 Alexander Vakhitov <alexander.vakhitov@gmail.com>
// Redistribution and use is allowed according to the terms of the 2-clause BSD license.

#ifndef ORB_SLAM2_EMPTYMATCHER_H
#define ORB_SLAM2_EMPTYMATCHER_H


#include <LineMatcher.h>

class EmptyMatcher : public LineMatcher {
    double MatchLineDescriptors(const cv::Mat& desc1, const cv::Mat& desc2);

};


#endif //ORB_SLAM2_EMPTYMATCHER_H
