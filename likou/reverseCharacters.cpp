/*
描述
将一个英文语句以单词为单位逆序排放。例如“I am a boy”，逆序排放后为“boy a am I”
所有单词之间用一个空格隔开，语句中除了英文字母外，不再包含其他字符

数据范围：输入的字符串长度满足

注意本题有多组输入
输入描述：
输入一个英文语句，每个单词用空格隔开。保证输入只包含空格和字母。

输出描述：
得到逆序的句子

示例1
输入：
I am a boy
复制
输出：
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