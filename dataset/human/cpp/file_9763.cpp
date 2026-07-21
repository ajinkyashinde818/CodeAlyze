#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <float.h>
#include <iomanip>
#include <iostream>
using namespace std;
 
int gcd(int x,int y){
    if(y==0)return x;

    return gcd(y,x%y);
}
int lcm(int x,int y){
    return x*y/gcd(x,y);
}

int main(){

    long long ans ,d=1000000007;
    int N,X[27]={};
    string S,a="0abcdefghijklmnopqrstuvwxyz";
    cin>>N;
    cin>>S;

    for(int i=1;i<=26;i++){
        //文字ループ
        X[i]=1;
        for(int j=0;j<S.length();j++){
            //a[i]と一致でインクリメント
            if(S[j]==a[i]){
                X[i]++;
            }
        }
    }

    ans=1;
    for(int i=1;i<=26;i++){
        if(X[i]>0){
            ans*=X[i];
            ans%=d;
        }
    }
    ans-=1;

    cout<<ans<<endl;
    
    return 0;
}
