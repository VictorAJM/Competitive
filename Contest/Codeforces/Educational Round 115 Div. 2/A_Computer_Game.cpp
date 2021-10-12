#include <bits/stdc++.h>
using namespace std;
int t,n;
string s,d;
bool can;

int main()
{
    cin >> t;
    while (t--) {
        cin >> n >> s >> d;
        can =1 ;
        for(int i=0;i<n;i++) if (s[i] == d[i] && s[i] == '1') can = false;

        cout << (can ? "YES" : "NO") << "\n";
    }
}