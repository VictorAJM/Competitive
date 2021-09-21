#include <bits/stdc++.h>

#define fast_io cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define F first
#define S second

using namespace std;

const int mod=998244353;
const int N=0;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

void solve()
{
    int n,m;
    cin >> n >> m;
    string a,b;
    cin >> a >> b;
    ll cnt = 0;
    for (int i=0;i<b.size();i++) if (b[i]=='1') cnt++;
    ll x=1;
    ll res =0;
    int con=0;
    for (int i=a.size()-1;i>=0;i--) {
        if (a[i] == '1') {
            ll y = cnt * x;
            y %= mod;
            res += y;
            res %= mod;
        }
        x *= 2;
        x %= mod;
        if (con<b.size() && b[b.size()-con-1]=='1') {
            cnt--;
        }  
        con++;
    }
    cout << res;
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
