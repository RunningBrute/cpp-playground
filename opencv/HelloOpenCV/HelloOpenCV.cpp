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

    std::string windowName = "Hello OpenCV!";
    cv::namedWindow(windowName, cv::WINDOW_AUTOSIZE);
    cv::imshow(windowName, img);
    cv::waitKey(0);
    cv::destroyWindow(windowName);

    return 0;
}