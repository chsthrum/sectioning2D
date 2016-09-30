#include <QCoreApplication>
#include <QString>
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

#include "fsimagesection2d.h"
#include "fsfilledrotatedrect.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int OutputImageWidth = 1024;
    int OutputImageHeight = 1024;
    int NumberOfImages = 20;

    //rotated rect parameters
    cv::Point center(500,500);
    cv::Size rectSizePixels(60,800);
    double rotDeg = 30.0;
    cv::Scalar color = cv::Scalar(100.0, 0.0, 0.0);


    //cv::Mat i = cv::imread("C:/Users/Charles/Documents/Customer_Sample_Reports/OwensCorningFrance/96m_SansDefaut_Corrigee.jpg",0);
    //cv::Mat i = cv::imread("F:/Hofer_CoatingDefect_la.bmp");
   //cv::Mat i = cv::imread("C:/Users/Charles/Documents/Customer_Sample_Reports/Hofer/IMG_0449.JPG",0);
   //cv::Mat i = cv::imread("C:/Users/Charles/Documents/Formax/Hexcel_Fabric_Stemmer_2016_24b.bmp",0);
    //cv::Mat i = cv::imread("F:/Seneclause/Seneclause3_4000w_8192h_lowcontrast.bmp",0);
    //cv::Mat i = cv::imread("C:/Users/Charles/Desktop/Seneclause/Seneclause/SeneclauseSample3_missingThread_easy_MIT300DPI_Front_lit.bmp",0);
    cv::Mat i = cv::imread("C:/Users/Charles/Desktop/Seneclause/Seneclause/SeneclauseSample2_missingThread_more_difficult_MIT300DPI_Front_lit.bmp",0);

    if (!i.data)
    {
        std::cout << "no image data" << std::endl;
        return 0;
    }

    std::vector<cv::Mat> sectionedImageVec = fsImageSection2D(i,OutputImageWidth,OutputImageHeight,NumberOfImages);
    assert (sectionedImageVec[0].data != NULL);


    for(std::vector<cv::Mat>::size_type i = 0; i != sectionedImageVec.size(); ++i)
    {

        //QString imSecFileName = "NOTOwensCorningSectionedImages/bad_OwensCorning_" + QString::number(i+1)+ ".png";
        //QString imSecFileName = "Hofer/Hofer_Stitch_" + QString::number(i+1)+ ".png";
        //QString imSecFileName = "Formax/formax_1024_sample_" + QString::number(i+1)+ ".png";
        //QString imSecFileName = "Seneclauze/Seneclauze_1024_sample_" + QString::number(i+1)+ ".png";
        QString imSecFileName = "Seneclauze/Seneclauze_1024_sample_more_diff_front_lit" + QString::number(i+1)+ ".png";

        //drawRectangle(sectionedImageVec[i],center, rectSizePixels, rotDeg, color);// comment out for GOOD images

        imwrite(imSecFileName.toStdString(), sectionedImageVec[i]);

//        try {
//            imwrite(imSecFileName.toStdString(), sectionedImageVec[i]);
//        }
//        catch (runtime_error& ex) {
//            fprintf(stderr, "Exception converting image to PNG format: %s\n", ex.what());
//            return 1;
//        }

            fprintf(stdout, "Saved PNG file - Number . %d\n",i);
    }

//    cv::Point center(1000,1000);
//    cv::Size rectSizePixels(100,500);
//    double rotDeg = 30.0;
//    cv::Scalar color = cv::Scalar(100.0, 0.0, 0.0);


//    drawRectangle(sectionedImageVec[2],center, rectSizePixels, rotDeg, color);

//    cv::namedWindow( "Display window", CV_WINDOW_AUTOSIZE );// Create a window for display.
//    cv::imshow( "Display window", sectionedImageVec[2] );                   // Show our image inside it.
//    cv::waitKey(0);

    return 0;







    return a.exec();
}
