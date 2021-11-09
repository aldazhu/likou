#include <iostream>
#include <string>

//动态规划
class Solution {
public:
	std::string longestPalindrome(std::string s) {
		int len = s.size();
		if (len == 1)
			return s;
		else if (len == 2)
		{
			if (s[0] == s[1])
				return s;
			else
				return s.substr(0, 1);
		}

		int maxsublen = 1;//最长回文串的长度，初始化为1，因为到这里最少为1
		int start = 0;
		bool *p = new bool[len*len];
		for (int i = 0; i < len; i++)
			p[i*len + i] = true;
		for (int j = 0; j < len; j++)
		{
			for (int i = 0; i < j; i++)
			{
				//如果字串长度小于3，则字串j-i+1=2,有两个
				if (j - i + 1 < 3 )
				{
					if (s[i] == s[j])
						p[i*len + j] = true;
					else
						p[i*len + j] = false;

				}
				else
					p[i*len + j] = (p[(i + 1)*len + j-1] && s[i] == s[j]);

				if (p[i*len +j])
				{
					if (j - i + 1 > maxsublen)
					{
						maxsublen = j - i + 1;
						start = i;
					}
				}
			}
		}

		delete[] p;
		return s.substr(start,maxsublen);
	}
};

//暴力求解
class Solution_force {
public:
	std::string longestPalindrome(std::string s) {
		int len = s.size();

		int maxsublen = 1;
		int curlen = 0;
		int start = 0;
		int end = 0;
		int m, n;
		for (int i = 0; i < len; i++)
		{
			//这里可以优化，
			if (len - i < maxsublen)
				break;
			for (int j = len - 1; j > i; j--)
			{
				if (j - i < maxsublen)
					break;
				if (s[i] != s[j])
					continue;
				curlen = 0;
				//start = i;
				m = i;
				n = j;
				while (s[m] == s[n] && m < n)
				{
					m++;
					n--;
					curlen += 2;

				}//end while
				if (m < n)
				{
					curlen = 0;
					continue;
				}
				else if (m == n)
				{
					//the substring's length is an odd number
					curlen += 1;
				}
				if (curlen > maxsublen)
				{
					start = i;
					maxsublen = curlen;
				}
			}//end for
		}//end for

		return s.substr(start, maxsublen);

	}//end function
};


void test()
{
	Solution_force solve1;
	Solution solve2;
	//std::string s = "aacabdkacaa";
	std::string s = "aaca";
	std::string s1, s2;
	s1 = solve1.longestPalindrome(s);
	s2 = solve2.longestPalindrome(s);

	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;

	if (s1 == s2)
		std::cout << true;
}


int main_longestPalind()
{
	test();
	return 0;
}