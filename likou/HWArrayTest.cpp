//数组去重，并按照出现频次降序排列输出,相同次数的，按第一次出现的顺序输出
// eg； 3，3，3，1，2，2, 4
// out: 3,2,1,4

// len 已知；
//array 已知；

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
	int len = sizeof arr / sizeof(int);//数组长度
	for (int i = 0; i < len; i++)
	{
		map[arr[i]] += 1;//相当于对值做直方图统计
	}


	return 0;
}