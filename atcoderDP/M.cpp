#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
typedef long long ll;
ll dp[105][100005],a[105],n,k;
int main()
{
    cin >> n >> k;
    for (int i=0;i<n;i++)
        cin >> a[i];
    dp[n][0] = 1;
    for (int i=n-1;i>=0;i--) {
        ll res = 0;
        for (int j=0;j<=k;j++) {
            res += dp[i+1][j];
            if (j > a[i]) res -= dp[i+1][j-a[i]-1];
            if (res < 0) res += mod;
            res %= mod;
            dp[i][j] = res;
        }
    }
    ll ans = 0;
    cout << dp[0][k] << "\n";
    return 0;
}
