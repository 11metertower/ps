#include <iostream>
#include <queue>
#include <map>

using namespace std;

typedef long long ll;

struct xy {
	ll a;
	ll b;
};

int n, k;
ll a[300001];
queue<xy> q;
map<ll, bool> visit;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll l;
	xy tmp, tmp2;
	int n, k, i, cnt;
	cin >> l >> n >> k;
	for (i = 1; i <= n; i++) {
		cin >> a[i];
		visit[a[i]] = 1;
		tmp.a = a[i], tmp.b = 0;
		q.push(tmp);
	}
	
	if (n >= k) {
		for (i = 1; i <= k; i++)
			cout << "0\n";
		return 0;
	}

	cnt = k;

	while (!q.empty()) {
		tmp = q.front();
		q.pop();
		cout << tmp.b << "\n";
		if (--cnt == 0)
			break;
		if (visit.count(tmp.a - 1) == 0 && tmp.a - 1 >= 0) {
			visit[tmp.a - 1] = 1;
			tmp2.a = tmp.a - 1, tmp2.b = tmp.b + 1;
			q.push(tmp2);
		}
		if (visit.count(tmp.a + 1) == 0 && tmp.a + 1 <= l) {
			visit[tmp.a + 1] = 1;
			tmp2.a = tmp.a + 1, tmp2.b = tmp.b + 1;
			q.push(tmp2);
		}
	}
	return 0;
}