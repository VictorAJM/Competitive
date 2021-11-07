#include <bits/stdc++.h>
#define fast_io cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
void solve(int Case)
{
    long long x,y;
    cin  >> x >> y;
    if (x>y) cout << x+y <<"\n";
    else cout << ((y/x)*x+y)/2 << "\n";
}
int main()
{
    fast_io;
    int tt = 1, Case = 0;
    cin >> tt;
    while (tt--) solve(++Case);
    return 0;
}