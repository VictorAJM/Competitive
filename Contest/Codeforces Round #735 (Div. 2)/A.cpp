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
ll a[N];
void solve()
{
    int n;
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    ll k = *max_element(a,a+n);
    ll r = 0;
    for (int i=0;i<n;i++) if (a[i] == k) {
        if (i-1 >= 0 ) r = max(r,a[i-1]);
        if (i+1 < n ) r = max(r,a[i+1]);
    }
    cout << k*r <<"\n";
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