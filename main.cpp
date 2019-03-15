#include <iostream>
#include "src/precomp.hpp"

int main()
{
    std::cout << "Hello, World!" << std::endl;

    cv::Mat image = cv::imread("000000.png", 0);
    cv::Mat image2 = cv::imread("000001.png", 0);
    cv::line_descriptor::BinaryDescriptor::Params p;
    p.numOfOctave_ = 8;
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
    (*bd)(image, cv::Mat(), lines, descs, false, true);
    long long t1 = cv::getTickCount();
    double dt = (t1 - t0) / cv::getTickFrequency();

//        bd->compute(image, *lines_p, descs);
    std::cout << " full done " << dt << std::endl;

    t0 = cv::getTickCount();
    bd->detect(image, lines, mask);
    t1 = cv::getTickCount();
    dt = (t1 - t0) / cv::getTickFrequency();
    std::cout << " detect done " << dt << std::endl;
    t0 = cv::getTickCount();
    //bd->compute(image, lines, descs, false);
    (*bd)(image, mask, lines, descs, false, false);
    t1 = cv::getTickCount();
    dt = (t1 - t0) / cv::getTickFrequency();
    std::cout << " compute bin done " << dt << std::endl;
    std::cout << descs.cols << " " << descs.rows << " " << descs.type() << " " << CV_8UC1 << std::endl;
    t0 = cv::getTickCount();
    bd->compute(image, lines, descs, true);
    t1 = cv::getTickCount();
    dt = (t1 - t0) / cv::getTickFrequency();
    std::cout << " compute float done " << dt << std::endl;
    std::cout << descs.cols << " " << descs.rows << " " << descs.type() << " " << CV_32FC1 << std::endl;
    std::vector<cv::line_descriptor::KeyLine> lines2;
    bd->detect(image2, lines2, mask);

    lines2.clear();
    lines2.push_back(lines[0]);
    //bd->compute(image, lines2, descs, false);
    (*bd)(image, mask, lines, descs, false, false);
    std::cout << " compute float 2 done " << dt << std::endl;
    return 0;
}