//����ȥ�أ������ճ���Ƶ�ν����������,��ͬ�����ģ�����һ�γ��ֵ�˳�����
// eg�� 3��3��3��1��2��2, 4
// out: 3,2,1,4

// len ��֪��
//array ��֪��

#include <iostream>
#include <string>
#include <map>


void getInput(int * arr)
{
	int i = 0;
	int temp;
	
	
}


int main_HWArrayTest()
{
	int arr[100] = { 0 };
	
	getInput(arr);

	int map[100] = { 0 };
	int len = sizeof arr / sizeof(int);//���鳤��
	for (int i = 0; i < len; i++)
	{
		map[arr[i]] += 1;//�൱�ڶ�ֵ��ֱ��ͼͳ��
	}


	return 0;
}