///Trial_Division_Factorization
//分解质因数
//输入一个正整数，输出它的质因数分解
#include <iostream>
#include <vector>
//#include <algorithm>

std::vector<int> TrialDivisionFactorization(int n)
{
	std::vector<int> result;
	if (n <= 1)
		return result;
	int a = 2;
	//如果n是复合数，那么它最大的质因数q<=(n)^0.5
	while (a*a <= n)
	{
		while (n%a == 0)
		{
			//在这个循环中把含有质因数a的数目都找出来
			result.push_back(a);
			n = n / a;
		}
		a +=1 ;
	}
	//到这里如果n>1说明最后一个n已经是质数
	if (n > 1) result.push_back(n);
	return result;
}

std::vector<int> PollardDivision(int n)
{
	std::vector<int> result;
	if (n <= 1)
		return result;

	for (int i = 2; i <= n; i++)
	{
		while (i != n)
		{
			//这个循环用来检测n中有多少个i
			if (n%i == 0)
			{
				result.push_back(i);
				n /= i;
			}
			else
				break;
		}
	}
	result.push_back(n);

	return result;
}

void printVector(std::vector<int> vec)
{
	//std::sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++) 
		std::cout << vec[i] << " ";
}

int main_TrialDivisionFactorization()
{
	std::vector<int> vec1,vec2;
	int n;
	for (int i = 0; i < 10; i++)
	{
		scanf_s("%d", &n, 10);
		vec1 = TrialDivisionFactorization(n);//最好的策略速度很快
		vec2 = PollardDivision(n);
		std::cout << "TrialDivisionFactorization：";
		printVector(vec1);
		std::cout << "\n";
		std::cout << "PollardDivision               ：";
		printVector(vec2);
		std::cout << "\n";
	}
	
	return 0;
}