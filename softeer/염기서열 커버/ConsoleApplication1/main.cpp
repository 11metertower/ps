#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

char list[16][21];
int dp[21][21], check[16];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, i, j, k, flag, ans, cnt = 0;
	cin >> n >> m;
	ans = n;
	for (i = 1; i <= n; i++)
		cin >> list[i];

	for (i = 1; i < n; i++) {
		for (j = i + 1; j <= n; j++) {
			flag = 0;
			for (k = 0; k < m; k++) {
				if (list[i][k] == '.' || list[j][k] == '.' || list[i][k] == list[j][k])
					continue;
				flag = 1;
				break;
			}
			if (!flag) {
				dp[i][j] = 1;
				dp[j][i] = 1;
			}
		}
	}

	for (i = 1; i < n; i++) {
		for (j = i + 1; j <= n; j++) {
			if (dp[i][j]) {
				if (!check[i] && !check[j]) {
					ans--;
					cnt++;
					check[i] = cnt;
					check[j] = cnt;
				}
				else if (check[i] && !check[j]) {
					flag = 0;
					for (k = 1; k <= n; k++) {
						if (check[i] == check[k]) {
							if (!dp[j][k]) {
								flag = 1;
								break;
							}
						}
					}
					if (!flag) {
						ans--;
						check[j] = check[i];
					}
					else
						check[j] = ++cnt;
				}
				else if (!check[i] && check[j]) {
					flag = 0;
					for (k = 1; k <= n; k++) {
						if (check[j] == check[k]) {
							if (!dp[i][k]) {
								flag = 1;
								break;
							}
						}
					}
					if (!flag) {
						ans--;
						check[i] = check[j];
					}
					else
						check[i] = ++cnt;
				}
			}
		}
	}

	cout << ans;
	return 0;
}