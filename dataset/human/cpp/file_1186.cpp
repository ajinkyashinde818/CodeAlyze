#include<iostream>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>
#include<vector>
 
using namespace std;
int MOD=1000000007;

int main(){
    int R,G,B,N,ans=0;
    cin >> R >> G >> B >> N;
    for(int i=0; i<=N; i++){
        for(int j=0; j<=N; j++){
            if(R*i+G*j>N) break;
            if((N-(i*R+j*G))%B==0){
            ans+=1;
            }
        }
    }
    cout << ans << endl;
}
