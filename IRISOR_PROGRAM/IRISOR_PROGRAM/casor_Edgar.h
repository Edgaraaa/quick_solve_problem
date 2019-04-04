#pragma once
/*
writer:Edgar
Time:2019.4.5 0:10
 */
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
class casordemo
{
private:
	char en_code[1024] = { 0 };
	char de_code[1024] = { 0 };
public:
	void get_en_string(char* encode)
	{
		for (int i = 0; i < strlen(encode); i++)
		{
			this->en_code[i] = encode[i];
		}
	}
	void get_de_string(char* decode)
	{
		for (int i = 0; i < strlen(decode); i++)
		{
			this->de_code[i] = decode[i];
		}
	}
	void en_cypto(int offset_user)
	{
		for (int i = 0; i < strlen(this->en_code); i++)
		{
			if (this->en_code[i] >= 'a' && this->en_code[i] <= 'z') this->en_code[i] -= 32;
			this->de_code[i] = offset_user + this->en_code[i];
			if (this->en_code[i] > 'Z')
			{
				int num = this->de_code[i] - 'A';
				num %= 26;
				this->de_code[i] = num + 'A';
			}
		}
		cout << this->de_code << endl;
	}
	void de_cypto(int offset_user)
	{
		for (int i = 0; i < strlen(this->de_code); i++)
		{
			this->en_code[i] = this->de_code[i] - offset_user;
			if (this->en_code[i] < 'A')
			{
				this->en_code[i] = 'Z' - ('A' - this->en_code[i]);
			}
		}
		cout << this->en_code << endl;
	}
	void de_cyptoa_evidence()
	{
		for (int i = 0; i <= 26; i++)
		{
			printf("the offset is %d\n", i);
			de_cypto(i);
		}
	}
};
