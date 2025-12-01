#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat img = cv::imread("C:\\Users\\piotr\\Documents\\Programowanie\\HelloOpenCV\\img\\cats.jfif");

    if (img.empty())
    {
        std::cerr << "Error while loading image." << std::endl;
        return -1;
    }

    std::string windowBeforeBlur = "Blur Example - before transformation";
    std::string windowAfterBlur = "Blur Example - after transformation";
    cv::namedWindow(windowBeforeBlur, cv::WINDOW_AUTOSIZE);
    cv::namedWindow(windowAfterBlur, cv::WINDOW_AUTOSIZE);
    cv::imshow(windowBeforeBlur, img);

    cv::Mat imgAfterBlur;
    cv::GaussianBlur(img, imgAfterBlur, cv::Size(5,5), 3, 3);
    cv::GaussianBlur(imgAfterBlur, imgAfterBlur, cv::Size(5,5), 3, 3);
    cv::imshow(windowAfterBlur, imgAfterBlur);

    cv::waitKey(0);

    return 0;
}