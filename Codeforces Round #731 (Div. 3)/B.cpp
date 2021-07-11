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
bool vs[205];
bool solve()
{
    string s;
    for (int i='a';i<='z';i++) vs[i] = false;
    cin >> s;
    char  p =0;
    while (!s.empty()) {
        char k = 0;
        for (char u : s) k = max(k,u);
        if (vs[k]) return false;
        p = max(k,p);
        vs[k] = true;
        if (s[0] == k) {
            reverse(s.begin(),s.end());
            s.pop_back();
            reverse(s.begin(),s.end());
        } else if (s[s.size()-1]) {
            s.pop_back();
        } else {
            return false;
        }
    }
    for (int i='a';i<=p;i++) if (!vs[i]) return false;
    return true;
}

int main()
{
    fast_io;
    int t = 1;
    cin >> t;
    while (t--) {
        if (solve()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}