//����ȥ�أ������ճ���Ƶ�ν����������,��ͬ�����ģ�����һ�γ��ֵ�˳�����
// eg�� 3��3��3��1��2��2, 4
// out: 3,2,1,4

// len ��֪��
//array ��֪��

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <map>
#include <iostream>
#include <string>
//�ṹ�巽��
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
	std::multimap<int, int,mycompare> multimap;//��˳�����,num,frac

	int frac[100] = { 0 };
	for (int i = 0; i < len; i++)
	{
		frac[a[i]] += 1;
	}

	for (int i = 0; i < len; i++)
	{
		if (frac[a[i]] != 0 && a[i]!=0)//��������ǰ�����˳��ȥ����frac��
		{
			//Ϊ�����ظ����ʹ���frac��0��
			multimap.insert(std::make_pair(frac[a[i]], a[i]));//�Ե�һ�ؼ��ֽ���������
			frac[a[i]] = 0;
		}
	}

	//�������
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
	//hist�洢��ÿ���ַ����ֵĴ���
	//sort �洢ÿ��hist�е��ַ����ֵ�˳��
	for (int i = 0; i < len; i++)
	{
		if (hist[arr[i]] != 0)
		{
			if(sort[arr[i]] ==0)
				sort[arr[i]] = i+1;
		}
	}
}

//�˴���lenΪ100����ֵ��Χ����Ϊhist��������arr[i]
void sortHist(int *arr, int *hist, int *value, int *numsort)
{
	//�ڶ�hist����ǰ��hist��index����value��ֵ
	int len = 100;
	for (int i = 0; i < len; i++)
	{
		value[i] = i;
	}
	
	//����hist��ֵ�Ĵ�С�Ӵ�С����
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
	//�˴���len�ǲ�ͬ���ֵĸ�����Ҳ����hist��Ϊ0����Ŀ
	for (int i = 0; i < 100; i++)
	{
		if (hist[i] != 0)
			len++;
	}
	*n = len;
}

void sortValue(int *hist, int *value, int *numsort,int len)
{
	
	//������hist�Ѿ����Ӵ�С������
	//����Ҫ�Գ�����ͬ���������ְ�����˳������

	int temp = 0;
	
	for (int i = 0; i < len; i++)
	{
		int j=0;//�������ٸ������ִ�����ͬ
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
		//��λ��i��i+j֮���value��������
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
	int hist[100] = { 0 }; //hist�洢��ÿ���ַ����ֵĴ���
	int value[100] = { 0 };//value�洢ÿһ��hist�е�Ԫ�ض�Ӧ��ֵ
	int numsort[100] = { 0 }; //numsort �洢ÿ��hist�е��ַ����ֵ�˳��
	int len=6;
	//getInput(a, &len);
	printArr(a, len);
	getHist(a, hist, len);
	getSort(a, hist, numsort, len);//��ȡ���ֳ��ֵ�˳��

	sortHist(a, hist, value, numsort);

	getDiffNumbers(hist, &len);//��ȡ��ͬ���ֵĸ���
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
//		// ���ﰴ��j��0-100��˳��ִ���Ѿ������ȳ��ֵ��Ȳ�����
//		//�����ڼ���map��Ȼ���������ԣ�myCompare�� return v1>v2��ת��map�Ĵ�С�����˳��
//		//ʹ��firstֵ�����ǰ��Ҳ���ǳ��ִ�������Ԫ��
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
