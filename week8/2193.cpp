#include <iostream>
using namespace std;
int main()
{
	long long n, dp[91]={0,1,1};
	cin >> n;
	for(int i=3;i<=n;i++) dp[i] = dp[i-1] + dp[i-2];
	cout << dp[n] << '\n';
}