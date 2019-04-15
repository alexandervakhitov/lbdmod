#include <iostream>
#include "src/precomp.hpp"
#include "lbd_mod_funcs.h"

int main()
{
    bool is_simultaneous = false;
    std::cout << "Hello, World!" << std::endl;

    cv::Mat image;
    image = cv::imread("/home/alexander/materials/sego/kitti_odometry/dataset/sequences/00/image_0/000000.png", 0);
    cv::Mat image2 = cv::imread("/home/alexander/materials/sego/kitti_odometry/dataset/sequences/00/image_0/000001.png", 0);
    cv::line_descriptor::BinaryDescriptor::Params p;
    int n_octaves = 8;
    p.numOfOctave_ = n_octaves;
//    p.reductionRatio = 2;
    p.widthOfBand_ = 7;
    p.ksize_ = 5;
    p.factor = 1.2;

    std::cout << " params created " << std::endl;
    cv::Ptr<cv::line_descriptor::BinaryDescriptor> bd = cv::line_descriptor::BinaryDescriptor::createBinaryDescriptor(p);
//        bd->setNumOfOctaves(n_octaves);
//    cv::Mat mask = cv::Mat::ones(image.size(), CV_8UC1);
    cv::Mat mask;
    long long t0 = cv::getTickCount();
    std::cout << " detect start " << std::endl;
//        bd->detect(image, *lines_p, mask);
//        InputArray image, InputArray mask, CV_OUT std::vector<KeyLine>& keylines, OutputArray descriptors,
//                bool useProvidedKeyLines, bool returnFloatDescr
    cv::Mat descs;
    std::vector<cv::line_descriptor::KeyLine> lines;
    if (is_simultaneous)
    {
        (*bd)(image, cv::Mat(), lines, descs, false, false);
    } else {

//        DetectComputeLBD(image, n_octaves, 1.2, &lines, &descs);

        DetectEDLines(image, n_octaves, 1.2, &lines);
        ComputeLBD(image, n_octaves, 1.2, lines, &descs);
    }


    long long t1 = cv::getTickCount();
    double dt = (t1 - t0) / cv::getTickFrequency();

    cv::Mat debugDetector, imageColor;
    cv::cvtColor(image, imageColor, CV_GRAY2BGR);
    cv::line_descriptor::drawKeylines(imageColor, lines, debugDetector);
    cv::imshow("detect 1", debugDetector);

//        bd->compute(image, *lines_p, descs);
    std::cout << " full done " << dt << std::endl;

//    t0 = cv::getTickCount();
//    bd->detect(image, lines, mask);
//    t1 = cv::getTickCount();
//    dt = (t1 - t0) / cv::getTickFrequency();
//    std::cout << " detect done " << dt << std::endl;
//    t0 = cv::getTickCount();
//    //bd->compute(image, lines, descs, false);
//    (*bd)(image, mask, lines, descs, false, false);
//    t1 = cv::getTickCount();
//    dt = (t1 - t0) / cv::getTickFrequency();
//
//
//    std::cout << " compute bin done " << dt << std::endl;
//    std::cout << descs.cols << " " << descs.rows << " " << descs.type() << " " << CV_8UC1 << std::endl;
//    t0 = cv::getTickCount();
//    bd->compute(image, lines, descs, true);
//    t1 = cv::getTickCount();
//    dt = (t1 - t0) / cv::getTickFrequency();
//    std::cout << " compute float done " << dt << std::endl;
//    std::cout << descs.cols << " " << descs.rows << " " << descs.type() << " " << CV_32FC1 << std::endl;
//    std::vector<cv::line_descriptor::KeyLine> lines2;
//    bd->detect(image2, lines2, mask);
//
//    lines2.clear();
//    lines2.push_back(lines[0]);
//    //bd->compute(image, lines2, descs, false);
//    (*bd)(image, mask, lines, descs, false, false);
//    std::cout << " compute float 2 done " << dt << std::endl;
//
    cv::Mat descs2;
    std::vector<cv::line_descriptor::KeyLine> lines2;
    if (is_simultaneous) {
        (*bd)(image2, cv::Mat(), lines2, descs2, false, false);
    } else {
//        DetectComputeLBD(image2, n_octaves, 1.2, &lines2, &descs2);
        DetectEDLines(image, n_octaves, 1.2, &lines2);
        ComputeLBD(image, n_octaves, 1.2, lines2, &descs2);
    }

    cv::Mat debugDetector2, imageColor2;
    cv::cvtColor(image2, imageColor2, CV_GRAY2BGR);
    cv::line_descriptor::drawKeylines(imageColor2, lines2, debugDetector2);
    cv::imshow("detect 2", debugDetector2);


    cv::line_descriptor::BinaryDescriptorMatcher matcher;
    std::vector<cv::DMatch> matches;
    matcher.match(descs2, descs, matches);
    cv::Mat debugMatchingImg;
    bool is_vertical = true;
    cv::line_descriptor::drawLineMatches(imageColor2, lines2, imageColor, lines, matches, debugMatchingImg, true);
    cv::imshow("Matching", debugMatchingImg);


    cv::waitKey();

    return 0;
}