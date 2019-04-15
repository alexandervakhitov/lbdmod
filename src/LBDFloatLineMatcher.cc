//
// Created by alexander on 24.08.18.
//

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