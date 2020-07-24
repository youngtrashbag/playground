#include "header.h"

void draw_random_lines(cv::Mat image)
{
	int a = 0;
	int b = 901;
	cv::Point pt1, pt2;

	//random variable thingy
	cv::RNG rand = (0xFFFFFFFF);
	
	//10 random lines will get drawn onto image
	for(int i=0; i<10; i++)
	{
		pt1.x = rand.uniform(a, b);
		pt1.y = rand.uniform(a, b);
		pt2.x = rand.uniform(a, b);
		pt2.y = rand.uniform(a, b);

		cv::line(image, pt1, pt2, randomColor(rand), rand.uniform(1, 10), 8);
	}
}

