#include "header.h"

//using namespace cv;

int main(int argc, char* argv[])
{
	if(argc <= 1)
	{
		//no filepath as argument
		std::cout << "Please enter a filepath as argument" << std::endl;
		exit(NO_ARG_ERR);
	}

	//set filepath/name as variable
	std::string filePath = argv[1];

	cv::Mat image;

	//read the file from the command line argument
	image = cv::imread(cv::samples::findFile(filePath), cv::IMREAD_COLOR);

	if(image.empty())
	{
		//image is empty, or may be another filetype
		std::cout << "Image is Empty" << std::endl;
		exit(IMG_EMPTY_ERR);
	}

	//create a window
	std::string windowTitle = "Image: " + filePath;

	//creating a window, that auto sizes
	cv::namedWindow(windowTitle, cv::WINDOW_AUTOSIZE);

	cv::imshow(windowTitle, image);

	//wait for a keystroke
	cv::waitKey(0);

	//conventional
	return 0;
}

