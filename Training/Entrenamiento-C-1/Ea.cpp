#include <bits/stdc++.h>
using namespace std;
string s;
int t[30],cnt;
int main()
{
	cin >> s;
	for (char u : s) {
		if (t[u-'a']==0) {
			cnt++;
			t[u-'a'] = 1;
		} 
	}
	if (cnt %2==0) cout << "CHAT WITH HER!"
	else cout << "IGNORE HIM!"
}