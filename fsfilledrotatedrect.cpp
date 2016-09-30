#include "fsfilledrotatedrect.h"


// default color is white
void drawRotatedRect(cv::Mat& image, cv::RotatedRect rRect, cv::Scalar color)
{

  cv::Point2f vertices2f[4];
  cv::Point vertices[4];
  rRect.points(vertices2f);
  for(int i = 0; i < 4; ++i){
    vertices[i] = vertices2f[i];
  }
  cv::fillConvexPoly(image,
                     vertices,
                     4,
                     color);
}


// default color is white
void drawRectangle(cv::Mat& image, cv::Point center, cv::Size rectSizePixels, double rotDeg, cv::Scalar color )
{

  cv::RotatedRect rRect(center, rectSizePixels, rotDeg); // opencv expects degrees
  drawRotatedRect(image,rRect,color);

}
