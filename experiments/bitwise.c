#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int number = 69;
	
	if(argc == 2)
	{
		number = atoi(argv[1]);
	}

	if(number & 1 == 1)
	{
		printf("Number is odd.\n");
	}
	else
	{
		printf("Number is not odd.\n");
	}

	return 0;
}

