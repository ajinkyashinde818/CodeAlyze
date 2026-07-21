#include <bits/stdc++.h>

using namespace std;

int main()
{
     int K,R,inR;
     cin>>K>>R;
    if(K>=1&&K<=100&&R>=0&&R<=4111){
     if(K>=10){
        inR=R; 
     }
     else{
         inR=R+(100*(10-K));
     }
     cout<<inR;
    }
   return 0;
}
