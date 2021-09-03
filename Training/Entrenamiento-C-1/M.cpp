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
int n,m,a[N],b[N],f[N];
int ok;
priority_queue<ii,vector<ii>,greater<ii>> pq;
void solve()
{
    cin >> n >> m;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<m;i++) cin >> b[i];

    for (int i=0;i<m;i++) f[b[i]]++;
    for (int i=30;i>=0;i--) {
        while (!pq.empty()) pq.pop();
        for (int j=0;j<n;j++) if (a[j]>=(1<<i)) pq.push({a[j],j});
        while (f[i]--) {
            if (!pq.empty()) {
                ok++;
                ii x = pq.top();
                pq.pop();
                a[x.S] -= (1<<i);
                if (a[x.S]>=(1<<i)) pq.push({a[x.S],x.S});
            }
        }
    }
    cout << ok;
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