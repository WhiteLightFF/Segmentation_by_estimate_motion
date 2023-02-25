
#include "functions.h"
#include <iostream>
using namespace cv;
void InvertFunc(Mat &img)
{
	for (int y = 0; y < img.rows; ++y)
		for (int x = 0; x < img.cols; x++) {
			if (img.at<unsigned char>(y, x) == 255)
			{
				img.at<unsigned char>(y, x) = 0;
			}
			else
			{
				img.at<unsigned char>(y, x) = 255;
			}
		}
}

std::vector<int>CreateHistogram(int widthFrame, int heightFrame, Mat& image)
{
	int* histX = { new int[widthFrame] {} };
	int* histY = { new int[heightFrame]{} };
	
	//X histogram
	for (int y = 0; y < image.rows; ++y)
		for (int x = 0; x < image.cols; x++)
			if (image.at<unsigned char>(y, x) == 255)
				histX[x]++;



	//Y histogram
	for (int x = 0; x < image.cols; ++x)
		for (int y = 0; y < image.rows; y++)
			if (image.at<unsigned char>(y, x) == 255)
				histY[y]++;

	std::vector<int> coord(4);

	//Searching x1
	for (int i = 0; i < WIDTH; i++)
	{
		if (histX[i] != 0)
		{
			coord[0] = i;
			break;
		}
	}
	//Searching x2
	for (int i = WIDTH - 1; i > 0; i--)
	{
		if (histX[i] != 0)
		{
			coord[1] = i;
			break;
		}
	}
	//Searching y1
	for (int i = 0; i < HEIGHT; i++)
	{
		if (histY[i] != 0)
		{
			coord[2] = i;
			break;
		}
	}
	//Searching y2
	for (int i = HEIGHT - 1; i > 0; i--)
	{
		if (histY[i] != 0)
		{
			coord[3] = i;
			break;
		}
	}
	delete[] histX;
	delete[] histY;

	return coord;
}
