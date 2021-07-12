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
int k,n,m,a[N],b[N];
vi res;
void solve()
{
    cin >> k >> n >> m;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<m;i++) cin >> b[i];
    int p = 0;
    int q = 0;
    res.clear();
    while (p < n || q < m) {
        if (p < n && a[p] <= k) {
            if (a[p] == 0) k++;
            res.push_back(a[p]);
            p++;
        } else if (q<m && b[q]<=k) {
            if (b[q]==0) k++;
            res.push_back(b[q]);
            q++;
        } else {
            cout << "-1\n";
            p=q=n+m;
            return;
        }
    }
    for (int u : res) cout << u << " ";
    cout << "\n";
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