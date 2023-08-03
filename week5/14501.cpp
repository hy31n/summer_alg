#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int i, j;
    int l[18], c[18], r[18] = {
                          0,
                      };

    cin >> i;
    for (j = 1; j <= i; j++)
    {
        cin >> l[j] >> c[j];
    }

    for (j = i; j > 0; j--)
    {
        if (l[j] > i - j + 1)
            r[j] = r[j + 1];
        else
            r[j] = max(c[j] + r[j + l[j]], r[j + 1]);
    }

    cout << r[1];
}