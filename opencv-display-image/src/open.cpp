#include "header.h"

using namespace cv;

int main(int argc, char* argv[])
{
	if(argc <= 1)
	{
		//no filepath as argument
		std::cout << "Please enter a filepath as argument" << std::endl;
		exit(NO_ARG_ERR);
	}

	//set filepath/name as variable
	char[] filePath = argv[1];

	Mat image;

	//read the file from the command line argument
	image = imread(samples::findFile(filePath), IMREAD_COLOR);

	if(image.empty())
	{
		std::cout << "Image is Empty" << std::endl;
		exit(IMG_EMTPY_ERR);
	}

	//create a window
	namedWindow("Image: " + filePath, WINDOW_AUTOSIZE);

	imshow("test", image);

	//wait for a keystroke
	waitKey(0);

	//conventional
	return 0;
}

