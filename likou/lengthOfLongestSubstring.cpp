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
			//从第i个字符开始看后面的不重复的字符串
			int a[128] = { 0 };//类似hash表，所有ASCII字符只有128个
			currNum = 0;
			for (int j = i; j < len; j++)
			{
				//把char类型的字符转为int型，也就是数组的索引，查找时间为1
				//如果字符s[j]之前已经存在了，则退出这一层的循环
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
	//所有字符只有128个
}

int main_lengthOfLongestSubstring()
{
	test_lengthOfLongestSubstring();
	return 0;

}