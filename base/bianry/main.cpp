#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int key = 2;
    int forsearch[5] = {1,2,3,4,5};
    int lo = 0;
    int hi = 4;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (key < forsearch[mid])
            hi = mid - 1;
        else if (key > forsearch[mid])
            lo = mid + 1;
        else
        {
            cout << mid << endl;
            break;
        }
        
        cout << "debug" <<endl;
    }
    cout<<cos(3.1415926/2)<<endl;
    return 1;
}