#pragma once
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
char lable1[128];
void lable_init(char* lable1)
{
	for (int i = 0; i < 26; i++)
	{
		lable1['A' + i] = 'Z' - i;
		lable1['a' + i] = 'z' - i;
	}
}
class atbash
{
private:
	char en_code[1024] = {0};
	char de_code[1024] = {0};
public:
	atbash() 
	{
		lable_init(lable1);
	}
	void get_en_code(char* str)
	{
		for (int i = 0; i < strlen(str); i++)
		{
			this->en_code[i] = str[i];
		}
	}
	void get_de_code(char* str)
	{
		for (int i = 0; i < strlen(str); i++)
		{
			this->de_code[i] = str[i];
		}
	}
	void en_cypto()
	{
		for (int i = 0; i < strlen(this->en_code); i++)
		{
			this->de_code[i] = lable1[this->en_code[i]];
		}
		cout << this->de_code << endl;
	}
	void de_cypto()
	{
		for (int i = 0; i < strlen(this->de_code); i++)
		{
			this->en_code[i] = lable1[this->de_code[i]];
		}
		cout << this->en_code << endl;
	}
};