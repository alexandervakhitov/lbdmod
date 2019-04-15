//
// Created by alexander on 24.08.18.
//

#include "LLDLineMatcher.h"

LLDLineMatcher::LLDLineMatcher() {};

double LLDLineMatcher::MatchLineDescriptors(const cv::Mat &desc1, const cv::Mat &desc2) {
    return 2.0 - desc1.dot(desc2);
}