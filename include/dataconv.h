//
// Created by alexander on 11.04.19.
//

#ifndef PYLBD_DATACONV_H
#define PYLBD_DATACONV_H

#include <opencv2/line_descriptor.hpp>

cv::Mat ConvertKeyLines2Mat(const std::vector<cv::line_descriptor::KeyLine>& detections);
std::vector<cv::line_descriptor::KeyLine> ConvertMat2KeyLines(const cv::Mat& lines_data);
cv::Mat ConvertMatches2Mat(const std::vector<cv::DMatch>& matchingVec);
std::vector<cv::DMatch> ConvertMat2Matches(const cv::Mat& matchMat);

#endif //PYLBD_DATACONV_H
