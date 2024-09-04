#include <iostream>
#include <string.h>
#include <stack>

using namespace std;

stack<double> st;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, i, len, l[28];
	char c, s[100];
	double inp, a, b;
	cin >> n;
	cin >> s;
	len = strlen(s);
	for (i = 0; i < n; i++)
		cin >> l[i];
	for (i = 0; i < len; i++) {
		c = s[i];
		if (c == '*' || c == '/' || c == '-' || c == '+') {
			b = st.top();
			st.pop();
			a = st.top();
			st.pop();
			if (c == '*')
				st.push(a * b);
			else if (c == '/')
				st.push(a / b);
			else if (c == '-')
				st.push(a - b);
			else
				st.push(a + b);
		}
		else {
			inp = l[c - 'A'];
			st.push(inp);
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << st.top();
	return 0;
}