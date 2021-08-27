#include <bits/stdc++.h>

#define fast_io cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define F first
#define S second

using namespace std;

const int mod=0;
const int N=2e4+5;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int n,a[N];
void solve()
{
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    if (a[0] == 1) {
        cout <<n+1 <<" ";
        for (int i=1;i<=n;i++) cout << i << " ";
        cout << "\n";
        return;
    }
    if (a[n-1] == 0) {
        for (int i=1;i<=n;i++) cout << i << " ";
        cout <<n+1 <<" ";
                cout << "\n";
        return;
    }
    for (int i=0;i<n-1;i++) if (a[i] == 0 && a[i+1]==1) {
        int x = 1;
        while (x<=i+1) { cout << x << " "; x++; }
        cout << n+1 << " ";
        x = i+2;
        while (x<=n) { cout << x << " "; x++;}
        cout << "\n";
        return;
    }
    cout << -1 << "\n";
    return;
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
