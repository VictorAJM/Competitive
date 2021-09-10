#include <bits/stdc++.h>

#define fast_io cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define F first
#define S second

using namespace std;

const int mod=0;
const int N=1e6+6;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int n,m,a[N],b[N],f[32],cnt;
void solve()
{
    cin >> n >> m;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<m;i++) cin >> b[i];
    sort(a,a+n);
    for (int i=0;i<m;i++) f[b[i]]++;
    for (int i=0;i<=30;i++) {
        int k = f[i];
        for (int j=0;j<n;j++) if (a[j]%2==1 && k>0) {
            a[j]--;
            cnt++;
            k--;
        }
        for (int j=0;j<n;j++) while (k>0 && a[j] >0) {
            a[j]--;
            cnt++;
            k--;
        }
        if (k>0) {
            cout << cnt << "\n";
            return;
        } else {
            for (int j=0;j<n;j++) a[j] /= 2;
        }
    }
    cout << cnt;
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