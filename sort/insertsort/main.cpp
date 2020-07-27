#include <iostream>
using namespace std;

template <typename T>
class insertsort
{
private:
    T *a;
    int size;
public:
    insertsort(T b[], int insize)
    {
        a = b;
        size = insize;
    }
    void sort()
    {
        for (int i=1; i<size; i++)
        {
            for (int j=i; j>0&&a[j]<a[j-1]; j--)
            {
                swap(j, j-1);
            }
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
    int a[5] = {1, 2, 5, 3, 0};
    int size = sizeof(a)/sizeof(a[0]);
    insertsort<int> t(a, size);
    t.sort();
    t.show();
}