//
// Created by alexander on 24.08.18.
//

#include "EmptyExtractor.h"

EmptyExtractor::EmptyExtractor()
{

}

void EmptyExtractor::ExtractDescriptors(const cv::Mat& frame, std::vector<KeyLine> &keyLines, cv::Mat *lineDescs) {

}

void EmptyExtractor::ExtractDetections(const cv::Mat& frame, std::vector<KeyLine> *extrLines) {

}

void EmptyExtractor::ExtractLines(const cv::Mat& frame, std::vector<KeyLine>* extrLines, cv::Mat* lineDescs)
{

}