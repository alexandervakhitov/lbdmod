// Copyright (c) 2018 Alexander Vakhitov <alexander.vakhitov@gmail.com>
// Redistribution and use is allowed according to the terms of the 2-clause BSD license.

#include "LLDLineMatcher.h"

LLDLineMatcher::LLDLineMatcher() {};

double LLDLineMatcher::MatchLineDescriptors(const cv::Mat &desc1, const cv::Mat &desc2) {
    return 2.0 - desc1.dot(desc2);
}