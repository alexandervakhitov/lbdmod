// Copyright (c) 2018 Alexander Vakhitov <alexander.vakhitov@gmail.com>
// Redistribution and use is allowed according to the terms of the 2-clause BSD license.
#include "LBDFloatLineMatcher.h"
#include <opencv2/core.hpp>
#include <iostream>

LBDFloatLineMatcher::LBDFloatLineMatcher() {};

double LBDFloatLineMatcher::MatchLineDescriptors(const cv::Mat &desc1, const cv::Mat &desc2) {
//    std::cout << desc1 << std::endl;
//    std::cout << desc2 << std::endl;
    cv::Mat d = desc1 - desc2;
    return cv::norm(d);
}