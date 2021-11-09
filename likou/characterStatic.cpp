//输入一个没有空格的字符串，统计里面有字符的种类数
//eg: abbb-->2, abc-->3,aaaaa-->1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main_characterStatic()
{
	char str[500];
	scanf_s("%s", str,500);
	int nu[128] = { 0 };
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		nu[(int)str[i]] += 1;
	}
	int num = 0;
	for (int i = 0; i < 128; i++)
	{
		if (nu[i] > 0)
			num++;
	}
	printf("%d", num);
	return 0;
}