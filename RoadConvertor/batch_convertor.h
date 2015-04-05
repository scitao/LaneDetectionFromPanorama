﻿#ifndef STCV_BATCH_CONVERTOR
#define STCV_BATCH_CONVERTOR
#include <map>
#include <string>
#include <iostream>
#include "road_convertor.h"
namespace stcv {
namespace road_cvtor {
struct RoadCvtParm {
    float camera_height;
    float heading;
    float pitch;
    float pitch_back;
};

class BatchConvertor
{
public:
    BatchConvertor();
    ~BatchConvertor();

    int init(const std::map<std::string, RoadCvtParm>& parm_map, const int& pixels_per_meter,
        const int& road_width_meters, const int& road_length_meters);

    int road_cvtor(const std::string& prefix, const cv::Mat& src_img, cv::Mat* p_dst_img);

private:
    /// \brief  同一批次数据的名字，如20150104TT_1057515，前缀为20150104TT.
    std::string _prefix_name;
    int _road_width_meters;
    int _road_length_meters;
    int _pixels_per_meter;
    /// \brief  道路转换类.
    RoadConvertor _road_convertor;
    /// \brief  每批次数据对应的参数.
    std::map<std::string, RoadCvtParm> _parm_map;

    DISALLOW_COPY_AND_ASSIGN(BatchConvertor);
};
} // namespace road_cvtor
} // namespace stcv
#endif