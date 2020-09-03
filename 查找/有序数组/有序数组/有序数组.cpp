// 有序数组.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

template <typename Key, typename Val>
class ArraySearch
{
private:
	Key *keys;
	Val *vals;
	int size, N;
public:
	ArraySearch(int n = 2)
	{
		keys = new Key[n];
		vals = new Val[n];
		N = n;
		size = 0;
	}
	int rank(Key key)//二分查找
	{
		int lo = 0, hi = size - 1;
		while (lo <= hi)
		{
			int mid = lo + (hi - lo) / 2;
			if (keys[mid] < key) lo = mid + 1;
			else if (keys[mid] > key) hi = mid - 1;
			else return mid;
		}
		return lo;
	}
	Val get(Key key)
	{
		int i = rank(key);
		if (i < N && keys[i] == key) return vals[i];
		else return NULL;
	}
	void put(Key key, Val val)
	{
		if (size == N) resize(2 * N);
		int i = rank(key);
		if (keys[i] == key && i < size)
		{
			vals[i] = val;
			return;
		}
		else
		{
			for (int j = size; j > i; j--)
			{
				keys[j] = keys[j - 1];
				vals[j] = vals[j - 1];
			}
			keys[i] = key;
			vals[i] = val;
			size++;
		}
	}
	void resize(int n)
	{
		Key *keys_tmp = new Key[n];
		Val *vals_tmp = new Val[n];
		for (int i = 0; i < size; i++)
		{
			keys_tmp[i] = keys[i];
			vals_tmp[i] = vals[i];
		}
		delete[]keys;
		delete[]vals;
		keys = keys_tmp;
		vals = vals_tmp;
	}
};

int main()
{
	ArraySearch<int, int> st;
	st.put(0, 1);
	cout << st.get(1) << endl;
    return 0;
}

