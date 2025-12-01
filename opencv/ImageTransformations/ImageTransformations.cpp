#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

int main()
{
    const auto baseImg = cv::imread("C:\\Users\\piotr\\Documents\\Programowanie\\ImageTransformations\\img\\cats.jfif");

    if (baseImg.empty())
    {
        std::cerr << "Error while loading image." << std::endl;
        return -1;
    }

    const auto image = "Original Image";
    cv::namedWindow(image, cv::WINDOW_AUTOSIZE);
    cv::imshow(image, baseImg);

    cv::Mat outImg;

    const auto resizedImage = "After resize (smaller image)";
    const auto newSize = cv::Size(200, 200);
    cv::resize(baseImg, outImg, newSize); // make image smaller
    cv::namedWindow(resizedImage, cv::WINDOW_AUTOSIZE);
    cv::imshow(resizedImage, outImg);

    const auto affineTransformation = "Przeksztalcanie afiniczne";
    cv::Point2f srcImageCoordinates[] =
    {
        cv::Point2f(0, 0),
        cv::Point2f(baseImg.cols-1, 0),
        cv::Point2f(0, baseImg.rows-1)
    };

    cv::Point2f dstImageCoordinates[] =
    {
        cv::Point2f(baseImg.cols*0.f, baseImg.rows*0.33f),
        cv::Point2f(baseImg.cols*0.85f, baseImg.rows*0.25f),
        cv::Point2f(baseImg.cols*0.15f, baseImg.rows*0.7f),
    };

    const auto imgSize = baseImg.size();
    cv::Mat affineTransformMatrix = cv::getAffineTransform(srcImageCoordinates, dstImageCoordinates);
    cv::warpAffine(baseImg, outImg, affineTransformMatrix, imgSize);
    cv::imshow(affineTransformation, outImg);

    const auto perspectiveTransformation = "Przeksztalcanie perspektywiczne";
    cv::Point2f srcImageCoordinates2[] =
    {
        cv::Point2f(0, 0),
        cv::Point2f(baseImg.cols-1, 0),
        cv::Point2f(baseImg.cols-1, baseImg.rows-1),
        cv::Point2f(0, baseImg.rows-1)
    };

    cv::Point2f dstImageCoordinates2[] =
    {
        cv::Point2f(baseImg.cols*0.05f, baseImg.rows*0.33f),
        cv::Point2f(baseImg.cols*0.9f, baseImg.rows*0.25f),
        cv::Point2f(baseImg.cols*0.8f, baseImg.rows*0.9f),
        cv::Point2f(baseImg.cols*0.2f, baseImg.rows*0.7f)
    };

    cv::Mat perspectiveTransformMatrix = cv::getPerspectiveTransform(srcImageCoordinates2, dstImageCoordinates2);
    cv::warpPerspective(baseImg, outImg, perspectiveTransformMatrix, imgSize);
    cv::imshow(perspectiveTransformation, outImg);

    cv::waitKey(0);

    return 0;
}