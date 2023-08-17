#include <iostream>
#include <algorithm>

using namespace std;

int n, m, arr[100001], cnt;
int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    
    int min = 0, max = n - 1;

    while (min < max)
    {
        if (arr[min] + arr[max] == m)
        {
            min++;
            max--;
            cnt++;
        }
        else if (arr[min] + arr[max] < m)
        {
            min++;
        }
        else
        {
            max--;
        }
    }
    cout << cnt;
    return 0;
}
