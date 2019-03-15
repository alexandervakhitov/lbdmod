// Copyright (c) 2018 Alexander Vakhitov <alexander.vakhitov@gmail.com>
// Redistribution and use is allowed according to the terms of the 2-clause BSD license.

#ifndef ORB_SLAM2_STOREDLINEEXTRACTOR_H
#define ORB_SLAM2_STOREDLINEEXTRACTOR_H


#include "LineExtractor.h"

class StoredLineExtractor : public LineExtractor
{
public:
    StoredLineExtractor(const std::string& strDetectionsStorage, bool isLeft, bool isTest = false);

    void SetFrameId(int id);
    void ExtractDetections(const cv::Mat& frame, std::vector<KeyLine>* extrLines) override;

    void ReadTXTDescriptors(std::vector<KeyLine> &extrLines, const std::string& strDescriptorsStorage, cv::Mat *lineDescs);

protected:
    int posInBatch;
    int batchId;
    std::string strDetectionsStorage;
    bool isLeft;
    int frameId;
    cv::Mat linesMat;
    bool isTest;

    void LoadDetectionsTrainDataset(int frameId);
    void LoadDetectionsTestDataset(int frameId);
};


#endif //ORB_SLAM2_STOREDLINEEXTRACTOR_H
