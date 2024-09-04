#include <iostream>
#include <stack>

using namespace std;

int n;
struct p {
	int i;
	int h;
};
stack<p> s;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int i, inp, oup;
	p tmp;
	cin >> n;
	for (i = 1; i <= n; i++) {
		oup = 0;
		cin >> inp;
		while (!s.empty()) {
			tmp = s.top();
			if (tmp.h >= inp) {
				oup = tmp.i;
				break;
			}
			s.pop();
		}
		tmp.h = inp, tmp.i = i;
		s.push(tmp);
		cout << oup << " ";
	}
	return 0;
}