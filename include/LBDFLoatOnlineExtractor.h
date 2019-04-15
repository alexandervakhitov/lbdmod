//
// Created by alexander on 04.09.18.
//

#ifndef LINEDESCDATACOLLECTOR_LBDFLOATONLINEEXTRACTOR_H
#define LINEDESCDATACOLLECTOR_LBDFLOATONLINEEXTRACTOR_H


#include "LineExtractor.h"

class LBDFLoatOnlineExtractor : public LineExtractor {
public:
    LBDFLoatOnlineExtractor();
    void ExtractDescriptors(const cv::Mat& frame, std::vector<KeyLine>& keyLines, cv::Mat* lineDescs) override;
    void ExtractDetections(const cv::Mat& frame, std::vector<KeyLine>* extrLines) override;

    int n_octaves = 4;
    double pyramid_factor = 1.2*1.2;
    cv::line_descriptor::BinaryDescriptor bd;
};


#endif //LINEDESCDATACOLLECTOR_LBDFLOATONLINEEXTRACTOR_H
