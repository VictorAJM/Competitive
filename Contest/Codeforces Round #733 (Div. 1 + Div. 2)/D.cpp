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
int k,n,a[N],f[N],b[N];
bool vs[N],vv[N],h[N];
void solve()
{
    k=0;
    cin >> n;
    for (int i=1;i<=n;i++) vs[i] = h[i] = false;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) if (!vs[a[i]]) {
        k++;
        b[i] = a[i];
        vs[a[i]] = true;
        h[i] = true;
    }
    cout << k << "\n";
    vi node;
    for (int i=1;i<=n;i++) if (!h[i])  node.push_back(i);
    
    vi poss;
    for (int i=1;i<=n;i++) if (!vs[i]) poss.push_back(i);
    if (node.size()==1 && poss[0] == node[0]) {
        for (int i=1;i<=n;i++) vs[i] = h[i] = false;
        for (int i=n;i>=1;i--) if (!vs[a[i]]) {
            k++;
            b[i] = a[i];
            vs[a[i]] = true;
            h[i] = true;
        }
        node.clear();
        poss.clear();
        for (int i=1;i<=n;i++) if (!vs[i]) poss.push_back(i);
        for (int i=1;i<=n;i++) if (!h[i])  node.push_back(i);
        int aux = node.size()-1;
        for (int i=0;i<aux+1;i++) b[node[i]] = poss[i];

    } else if (node.size()>0) {
    for (int i=0;i<(int)node.size()-1;i++) if (poss[i] == node[i]) {
        swap(poss[i],poss[i+1]);
    }
    int aux = node.size()-1;
    if (poss[aux] == node[aux]) {
        swap(poss[aux],poss[0]);
    }
    for (int i=0;i<aux+1;i++) b[node[i]] = poss[i];
    }
    for (int i=1;i<=n;i++) cout << b[i] << " ";
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