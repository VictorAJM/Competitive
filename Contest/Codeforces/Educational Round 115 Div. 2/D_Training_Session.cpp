#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int N = 2e5+5;
pair<int,int> a[N];
long long n;
long long res = 0;
void solve()
{
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i].F >> a[i].S;
    long long res = n*(n-1)*(n-2);
    res /= 6;
    map<long long,long long> h,g;
    for (int i=0;i<n;i++) h[a[i].F]++;
    for (int i=0;i<n;i++) g[a[i].S]++;
    for (int i=0;i<n;i++) res -= (h[a[i].F]-1)*(g[a[i].S]-1);
    cout << res << "\n";
}
int main()
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t=1; cin >> t;
    while (t--) solve();
}