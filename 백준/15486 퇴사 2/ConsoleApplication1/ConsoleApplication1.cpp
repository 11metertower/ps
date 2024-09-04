#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[1500001], t[1500001], p[1500001];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int i;
	cin >> n;
	for (i = 1; i <= n; i++)
		cin >> t[i] >> p[i];
	for (i = 1; i <= n; i++) {
		a[i] = max(a[i], a[i - 1]);
		if (i + t[i] - 1 <= n)
			a[i + t[i] - 1] = max(a[i + t[i] - 1], a[i - 1] + p[i]);
	}
	cout << a[n];
	return 0;
}