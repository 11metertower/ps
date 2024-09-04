#include <iostream>
#include <vector>
#include <algorithm>

#define MAXN 15001
using namespace std;

int arr[MAXN];
int n, m, ans;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int i, j, rem = 0;
	cin >> n >> m;
	for (i = 1; i <= n; i++)
		cin >> arr[i];
	sort(arr + 1, arr + n + 1);
	for (i = n; i >= 1; i--) {
		for (j = rem + 1; j <= n; j++) {
			if (i <= j || arr[i] + arr[j] > m)
				break;
			if (arr[i] + arr[j] == m) {
				ans++;
				rem = j;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}