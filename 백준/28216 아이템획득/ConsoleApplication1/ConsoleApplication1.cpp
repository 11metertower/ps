#include <iostream>
#include <algorithm>
#include <vector>

#define MAXN 200001
using namespace std;

long long ans;
int n, q;

struct item {
	int x, y, v;
};

vector<item> mapx;
vector<item> mapy;
vector<long long> sumx;
vector<long long> sumy;

bool cmpx(item a, item b)
{
	if (a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}
bool cmpy(item a, item b)
{
	if (a.y == b.y)
		return a.x < b.x;
	return a.y < b.y;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int i, a, b, c, idx1, idx2;
	long long sum;
	item s, d;
	cin >> n >> q;
	for (i = 1; i <= n; i++) {
		cin >> a >> b >> c;
		item t;
		t.x = a, t.y = b, t.v = c;
		mapx.push_back(t);
		mapy.push_back(t);
	}
	sort(mapx.begin(), mapx.end(), cmpx);
	sort(mapy.begin(), mapy.end(), cmpy);

	sum = 0;
	sumx.push_back(0);
	sumy.push_back(0);
	for (item j : mapx) {
		sum += j.v;
		sumx.push_back(sum);
	}
	sum = 0;
	for (item j : mapy) {
		sum += j.v;
		sumy.push_back(sum);
	}

	s.x = 1, s.y = 1;
	d = s;
	for (i = 1; i <= q; i++) {
		cin >> a >> b;
		if (a == 0) {
			d.x = s.x + b;
			idx1 = upper_bound(mapy.begin(), mapy.end(), s, cmpy) - mapy.begin();
			idx2 = upper_bound(mapy.begin(), mapy.end(), d, cmpy) - mapy.begin();
			ans += sumy[idx2] - sumy[idx1];
		}
		else if (a == 1) {
			d.y = s.y + b;
			idx1 = upper_bound(mapx.begin(), mapx.end(), s, cmpx) - mapx.begin();
			idx2 = upper_bound(mapx.begin(), mapx.end(), d, cmpx) - mapx.begin();
			ans += sumx[idx2] - sumx[idx1];
		}
		else if (a == 2) {
			d.x = s.x - b;
			idx1 = lower_bound(mapy.begin(), mapy.end(), s, cmpy) - mapy.begin();
			idx2 = lower_bound(mapy.begin(), mapy.end(), d, cmpy) - mapy.begin();
			ans += sumy[idx1] - sumy[idx2];
		}
		else {
			d.y = s.y - b;
			idx1 = lower_bound(mapx.begin(), mapx.end(), s, cmpx) - mapx.begin();
			idx2 = lower_bound(mapx.begin(), mapx.end(), d, cmpx) - mapx.begin();
			ans += sumx[idx1] - sumx[idx2];
		}
		s = d;
	}
	cout << ans;
	return 0;
}