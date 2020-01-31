#include "header.h"

//using namespace cv;

int main(int argc, char* argv[])
{
	//new, empty image
	//window_width, window_height, created matrix type
	cv::Mat image = cv::Mat::zeros(500, 500, CV_8UC3);
	cv::RNG rand = (0xFFFFFFFF);

	std::string windowTitle = "Random Image";
	std::string fileName = "./image.png";
	
	//generate random lines and stuff

	Draw_random_lines(image, &windowTitle, rand);

	//draw_random_rectangles(image, windowTitle, rand);

	//draw_random_ellipses(image, windowTitle, rand);

	cv::imshow(windowTitle, image);

	//exception hanlding for saving the image
	bool result = false;
	try
	{
		//save image
		result = cv::imwrite(fileName, image);
	}
	catch (const cv::Exception& ex)
	{
		std::cout << "Exception happened: " << ex.what() << std::endl;
	}

	//determine, if the file could be saved or not with return value
	if(result)
	{
		std::cout << "Successfully saved file: " << fileName << std::endl;
	}
	else
	{
		std::cout << "Could not save file: " << fileName << std::endl;
		exit(FILE_SAVE_ERR);
	}

	//wait for a keystroke
	cv::waitKey(0);

	//conventional
	return 0;
}

