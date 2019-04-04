#pragma once
/*
writer:Edgar
Time:2019.4.5 0:10
 */
#ifndef BASE_64
#define BASE_64
#include <cstdio>
#include <iostream>
#include <cstring>
static const char *LETTER = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
void enBase64(char *enString, int stringLength, char *outString, int &outStringLen) {
	int i = 0;
	int a = 0;
	while (i < stringLength)
	{
		char s0 = enString[i++];
		char s1 = (i < stringLength) ? enString[i++] : 0;
		char s2 = (i < stringLength) ? enString[i++] : 0;
		int int63 = 0x3f;
		int int255 = 0xff;
		outString[a++] = LETTER[(s0 >> 2) & int63];
		outString[a++] = LETTER[((s0 << 4) | ((s1&int255) >> 4))&int63];
		outString[a++] = LETTER[((s1 << 2) | ((s2&int255) >> 6))&int63];
		outString[a++] = LETTER[s2 & int63];
	}
	switch (stringLength % 3)
	{
	case 1:outString[--a] = '=';
	case 2:outString[--a] = '=';
	}
	outStringLen = strlen(outString);
}
void deBase64(char *inString, int inStringLen, char *outString, int &outStringLen) {
	int map[128] = { -1 };
	for (int i = 0; i < 64; i++) {
		int pas = LETTER[i];
		map[pas] = i;
	}
	int int255 = 0xff;
	int index = 0;
	for (int i = 0; i < inStringLen; i += 4) {
		int c0 = map[inString[i]];
		int c1 = map[inString[i + 1]];
		outString[index++] = (((c0 << 2) | (c1 >> 4)) & int255);
		if (index >= inStringLen) {
			return;
		}
		int c2 = map[inString[i + 2]];
		outString[index++] = (((c1 << 4) | (c2 >> 2))&int255);
		if (index >= inStringLen) {
			return;
		}
		int c3 = map[inString[i + 3]];
		outString[index++] = (((c2 << 6) | c3)&int255);
	}
	outStringLen = strlen(outString);
}
#endif // !BASE_64




