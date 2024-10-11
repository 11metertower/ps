#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int n, m;
long long distant[501];
struct edge {
	int start;
	int end;
	long long cost;
};
vector<edge> edges;

bool bf(void)
{
	int i;
	for (i = 1; i < n; i++) {
		for (auto tmp : edges) {
			int curr = tmp.start, next = tmp.end;
			long long cost = tmp.cost;
			if (distant[next] > distant[curr] + cost && distant[curr] != 0x7fffffffffffffff)
				distant[next] = distant[curr] + cost;
		}
	}
	for (auto tmp : edges) {
		int curr = tmp.start, next = tmp.end;
		long long cost = tmp.cost;
		if (distant[next] > distant[curr] + cost && distant[curr] != 0x7fffffffffffffff) {
			distant[next] = distant[curr] + cost;
			return false;
		}
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);
	int i, a, b, c;
	edge tmp;
	cin >> n >> m;
	for (i = 1; i <= m; i++) {
		cin >> a >> b >> c;
		tmp.start = a, tmp.end = b, tmp.cost = c;
		edges.push_back(tmp);
	}
	for (i = 1; i <= n; i++)
		distant[i] = 0x7fffffffffffffff;
	distant[1] = 0;
	bool ans = bf();
	if (!ans) {
		cout << "-1";
		return 0;
	}
	for (i = 2; i <= n; i++) {
		if (distant[i] == 0x7fffffffffffffff)
			cout << "-1\n";
		else
			cout << distant[i] << '\n';
	}
	return 0;
}