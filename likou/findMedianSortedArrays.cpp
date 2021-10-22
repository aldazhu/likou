#include <vector>
#include <iostream>


class Solution_findMedianSortedArrays2 {
public:
	double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
		
		double median = 0;
		int len1 = nums1.size();
		int len2 = nums2.size();
		int lenall = len1 + len2;
		//������ż�����������е���λ����һ��
		//1. lenall �������Ļ��������еĵ�(lenall+1)/2��������Ҫ����λ��
		//����ֵ��(lenall+1)/2-1��
		//2. lenall��ż�������lenall/2,��lenall/2 + 1������ƽ��
		//����ֵ��lenall/2-1,lenall/2

		//�������������ɡ�װ�����Ĺ��̣�ÿ�δ�������ȡ��һ����С��ֵ�������
		//����������������(lenall+1)/2��������ӵ���������λ����
		//���������ż�����lenall/2,��lenall/2 + 1�����ľ�ֵ����λ��
		//װ���Ĺ�������ʵ�֣����ǵ�ż���У����Ǽ�¼���Ž�ȥ��������
		
		int neednum = 0;//װ����ж��ٸ�
		if (lenall % 2 == 1)
		{
			neednum = (lenall + 1) / 2;//����ʱװ��(lenall + 1) / 2��ֹͣ��ȡ���һ��װ������
		}
		else {
			neednum = lenall / 2 + 1;//ż��ʱװ��lenall / 2 + 1��ֹͣ��ȡ�������
		}
		int num = 0;//��ʾ�ڼ�������������
		int i = 0, j = 0;//�������������
		int lastone = 0, lasttwo = 0;
		while (num < neednum)
		{
			if ( i < len1 && j < len2 && nums1[i] < nums2[j] )
			{
				//nums1ѡ��һ����װ������������ָ����һ��,��ʱװ������nums1[i]
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
			//���Ʋ�ҪԽ��
			if (i == len1)
			{
				//��ʱ��һ�������Ѿ�������ϣ�nums1�����һ��Ԫ���Ѿ�װ���ˣ�
				//����ֱ�Ӵӵڶ��������ȡ��
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
		//�������Ѿ������װ��neednum����
		if (lenall % 2 == 0)
			median = (lastone + lasttwo) / 2.0;
		else
			median = lastone;

		return median;
	}//end function
};


void test_findMedianSortedArrays()
{
	std::vector<int> num1{ 1,2,6};
	std::vector<int> num2{ 3,4,5};

	Solution_findMedianSortedArrays2 solve;
	double mid = solve.findMedianSortedArrays(num1, num2);
	std::cout << mid << std::endl;

}

//int main_findMedianSortedArrays()
int main()
{
	test_findMedianSortedArrays();
	return 0;
}