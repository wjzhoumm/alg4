#include <iostream>
using namespace std;

template <typename T>
class myqueue
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
    NodePtr last;
public:
    myqueue()
    {
        //init = new T[1];
        //first = NULL;
        //last = NULL;
        count = 0;
    }
    void push(T t)
    {
        NodePtr oldlast = last;
        last = new Node;
        last->value = t;
        last->next = NULL;
        if (this->isEmpty())
        {
            first = last;
        }
        else
        {
            oldlast->next = last;
        }
        count++;
        
    }
    T pop()
    {
        if (!isEmpty())
        {
            NodePtr oldsecond = first->next;
            T temp = first->value;
            delete first;
            first = oldsecond;
            if (isEmpty())
            {
                last = NULL;
            }
            count--;
            return temp;
        }
        else
        {
            cout << "队列已空" << endl;
            return -1;
        }
        
    }
    int size()
    {
        return count;
    }
    bool isEmpty()
    {
        return (first == NULL);
    }
};

int main()
{
    myqueue<int> a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    //cout << a.pop() << "\t" << a.pop() << "\t" << a.pop() << endl;
    while (!a.isEmpty())
    {
        cout << a.pop() << endl;
    }
    cout << a.pop() << endl;
}