#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    long long  a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int flag=0;
    int co=0;
    for(int i=0; i<n; i++){
          if (a[i]==0){
              flag=1;
          }
          else if (a[i]<0){
              co++;
          }
        }

    if (flag==1 or co%2==0){
        long long su=0;
        for(int i=0; i<n; i++){
            su+=abs(a[i]);
        }
        cout<<su<<endl;
    }
    else{
        long long su=0;
        long long mi=1e+10;
        for(int i=0; i<n; i++){
            su+=abs(a[i]);
            mi=min(abs(a[i]),mi);
        }
        cout<<su-2*mi<<endl;
    }
}
