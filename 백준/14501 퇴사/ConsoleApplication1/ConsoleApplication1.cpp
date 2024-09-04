#include <iostream>
#include <algorithm>

using namespace std;

int visit[17], arr[17][2];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int i, n, a, b, ans = 0, j, cnt;
	cin >> n;
	for (i = 1; i <= n; i++)
		cin >> arr[i][0] >> arr[i][1];

	for (i = 1; i <= n; i++) {
		j = i;
		if (visit[i])
			continue;
		cnt = 0;
		while (1) {
			cnt += arr[j][1];
			j += arr[j][0];
			if (visit[j])
				break;
			if (j == n) {
				if (arr[j][0] == 1)
					cnt += arr[j][1];
				visit[j] = 1;
				ans = max(ans, cnt);
				break;
			}
			if (j > n) {
				if (j == n + 1)
					ans = max(ans, cnt);
				break;
			}
			visit[j] = 1;
			ans = max(ans, cnt);
		}
	}
	cout << ans;
	return 0;
}