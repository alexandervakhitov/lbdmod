// Copyright (c) 2018 Alexander Vakhitov <alexander.vakhitov@gmail.com>
// Redistribution and use is allowed according to the terms of the 2-clause BSD license.

#ifndef ORB_SLAM2_LINEEXTRACTOR_H
#define ORB_SLAM2_LINEEXTRACTOR_H

#include <opencv2/line_descriptor.hpp>

typedef cv::line_descriptor::KeyLine KeyLine;

class LineExtractor {
public:

    void ExtractLines(const cv::Mat& frame, std::vector<KeyLine>* extrLines, cv::Mat* lineDescs);

    virtual void ExtractDescriptors(const cv::Mat& frame, std::vector<KeyLine>& keyLines, cv::Mat* lineDescs) = 0;
    virtual void ExtractDetections(const cv::Mat& frame, std::vector<KeyLine>* extrLines) = 0;

    virtual ~LineExtractor(){};

};


#endif //ORB_SLAM2_LINEEXTRACTOR_H
