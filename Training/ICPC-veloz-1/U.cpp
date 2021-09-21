    #include <bits/stdc++.h>

#define fast_io cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define F first
#define S second

using namespace std;

const int mod=0;
const int N=0;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int n;
void solve()
{
    cin >> n;
    if (n%2==1) {
        cout << "3 1 2 ";
        for (int i=4;i<=n;i+=2) {
            cout << i+1 << " "<<i << " ";
        }
        cout << "\n";
    } else {
        for (int i=1;i<=n;i+=2) {
            cout << i+1 << " "<<i << " ";
        }
        cout << "\n";
    }
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
