#include<iostream>
#include"File.h"


int main(void)
{
	File* file = new File();
	file->OpenFile("center.txt");
	file->Split();

	delete file;
	return 0;
}