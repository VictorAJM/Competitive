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
string s;
void solve()
{
    cin >> n >> s;
    set<int> q;
    bool t=false;
    for (int i=0;i<n;i++) 
        if (s[i] == '4' || s[i] == '6' || s[i] == '8' || s[i] == '9') 
            t = true;
    if (t) {
        for (int i=0;i<n;i++) 
        if (s[i] == '4' || s[i] == '6' || s[i] == '8' || s[i] == '9') 
        {
            cout <<1<<"\n";
            cout << s[i] <<"\n";
            return;
        }
    }
    int k;
    for (int i=0;i<n;i++) for (int j=i+1;j<n;j++) {
        k = (s[i]-'0')*10 + s[j]-'0';
        if (q.count(k)) {
            cout << "2\n";
            cout <<s[i]<<S[j]<<"\n";
        }
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
