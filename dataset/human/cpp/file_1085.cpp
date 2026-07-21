#include<bits/stdc++.h>
using namespace std;
int main() {
    int cont=0;
    int r,g,b,n;
    cin>>r>>g>>b>>n;
    for(int x=0; x*r<=n; x++){
        for(int y=0; x*r + g*y<=n;y++){
            if((n-(r*x)-(g*y))%b==0){


                cont++;}
        }
    }

    cout<<cont;
  return 0;
}
