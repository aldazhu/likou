#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main_decoderString()
{
	char s[100] = { 0 };
	

	int ASCII_3 = int('3');
	int ASCII_1 = int('1');//两位数的时候可能出现
	int ASCII_9 = int('9');

	scanf_s("%s",s,100);
	int len = strlen(s);
	//如果最后一个字符是数字则报错
	if (len > 100 || int(s[len - 1]) >= ASCII_3 && int(s[len - 1]) <= ASCII_9)
	{
		printf("!error\n");
		return 0;
	}

	int allchar = 0;//解码后的字符串总数
	char result[100] = { 0 };//由于最后解码字符串长度大于100时会出错，所以不能直接输出
	int m = 0;//标示result字符数组当前存到哪一位
	int temp;//解析出来的数字
	int j;//连续几个字符是数字
	char c;//数字后面的字符
	for (int i = 0; i < len; i++)
	{
		//遇到数字s[i]是数字且在3-9
		if (int(s[i]) >= ASCII_1 && int(s[i]) <= ASCII_9)
		{
			j = 0;
			while (int(s[i+j]) >= ASCII_1 && int(s[i+j]) <= ASCII_9 && (i + j) < len)
				j++;
			if (j == 1)//
			{
				temp = atoi(&s[i]);
				c = s[i + 1];
				i += 1;//

			}
			else if (j == 2)
			{
				temp = 10 * atoi(&s[i]) + atoi(&s[i + 1]);
				c = s[i + 2];
				i += 2;
			}
			else if (j > 2 )
			{
				//数字超过两位，
				printf("!error\n");
				return 0;
			}
			if (temp < 3)
			{
				//或者数字值小于3
				printf("!error\n");
				return 0;
			}
			//把解码结果存到result,m++
			for (int k = 0; k < temp; k++,m++)
			{
				result[m] = c;
			}
				//printf("%c", s[i]);
		}
		else 
		{
			//printf("%c", s[i]);
			result[m] = s[i];
			m++;
		}	
	}//end for

	if (m > 100)
		printf("!error");
	else
	{
		for (int i = 0; i < m; i++)
			printf("%c", result[i]);
	}

	return 0;
}