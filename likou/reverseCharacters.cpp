/*
����
��һ��Ӣ������Ե���Ϊ��λ�����ŷš����硰I am a boy���������ŷź�Ϊ��boy a am I��
���е���֮����һ���ո����������г���Ӣ����ĸ�⣬���ٰ��������ַ�

���ݷ�Χ��������ַ�����������

ע�Ȿ���ж�������
����������
����һ��Ӣ����䣬ÿ�������ÿո��������֤����ֻ�����ո����ĸ��

���������
�õ�����ľ���

ʾ��1
���룺
I am a boy
����
�����
boy a am I
*/


#include <iostream>
#include <algorithm>
void printArray(int * a, int len)
{
	for (int i = 0; i < len; i++)
		std::cout << a[i] << " ";
	std::cout << "\n";
}

int main_reverseCharacters()
{
	int a[10] = { 2,1,0,3,54,1 };
	size_t len = sizeof a / (sizeof(int));
	std::sort(a,a+len);
	printArray(a, len);
	return 0;
}