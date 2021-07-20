#include <bits/stdc++.h>

#define fast_io cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define F first
#define S second

using namespace std;

const int mod = 1e9+7;
const int N = 2e2+5;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int a[N][N];
void solve()
{
    int h,w;
    cin >> h >> w;
    for (int i=1;i<=h;i++) for (int j=1;j<=w;j++) a[i][j] = 0;
    for (int i=1;i<2;i++) for (int j=1;j<=w;j+=2) a[i][j] = 1;
    for (int i=h;i<=h;i++) for (int j=1;j<=w;j+=2) a[i][j] = 1;
    for (int i=3;i<=h-2;i+=2) for (int j=1;j<=1;j++) a[i][j] = 1;
    for (int i=3;i<=h-2;i+=2) for (int j=w;j<=w;j++) a[i][j] = 1;
    for (int i=1;i<=h;i++) {
        for (int j=1;j<=w;j++) cout << a[i][j];
        cout << "\n";
    }
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