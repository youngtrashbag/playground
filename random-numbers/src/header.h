/*
 * header.h
 * Author: youngtrashbag
 * Date:   06.02.2020
 */

using namespace std;

/* includes */
#include <fstream>
#include <cstdlib>
#include <iostream>
extern "C"
{
	#include <sodium.h>
}

/* defines */
#ifndef FILENAME
#define FILENAME "random-numbers.txt"
#endif //FILENAME

#ifndef ITERATIONS
#define ITERATIONS 10000
#endif //ITERATIONS

