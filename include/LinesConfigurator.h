// Copyright (c) 2018 Alexander Vakhitov <alexander.vakhitov@gmail.com>
// Redistribution and use is allowed according to the terms of the 2-clause BSD license.

#ifndef ORB_SLAM2_LINESCONFIGURATOR_H
#define ORB_SLAM2_LINESCONFIGURATOR_H

#include <opencv2/line_descriptor.hpp>
#include "LineExtractor.h"
#include "LineMatcher.h"
#include "StoredLineExtractor.h"

class LinesConfigurator
{
public:
    static StoredLineExtractor* CreateLineExtractor(const std::string& strSettings, bool isLeft);
    static LineMatcher* CreateLineMatcher(const cv::FileStorage& settings);
};


#endif //ORB_SLAM2_LINESCONFIGURATOR_H
