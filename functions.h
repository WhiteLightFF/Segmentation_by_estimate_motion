#pragma once
#include "opencv2/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/imgproc.hpp"
#include <vector>
using namespace cv;

#define WIDTH 1280 
#define HEIGHT 720
void InvertFunc(Mat& img);
std::vector<int>CreateHistogram(int widthFrame, int heightFrame, Mat& image);
