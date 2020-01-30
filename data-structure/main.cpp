/*
 * Author: youngtrashbag
 * Date: 30.01.2020
 */

#include "header.h"

int main(int argc, char* argv[])
{
	Data d;
	PrintData(d);

	d = Data(1);
	PrintData(d);

	d.SetString("yes, hello world");
	PrintData(d);

	d.SetId(2);
	PrintData(d);

	try {
		d.~Data();
		PrintData(d);
		std::cout << "Deconstructor called" << std::endl;
	}
	catch(...) {
		std::cout << "Deconstructor could not be called" << std::endl;
	}

	// conventional
	return 0;
}

