#include <iostream>
using namespace std;

int main(){
    
    int cat[10005];
    int id=0;
    float sueldo[10005];
    float cambio[8];
    cambio[0] = 0.0;
    cambio[1] = 0.5;
    cambio[2] = 1.0;
    cambio[3] = 1.4;
    cambio[4] = 1.6;
    while (cin >> id) {
      cin >> cat[id];
      cin >> sueldo[id];
    }

    for (int i=1;i<=id;i++) {
      sueldo[i] = sueldo[i] * (1.0 + cambio[cat[i]]);
    }
    for (int i=1;i<=id;i++) {
    	cout << i << " "<<sueldo[i] << "\n";
    }
}