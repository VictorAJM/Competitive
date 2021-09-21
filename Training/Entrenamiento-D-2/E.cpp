// Problem: E - Counting Rectangles is Fun
// Contest: Virtual Judge - Entrenamiento ICPC - D (2)
// URL: https://vjudge.net/contest/457955#problem/E
// Memory Limit: 262 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define fast_io cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define F first
#define S second

using namespace std;

const int mod=0;
const int N=42;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int n,m,q,dp[N][N],dp1[N][N][N][N],dp2[N][N][N][N];
char a[N][N];
void solve()
{
	cin >> n >> m >> q;
	for (int i=0;i<n;i++) for (int j=0;j<m;j++) cin >> a[i][j];
	for (int i=n-1;i>=0;i--) for (int j=m-1;j>=0;j--) {
		dp[i][j] = (a[i][j] == '1' ? 1 : 0);
		dp[i][j] += dp[i][j+1] ;
		dp[i][j] += dp[i+1][j] ;
		dp[i][j] -= dp[i+1][j+1]; 
	}
	for (int i=0;i<n;i++) for (int j=0;j<m;j++) 
	for (int k=i;k<n;k++) for (int l=j;l<m;l++) {
		dp1[i][j][k][l] = dp[i][j] - dp[k+1][j] - dp[i][l+1] + dp[k+1][l+1];
		dp1[i][j][k][l] = (dp1[i][j][k][l] > 0 ? 0 : 1);
	}
	for (int i=n-1;i>=0;i--) for (int j=m-1;j>=0;j--) 
	for (int k=i;k<n;k++) for (int l=j;l<m;l++) 
		dp2[i][j][k][l] = dp1[i][j][k][l] + dp2[i][j+1][k][l] 
						+ dp2[i+1][j][k][l] - dp2[i+1][j+1][k][l];
	while (q--) {
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		a--; b--; c--; d--;
		ll res = 0;
		for (int i=a;i<=c;i++) for (int j=b;j<=d;j++)
			res += dp2[a][b][i][j];
		cout << res <<"\n";
	}
}

int main()
{
    fast_io;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
