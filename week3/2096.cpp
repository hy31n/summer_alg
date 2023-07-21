#include <iostream>
using namespace std;

int n;
int arr[3];
int max_dp[3] = {0};
int min_dp[3] = {0};

int min(int a, int b)
{
    if (a > b)
    {
        return b;
    }
    return a;
}

int max(int a, int b)
{
    if (a < b)
    {
        return b;
    }
    return a;
}

int main()
{
    cin >> n;
    int temp0;
    int temp1;
    int temp2;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[0] >> arr[1] >> arr[2];

        temp0 = min_dp[0];
        temp1 = min_dp[1];
        temp2 = min_dp[2];

        min_dp[0] = min(temp0, temp1) + arr[0];
        min_dp[2] = min(temp1, temp2) + arr[2];
        min_dp[1] = min(min(temp0, temp1), temp2) + arr[1];

        temp0 = max_dp[0];
        temp1 = max_dp[1];
        temp2 = max_dp[2];

        max_dp[0] = max(temp0, temp1) + arr[0];
        max_dp[2] = max(temp0, temp2) + arr[2];
        max_dp[1] = max(max(temp0, temp1), temp2) + arr[1];
    }
    cout << max(max(max_dp[0], max_dp[1]), max_dp[2]) << " " << min(min(min_dp[0], min_dp[1]), min_dp[2]);
    return 0;
}