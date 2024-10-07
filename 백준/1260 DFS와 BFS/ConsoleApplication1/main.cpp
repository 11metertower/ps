#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, v;
vector<int> adj[1001];
queue<int> q;
int visit[1001];

void dfs(int curr)
{
	cout << curr << " ";
	for (auto i : adj[curr]) {
		if (!visit[i]) {
			visit[i] = 1;
			dfs(i);
		}
	}
}

void bfs(void)
{
	while (!q.empty()) {
		auto next = q.front();
		q.pop();
		cout << next << " ";
		for (auto i : adj[next]) {
			if (!visit[i]) {
				visit[i] = 1;
				q.push(i);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int i, a, b;
	cin >> n >> m >> v;
	for (i = 1; i <= m; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (i = 1; i <= n; i++)
		sort(adj[i].begin(), adj[i].end());
	visit[v] = 1;
	dfs(v);
	cout << "\n";
	memset(visit, 0, sizeof(visit));
	visit[v] = 1;
	q.push(v);
	bfs();
	return 0;
}