#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string pw;
    int size, pwsize, ans = 0, A, C, G, T;
    int cA = 0, cC = 0, cG = 0, cT = 0;

    cin >> size >> pwsize >> pw >> A >> C >> G >> T;

    for (int i = 0; i < pwsize; i++)
    {
        if (pw[i] == 'A')
        {
            cA++;
        }
        else if (pw[i] == 'C')
        {
            cC++;
        }
        else if (pw[i] == 'G')
        {
            cG++;
        }
        else if (pw[i] == 'T')
        {
            cT++;
        }
    }

    if (A <= cA && C <= cC && G <= cG && T <= cT)
    {
        ans++;
    }

    for (int i = pwsize; i < size; i++)
    {
        if (pw[i] == 'A')
        {
            cA++;
        }
        else if (pw[i] == 'C')
        {
            cC++;
        }
        else if (pw[i] == 'G')
        {
            cG++;
        }
        else if (pw[i] == 'T')
        {
            cT++;
        }

        if (pw[i - pwsize] == 'A')
        {
            cA--;
        }
        else if (pw[i - pwsize] == 'C')
        {
            cC--;
        }
        else if (pw[i - pwsize] == 'G')
        {
            cG--;
        }
        else if (pw[i - pwsize] == 'T')
        {
            cT--;
        }

        if (A <= cA && C <= cC && G <= cG && T <= cT)
        {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
