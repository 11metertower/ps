#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;

struct xyz {
	int x;
	int y;
	int z;
};

int n, m, h;
int mapp[101][101][101], visit[101][101][101];
int direction[3][6] = { {1, -1, 0, 0, 0, 0}, {0, 0, 1, -1, 0, 0}, {0, 0, 0, 0, 1, -1} };
queue<xyz> q;

int bfs(void)
{
	xyz cur, next;
	int x, y, z, cnt = 0;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		for (int i = 0; i < 6; i++) {
			x = cur.x + direction[0][i], y = cur.y + direction[1][i], z = cur.z + direction[2][i];
			if (x < 1 || x > n || y < 1 || y > m || z < 1 || z > h || visit[x][y][z] == 1 || mapp[x][y][z] == -1)
				continue;
			mapp[x][y][z] = mapp[cur.x][cur.y][cur.z] + 1;
			visit[x][y][z] = 1;
			next.x = x, next.y = y, next.z = z;
			q.push(next);
		}
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int i, j, k, ans = 0, minus = 0, cnt_cur = -1, cnt_bef = -1, one = 0;
	xyz tmp;
	cin >> m >> n >> h;
	for (k = 1; k <= h; k++) {
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= m; j++) {
				cin >> mapp[i][j][k];
				if (mapp[i][j][k] == 1) {
					visit[i][j][k] = 1;
					tmp.x = i, tmp.y = j, tmp.z = k;
					q.push(tmp);
				}
			}
		}
	}

	bfs();

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			for (k = 1; k <= h; k++) {
				if (mapp[i][j][k] == 0) {
					cout << "-1";
					return 0;
				}
				ans = max(ans, mapp[i][j][k]);
			}
		}
	}
	cout << ans - 1;
	return 0;
}