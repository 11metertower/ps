#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct xy {
	int level;
	int x;
	int y;
};

queue<xy> q;

int direction[8][2] = { {1, 2},{2, 1},{1, -2},{-1, 2},{-1, -2},{2, -1},{-2, 1},{-2, -1} };
int memo[301][301];

int bfs(int l, int x1, int y1, int x2, int y2)
{
	int i, x, y;
	xy tmp, tmp2;
	while (!q.empty()) {
		tmp = q.front();
		q.pop();
		if (tmp.x == x2 && tmp.y == y2)
			return tmp.level;
		for (i = 0; i < 8; i++) {
			x = tmp.x + direction[i][0];
			y = tmp.y + direction[i][1];
			if (memo[x][y] == 0 && x < l && y < l && x >= 0 && y >= 0) {
				memo[x][y] = 1;
				tmp2.level = tmp.level + 1;
				tmp2.x = x, tmp2.y = y;
				q.push(tmp2);
			}
		}
	}
}

int main()
{
	int t, i, l, a, b, c, d;
	xy tmp;
	cin >> t;
	for (i = 1; i <= t; i++) {
		while (!q.empty())
			q.pop();
		memset(memo, 0, sizeof(memo));
		cin >> l;
		cin >> a >> b >> c >> d;
		tmp.level = 0, tmp.x = a, tmp.y = b;
		memo[a][b] = 1;
		q.push(tmp);
		cout << bfs(l, a, b, c, d) << endl;
	}
	return 0;
}