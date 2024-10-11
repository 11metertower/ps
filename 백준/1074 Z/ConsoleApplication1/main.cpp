#include <iostream>

using namespace std;

int n, r, c;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int i, sx, sy, tx, ty, ans = 0;
	cin >> n >> r >> c;
	r++, c++;
	sx = 1, sy = 1, tx = 1 << n, ty = 1 << n;
	while (sx != tx && sy != ty) {
		if ((sx + tx) / 2 >= r) {
			if ((sy + ty) / 2 >= c) {
				tx = ((tx + sx - 1) / 2);
				ty = ((ty + sy - 1) / 2);
			}
			else {
				ans += ((tx - sx + 1) / 2) * ((tx - sx + 1) / 2);
				sy = ((ty + sy - 1) / 2) + 1;
				tx = ((tx + sx - 1) / 2);
			}
		}
		else {
			if ((sy + ty) / 2 >= c) {
				ans += ((tx - sx + 1) / 2) * ((tx - sx + 1) / 2) * 2;
				sx = ((tx + sx - 1) / 2) + 1;
				ty = ((ty + sy - 1) / 2);
			}
			else {
				ans += ((tx - sx + 1) / 2) * ((tx - sx + 1) / 2) * 3;
				sx = ((tx + sx - 1) / 2) + 1;
				sy = ((ty + sy - 1) / 2) + 1;
			}
		}
	}
	cout << ans;
	return 0;
}