#include <string>
#include<iostream>

class Solution_lengthOfLongestSubstring {
public:
	int lengthOfLongestSubstring(std::string s) {

		int maxNum = 0;
		int currNum = 0;
		int len = s.length();

		for (int i = 0; i < len; i++)
		{
			//�ӵ�i���ַ���ʼ������Ĳ��ظ����ַ���
			int a[128] = { 0 };//����hash������ASCII�ַ�ֻ��128��
			currNum = 0;
			for (int j = i; j < len; j++)
			{
				//��char���͵��ַ�תΪint�ͣ�Ҳ�������������������ʱ��Ϊ1
				//����ַ�s[j]֮ǰ�Ѿ������ˣ����˳���һ���ѭ��
				if (a[(int)s[j]] == 1)
					break;
				else {
					a[(int)s[j]] = 1;
					currNum += 1;
				}
			}
			if (currNum > maxNum)
				maxNum = currNum;
		}

		return maxNum;
	}//end function
};


void test_lengthOfLongestSubstring()
{
	std::string s = "abc";
	int len = s.length();
	char i = s[1];
	Solution_lengthOfLongestSubstring sol;
	int num = sol.lengthOfLongestSubstring(s);
	std::cout << num << std::endl;
	//�����ַ�ֻ��128��
}

int main_lengthOfLongestSubstring()
{
	test_lengthOfLongestSubstring();
	return 0;

}