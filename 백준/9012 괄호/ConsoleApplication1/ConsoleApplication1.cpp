#include <iostream>
#include <stack>
#include <string.h>

using namespace std;

stack<char> st;
char s[252];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t, tc, i, len, flag;
	cin >> t;
	for (tc = 1; tc <= t; tc++) {
		while (!st.empty())
			st.pop();
		flag = 0;
		cin >> s;
		len = strlen(s);
		for (i = 0; i < len; i++) {
			if (s[i] == '(')
				st.push(s[i]);
			else {
				if (st.empty()) {
					flag = 1;
					break;
				}
				st.pop();
			}
		}
		if (!st.empty())
			flag = 1;
		if (flag) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
	}
	return 0;
}