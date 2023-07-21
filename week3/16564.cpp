#include <iostream>
#include <algorithm>
using namespace std;

long long X[1000001];
long long N, K, tmp, n, dif, ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    for (int i = 0; i < N; i++)
        cin >> X[i];

    sort(X, X + N);

    while (true)
    {
        tmp = X[0];
        n = upper_bound(X, X + N, tmp) - X;

        if (n == N)
        {
            ans = tmp + K / n;
            break;
        }

        dif = X[n] - tmp;

        if (dif * n <= K)
        {
            X[0] += dif;
        }
        else
        {
            ans = tmp + K / n;
            break;
        }

        K -= dif * n;
    }

    cout << ans << '\n';
}