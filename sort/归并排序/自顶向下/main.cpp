#include <iostream>
using namespace std;

template <typename T>
class merge
{
private:
    T *a;
    T *aux;
    int size;
public:
    merge(T b[], int insize)
    {
        a = b;
        size = insize;
    }
    void sort()
    {
        aux = new T[size];
        sort(0, size-1);
    }
    void sort(int lo, int hi)
    {
        if (lo>=hi)
            return;
        int mid = lo + (hi - lo) / 2;
        sort(lo, mid);
        sort(mid+1, hi);
        lomerge(lo, mid, hi);
    }
    void lomerge(int lo, int mid, int hi)
    {
        int i = lo, j = mid + 1;
        for (int k=lo; k<=hi; k++)
            aux[k] = a[k];
        for (int k=lo; k<=hi; k++)
        {
            if (i>mid) a[k] = aux[j++];
            else if (j>hi) a[k] = aux[i++];
            else if (aux[i]<aux[j]) a[k] = aux[i++];
            else a[k] = aux[j++];
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
    int size = sizeof(a) / sizeof(a[0]);
    merge<int> t(a, size);
    t.sort();
    t.show();
}