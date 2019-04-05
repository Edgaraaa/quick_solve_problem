#pragma once
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

class base_32
{
private:
	string en_code;
	string de_code;
public:
	void get_en_code(string str)
	{
		this->en_code = str;
	}

};