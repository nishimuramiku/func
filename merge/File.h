#pragma once

#include<iostream>
#include<vector>

class File
{
public:
	File();
	~File();

	bool OpenFile(const char* fileName);
	void Split();


private:
	int GetSize();
	void Show();//Šm”F—p


private:
	FILE* file;
	int size;
	char* container;
	std::vector< std::vector< std::vector<int>>> all;

	int pos;

};

