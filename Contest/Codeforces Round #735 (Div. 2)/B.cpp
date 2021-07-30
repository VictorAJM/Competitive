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
int n,k,r,q,w,a[N];
void solve()
{
    cin >> n >> k;
    for (int i=0;i<n;i++) cin >> a[i];
    r = *max_element(a,a+n);
    q = 1;
    while (q <= r) q *= 2;
    q /= 2;
    r = q;
    q = w = -1;
    for (int i=0;i<n;i++) if (a[i] < r) q = i;
    else w = i;
    ll gg = -mod;
    for (int i=0;i<n;i++) {
        ll ok1 = -mod;
        ll ok2 = -mod;
        if (i < q){ 
        ok1 = (i+1)*(q+1) - k*(a[i]|a[q]);
        }
        if (i < w) {
            ok2 = (i+1)*(w+1) - k*(a[i] | a[w]);
        }
        gg = max(max(gg,ok1),ok2);
    }
    cout << gg << "\n";
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