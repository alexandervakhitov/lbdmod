// Copyright (c) 2018 Alexander Vakhitov <alexander.vakhitov@gmail.com>
// Redistribution and use is allowed according to the terms of the 2-clause BSD license.

#ifndef ORB_SLAM2_LINEMATCHER_H
#define ORB_SLAM2_LINEMATCHER_H


#include <opencv2/core/mat.hpp>

class LineMatcher {
public:
    virtual double MatchLineDescriptors(const cv::Mat& desc1, const cv::Mat& desc2) = 0;
    virtual ~LineMatcher() {};
};


#endif //ORB_SLAM2_LINEMATCHER_H
