//global includes
#include <iostream>
#include <string>

//opencv includes
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

//defining different error codes
#ifndef NO_ARG_ERR
#define NO_ARG_ERR 2
#endif //NO_ARG_ERR

#ifndef IMG_EMPTY_ERR
#define IMG_EMPTY_ERR 3
#endif //IMG_EMPTY_ERR

#ifndef FILE_SAVE_ERR
#define FILE_SAVE_ERR 4
#endif //FILE_SAVE_ERR

#ifndef DRAW_RAND_ERR
#define DRAW_RAND_ERR 5
#endif //DRAW_RAND_ERR

//functions
void draw_random_lines(cv::Mat image);
static cv::Scalar randomColor(cv::RNG& rng);

