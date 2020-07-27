#include <iostream>
using namespace std;

template <typename T>
class shell
{
private:
    T *a;
    int size;
public:
    shell(T b[], int insize)
    {
        a = b;
        size = insize;
    }
    void sort()
    {
        int h = 1;
        while (h<size/3)
        {
            h = 3 * h + 1;
        }
        while (h >= 1)
        {
            for (int i=h; i<size; i++)
            {
                for (int j=i; j>=h&&a[j]<a[j-h]; j-=h)
                {
                    swap(j, j-h);
                }
            }
            h /= 3;
        }
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
    shell<int> t(a, 5);
    t.sort();
    t.show();
}