#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main_decoderString()
{
	char s[100] = { 0 };
	

	int ASCII_3 = int('3');
	int ASCII_1 = int('1');//��λ����ʱ����ܳ���
	int ASCII_9 = int('9');

	scanf_s("%s",s,100);
	int len = strlen(s);
	//������һ���ַ��������򱨴�
	if (len > 100 || int(s[len - 1]) >= ASCII_3 && int(s[len - 1]) <= ASCII_9)
	{
		printf("!error\n");
		return 0;
	}

	int allchar = 0;//�������ַ�������
	char result[100] = { 0 };//�����������ַ������ȴ���100ʱ��������Բ���ֱ�����
	int m = 0;//��ʾresult�ַ����鵱ǰ�浽��һλ
	int temp;//��������������
	int j;//���������ַ�������
	char c;//���ֺ�����ַ�
	for (int i = 0; i < len; i++)
	{
		//��������s[i]����������3-9
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
				//���ֳ�����λ��
				printf("!error\n");
				return 0;
			}
			if (temp < 3)
			{
				//��������ֵС��3
				printf("!error\n");
				return 0;
			}
			//�ѽ������浽result,m++
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