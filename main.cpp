#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <string>
using namespace cv;

int main()
{
    cv::Mat img = cv::imread("D:/Camera/test.jpg");
    if (!img.data)
    {
        printf("Error loading image \n"); return -1; 
    }
    namedWindow("Input", WINDOW_AUTOSIZE); 

    std::string r = std::to_string(img.rows);
    std::string c = std::to_string(img.cols);

    cv::putText(img, r, cv::Point(3, 15), FONT_HERSHEY_DUPLEX, 0.5, Scalar(255, 255, 255), 1);
    cv::putText(img, c, cv::Point(50, 15), FONT_HERSHEY_DUPLEX, 0.5, Scalar(255, 255, 255), 1);
    cv::line(img, cv::Point(4, 20), cv::Point(50, 20), Scalar(255, 0, 0), 2, LINE_8);
    cv::rectangle(img, Point(5, 30), Point(65, 90), Scalar(0, 0, 0), FILLED);
    cv::rectangle(img, Point(5, 150), Point(65, 215), Scalar(100, 0, 100), 2);
    cv::circle(img, Point(200, 200), 30, Scalar(255, 0, 0), FILLED);
    cv::circle(img, Point(200, 50), 40, Scalar(0, 255, 0), 2);

    cv::imshow("Input", img);

    cv::Mat p1 = img(Rect(0, 0, img.rows / 2, img.rows / 2));
    cv::imshow("Output1", p1);

    cv::Mat p2 = img(Rect(0, img.cols / 2, img.rows / 2, img.rows / 2));
    cv::imshow("Output2", p2);

    cv::Mat p3 = img(Rect(img.cols / 2, 0, img.rows / 2, img.rows / 2));
    cv::imshow("Output3", p3);

    cv::Mat p4 = img(Rect(img.cols / 2, img.cols / 2, img.rows / 2, img.rows / 2));
    cv::imshow("Output4", p4);

    cv::Mat mask(img.rows, img.cols, CV_8UC1, Scalar(0));
    cv::circle(mask, Point(img.rows / 2, img.cols / 2), 100, Scalar(255, 255, 255), -1);
    Mat result;
    img.copyTo(result, mask);
    cv::imshow("Mask", result);
    

    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}