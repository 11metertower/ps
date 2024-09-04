#include <iostream>

using namespace std;

int map[101][101], map2[101][101], memo[101][101], n, m;

int count_cheese()
{
	int cnt=0, i, j;
	for(i=1;i<=n;i++) {
		for(j=1;j<=m;j++) {
			if(map[i][j])
				cnt++;
		}
	}
	return cnt;
}

void whitening()
{
	int i, j;
	for(i=1;i<=n;i++) {
		for(j=1;j<=m;j++) {
			map2[i][j]=0;
			memo[i][j]=0;
		}
	}
}

void synchronization()
{
	int i, j;
	for(i=1;i<=n;i++) {
		for(j=1;j<=m;j++) {
			if(map2[i][j]>=2)
				map[i][j]=0;
		}
	}
}

void floodfill(int x, int y)
{
	if(map[x][y]) {
        memo[x][y]=0;
		map2[x][y]++;
		return;
	}
	if(x-1>0 && !memo[x-1][y]) {
		memo[x-1][y] = 1;
		floodfill(x-1, y);
	}
	if(x+1<=n && !memo[x+1][y]) {
		memo[x+1][y] = 1;
		floodfill(x+1, y);
	}
	if(y-1>0 && !memo[x][y-1]) {
		memo[x][y-1] = 1;
		floodfill(x, y-1);
	}
	if(y+1<=m && !memo[x][y+1]) {
		memo[x][y+1] = 1;
		floodfill(x, y+1);
	}
}

int main()
{
	int i, j, current_cheese, last_cheese, time = 0;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			cin>>map[i][j];
	while(1) {
		current_cheese = count_cheese();
		if(!current_cheese)
			break;
		last_cheese = current_cheese;
		whitening();
		memo[1][1]=1;
		floodfill(1, 1);
		synchronization();
		time++;
	}
	cout<<time;
	return 0;
}
