#include <iostream>
#include <string.h>
#include <cmath>
#include <vector>

using namespace std;

int r, c, ix, iy;
int mapp[101][101], visit[101][101];
int direct[10][2] = { {0,0},{1,-1},{1,0},{1,1},{0,-1},{0,0},{0,1},{-1,-1},{-1,0},{-1,1} };
struct xy {
	int x;
	int y;
};
vector<xy> loc;

xy what_direct(int x, int y)
{
	int i, minn = 0x7fffffff, tmp, ret;
	xy re;
	for (i = 1; i <= 9; i++) {
		tmp = abs(x + direct[i][0] - ix) + abs(y + direct[i][1] - iy);
		if (tmp < minn) {
			minn = tmp;
			ret = i;
		}
	}
	re.x = x + direct[ret][0], re.y = y + direct[ret][1];
	return re;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int i, j, k, len, mov;
	char inp[102];
	xy tmp;
	cin >> r >> c;
	for (i = 1; i <= r; i++) {
		cin >> inp;
		for (j = 1; j <= c; j++) {
			if (inp[j - 1] == 'I') {
				mapp[i][j] = 1;
				ix = i, iy = j;
			}
			else if (inp[j - 1] == 'R') {
				mapp[i][j] = 2;
			}
		}
	}
	cin >> inp;
	len = strlen(inp);
	for (i = 1; i <= len; i++) {
		mov = inp[i - 1] - '0';
		mapp[ix][iy] = 0;
		if (mapp[ix + direct[mov][0]][iy + direct[mov][1]] == 2) {
			cout << "kraj " << i;
			return 0;
		}
		ix += direct[mov][0];
		iy += direct[mov][1];
		mapp[ix][iy] = 1;
		memset(visit, 0, sizeof(visit));
		for (j = 1; j <= r; j++) {
			for (k = 1; k <= c; k++) {
				if (mapp[j][k] == 2) {
					mapp[j][k] = 0;
					tmp = what_direct(j, k);
					if (mapp[tmp.x][tmp.y] == 1) {
						cout << "kraj " << i;
						return 0;
					}
					if (visit[tmp.x][tmp.y] == 1)
						loc.push_back(tmp);
					else
						visit[tmp.x][tmp.y] = 1;
				}
			}
		}
		while (!loc.empty()) {
			tmp = loc.back();
			loc.pop_back();
			visit[tmp.x][tmp.y] = 0;
		}
		for (j = 1; j <= r; j++) {
			for (k = 1; k <= c; k++) {
				if (visit[j][k] == 1)
					mapp[j][k] = 2;
			}
		}
	}
	for (i = 1; i <= r; i++) {
		for (j = 1; j <= c; j++) {
			if (mapp[i][j] == 0)
				cout << ".";
			else if (mapp[i][j] == 1)
				cout << "I";
			else cout << "R";
		}
		cout << "\n";
	}
	return 0;
}