#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

int main()
{
    const auto baseImg = cv::imread("C:\\Users\\piotr\\Documents\\Programowanie\\Derivatives\\img\\cats.jfif");

    if (baseImg.empty())
    {
        std::cerr << "Error while loading image." << std::endl;
        return -1;
    }

    const auto image = "Original Image";
    cv::namedWindow(image, cv::WINDOW_AUTOSIZE);
    cv::imshow(image, baseImg);

    const auto grayImage = "Image in grayscale";
    cv::Mat greyImg;
    cv::cvtColor(baseImg, greyImg, cv::COLOR_BGR2GRAY);
    cv::namedWindow(grayImage, cv::WINDOW_AUTOSIZE);
    cv::imshow(grayImage, greyImg);

    cv::Mat outImg;
    const auto kernelSize = 3;

    const auto sobelImage = "After Sobel derivative for x";
    const auto depth = CV_16S;
    auto dx = 1;
    auto dy = 0;
    cv::Sobel(greyImg, outImg, depth, dx, dy, kernelSize);
    cv::namedWindow(sobelImage, cv::WINDOW_AUTOSIZE);
    cv::imshow(sobelImage, outImg);

    const auto sobel2Image = "After Sobel derivative for y";
    dx = 0;
    dy = 1;
    cv::Sobel(greyImg, outImg, depth, dx, dy, kernelSize);
    cv::namedWindow(sobel2Image, cv::WINDOW_AUTOSIZE);
    cv::imshow(sobel2Image, outImg);

    const auto laplacianImage = "After laplacjan";
    cv::Laplacian(greyImg, outImg, depth, kernelSize);
    cv::namedWindow(laplacianImage, cv::WINDOW_AUTOSIZE);
    cv::imshow(laplacianImage, outImg);

    cv::waitKey(0);

    return 0;
}