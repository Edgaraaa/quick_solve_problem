#include <iostream>
#include <cstring>
#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <string>
#include "affine_demo.h"
using namespace std;

affine teatp;
char demo1[100];
int main()
{
	cin.get(demo1,50);
	teatp.get_en_code(demo1);
	teatp.en_cypto(7,3);
	teatp.de_cypto(7, 3, 26);
	
	
}