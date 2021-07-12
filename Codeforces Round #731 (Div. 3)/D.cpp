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
int n,a[N],b[N];
void solve()
{
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n;i++) b[i] = 0;
    for (int i=30;i>=0;i--) {
        int p = (1<<i);
        bool t = (a[0]&p);
        if (t) {
            int q = 0;
            while (q<n && (a[q]&p) == p) q++;
            while (q<n) {
                if ((a[q]&p) == 0) b[q] += p;
                q++;
            }
        } else {
            int q = 0;
            while (q<n && (a[q]&p) == 0) q++;
            while (q<n) {
                if ((a[q]&p)==0) b[q] += p;
                q++;
            }
        }
    }
    for (int i=0;i<n;i++) cout << b[i]<<" ";
    cout << "\n";
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