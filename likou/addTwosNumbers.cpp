
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
		int flg = 0;//当前位置的进位标志
		int flg_next = 0;//下一个位置的进位标志

		//两个链表长度一致的部分的相加
		while (l1 != nullptr && l2 != nullptr)
		{
			int m = l1->val + l2->val + flg;
			if (m >= 10)
			{
				l3->val = m - 10;
				flg_next = 1;//产生进位
			}
			else {
				l3->val = m;
				flg_next = 0;
			}

			//移到下一个计算位置
			l1 = l1->next;
			l2 = l2->next;
			flg = flg_next;
			flg_next = 0;
			//如果下一位置的l1,l2都还存在则结果l3长度加长，此时l3的最长长度是公共部分长
			if (l3->next == nullptr && (l1 != nullptr || l2 != nullptr))
			{
				l3->next = new ListNode;
				l3 = l3->next;
			}
		}

		//运行到这里，两个链表的相同的部分已经相加完成，现在只有两种可能，
		//一是，链表长度相同全部加完，如果有进位flg=1,则l3增长一位
		//二是，链表长度不一样公共部分相加完成
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

		//运行到这里最长的链表也已经加完，现在有两种可能
		//如果flg=1，说明有进位，最终结果比lmax多一个节点
		//flg = 0,则结束
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
	//用new分配的地址，测试当程序结束时会不会被回收
	for (int i = 0; i < 5; i++)
	{
		double *a = new double[100000000];
		for (int j = 0; j < 100; j++)
			*(a++) = 9;
		int b;
		std::cin >> b;
	}

	//2021年10月21日测试显示在程序结束后内存被回收
	//debug模式下，用任务管理器看得到内存分配的增加，
	//但是在release模式下内存没有明显的变化，dont know why
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

