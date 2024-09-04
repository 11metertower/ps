//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, k;
int first[51][51], a[51][51], b[51][51], rcs[7][4], turn[721][7], tcnt = 0;

void rotate(int r, int c, int s)
{
	int i, j, cnt;
	b[r][c] = a[r][c];
	cnt = 0;
	for (i = r - s; i <= r - 1; i++) {
		cnt++;
		for (j = c - s + cnt; j <= c + s - cnt + 1; j++)
			b[i][j] = a[i][j - 1];
	}

	cnt = 0;
	for (j = c - s; j <= c - 1; j++) {
		cnt++;
		for (i = r + s - cnt; i >= r - s + cnt - 1; i--)
			b[i][j] = a[i + 1][j];
	}

	cnt = 0;
	for (i = r + s; i >= r + 1; i--) {
		cnt++;
		for (j = c + s - cnt; j >= c - s + cnt - 1; j--)
			b[i][j] = a[i][j + 1];
	}

	cnt = 0;
	for (j = c + s; j >= c + 1; j--) {
		cnt++;
		for (i = r - s + cnt; i <= r + s - cnt + 1; i++)
			b[i][j] = a[i - 1][j];
	}
	
	for (i = r - s; i <= r + s; i++)
		for (j = c - s; j <= c + s; j++)
			a[i][j] = b[i][j];
}

void make_turn(int level, int* arr)
{
	int i;
	if (level == k) {
		tcnt++;
		for (i = 1; i <= k; i++)
			turn[tcnt][arr[i]] = i;
		return;
	}
	for (i = 1; i <= k; i++) {
		if (arr[i] == 0) {
			arr[i] = level + 1;
			make_turn(level + 1, arr);
			arr[i] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);
	int i, j, l, r, c, s, sum, minn, ans = 0x7fffffff;
	cin >> n >> m >> k;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			cin >> first[i][j];

	for (i = 1; i <= k; i++) {
		int arr[7] = { 0, };
		arr[i] = 1;
		cin >> rcs[i][1] >> rcs[i][2] >> rcs[i][3];
		make_turn(1, arr);
	}

	for (i = 1; i <= tcnt; i++) {
		for (j = 1; j <= n; j++)
			for (l = 1; l <= m; l++)
				a[j][l] = first[j][l];
		for (j = 1; j <= k; j++) {
			r = rcs[turn[i][j]][1], c = rcs[turn[i][j]][2], s = rcs[turn[i][j]][3];
			rotate(r, c, s);
		}
		minn = 0x7fffffff;
		for (j = 1; j <= n; j++) {
			sum = 0;
			for (l = 1; l <= m; l++) {
				sum += a[j][l];
			}
			minn = min(minn, sum);
		}
		ans = min(ans, minn);
	}

	cout << ans;
	return 0;
}