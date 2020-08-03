#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

template <typename T>
class quick
{
private:
    T *a;
    int size;
public:
    quick(T b[], int insize)
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

        int flag = parti(lo, hi);
        sort(lo, flag-1);
        sort(flag+1, hi);
    }
    int parti(int lo, int hi)
    {
        T v = a[lo];
        int i = lo, j = hi + 1;
        
        while (true)
        {
            while (a[++i]<v)
            {
                if (i==hi)
                    break;
            }
            while (a[--j]>v)
            {
                if (j==lo)
                    break;
            }
            if (i>=j)
                break;
            swap(i, j);
        }
        swap(lo, j);
        return j;
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
    quick<int> t(a, size);
    t.sort();
    t.show();
}