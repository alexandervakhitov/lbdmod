//
// Created by alexander on 24.08.18.
//

#ifndef ORB_SLAM2_EMPTYEXTRACTOR_H
#define ORB_SLAM2_EMPTYEXTRACTOR_H


#include <opencv2/core/mat.hpp>
#include "StoredLineExtractor.h"

class EmptyExtractor : public LineExtractor
{
public:
    EmptyExtractor();
    void ExtractLines(const cv::Mat& frame, std::vector<KeyLine>* extrLines, cv::Mat* lineDescs);
    void ExtractDescriptors(const cv::Mat& frame, std::vector<KeyLine>& keyLines, cv::Mat* lineDescs) override;
    void ExtractDetections(const cv::Mat& frame, std::vector<KeyLine>* extrLines) override;
};


#endif //ORB_SLAM2_EMPTYEXTRACTOR_H
