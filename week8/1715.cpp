#include <iostream>
#include <queue>
#include <functional>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    priority_queue<int, vector<int>, greater<>> pq;
    int N;
    int sum = 0;
    cin >> N;
 
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        pq.push(num);
    }
 
    while (1) {

        if (pq.size() == 1) {
            cout << sum;
            break;
        }
        int temp1, temp2;
        temp1 = pq.top();
        pq.pop();
        temp2 = pq.top();
        pq.pop();
        int tempsum = temp1 + temp2;
        sum += tempsum;
        pq.push(tempsum);
    }
    return 0;
}
