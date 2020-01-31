#include "header.h"

void Draw_random_lines(cv::Mat* image, char* window_name, cv::RNG rand)
{
	int lineType = 8;
	cv::Point pt1, pt2;

	//10 random lines will get drawn onto image
	for(int i=0; i<10; i++)
	{
		pt1.x = rng.uniform(x_1, x_2);
		pt1.y = rng.uniform(y_1, y_2);
		pt2.x = rng.uniform(x_1, x_2);
		pt2.y = rng.uniform(y_1, y_2);

		line(image, pt1, pt2, cv::randomColor(rng), rng.uniform(1.10), 8);
	}


}

/*int draw_random_rectangles(cv::Mat image, char* window_name, cv::RNG rand)
{
}

int draw_random_ellipses(cv::Mat image, char* window_name, cv::RNG rand)
{
}
*/


