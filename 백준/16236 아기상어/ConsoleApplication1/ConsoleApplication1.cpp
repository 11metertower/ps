#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;

struct xy {
	int x;
	int y;
	int d;
};

int n, big = 2, bigcnt = 0, flag = 0;
int mapp[21][21], visit[21][21];
int direction[2][4] = { {-1, 0, 0, 1}, {0, -1, 1, 0} };
xy loc;
queue<xy> q;

void flush(void)
{
	flag = 0;
	memset(visit, 0, sizeof(visit));
	while (!q.empty())
		q.pop();
}

int bfs(void)
{
	xy cur, next;
	int x, y, cnt = 0;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		if (flag != 0 && cur.d + 1 > flag) {
			mapp[loc.x][loc.y] = 0;
			return loc.d;
		}
		for (int i = 0; i < 4; i++) {
			x = cur.x + direction[0][i], y = cur.y + direction[1][i];
			if (x < 1 || x > n || y < 1 || y > n || visit[x][y] == 1 || mapp[x][y] > big)
				continue;
			if (mapp[x][y] != 0 && mapp[x][y] < big && (flag == 0 || loc.x > x || (loc.x == x && loc.y > y))) {
				loc.x = x, loc.y = y, loc.d = cur.d + 1;
				flag = cur.d + 1;
			}
			visit[x][y] = 1;
			next.x = x, next.y = y, next.d = cur.d + 1;
			q.push(next);
		}
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int i, j, ans = 0, tmp;
	cin >> n;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			cin >> mapp[i][j];
			if (mapp[i][j] == 9) {
				mapp[i][j] = 0;
				loc.x = i, loc.y = j, loc.d = 0;
			}
		}
	}
	while (1) {
		flush();
		q.push(loc);
		visit[loc.x][loc.y] = 1;
		tmp = bfs();
		if (tmp == -1)
			break;
		ans += tmp;
		bigcnt++;
		if (bigcnt == big) {
			bigcnt = 0;
			big++;
		}
		loc.d = 0;
	}
	cout << ans;
	return 0;
}