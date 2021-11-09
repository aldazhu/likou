#include <vector>
#include <iostream>


class Solution_findMedianSortedArrays2 {
public:
	double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
		
		double median = 0;
		int len1 = nums1.size();
		int len2 = nums2.size();
		int lenall = len1 + len2;
		//奇数和偶数个数的排列的中位数不一样
		//1. lenall 是奇数的话，总排列的第(lenall+1)/2个数就是要的中位数
		//索引值是(lenall+1)/2-1；
		//2. lenall是偶数，则第lenall/2,和lenall/2 + 1个数求平均
		//索引值是lenall/2-1,lenall/2

		//把这个问题想象成“装袋”的过程，每次从两列中取出一个最小的值放入袋子
		//如果总列是奇数则第(lenall+1)/2个放入袋子的数就是中位数，
		//如果总列是偶数则第lenall/2,和lenall/2 + 1个数的均值是中位数
		//装袋的过程容易实现，考虑到偶数列，我们记录最后放进去的两个数
		
		int neednum = 0;//装入袋中多少个
		if (lenall % 2 == 1)
		{
			neednum = (lenall + 1) / 2;//奇数时装袋(lenall + 1) / 2个停止，取最后一个装袋的数
		}
		else {
			neednum = lenall / 2 + 1;//偶数时装袋lenall / 2 + 1个停止，取最后两个
		}
		int num = 0;//标示第几个，不是索引
		int i = 0, j = 0;//两个数组的索引
		int lastone = 0, lasttwo = 0;
		while (num < neednum)
		{
			if ( i < len1 && j < len2 && nums1[i] < nums2[j] )
			{
				//nums1选出一个数装袋，并把索引指向下一个,此时装袋的是nums1[i]
				lasttwo = lastone;
				lastone = nums1[i];
				++i;
				++num;
				continue;
			}
			else if(i < len1 && j < len2 && nums1[i] >= nums2[j]  )
			{
				lasttwo = lastone;
				lastone = nums2[j];
				++j;
				++num;
				continue;
			}
			//控制不要越界
			if (i == len1)
			{
				//此时第一个数组已经访问完毕，nums1的最后一个元素已经装袋了，
				//后续直接从第二个数组获取；
				lasttwo = lastone;
				lastone = nums2[j];
				++j;
				++num;
				continue;
			}
			if (j == len2)
			{
				lasttwo = lastone;
				lastone = nums1[i];
				++i;
				++num;
				continue;
			}
		}//end while
		//到这里已经向袋中装入neednum个数
		if (lenall % 2 == 0)
			median = (lastone + lasttwo) / 2.0;
		else
			median = lastone;

		return median;
	}//end function
};


void test_findMedianSortedArrays()
{
	std::vector<int> num1{ 1};
	std::vector<int> num2{ 3};

	Solution_findMedianSortedArrays2 solve;
	double mid = solve.findMedianSortedArrays(num1, num2);
	std::cout << mid << std::endl;

}


struct myData {
	int a;
	char b;
};

void test_c()
{
	//计算数组的长度，
	//一般情况下把数组名视为数组第一个元素的地址
	//例外情况是使用 sizeof 操作符作用于数组名时，返回整个数组所占字节数；
	int a[10] = { 0 };
	int lena = sizeof a / sizeof a[0];
	std::cout << "lena = " << lena << "\n";

	myData data,*p;
	sizeof(myData);		//存储myData类型的对象所占的字节数
	sizeof data;				//data变量的类型占据的空间的字节数，相当于sizeof(myData)
	sizeof p;					//指针p所占空间的字节数
	sizeof *p;					//p指向的类型占据的空间的字节数，相当于sizeof(myData)
	sizeof data.a;			//结构体成员对应类型的大小
	sizeof myData::a;		//另一种获取结构体成员大小的方法

	std::cout <<
		"sizeof(myData) = " << sizeof(myData) << "\n" <<
		"sizeof data = " << sizeof data << "\n" <<
		"sizeof p = " << sizeof p << "\n" <<
		"sizeof *p = " << sizeof *p << "\n" <<
		"sizeof data.a = " << sizeof data.a << "\n" <<
		"sizeof myData::a = " << sizeof myData::a << "\n";

	char *c;
	std::cout <<
		"sizeof c = " << sizeof c << "\n" <<
		"sizeof *c = " << sizeof *c << "\n";
 }


int main_findMedianSortedArrays()
//int main()
{
	//test_findMedianSortedArrays();
	test_c();
	return 0;
}