#pragma once
/*A / a	aaaaa	H / h	aabbb	O / o	abbba	V / v	babab
B / b	aaaab	I / i	abaaa	P / p	abbbb	W / w	babba
C / c	aaaba	J / j	abaab	Q / q	baaaa	X / x	babbb
D / d	aaabb	K / k	ababa	R / r	baaab	Y / y	bbaaa
E / e	aabaa	L / l	ababb	S / s	baaba	Z / z	bbaab
F / f	aabab	M / m	abbaa	T / t	baabb
G / g	aabba	N / n	abbab	U / u	babaa*/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

vector<string> mapp;
class bacon {
private:
	string en_code="";
	string de_code="";
public:
	void get_encode(string str)
	{
		this->en_code = str;
		for (int i = 0; i < this->en_code.size(); i++)
		{
			if (this->en_code[i] >= 'A' && this->en_code[i] <= 'Z') this->en_code[i] += 32;
		}
	}
	void get_vector()
	{
		mapp.push_back("aaaaa");
		mapp.push_back("aaaab");
		mapp.push_back("aaaba");
		mapp.push_back("aaabb");
		mapp.push_back("aabaa");
		mapp.push_back("aabab");
		mapp.push_back("aabba");
		mapp.push_back("aabbb");
		mapp.push_back("abaaa");
		mapp.push_back("abaab");
		mapp.push_back("ababa");
		mapp.push_back("ababb");
		mapp.push_back("abbaa");
		mapp.push_back("abbab");
		mapp.push_back("abbba");
		mapp.push_back("abbbb");
		mapp.push_back("baaaa");
		mapp.push_back("baaab");
		mapp.push_back("baaba");
		mapp.push_back("baabb");
		mapp.push_back("babaa");
		mapp.push_back("babab");
		mapp.push_back("babba");
		mapp.push_back("babbb");
		mapp.push_back("bbaaa");
		mapp.push_back("bbaab");

	}
	void en_cypto()
	{
		get_vector();
		for (int i = 0; i <this->en_code.size(); i++)
		{
			int p = this->en_code[i] - 'a';
			this->de_code = this->de_code + mapp[p];
		}
		cout << this->de_code.c_str() << endl;
	}
	void de_cypto()
	{
		string ans = "";
		string decode = "";
		int n = this->de_code.size() / 5;
		int p = 0;
		int k = 0;
		for (int i = 0; i < n; i++)
		{
			while (p < 5)
			{
				decode = decode + this->de_code[k];
				p++;
				k++;
			}
			p = 0;
			for (int i = 0; i < mapp.size(); i++)
			{
				if (mapp[i] == decode)
				{
					string kkp = "a";
					kkp[0] += i;
					ans = ans + kkp;
				}
			}
			decode = "";
		}
		cout << ans.c_str() << endl;
	}

};