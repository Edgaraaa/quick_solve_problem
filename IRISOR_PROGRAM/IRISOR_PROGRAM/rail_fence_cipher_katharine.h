#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
char map[100][100] = { 0 };
using namespace std;
class rail_fence
{
private:
	char en_code[1024] = { 0 };
	char de_code[1024] = { 0 };
public:
	void get_en_code(char* str)
	{
		int p = 0;
		for (int i = 0; i < strlen(str); i++)
			if (str[i] != ' ')
			{
				this->en_code[p++] = str[i];
			}
		cout << this->en_code << endl;
		cout <<"this is the length of en_code   "<< strlen(this->en_code) << endl;

	}
	void get_de_code(char* str)
	{
		int p = 0;
		for (int i = 0; i < strlen(str); i++)
				this->de_code[p++] = str[i];
	}
	void en_cypto(int a)
	{
		int num = strlen(this->en_code) % a;
		int num2 = strlen(this->en_code) / a;
		int p = 0;
		int k = 0;
		if (num != 0) k = 1;
		for (int i = 0; i < num2 + k; i++)
		{
			for (int j = 0; j < a; j++)
			{
				if (p == strlen(this->en_code)) break;
				map[i][j] = this->en_code[p];
				p++;
				cout << map[i][j] << " ";
			}
			cout << endl;
		}
		int kkl = 0;
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < num2 + k; j++)
			{
				if (map[j][i] == 0) continue;
				this->de_code[kkl++] = map[j][i];
			}
		}
		cout << this->de_code << endl;
		cout << "this is the strlen of de_code    " << strlen(this->de_code) << endl;
	}
	void de_cypto(int a)
	{
		cout << "this is de_code   " << this->de_code << endl;
		char map[100][100] = {0};
		int num = strlen(this->de_code) / a;
		int num1 = strlen(this->de_code) % a;
		int p = (num1 != 0) ? 1 : 0;
		num += p;
		int k = 0;
		int flag = 0;
		p = 0;
		if (num1 != 0)
		{
			for (int i = 0; i < num1; i++)
			{
				for (int j = 0; j < num; j++)
				{
					if (p >= strlen(this->de_code)) {
						flag = 1;
						break;
					}
					map[j][i] = this->de_code[p];
					p++;
					//cout << map[j][i] << " ";
				}
				//cout << endl;
				if (flag == 1) break;
			}
			for (int i = num1; i < a; i++)
			{
				for (int j = 0; j < num - 1; j++)
				{
					if (p >= strlen(this->de_code)) {
						flag = 1;
						break;
					}
					map[j][i] = this->de_code[p];
					p++;
					//cout << map[j][i] << " ";
				}
				//cout << endl;
				if (flag == 1) break;
			}
		}
		else {
			for (int i = 0; i < a; i++)
			{
				for (int j = 0; j < num; j++)
				{
					if (p >= strlen(this->de_code)) {
						flag = 1;
						break;
					}
					map[j][i] = this->de_code[p];
					p++;
					//cout << map[j][i] << " ";
				}
				//cout << endl;
				if (flag == 1) break;
			}
		}
		char str1[1024] = { 0 };
		p = 0;
		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j < a; j++)
			{
				if (map[i][j] == 0)
				{
					continue;
				}
				str1[p++]=map[i][j];
			}
		}
		cout << str1 << endl;
	}
	void rail_evidence()
	{
		for (int i = 2; i < strlen(this->de_code); i++)
		{
			cout << i << endl;
			this->de_cypto(i);
		}
	}
};