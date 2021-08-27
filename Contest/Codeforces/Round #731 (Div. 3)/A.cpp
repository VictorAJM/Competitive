#include <bits/stdc++.h>

#define fast_io cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define F first
#define S second

using namespace std;

const int mod = 1e9+7;
const int N = 2e5+5;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

void solve()
{
    int n,pa,pb,da,db,fa,fb;

    cin >> pa >> pb;
    cin >> da >> db;
    cin >> fa >> fb;
    int r = abs(pa-da) + abs(pb-db);
    if (pa == da && fa == da && ((pb <= fb && fb <= db) || (db <= fb && fb <= pb))) r += 2;
    else if (pb == db && fb == db && ((pa <= fa && fa <= da) || (da <= fa && fa <= pa))) r += 2;
    cout << r << "\n";
    return; 
}

int main()
{
    fast_io;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}