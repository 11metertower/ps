#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int n, m;
char list[16][21], super_dna[2000][21];

void merge(int index, char a[], char b[])
{
    int i;
    char ret[21];
    if (b == "") {
        super_dna[index] = "";
        return;
    }
    for (i = 0; i < m; i++) {
        if (a[i] == '.' && b[i] != '.')
            ret[i] = b[i];
        else if (a[i] != '.' && b[i] == '.')
            ret[i] = a[i];
        else if (a[i] == '.' && b[i] == '.')
            ret[i] = '.';
        else {
            ret = "";
            break;
        }
    }
    super_dna[index] = ret;
}

void gen_super(int index)
{
    int i, tmp = index, loc = 0;
    while (tmp % 2 == 0) {
        loc++;
        tmp /= 2;
    }
    cout << "index:" << index << "\n" << list[loc + 1] << "\n" << super_dna[index - int(pow(2, loc))] << endl;
    merge(index, list[loc + 1], super_dna[index - int(pow(2, loc - 1))]);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int i, j, t;
    cin >> n >> m;
    for (i = 1; i <= n; i++)
        cin >> list[i];

    t = pow(2, n) - 1;

    for (i = 0; i < m; i++)
        super_dna[0][i] = '.';
    for (i = 1; i <= t; i++) {
        gen_super(i);
        cout << super_dna[i];
    }
    return 0;
}