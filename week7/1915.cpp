#include <iostream>
#include <cmath>

using namespace std;

static int n, m;
static int dp[1001][1001];

int main(){
	cin >> n >> m;
	long max = 0;
	
	for (int i = 0; i <n; i++){
		string line;
		cin >> line;
		for(int j = 0; j < m; j++){
			dp[i][j] = line[j]-'0';
			if(dp[i][j]==1 && j >0 && i>0){
				dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
			}
			if(max <dp[i][j]){
				max = dp[i][j];
			}
		}
	}
	cout << max * max << "\n";
}