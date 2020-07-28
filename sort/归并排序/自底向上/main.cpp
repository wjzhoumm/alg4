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
        for (int sz=1; sz<size; sz*=2)  //sz是子数组大小，数组两两排序
        {
            for (int lo=0; lo<size-sz; lo+=sz*2)
            {
                lomerge(lo, lo+sz-1, min(lo+sz*2-1, size-1));
            }
        }
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
    merge<int> t(a, size);
    t.sort();
    t.show();
}