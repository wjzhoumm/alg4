#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

template <typename T>
class quick3way
{
private:
    T *a;
    int size;
public:
    quick3way(T b[], int insize)
    {
        a = b;
        size = insize;
    }
    void sort()
    {
        srand(unsigned (time(0)));
        random_shuffle(a, a+size);
        sort(0, size-1);
    }
    void sort(int lo, int hi)
    {
        if (lo >= hi) return;

        int lt = lo, i = lo + 1, gt = hi;
        T v = a[lo];
        while (i<=gt)
        {
            if (a[i]<v) swap(i++, lt++);
            else if (a[i]>v) swap(i, gt--);
            else i++;
        }
        sort(lo, lt-1);
        sort(gt+1, hi);
    }
    T min(T x, T y)
    {
        return x<y?x:y;
    }
    void swap(int i, int j)
    {
        T temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    void show()
    {
        for (int i=0; i<size; i++)
        {
            cout << a[i] << "\t";
        }
        cout << endl;
    }
};

int main()
{
    int a[] = {1, 2, 3, 5, 0};
    int size = sizeof(a) / sizeof(a[0]);
    quick3way<int> t(a, size);
    t.sort();
    t.show();
}