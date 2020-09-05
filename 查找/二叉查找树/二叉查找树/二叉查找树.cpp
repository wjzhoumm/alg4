// 二叉查找树.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <queue>
using namespace std;

template < typename Key, typename Val >
class BST
{
private:
	typedef struct Node
	{
		Key key;
		Val val;
		struct Node *left, *right;
		int N;
		Node(Key key, Val val, int N)
		{
			this->key = key;
			this->val = val;
			this->N = N;
			this->left = NULL;
			this->right = NULL;
		}
	}Node;
	Node *root;

	int size(Node *x)
	{
		if (x == NULL)
			return 0;
		else
			return x->N;
	}
	Val get(Node *x, Key key)
	{
		while (x != NULL)
		{
			if (key < x->key)
				x = x->left;
			else if (key > x->key)
				x = x->right;
			else
				return x->val;
		}
		return NULL;
	}
	Node* put(Node *x, Key key, Val val)
	{
		if (x == NULL)
			return new Node(key, val, 1);
		if (key < x->key)
			x->left = put(x->left, key, val);
		else if (key > x->key)
			x->right = put(x->right, key, val);
		else
			x->val = val;
		x->N = size(x->left) + size(x->right) + 1;
		return x;
	}
	Node* min(Node *x)
	{
		if (x->left == NULL)
			return x;
		return min(x->left);
	}
	Node* max(Node *x)
	{
		if (x->right == NULL)
			return x;
		return max(x->right);
	}
	Node* floor(Node *x, Key key)
	{
		if (x == NULL) return NULL;
		if (key == x->key) return x;
		if (key < x->key) return floor(x->left, key);
		Node *t = floor(x->right, key);
		if (t != NULL) return t;
		else return x;
	}
	Node* ceiling(Node *x, Key key)
	{
		if (x == NULL) return NULL;
		if (key == x->key) return x;
		if (key > x->key) return ceiling(x->right, key);
		Node *t = ceiling(x->left, key);
		if (t != NULL) return t;
		else return x;
	}
	Node* select(Node *x, int k)
	{
		if (x == NULL) return NULL;
		int t = size(x->left);
		if (k < t) return select(x->left, k);
		else if (k > t) return select(x->right, k -t -1);
		else return x;
	}
	int rank(Key key, Node *x)
	{
		if (x == NULL) return NULL;
		if (key < x->key) return rank(key, x->left);
		else if (key > x->key) return 1 + size(x->left) + rank(key, x->right);
		else return size(x->left);
	}
	Node* deletemin(Node *x)
	{
		if (x->left == NULL) return x->right;
		x->left = deletemin(x->left);
		x->N = 1 + size(x->left) + size(x->right);
		return x;
	}
	Node* Delete(Node *x, Key key)
	{
		if (x == NULL) return NULL;
		if (key < x->key) x->left = Delete(x->left, key);
		else if (key > x->key) x->right = Delete(x->right, key);
		else
		{
			if (x->left == NULL) return x->right;
			else if (x->right == NULL) return x->left;
			else
			{
				Node *t = x;
				x = min(t->right);
				x->right = deletemin(t->right);
				x->left = t->left;
			}
		}
		x->N = 1 + size(x->left) + size(x->right);
		return x;
	}
	void keys(Node *x, queue<Key> &que, Key lo, Key hi)
	{
		if (x == NULL) return;
		if (lo < x->key) keys(x->left, que, lo, hi);
		if (lo <= x->key && hi >= x->key) que.push(x->key);
		if (hi > x->key) keys(x->right, que, lo, hi);
	}

public:
	BST()
	{
		root = NULL;
	}
	int size()
	{
		return size(root);
	}
	//查找
	Val get(Key key)
	{
		return get(root, key);
	}
	//插入
	void put(Key key, Val val)
	{
		root = put(root, key, val);
	}
	//取得最小键
	Key min()
	{
		return min(root)->key;
	}
	//取得最大值
	Key max()
	{
		return max(root)->key;
	}
	//返回小于等于key的最大值
	Key floor(Key key)
	{
		Node *tmp = floor(root, key);
		if (tmp == NULL) return NULL;
		return tmp->key;
	}
	//返回大于等于key的最小值
	Key ceiling(Key key)
	{
		Node *tmp = ceiling(root, key);
		if (tmp == NULL) return NULL;
		return tmp->key;
	}
	//找到排名为k的键
	Key select(int k)
	{
		return select(root, k)->key;
	}
	//找到小于键key的数量
	int rank(Key key)
	{
		return rank(key, root);
	}
	//删除最小键元素
	void deletemin()
	{
		root = deletemin(root);
	}
	//删除
	void Delete(Key key)
	{
		root = Delete(root, key);
	}
	//范围搜索
	queue<Key> keys()
	{
		return keys(min(), max());
	}
	queue<Key> keys(Key lo, Key hi)
	{
		queue<Key> que;
		keys(root, que, lo, hi);
		return que;
	}
};


int main()
{
	BST<int, int> bst;
	bst.put(1, 1);
	for (int i = 1; i < 5; i++)
		bst.put(i, i);
	cout << bst.get(1) << endl;
	cout << bst.size() << endl;
	cout << bst.min() << "\t" << bst.max() << endl;
	cout << bst.floor(5) << "\t" << bst.ceiling(0) << endl;
	cout << bst.select(3) << endl;
	cout << bst.rank(3) << endl;
	bst.deletemin();
	cout << bst.min() << endl;
	bst.Delete(2);
	cout << bst.min() << endl;
	queue<int> que = bst.keys();
	cout << que.front() << endl;
    return 0;
}