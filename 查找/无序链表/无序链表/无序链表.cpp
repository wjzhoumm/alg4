// 无序链表.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

template <typename Key, typename Val>
class ListNodeSearch
{
private:
	typedef struct ListNode
	{
		Key key;
		Val val;
		struct ListNode *next;
		ListNode(Key _key, Val _val, ListNode *_next) : key(_key), val(_val), next(_next) {}
	}ListNode;
	ListNode *first;

public:
	ListNodeSearch()
	{
		//ListNode tmp = { -1, 0, nullptr };
		//first = &tmp;  //这种给first赋值的写法不可以，函数结束后，变量就会被回收，first也就变成了野指针
		//first = new ListNode(-1, -1, nullptr);
		first = nullptr;
	}
	Val get(Key key)
	{
		for (ListNode *i = first; i != nullptr; i = i->next)
		{
			if (key == i->key)
				return i->val;
		}
		return NULL;
	}
	void put(Key key, Val val)
	{
		for (ListNode *i = first; i != nullptr; i = i->next)
		{
			if (key == i->key)
			{
				i->val = val;
				return;
			}
		}
		first = new ListNode(key, val, first);
		//ListNode tmp = { key, val, first };
		//first = &tmp;
	}
};


int main()
{
	ListNodeSearch<int, int> st;
	st.put(0, 1);
	cout << st.get(0) << endl;
    return 0;
}

