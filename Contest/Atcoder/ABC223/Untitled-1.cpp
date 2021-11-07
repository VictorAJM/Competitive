#include <iostream>
using namespace std;
char a[5];
int main()
{
	cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
	int x = (a[0]-'0')*10 + a[1] - '0';
	int y = (a[3]-'0')*10 + a[4] - '0';
	if (0 <= x && x <= 23 && 0 <= y && y <= 60) cout << "correcta";
	else cout << "incorrecta";
}