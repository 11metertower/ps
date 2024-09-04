#include <iostream>
#include <algorithm>
typedef long long ll;

using namespace std;

int n, k;
ll dp[1001][1001];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int i, j;
	cin >> n >> k;
	for (i = 1; i <= n; i++)
		dp[i][0] = 1;
	dp[2][1] = 2, dp[3][1] = 3;
	for (i = 4; i <= n; i++) {
		for (j = 1; j <= i/2; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i - 2][j - 1]) % 1000000003;
		}
	}
	cout << dp[n][k];
	return 0;
}