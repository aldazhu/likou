
#include <iostream>

// two number add


struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* l3 = new ListNode;//result
		ListNode*l3_head = l3;
		int flg = 0;//��ǰλ�õĽ�λ��־
		int flg_next = 0;//��һ��λ�õĽ�λ��־

		//����������һ�µĲ��ֵ����
		while (l1 != nullptr && l2 != nullptr)
		{
			int m = l1->val + l2->val + flg;
			if (m >= 10)
			{
				l3->val = m - 10;
				flg_next = 1;//������λ
			}
			else {
				l3->val = m;
				flg_next = 0;
			}

			//�Ƶ���һ������λ��
			l1 = l1->next;
			l2 = l2->next;
			flg = flg_next;
			flg_next = 0;
			//�����һλ�õ�l1,l2������������l3���ȼӳ�����ʱl3��������ǹ������ֳ�
			if (l3->next == nullptr && (l1 != nullptr || l2 != nullptr))
			{
				l3->next = new ListNode;
				l3 = l3->next;
			}
		}

		//���е���������������ͬ�Ĳ����Ѿ������ɣ�����ֻ�����ֿ��ܣ�
		//һ�ǣ���������ͬȫ�����꣬����н�λflg=1,��l3����һλ
		//���ǣ������Ȳ�һ����������������
		ListNode * lmax = nullptr;
		if (l1 == nullptr && l2 == nullptr)
		{
			if (flg == 1)
			{
				l3->next = new ListNode;
				l3->next->val = 1;
			}
		}
		else if (l1 != nullptr)
			lmax = l1;
		else
			lmax = l2;

		while (lmax != nullptr)
		{
			int m = lmax->val + flg;
			if (m >= 10)
			{
				l3->val = m - 10;
				flg_next = 1;
			}
			else
			{
				l3->val = m;
				flg_next = 0;
			}
			//move the next point
			lmax = lmax->next;
			flg = flg_next;
			flg_next = 0;
			if (lmax != nullptr)
			{
				l3->next = new ListNode;
				l3 = l3->next;
			}
		}//end while

		//���е������������Ҳ�Ѿ����꣬���������ֿ���
		//���flg=1��˵���н�λ�����ս����lmax��һ���ڵ�
		//flg = 0,�����
		if (flg == 1)
		{
			l3->next = new ListNode;
			l3->next->val = 1;
		}

		return l3_head;
	}//end addTwoNumbers
};

int getListLength(ListNode *l)
{
	int num = 0;
	while (l != nullptr)
	{
		num += 1;
		l = l->next;
	}
	return num;
}

ListNode * initList(int * list, int n)
{
	if (n == 0)
		return nullptr;
	ListNode *head;
	ListNode *l = new ListNode;
	head = l;
	for (int i = 0; i < n - 1; i++)
	{
		l->val = list[i];
		l->next = new ListNode;
		l = l->next;
	}
	l->val = list[n - 1];
	return head;
}

void printList(ListNode *l)
{
	while (l != nullptr)
	{
		std::cout << l->val;
		l = l->next;
	}
	std::cout << "\n";
}

void test_add()
{
	int a[] = { 1,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9 };
	int b[] = { 9,9,9,9 };

	int na = sizeof(a) / sizeof(a[0]);
	int nb = sizeof(b) / sizeof(b[0]);
	ListNode * l1 = initList(a, na);
	ListNode * l2 = initList(b, nb);
	printList(l1);
	printList(l2);

	Solution sol;
	ListNode *l3 = sol.addTwoNumbers(l1, l2);
	//int num = getListLength(l3);
	printList(l3);
}


void testMemory()
{
	//��new����ĵ�ַ�����Ե��������ʱ�᲻�ᱻ����
	for (int i = 0; i < 5; i++)
	{
		double *a = new double[100000000];
		for (int j = 0; j < 100; j++)
			*(a++) = 9;
		int b;
		std::cin >> b;
	}

	//2021��10��21�ղ�����ʾ�ڳ���������ڴ汻����
	//debugģʽ�£���������������õ��ڴ��������ӣ�
	//������releaseģʽ���ڴ�û�����Եı仯��dont know why
}

int main_add()
{
	test_add();
	testMemory();
	int i;
	std::cin >> i;
	std::cout << "Hello World!\n";
	return 0;
}

