/*
 * header.h
 * Author: youngtrashbag
 * Date:   06.02.2020
 */

/* includes */
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
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

/* functions */
std::string formattedTime(time_t time);
int validNumber(std::string &line);

