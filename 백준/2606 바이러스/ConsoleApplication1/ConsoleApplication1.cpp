#include <iostream>
#include <cmath>
#include <vector>

#define MAXN 101
using namespace std;

vector<int> adj[MAXN];

int visit[MAXN];
int n, ans;

void dfs(int here)
{
	for (int next : adj[here]) {
		if (!visit[next]) {
			ans++;
			visit[next] = 1;
			dfs(next);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int i, k, a, b;
	cin >> n >> k;
	for (i = 1; i <= k; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	visit[1] = 1;
	dfs(1);
	cout << ans;
	return 0;
}