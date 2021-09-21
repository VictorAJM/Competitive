#include <bits/stdc++.h>

#define fast_io cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define F first
#define S second

using namespace std;

const int mod=1e9+7;
const int N=1e5+5;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
ll k,dp[N];
ll acu[N],a,b;
void solve()
{
    cin >> a >> b;
    ll x = acu[b];
    x -= acu[a-1];
    if (x < 0) x += mod;
    cout << x << "\n";
    return;
}

int main()
{
    fast_io;
    int t = 1;
    cin >> t >> k; dp[0] = 1;
    for (int i=1;i<=100000;i++) {
        dp[i] = dp[i-1];
        if (i-k>=0) dp[i] += dp[i-k];
        dp[i] %= mod;
    }
    acu[0] = dp[0];
    for (int i=1;i<=100000;i++) {
        acu[i] = dp[i] + acu[i-1];
        acu[i] %= mod;
    }
    while (t--) {
        solve();
    }
    return 0;
}
