#include <bits/stdc++.h>

#define fast_io cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

using namespace std;
const int N=2e5+5;
typedef vector<int> vi;
int n,a[N],b[N],c[N];
bool  ok = true;
vi g[N];
void solve()
{
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n;i++) b[a[i]]++;
    for (int i=0;i<n;i++) g[a[i]].push_back(i+1);
    int M = *max_element(a,a+n);
    int q = 0;
    for (int i=0;i<=M;i++,q++) {
        if (b[i]==0) ok = false;
        else {
            c[i] = i;
            b[i]--;
        }
    }
    int  p = q;
    while (q<n) {
        while (b[p]==0) p -= 3;
        if (p < 0 ) { q = n; ok = false;}
        else {
            b[p]--;
            c[q] = p;
            p++;
            q++;
        }
    }
    if (ok) {
        cout << "Possible\n";
        for (int i=0;i<n;i++) {
            int gg = c[i];
            c[i] = g[c[i]][g[c[i]].size()-1];
            g[gg].pop_back();
        }
        for (int i=0;i<n;i++) cout << c[i] << " ";
    } else cout << "Impossible";
    return;
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
