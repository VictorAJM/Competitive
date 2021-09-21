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
ll n,q,cnt[N];
string s;
void solve()
{
    cin >> n >> q;
    cin >> s;
    for (int i=1;i<=n;i++) {
        cnt[i] = cnt[i-1] + s[i-1] - 'a'+1;
    }
    while (q--) {
        int x,y;
        cin >> x >> y;
        cout << cnt[y] - cnt[x-1] << "\n";
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
