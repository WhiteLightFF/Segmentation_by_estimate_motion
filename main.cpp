#include "opencv2/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
#include < vector>
#include "functions.h"

using namespace cv;

int main()
{
	Mat img1 = imread("../res/100.jpg", 0);//BitDepth = 8
	Mat img2 = imread("../res/101.jpg", 0);//BitDepth = 8
	Mat sobel, canny, ifd, combinedCanny;
	absdiff(img2, img1, ifd);
	imshow("img1", img1);
	imshow("img2", img2);
	imshow("ifd", ifd);

	Canny(img2, canny, 50, 200);// image, MatObject,lower border, upper border
	bitwise_and(ifd, canny, combinedCanny);
	imshow("AND", combinedCanny);
	threshold(combinedCanny, combinedCanny, 5, 255, THRESH_BINARY_INV);
	Mat element = cv::getStructuringElement(MORPH_RECT, Size(16, 16), Point(3, 3));
	morphologyEx(combinedCanny, combinedCanny, MORPH_ERODE, element);
	imshow("Erode", combinedCanny);

	InvertFunc(combinedCanny);//Invert by brightness

	imshow("InvertErode", combinedCanny);
	Mat image_floodFill = combinedCanny.clone();
	cv::floodFill(image_floodFill, Point(0, 0), Scalar(255));
	imshow("FillBackGround", image_floodFill);
	Mat image_floodFill_inv;

	bitwise_not(image_floodFill, image_floodFill_inv);
	imshow("FillBackGround_Inverted", image_floodFill_inv);
	Mat out = (combinedCanny | image_floodFill_inv);
	imshow("OUT", out);
	
	std::vector<int> coord(4);// vector of histogram extreme points
	coord = CreateHistogram((int)WIDTH, (int)HEIGHT, out);//get extreme points
	//Rectangle drawing by extreme points of histograms
	cv::rectangle(out, Point(coord[0], coord[2]), Point(coord[1], coord[3]), Scalar(255), 2, 8, 0);
	imshow("Rectangle", out);// Object is found
	waitKey(0);
	return 0;
}





