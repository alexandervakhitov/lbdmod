/**
* This file is part of LLD-SLAM.
*
* Copyright (C) 2018 Alexander Vakhitov <alexander.vakhitov at gmail dot com> (Skoltech)
* For more information see <https://github.com/alexandervakhitov/lld-slam>
*
* lld-slam is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* lld-slam is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with LLD-SLAM. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef PYLBD_DATACONV_H
#define PYLBD_DATACONV_H

#include <opencv2/line_descriptor.hpp>

cv::Mat ConvertKeyLines2Mat(const std::vector<cv::line_descriptor::KeyLine>& detections);
std::vector<cv::line_descriptor::KeyLine> ConvertMat2KeyLines(const cv::Mat& lines_data);
cv::Mat ConvertMatches2Mat(const std::vector<cv::DMatch>& matchingVec);
std::vector<cv::DMatch> ConvertMat2Matches(const cv::Mat& matchMat);

#endif //PYLBD_DATACONV_H
