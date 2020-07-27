#include <iostream>
#include <stack>
#include <fstream>
using namespace std;

template <typename T>
class mystack
{
private:
    //T *init;
    int count;
    int N;
    typedef struct Node{
        T value;
        Node *next;
    }Node, *NodePtr;
    NodePtr first;
public:
    mystack()
    {
        //init = new T[1];
        count = 0;
        N = 1;
    }
    void push(T t)
    {
        /*if (count == N)
        {
            cout << "增大栈大小" << endl;
            N *= 2;
            resize(N);
        }
        init[count++] = t;*/
        NodePtr temp = first;
        first = new Node;
        first->value = t;
        first->next = temp;
        count++;
    }
    T pop()
    {
        /*T temp = init[--count];
        if (count==N/4 && count)
        {
            cout << "减小栈大小" << endl;
            N /= 2;
            resize(N);
        }
        return temp;*/
        NodePtr t = first->next;
        T temp = first->value;
        delete first;
        first = t;
        count--;
        return temp;
    }
    int size()
    {
        return count;
    }
    bool isEmpty()
    {
        return (count == 0);
    }
    /*void resize(int n)
    {
        T *temp = new T[n];
        for (int i=0; i<count; i++)
        {
            temp[i] = init[i];
        }
        delete []init;
        init = temp;
    }*/
};

int main()
{
    mystack<int> a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    //cout << a.pop() << "\t" << a.pop() << "\t" << a.pop() << endl;
    while (!a.isEmpty())
    {
        cout << a.pop() << endl;
    }

    mystack<char> c;
    FILE *f = fopen("../data.txt", "r");
    char ch;
    while (!feof(f))
    {
        int end = fscanf(f, "%c", &ch);
        if (end == -1)
        {
            cout << "True" << endl;
            break;
        }
        cout << ch << endl;
        if (ch=='(' || ch=='[' || ch=='{')
        {
            c.push(ch);
        }
        else if (ch==')' || ch==']' || ch=='}')
        {
            if (ch==')')
            {
                if (c.pop()!='(')
                {
                    cout << "False" << endl;
                    break;
                }
            }
            else if (ch==']')
            {
                if (c.pop()!='[')
                {
                    cout << "False" << endl;
                    break;
                }
            }
            else if (ch=='}')
            {
                if (c.pop()!='{')
                {
                    cout << "False" << endl;
                    break;
                }
            }
        }
    }
}