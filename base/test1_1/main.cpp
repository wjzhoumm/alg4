#include <iostream>

using namespace std;

int main()
{
    cout<<"请输入整型参数N:"<<endl;
    int N;
    cin>>N;
    int n=1;
    int i=0;
    for (i=0; n<=N; i++)
    {
        n *= 2;
    }
    cout<<i-1<<endl;
}