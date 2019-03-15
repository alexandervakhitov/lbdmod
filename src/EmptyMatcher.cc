//
// Created by alexander on 24.08.18.
//
// Copyright (c) 2018 Alexander Vakhitov <alexander.vakhitov@gmail.com>
// Redistribution and use is allowed according to the terms of the 2-clause BSD license.
#include "EmptyMatcher.h"

double EmptyMatcher::MatchLineDescriptors(const cv::Mat &desc1, const cv::Mat &desc2) {
    return 1;
}