#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat baseImg = cv::imread("C:\\Users\\piotr\\Documents\\Programowanie\\Smoothing\\img\\cats.jfif");

    if (baseImg.empty())
    {
        std::cerr << "Error while loading image." << std::endl;
        return -1;
    }

    const std::string image = "Original Image";
    cv::namedWindow(image, cv::WINDOW_AUTOSIZE);
    cv::imshow(image, baseImg);

    cv::Mat outImg;
    cv::Size kernelSize = cv::Size(5, 5);

    const std::string blurImage = "After simple blur";
    cv::blur(baseImg, outImg, kernelSize);
    cv::namedWindow(blurImage, cv::WINDOW_AUTOSIZE);
    cv::imshow(blurImage, outImg);

    const std::string boxFilterImage = "After box filter";
    const auto depth = CV_8U;
    cv::boxFilter(baseImg, outImg, depth, kernelSize);
    cv::namedWindow(boxFilterImage, cv::WINDOW_AUTOSIZE);
    cv::imshow(boxFilterImage, outImg);

    const std::string medianFilterImage = "After median filter";
    const int medianBlurKernelSize = 5;
    cv::medianBlur(baseImg, outImg, medianBlurKernelSize);
    cv::namedWindow(medianFilterImage, cv::WINDOW_AUTOSIZE);
    cv::imshow(medianFilterImage, outImg);

    const std::string gaussianFilterImage = "After gaussian filter";
    const auto sigmaX = 0.9;
    const auto sigmaY = 0.3;
    cv::GaussianBlur(baseImg, outImg, kernelSize, sigmaX, sigmaY);
    cv::namedWindow(gaussianFilterImage, cv::WINDOW_AUTOSIZE);
    cv::imshow(gaussianFilterImage, outImg);

    const std::string bilateralFilterImage = "After bilateral filter";
    const auto maxDistance = 7;
    const auto sigmaColor = -1.0;
    const auto sigmaSpace = 120.8;
    cv::bilateralFilter(baseImg, outImg, maxDistance, sigmaColor, sigmaSpace);
    cv::namedWindow(bilateralFilterImage, cv::WINDOW_AUTOSIZE);
    cv::imshow(bilateralFilterImage, outImg);

    cv::waitKey(0);

    return 0;
}