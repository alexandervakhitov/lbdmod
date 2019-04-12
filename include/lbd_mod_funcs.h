//
// Created by alexander on 10.04.19.
//

#ifndef LBD_MOD_LBD_MOD_FUNCS_H
#define LBD_MOD_LBD_MOD_FUNCS_H

#include "../src/precomp.hpp"

void DetectEDLines(const cv::Mat& img, int n_octaves, double factor, std::vector<cv::line_descriptor::KeyLine>* detections_p);

void DetectComputeLBD(const cv::Mat& image, int n_octaves, double factor, std::vector<cv::line_descriptor::KeyLine>* detections, cv::Mat* descs_p);

void ComputeLBD(const cv::Mat& image, int n_octaves, double factor, std::vector<cv::line_descriptor::KeyLine>& detections_p, cv::Mat* descs_p);

void MatchLBD(const cv::Mat& descs1, const cv::Mat& descs2, std::vector<cv::DMatch>* matches_p);

#endif //LBD_MOD_LBD_MOD_FUNCS_H
