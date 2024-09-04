#include<iostream>
#include<cmath>
using namespace std;

int m,n,l;
int fire[100001],animal[100001][2];

int main()
{
	int i,j,ans=0,minf=0x7fffffff,maxf=0;
	cin>>m>>n>>l;
	for(i=1;i<=m;i++)
    {
		cin>>fire[i];
    }
	for(i=1;i<=n;i++)
    {
		cin>>animal[i][0]>>animal[i][1];
		if(animal[i][1]>l)
            continue;
		minf=animal[i][0]-(l-animal[i][1]);
		maxf=animal[i][0]+(l-animal[i][1]);
		for(j=1;j<=m;j++)
        {
            if(fire[j]>=minf && fire[j]<=maxf)
            {
                ans++;
                break;
            }
        }
    }
	cout<<ans;
	return 0;
}
