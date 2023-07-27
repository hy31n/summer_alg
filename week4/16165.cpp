#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int main()
{
    int N, M;
    vector<string>::iterator iter;

    string gName;

    map<string, vector<string>> group;

    map<string, string> member;

    cin >> N;
    cin >> M;

    for (int i = 0; i < N; i++)
    {
        int num;
        string name;
        vector<string> mem;
        cin >> gName >> num;

        for (int j = 0; j < num; j++)
        {
            cin >> name;
            mem.push_back(name);
            member.insert(make_pair(name, gName));
        }
        sort(mem.begin(), mem.end());
        group.insert(make_pair(gName, mem));
    }

    for (int i = 0; i < M; i++)
    {
        string p;
        int type;

        cin >> p >> type;
        if (type == 1)
        {
            cout << member[p] << endl;
        }
        else
        {
            for (iter = group[p].begin(); iter != group[p].end(); iter++)
            {
                cout << *iter << endl;
            }
        }
    }

    return 0;
}