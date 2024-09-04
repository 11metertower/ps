#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

struct xy {
	int x;
	int y;
};

int n, m, cnt1, cnt2;
int mapp[301][301], visit[301][301], zero[301][301];

xy many()
{
	int i, j;
	xy ret;
	for (i = 2; i < n; i++) {
		for (j = 2; j < m; j++) {
			if (mapp[i][j] != 0) {
				if (cnt1 == 0) {
					ret.x = i, ret.y = j;
				}
				cnt1++;
			}
		}
	}
	return ret;
}

void dfs(int x, int y)
{
	cnt2++;
	if (x - 1 >= 1) {
		if (mapp[x - 1][y] == 0)
			zero[x][y]++;
		else if (visit[x - 1][y] == 0) {
			visit[x - 1][y] = 1;
			dfs(x - 1, y);
		}
	}
	if (x + 1 <= n) {
		if (mapp[x + 1][y] == 0)
			zero[x][y]++;
		else if (visit[x + 1][y] == 0) {
			visit[x + 1][y] = 1;
			dfs(x + 1, y);
		}
	}
	if (y - 1 >= 1) {
		if (mapp[x][y - 1] == 0)
			zero[x][y]++;
		else if (visit[x][y - 1] == 0) {
			visit[x][y - 1] = 1;
			dfs(x, y - 1);
		}
	}
	if (y + 1 <= m) {
		if (mapp[x][y + 1] == 0)
			zero[x][y]++;
		else if (visit[x][y + 1] == 0) {
			visit[x][y + 1] = 1;
			dfs(x, y + 1);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int i, j, ans = 0;
	xy tmp;
	cin >> n >> m;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			cin >> mapp[i][j];

	while (1) {
		cnt1 = 0, cnt2 = 0;
		memset(visit, 0, sizeof(visit));
		memset(zero, 0, sizeof(zero));
		tmp = many();
		if (cnt1 == 0) {
			cout << "0";
			return 0;
		}
		visit[tmp.x][tmp.y] = 1;
		dfs(tmp.x, tmp.y);
		if (cnt1 != cnt2) {
			cout << ans;
			return 0;
		}
		for (i = 2; i < n; i++) {
			for (j = 2; j < m; j++) {
				if (zero[i][j] >= mapp[i][j])
					mapp[i][j] = 0;
				else mapp[i][j] -= zero[i][j];
			}
		}
		ans++;
	}
	return 0;
}