#include <bits/stdc++.h>

#define fast_io cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define F first
#define S second

using namespace std;

const int mod=0;
const int N=1e5+10000;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
ll n,a[2][N],dp[2][N][2];
void solve()
{
    cin >> n;
    for (int i=1;i<=2;i++) for (int j=1;j<=n;j++) cin >> a[i][j];
    for (int i=1;i<=2;i++) for (int j=0;j<=n+2;j++) for (int k=1;k<=2;k++)dp[i][j][k] = 0;
    for (int i=1;i<=2;i++) for (int j=1;j<=n;j++) dp[i][j][1] = dp[i][j-1][1] + a[i][j];
    for (int i=1;i<=2;i++) for (int j=n;j>=1;j--) dp[i][j][2] = dp[i][j+1][2] + a[i][j];
    ll A,B;
    B = 2000000000;
    for (int j=1;j<=n;j++) {
        ll k = max(dp[2][j-1][1],dp[1][j+1][2]);
        ll p = dp[1][j][1] + dp[2][j][2];
        //cerr << p << " "<<k<<"\n";
        if (k < B) {
            A = p;
            B = k;
        }
    }
    cout <<B <<"\n";
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