#pragma once
#include "string"
#include "iostream"
#include "iomanip"
class UI
{

private:
	std::string title;
	std::string* options;
	int arrSize;
public:

	void setTitle(std::string a) { title = a; }
	std::string getTitle() { return title; }
	void setArrSize(int a) {arrSize = a; }
	int getArrSize() { return arrSize; }

	int Menu() 
	{
		system("cls");
		int maxSize=0;
		int w;

		std::string input;
		for (int x = 0; x < arrSize; x++)
		{
			if (static_cast<int>(options[x].size()) > maxSize)
				maxSize = static_cast<int>(options[x].size());
		}
		if (maxSize < (8 + (2 * arrSize)))
		{
			maxSize = 8 + (2 * arrSize);
		}
		maxSize += 6;
		for (int x = 0; x < maxSize; x++)
		{
			std::cout << "-";
		}
		w = ((maxSize - static_cast<int>(title.size()))/2);
		std::cout << "\n" <<std::left<<std::setw(w)<<" "<< title << std::endl;
		for (int x = 0; x < maxSize; x++)
		{
			std::cout << "-";
		}
		std::cout << std::endl;
		
		for (int x = 0; x < arrSize; x++)
		{
			std::cout  << " " << x + 1 << ". " << options[x] << std::endl;
		}
		for (int x = 0; x < maxSize; x++)
		{
			std::cout << "-";
		}
		std::cout <<"\n "<< "Enter(";
		for (int x = 0; x < arrSize; x++)
		{
			std::cout << x + 1 ;
			if (x != arrSize - 1)
			{
				std::cout << ",";
			}
		}

		std::cout << "):\n";
		for (int x = 0; x < maxSize; x++)
		{
			std::cout << "-";
		}
		std::cout << std::endl;
		do {
			std::cin >> input;
		} while (atoi(input.c_str()) > arrSize || atoi(input.c_str()) < 0);

		return atoi(input.c_str());

	}


	//constructor
	UI():options(nullptr) , arrSize(0){}
	UI(std::string a, std::string * b,int c) 
	{
		title = a;
		arrSize = c;
		options = new std::string[arrSize];

		for (int x = 0; x < arrSize; x++)
		{
			options[x] = b[x];
		}
	}
	~UI() { delete[] options; }

};