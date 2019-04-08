#pragma once
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

class hex_user
{
private:
	char en_code[1024] = {0};
	char de_code[1024] = {0};
public:
	void get_en_code(char* str)
	{
		strcpy(this->en_code, str);
		cout << this->en_code << endl;
	}
	void en_cypto()
	{
		for (int i = 0; i < strlen(this->en_code); i++)
		{
			printf("%X", this->en_code[i]);
		}
		cout << endl;
	}
};