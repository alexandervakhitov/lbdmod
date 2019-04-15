//
// Created by alexander on 23.08.18.
//

#include "LBDFloatExtractor.h"

LBDFloatExtractor::LBDFloatExtractor(const std::string &strDetections, const std::string &strDescriptors, bool isLeft, bool isTest ) :
        StoredLineExtractor(strDetections, isLeft, isTest), strDescriptorsStorage(strDescriptors)
{}

void DecodeFloatDesc(cv::Mat* desc_float_p, const cv::Mat& desc_to_read, int col_ind)
{
//    std::cout << desc_to_read.rows << " " << desc_to_read.cols << std::endl;
    *desc_float_p = cv::Mat(1, desc_to_read.rows, CV_64FC1);

    for (int j = 0; j < desc_to_read.rows; j++)
    {
        const cv::Vec3b &val_coded = desc_to_read.at<cv::Vec3b>(j, col_ind);
        float desc_val_test = int(val_coded[0]) + (int(val_coded[1]) + int(val_coded[2]) / 256.0) / 256.0 - 128;
        desc_float_p->at<double>(0, j) = desc_val_test;
    }
//    std::cout << *desc_float_p << std::endl;
}

void ReadBinDescriptors(const std::string& descPath, cv::Mat* lineDescs)
{
    cv::Mat descs = cv::imread(descPath, CV_LOAD_IMAGE_UNCHANGED);
    cv::Mat descs_dec(descs.cols, descs.rows, CV_64FC1);
    for (int i = 0; i < descs.cols; i++)
    {
        cv::Mat desc_float;
        DecodeFloatDesc(&desc_float, descs, i);
        desc_float.copyTo(descs_dec.row(i));
    }
    *lineDescs = descs_dec.clone();
}

void LBDFloatExtractor::ExtractDescriptorsTest(std::vector<KeyLine> &extrLines, cv::Mat* lineDescs)
{
    std::string descPath = strDescriptorsStorage + std::to_string(frameId)+"_0.png";
    ReadBinDescriptors(descPath, lineDescs);
//    std::cout << " Read " << lineDescs->rows << " descs from " << descPath << std::endl;
//    ReadTXTDescriptors(extrLines, strDescriptorsStorage, lineDescs);
}

void LBDFloatExtractor::ExtractDescriptorsTrain(cv::Mat* lineDescs)
{

    std::string descPath = strDescriptorsStorage + "/" + std::to_string(batchId) + "/" + std::to_string(posInBatch)+"_f.png";
//    std::cout << descPath << std::endl;
    ReadBinDescriptors(descPath, lineDescs);
}



void LBDFloatExtractor::ExtractDescriptors(const cv::Mat& frame, std::vector<KeyLine> &extrLines, cv::Mat *lineDescs)
{
    int64 t_s = cv::getTickCount();
    if (isTest)
    {
        ExtractDescriptorsTest(extrLines, lineDescs);
    } else {
        ExtractDescriptorsTrain(lineDescs);
    }
    int64 t_e = cv::getTickCount();
//    std::cout << " descriptor load takes " << (t_e-t_s)/cv::getTickFrequency() << " sec" << std::endl;
}
