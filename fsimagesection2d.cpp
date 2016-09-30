#include "fsimagesection2d.h"
#include <QtMath>


std::vector<cv::Mat> fsImageSection2D(cv::Mat &imIn, int outX, int outY, int nIms)
{
        std::vector<cv::Mat> imVec; //for collecting the subimages
        int nImsInX = qFloor(nIms/2);
        int nImsInY = qFloor(nIms/2);

        int imOffsetX = qFloor((imIn.cols - outX)/nImsInX); // Offset = the distance the images are separated with respect to each other.
        int jumpX = 0; //  this will be the offset in X

        int imOffsetY = qFloor((imIn.rows - outY)/nImsInY); // Offset = the distance the images are separated with respect to each other.
        int jumpY = 0; //  this will be the offset in Y

        for (int i = 0; i != nImsInY; ++i)
        {
            for (int j = 0; j != nImsInX; ++j)
            {
                // get the sub image
                cv::Rect roi = cv::Rect(jumpX, jumpY, outX, outY);
                cv::Mat section = imIn(roi);
                imVec.push_back(section);
                jumpX += imOffsetX;   //jump down the image by the offset
            }
            jumpX = 0;
            jumpY += imOffsetY;
        }
        jumpY = 0;
        return imVec;


}
