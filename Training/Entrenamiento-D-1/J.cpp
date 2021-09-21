#include <bits/stdc++.h>

#define fast_io cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define F first
#define S second

using namespace std;

const int mod=0;
const int N=1e5+5;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
ll a[N],n,b[N],cnt1,cnt2,x,y;
void solve()
{
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    cnt1 = 0;
    for (int i=1;i<=n;i++) cnt2 += a[i];
    y = n;
    b[0] = cnt2;
    y--;
    for (ll i=1;i<=n;i++) {
        cnt2 -= a[i];
        b[i] = a[i]*x - cnt1 + cnt2-a[i]*y;
        x++;
        cnt1 += a[i];
        y--;
    }
    ll res = 0;
    for (int i=0;i<=n;i++) res += b[i];
    ll g = n;
    ll p = __gcd(res,g);
    res /= p;
    g /= p;
    cout << res << " "<<g;
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
