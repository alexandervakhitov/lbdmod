//
// Created by alexander on 10.04.19.
//

#include "lbd_mod_funcs.h"

void DetectEDLines(const cv::Mat& image, int n_octaves, double factor, std::vector<cv::line_descriptor::KeyLine>* detections_p)
{
    cv::line_descriptor::BinaryDescriptor::Params p;
    p.numOfOctave_ = n_octaves;
    p.widthOfBand_ = 7;
    p.ksize_ = 5;
    p.factor = factor;
    cv::Ptr<cv::line_descriptor::BinaryDescriptor> bd = cv::line_descriptor::BinaryDescriptor::createBinaryDescriptor(p);

    bd->detect(image, *detections_p, cv::Mat());
}

void DetectComputeLBD(const cv::Mat& image, int n_octaves, double factor, std::vector<cv::line_descriptor::KeyLine>* detections_p, cv::Mat* descs_p)
{
    cv::line_descriptor::BinaryDescriptor::Params p;
    p.numOfOctave_ = n_octaves;
    p.widthOfBand_ = 7;
    p.ksize_ = 5;
    p.factor = factor;
    cv::Ptr<cv::line_descriptor::BinaryDescriptor> bd = cv::line_descriptor::BinaryDescriptor::createBinaryDescriptor(p);
//    std::cout << "got " << detections.size() << " detections " << std::endl;
//    std::cout << " zero det: " << detections[0].startPointX << " " << detections[0].startPointY << " " << detections[0].endPointX << " " << detections[0].endPointY << std::endl;
//    std::cout << " zero det size: " << detections[0].size << std::endl;
//    int n = detections.size()-1;
//    std::cout << " n det: " << detections[n].startPointX << " " << detections[n].startPointY << " " << detections[n].endPointX << " " << detections[n].endPointY << std::endl;
//    std::cout << " n det size: " << detections[n].size << std::endl;
    (*bd)(image, cv::Mat(), *detections_p, *descs_p, false, false);
}

void ComputeLBD(const cv::Mat& image, int n_octaves, double factor, std::vector<cv::line_descriptor::KeyLine>& detections_p, cv::Mat* descs_p)
{
    cv::line_descriptor::BinaryDescriptor::Params p;
    p.numOfOctave_ = n_octaves;
    p.widthOfBand_ = 7;
    p.ksize_ = 5;
    p.factor = factor;
    cv::Ptr<cv::line_descriptor::BinaryDescriptor> bd = cv::line_descriptor::BinaryDescriptor::createBinaryDescriptor(p);
//    std::cout << "got " << detections.size() << " detections " << std::endl;
//    std::cout << " zero det: " << detections[0].startPointX << " " << detections[0].startPointY << " " << detections[0].endPointX << " " << detections[0].endPointY << std::endl;
//    std::cout << " zero det size: " << detections[0].size << std::endl;
//    int n = detections.size()-1;
//    std::cout << " n det: " << detections[n].startPointX << " " << detections[n].startPointY << " " << detections[n].endPointX << " " << detections[n].endPointY << std::endl;
//    std::cout << " n det size: " << detections[n].size << std::endl;
    bd->compute(image, detections_p, *descs_p, false);
}


void MatchLBD(const cv::Mat& descs1, const cv::Mat& descs2, std::vector<cv::DMatch>* matches_p)
{
    cv::line_descriptor::BinaryDescriptorMatcher matcher;
    matcher.match(descs1, descs2, *matches_p);
}