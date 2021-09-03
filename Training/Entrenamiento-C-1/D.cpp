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

bool b[N];

void solve()
{
    string s;
    vector<int> res;
    cin >> s;
    int w = s.size()-1;
    while (w>=0) {
        while (w>=0 && s[w] != 'a') w--;
        if (w>=0 && s[w] =='a') {
            b[w] = 1;
            w--;
            while (w>=0 && s[w] == 'a') w--;
            if (w>=0 && s[w]=='b') {
                b[w] =1;
                w--;
            }
        }
    }
    for (int i=0;i<s.size();i++) cout << b[i] << " ";   
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
