#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int A[50];
    int B[50];
    int check[50] = {
        0,
    };

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++)
    {
        cin >> B[i];
    }

    check[N] = {
        0,
    };
    sort(A, A + N);

    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        int temp = 0;
        int idx = 0;
        for (int i = 0; i < N; i++)
        {
            if (temp < B[i] && check[i] == 0)
            {
                temp = B[i];
                idx = i;
            }
        }
        check[idx] = 1;
        sum += A[i] * temp;
    }

    cout << sum;

    return 0;
}