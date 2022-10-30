#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

int main()
{
    const auto baseImg = cv::imread("C:\\Users\\piotr\\Documents\\Programowanie\\Morphology\\img\\cats.jfif");

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
    const auto kernel = cv::Mat(); // After using this initialized cv::Mat() kernel, functions erode and dilate use default 3x3 kernel

    const auto erodeImage = "After erode";
    cv::erode(greyImg, outImg, kernel);
    cv::namedWindow(erodeImage, cv::WINDOW_AUTOSIZE);
    cv::imshow(erodeImage, outImg);

    const auto dilateImage = "After dilate";
    cv::dilate(greyImg, outImg, kernel);
    cv::namedWindow(dilateImage, cv::WINDOW_AUTOSIZE);
    cv::imshow(dilateImage, outImg);

    const auto openImage = "After open";
    auto operation = cv::MORPH_OPEN;
    cv::morphologyEx(greyImg, outImg, operation, kernel); //default, multipurpose morphological transformation function
    cv::namedWindow(openImage, cv::WINDOW_AUTOSIZE);
    cv::imshow(openImage, outImg);

    const auto closeImage = "After close";
    operation = cv::MORPH_CLOSE;
    cv::morphologyEx(greyImg, outImg, operation, kernel); //default, multipurpose morphological transformation function
    cv::namedWindow(closeImage, cv::WINDOW_AUTOSIZE);
    cv::imshow(closeImage, outImg);

    const auto gradientImage = "After morphological gradient";
    operation = cv::MORPH_GRADIENT;
    cv::morphologyEx(greyImg, outImg, operation, kernel); //default, multipurpose morphological transformation function
    cv::namedWindow(gradientImage, cv::WINDOW_AUTOSIZE);
    cv::imshow(gradientImage, outImg);

    const auto tophatImage = "After Top Hat";
    operation = cv::MORPH_TOPHAT;
    cv::morphologyEx(greyImg, outImg, operation, kernel); //default, multipurpose morphological transformation function
    cv::namedWindow(tophatImage, cv::WINDOW_AUTOSIZE);
    cv::imshow(tophatImage, outImg);

    const auto blackhatImage = "After Black Hat";
    operation = cv::MORPH_BLACKHAT;
    cv::morphologyEx(greyImg, outImg, operation, kernel); //default, multipurpose morphological transformation function
    cv::namedWindow(blackhatImage, cv::WINDOW_AUTOSIZE);
    cv::imshow(blackhatImage, outImg);

    cv::waitKey(0);

    return 0;
}