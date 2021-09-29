#include <bits/stdc++.h>

using namespace std;

int tc,tam,blue,cut;
string s;
bool posible = false;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>tc;
    while (tc--){
        cin>>s;
        tam = s.size();
        blue = 0;
        cut = -1;
        posible = true;
        for (int i = 0; i<tam; i++){
            if (s[i] == 'B'){
                blue++;
            }
            else{
                blue--;
            }

            if (cut>-1 && blue<0 && s[i] == 'R'){
                posible = false;
            }
            if (blue<=0 && s[i] == 'B' && cut == -1){
                cut = i;
                blue = 1;
            }
        }
        if (!posible){
            cout<<-1<<"\n";
        }
        else{
            if (cut == -1 || cut == tam){
                cut = 0;
            }
            cout<<cut<<"\n";
        }
    }
    return 0;
}