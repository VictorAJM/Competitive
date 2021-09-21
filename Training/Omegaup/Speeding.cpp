// Problem: 11401. Speeding
// Contest: omegaUp
// URL: https://omegaup.com/arena/problem/Speeding/
// Memory Limit: 32 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#define fast_io cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
int n,a,b,c,d,e;
int main()
{
	fast_io;
	cin >> n;
	cin >> a >> b;
	n--;
	while(n--) {
		cin >> c >> d;
		// la ecuacion (d-b)/(c-a) representa la 
		// velocidad en este momento
		
		if (e < (d-b)/(c-a)) e = (d-b)/(c-a);
		// el if anterior es para meter el mayor valor de 
		// cada segmento en la variable e
		a = c;
		b = d;
	}
	cout << e;
    return 0;
}
