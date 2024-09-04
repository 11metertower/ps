#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> adj[100001], adj_r[100001];
int check[5][100001];
int n, m, s, t;

void dfs(int menu, int loc, vector<int> v[])
{
	if (check[menu][loc])
		return;
	check[menu][loc] = 1;
	for (auto i : v[loc]) {
		dfs(menu, i, v);
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int i, x, y, ans = -2;
	cin >> n >> m;
	for (i = 1; i <= m; i++) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj_r[y].push_back(x);
	}
	cin >> s >> t;
	check[1][t] = 1;
	check[2][s] = 1;
	dfs(1, s, adj);
	dfs(2, t, adj);
	dfs(3, s, adj_r);
	dfs(4, t, adj_r);
	for (i = 1; i <= n; i++)
		if (check[1][i] && check[2][i] && check[3][i] && check[4][i])
			ans++;
	cout << ans;
	return 0;
}