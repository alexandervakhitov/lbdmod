// Copyright (c) 2018 Alexander Vakhitov <alexander.vakhitov@gmail.com>
// Redistribution and use is allowed according to the terms of the 2-clause BSD license.

#include "LBDFLoatOnlineExtractor.h"

LBDFLoatOnlineExtractor::LBDFLoatOnlineExtractor()
{
    cv::line_descriptor::BinaryDescriptor::Params p;
    p.numOfOctave_ = n_octaves;
//        p.reductionRatio = 2;
    p.widthOfBand_ = 7;
    p.ksize_ = 5;
    p.factor = pyramid_factor;

    bd = cv::line_descriptor::BinaryDescriptor(p);
}

void LBDFLoatOnlineExtractor::ExtractDetections(const cv::Mat& frame, std::vector<KeyLine> *extrLines)
{

//        bd->setNumOfOctaves(n_octaves);

//    long long t0 = cv::getTickCount();
//    std::cout << " detect start " << std::endl;

//        cv::imshow("d", image);
//        cv::waitKey(0);
    cv::line_descriptor::BinaryDescriptor::Params p;
    p.numOfOctave_ = n_octaves;
//        p.reductionRatio = 2;
    p.widthOfBand_ = 7;
    p.ksize_ = 5;
    p.factor = pyramid_factor;

    bd = cv::line_descriptor::BinaryDescriptor(p);
    std::vector<KeyLine> lines;
    bd.detect(frame, lines, cv::Mat());
    *extrLines = lines;
}

void LBDFLoatOnlineExtractor::ExtractDescriptors(const cv::Mat &frame, std::vector<KeyLine> &keyLines,
                                                 cv::Mat *lineDescs)
{
    cv::Mat descs_loc;
    bd.compute(frame, keyLines, descs_loc, true);
    descs_loc.copyTo(*lineDescs);
}