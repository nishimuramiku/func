#include "File.h"
File::File()
	:file(nullptr)
	, container(nullptr)
	, size(0)
	, pos(0)
{
}

File::~File()
{
	if (container != nullptr)
	{
		delete container;
		container = nullptr;
	}

}

bool File::OpenFile(const char* fileName)
{
	errno_t error = fopen_s(&file, fileName, "r");

	if (error != 0)
	{
		fclose(file);
		return false;
		std::cout << "error fileOpen" << std::endl;
	}

	size = GetSize();
	container = new char[size + 1];
	fread(container, sizeof(char), size / sizeof(char), file);
	container[size] = '\0';

	//printf("%s", container);

	fclose(file);
	return true;
}

int File::GetSize()
{
	if (fseek(file, 0L, SEEK_END) == 0)
	{
		fpos_t pos;
		if (fgetpos(file, &pos) == 0)
		{
			fseek(file, 0L, SEEK_SET);
			return pos;
		}
	}
}

void File::Split()
{
	std::vector<int> token;
	std::vector<std::vector<int>> line;
	int i = 0;
	int j = 0;
	int k = 0;
	int l = 0;
	
	
	for (l = 0; l < 22; l++)
	{
		//1token‚ÅˆêŽü 1line‚ÅŠO
		for (i = j + 1; container[i] != '\n'; i++)
		{
			if (container[i] == '(')
			{
				continue;
			}

			//‚P”Žš‚ÅˆêŽü‚Ptoken‚ÅŠO
			for (j = i; container[j] != '(' && container[j] != '\n'; j++)
			{
				char c[5] = {};
				int count = 0;

				//ˆê”Žš‚Ü‚Å‹æØ‚é
				for (k = j; container[k] != ',' && container[k] != ')'; k++)
				{

					c[count] = container[k];
					count++;

				}
				
				if (count != 0)
				{
					token.push_back(atoi(c));
				}
				count = 0;
				j = k;
			}
			line.push_back(token);
			token.clear();
			i = k;

		}
		all.push_back(line);
		line.clear();
	}
	
		
	Show();

}

void File::Show()
{	
	for (std::vector<std::vector<int>> line : all)
	{
		for (std::vector<int> token : line)
		{
			std::cout << "(";
			for (int num : token)
			{
				std::cout << num << "," ;

			}
			std::cout << ")";


		} 
		std::cout << std::endl;
	
	}

}