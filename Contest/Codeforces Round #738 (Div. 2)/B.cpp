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
string s;
int n;
void solve()
{
    cin >> n;
    cin >> s;
    string b,c;
    int x = 0;
    char ant = 'a';
    while (x < n) {
        int cnt = 0;
        int in = x;
        while (x < n && s[x] == '?') {
            cnt++;
            x++;
        }
        if (x==n || s[x] == '?') {
            x = n;
            if (ant == 'a') ant = 'B';
            char c = ant;
            for (int i =in;i<x;i++) {
                        if (c=='B') c= 'R';
                        else c= 'B'; 
                        s[i] = c;
            }
        } else {
            char las = s[x];
            if (las == ant) {
                
                    char c = las;
                    for (int i=in;i<x;i++) {
                        if (c=='B') c= 'R';
                        else c= 'B'; 
                        s[i] = c;
                        
                    }
                
            } else {
                char c = las;
                    for (int i=x-1;i>=in;i--) {
                        if (c=='B') c= 'R';
                        else c= 'B'; 
                        s[i] = c;
                        
                    }
            }
            while (x<n && s[x] != '?') {
                ant = s[x];
                x++;
            }
        }
    }
    cout << s << "\n";
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
