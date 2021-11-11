//数组去重，并按照出现频次降序排列输出,相同次数的，按第一次出现的顺序输出
// eg； 3，3，3，1，2，2, 4
// out: 3,2,1,4

// len 已知；
//array 已知；

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <map>
#include <iostream>
#include <string>
//结构体方案
//struct bignum {
//	int data;
//	int frac;
//	int sort;
//};

class mycompare {
public:
	bool operator()(int v1, int v2) {
		return v1 > v2;
	}
};

int main()
{
	int a[100] = { 2,3,3,2,5,6 };
	int len = 6;//the length of the array
	std::multimap<int, int,mycompare> multimap;//按顺序插入,num,frac

	int frac[100] = { 0 };
	for (int i = 0; i < len; i++)
	{
		frac[a[i]] += 1;
	}

	for (int i = 0; i < len; i++)
	{
		if (frac[a[i]] != 0 && a[i]!=0)//在这里就是按出现顺序去访问frac的
		{
			//为避免重复访问过的frac置0；
			multimap.insert(std::make_pair(frac[a[i]], a[i]));//对第一关键字降序序排列
			frac[a[i]] = 0;
		}
	}

	//反向遍历
	//std::multimap<int, int>::reverse_iterator rit;
	std::multimap<int, int>::iterator it;
	std::string s;
	for (it = multimap.begin(); it != multimap.end(); it++)
	{
		s += std::to_string(it->second) + ",";
	}
	s = s.substr(0, s.size() - 1);
	std::cout << s;
}


/*
void getInput(int *arr, int *count)
{
	int temp;
	*count = 0;
	char str[500] = { 0 };
	int state=0;
}

void printArr(int *a, int len)
{
	for (int i=0; i<len-1 ; i++)
	{
		printf("%d,", a[i]);
	}
	printf("%d\n", a[len - 1]);
}

void getHist(int *arr,int *hist,int len)
{
	for (int i = 0; i < len; i++)
		hist[arr[i]] += 1;
}

void getSort(int *arr, int *hist, int *sort, int len)
{
	//hist存储着每个字符出现的次数
	//sort 存储每个hist中的字符出现的顺序
	for (int i = 0; i < len; i++)
	{
		if (hist[arr[i]] != 0)
		{
			if(sort[arr[i]] ==0)
				sort[arr[i]] = i+1;
		}
	}
}

//此处的len为100；是值域范围，因为hist的索引是arr[i]
void sortHist(int *arr, int *hist, int *value, int *numsort)
{
	//在对hist排序前，hist的index就是value的值
	int len = 100;
	for (int i = 0; i < len; i++)
	{
		value[i] = i;
	}
	
	//按照hist的值的大小从大到小排列
	int temp;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (hist[j] < hist[j + 1])
			{
				temp = hist[j];
				hist[j] = hist[j + 1];
				hist[j + 1] = temp;

				temp = value[j];
				value[j] = value[j + 1];
				value[j + 1] = temp;

				temp = numsort[j];
				numsort[j] = numsort[j + 1];
				numsort[j + 1] = temp;
			}
		}
	}

}

void getDiffNumbers(int *hist, int*n)
{
	int len = 0;
	//此处的len是不同数字的个数，也就是hist不为0的数目
	for (int i = 0; i < 100; i++)
	{
		if (hist[i] != 0)
			len++;
	}
	*n = len;
}

void sortValue(int *hist, int *value, int *numsort,int len)
{
	
	//到这里hist已经按从大到小排列了
	//还需要对出现相同次数的数字按出现顺序排列

	int temp = 0;
	
	for (int i = 0; i < len; i++)
	{
		int j=0;//连续多少个数出现次数相同
		while (i + j < len-1)
		{
			if (hist[i] == hist[i + j + 1])
			{
				j++;
			}
			else {
				break;
			}
		}
		//在位置i和i+j之间对value数组排序
		for (int n = i; n < i + j; n++)
		{
			for (int m = i; m <= i + j-1 ; m++)
			{
				if (numsort[m] > numsort[m + 1])
				{
					temp = numsort[m];
					numsort[m ] = numsort[m + 1];
					numsort[m + 1] = temp;

					temp = value[m];
					value[m] = value[m + 1];
					value[m + 1] = temp;
				}
			}
		}
		i = i + j;

	}//end for

}

int main()
{
	int a[100] = { 5,2,30,5,2,30 };
	int hist[100] = { 0 }; //hist存储着每个字符出现的次数
	int value[100] = { 0 };//value存储每一个hist中的元素对应的值
	int numsort[100] = { 0 }; //numsort 存储每个hist中的字符出现的顺序
	int len=6;
	//getInput(a, &len);
	printArr(a, len);
	getHist(a, hist, len);
	getSort(a, hist, numsort, len);//获取数字出现的顺序

	sortHist(a, hist, value, numsort);

	getDiffNumbers(hist, &len);//获取不同数字的个数
	//printArr(hist, len);
	//printArr(numsort, len);
	//printArr(value, len);

	sortValue(hist,value,numsort,len);
	printArr(value,len);
	
	return 0;
}
*/

///good answer
////#include <bits/stdc++.h>
//#include <iostream>
//#include <string>
//#include <map>
//using namespace std;
//class MyCompare
//{
//public:
//	bool operator()(int v1, int v2)const
//	{
//		return v1 > v2;
//	}
//};
//
//int main_nb()
//{
//	int num[101] = { 0 };
//	int counts[101] = { 0 };// save the counts of the input number,like a hash map
//	string str;
//	cin >> str;
//	int start = 0;
//	int end = str.length() - 1;
//	int i = 0;
//	while (start <= end)
//	{
//		int pos = str.find(',', start);
//		string tmp;
//		if (pos >= 0)
//		{
//			tmp = str.substr(start, pos - start);
//			start = pos + 1;
//			int tt = atoi(tmp.c_str());
//			if (counts[tt] == 0)
//			{
//				num[i++] = tt;
//			}
//			counts[tt] += 1;
//			tmp.clear();
//		}
//		else
//		{
//			tmp = str.substr(start, end - start + 1);
//			int tt = atoi(tmp.c_str());
//			if (counts[tt] == 0)
//			{
//				num[i++] = tt;
//			}
//			counts[tt] += 1;
//
//			tmp.clear();
//			break;
//		}
//	}
//	multimap<int, int, MyCompare> myMap;
//	for (int j = 0; j < i; j++)
//	{
//		// 这里按照j从0-100的顺序执行已经做到先出现的先插入了
//		//另外在加上map天然的排序特性，myCompare中 return v1>v2反转了map的从小到大的顺序，
//		//使得first值大的在前，也就是出现次数最多的元素
//		myMap.insert(make_pair(counts[num[j]], num[j]));
//	}
//	string res;
//	for (multimap<int, int, MyCompare>::iterator it = myMap.begin(); it != myMap.end(); it++)
//	{
//		res += to_string(it->second);
//		res += ",";
//	}
//	cout << res.substr(0, res.size() - 1);
//	return 0;
//}
//
