#include <iostream>

using namespace std;

int rule[20001];

int gcd(int a, int b)
{
    if(b==0)
        return a;
    return gcd(b, a%b);
}

int lcm(int a, int b)
{
    int g = gcd(a, b);
    return a/g*b;
}

int find(int level, int a, int b)
{
    if(a==rule[b])
    {
        return level;
    }
    return find(level+1, a, rule[b]);
}

int main()
{
	int n, i, a;
	cin>>n;
	for(i=1;i<=n;i++)
        cin>>rule[i];
    a=find(1, 1, 1);
    for(i=2;i<=n;i++)
    {
        a=lcm(a, find(1, i, i));
    }
    cout<<a;
	return 0;
}
