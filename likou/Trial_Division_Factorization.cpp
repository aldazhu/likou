///Trial_Division_Factorization
//�ֽ�������
//����һ������������������������ֽ�
#include <iostream>
#include <vector>
//#include <algorithm>

std::vector<int> TrialDivisionFactorization(int n)
{
	std::vector<int> result;
	if (n <= 1)
		return result;
	int a = 2;
	//���n�Ǹ���������ô������������q<=(n)^0.5
	while (a*a <= n)
	{
		while (n%a == 0)
		{
			//�����ѭ���аѺ���������a����Ŀ���ҳ���
			result.push_back(a);
			n = n / a;
		}
		a +=1 ;
	}
	//���������n>1˵�����һ��n�Ѿ�������
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
			//���ѭ���������n���ж��ٸ�i
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
		vec1 = TrialDivisionFactorization(n);//��õĲ����ٶȺܿ�
		vec2 = PollardDivision(n);
		std::cout << "TrialDivisionFactorization��";
		printVector(vec1);
		std::cout << "\n";
		std::cout << "PollardDivision               ��";
		printVector(vec2);
		std::cout << "\n";
	}
	
	return 0;
}