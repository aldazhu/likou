//test the input and output of the niucoder plateform
#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS


void test_cin()
{
	std::string s;
	while (std::cin >> s)
	{
		std::cout << s<<"___\n";
	}
	
}

void test_scanf()
{
	char a[500] ;
	scanf_s("%s",a,500);
	printf_s("%s\n", a);
	int size = strlen(a);
	printf("you have input %d letters\n",size);
	//std::cout << a << std::endl;
}


void test_fgets()
{
	char a[50];
	fgets(a, 50, stdin);
	printf("%s\n",a);
	int len = strlen(a);
	printf("%d\n",len);
	printf("%c\n",a[len-1]);

	scanf_s("%s\n",a,sizeof a);
	printf("%s\n", a);
	len = strlen(a);
	printf("%d\n",len);

}

void test_getline()
{
	std::string s;
	char a[50];
	std::cin.getline(a,50);
	std::cout << a;

	int len = strlen(a);
	printf("%d", len);
	s = std::string(a);
	int len2 = s.size();
	std::cout << len2 << std::endl;

}

int main_langrage()
{
	//test_cin();
	//test_scanf();
	///test_getline();
	test_fgets();
	return 0;
}
