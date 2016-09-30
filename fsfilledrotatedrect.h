#ifndef FSFILLEDROTATEDRECT
#define FSFILLEDROTATEDRECT

#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"



// default color is white
 void drawRotatedRect(cv::Mat& image, cv::RotatedRect rRect, cv::Scalar color );


// default color is white
 void drawRectangle(cv::Mat& image, cv::Point center, cv::Size rectSizePixels, double rotDeg, cv::Scalar color  );
#endif // FSFILLEDROTATEDRECT

