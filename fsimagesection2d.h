#ifndef FSIMAGESECTION2D
#define FSIMAGESECTION2D

//fsImageSection2D
//Chs 110116
// Takes an image and a reference image size and splits it along x and y into a number of smaller images.Returns a vector of cv::Mats.

#include <iostream>
#include <vector>
#include "opencv2/core/core.hpp"

std::vector <cv::Mat> fsImageSection2D (cv::Mat& imIn, int outX, int outY, int nIms);


#endif // FSIMAGESECTION2D

