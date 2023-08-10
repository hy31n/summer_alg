#include <iostream>
#include <string>

using namespace std;

class stack
{
private:
    int *arr;
    int head;

public:
    stack(int size)
    {
        arr = new int[size];
        head = -1;
    }

    void push(int data)
    {
        arr[++head] = data;
    }

    void pop()
    {
        head--;
    }

    int top()
    {
        return arr[head];
    }

    bool isEmpty()
    {
        return (head == -1);
    }
};

int main()
{
    stack s(100);
    string str;

    int n, m, max = 1;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> m;
        while (m >= max)
        {
            s.push(max);
            max++;
            str += "+\n";
        }

        if (m == s.top())
        {
            s.pop();
            str += "-\n";
        }
    }
    if (!s.isEmpty())
        cout << "NO" << '\n';
    else
        cout << str;
}