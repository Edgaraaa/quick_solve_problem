#include "hex_demo.h"
using namespace std;

hex_user demo1;
char str[10];
int main()
{
	cin >> str;
	demo1.get_en_code(str);
	demo1.en_cypto();
	return 0;
}
