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

void solve()
{
    ll n;
    cin >> n;
    if (n<=6) cout <<"15\n";
    else {
        ll k = n/6 ;
        k *= 15;
        n %= 6;
        if (n>4) k += 15;
        else if (n>2) k += 10;
        else if (n>0) k += 5;
        cout << k << "\n";
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