#include <iostream>
#include <cstring>
#include "casor_edgar.h"
#include "atbash_demo.h"
using namespace std;

atbash teatp;
char demo1[] = "hshkjaJHIHJKnkejfBJKBJK";
int main()
{
	teatp.get_en_code(demo1);
	teatp.en_cypto();
	teatp.de_cypto();
	
}