/*
Author: youngtrashbag
Date 16.07.2019
Purpose: Read a File and Pick one of the files contents (in this case where to eat).
A Cryptographically Secure Random generator//list picker.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sodium.h>

int main()
{
	//creating pointer to file just a variable for now
	FILE *listfile;

	//opening the file in read mode
	listfile = fopen("./list.txt", "r");

	//fiel does not exist, or does not have any contents
	if(listfile == NULL)
	{
		printf("File doesn't exist, exiting now.\n");
		fclose(listfile);

		exit(1);
	}

	//for the amount of lines in file and the amount of chars on a line
	int line_amount = 0;
	int char_counter = 0;

	//127 has no reason, it is a prime number tho
	//first array for the element number(so max 127 elements) and last one for max char in element name
	char items_on_list[127][127];

	//single char of the file
	char filechar = getc(listfile);

	//made for counting the lines of the text file until it ends
	while(filechar != EOF)
	{
		//counts if new line is encountered
		if(filechar == '\n')
		{
			line_amount++;
			char_counter = 0;
		}
		else
		{
			//scans each char in line
			items_on_list[line_amount][char_counter] = filechar;
			char_counter++;
		}

		//scans new char
		filechar = getc(listfile);
	}

	for(int i=0;i<line_amount;i++)
	{
		printf("item nr. %d: %s\n", i+1, items_on_list[i]);
	}

	//closing becuase good boy
	fclose(listfile);

	//begin of randomization

	//initializing sodium library for randombytes command
	if(sodium_init() < 0)
	{
		printf("\nError:\nLibSodium was not found!\n");
		exit(1);
	}

	int random_number = randombytes_uniform(line_amount);

	printf("\nItem nr. %d\t%s has been Selected!\n",random_number+1, items_on_list[random_number]);

	//end of randomization

	//returning because good boy
	return 0;
}

