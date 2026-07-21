#include<bits/stdc++.h>
using namespace std;
int main(){
  long long N,loop;
  cin >> N;
  string S;
  cin >> S;
  long long ans,K;
  if(S[0]=='W'){
    ans=0;
  }else{
    ans=1;
    K=1;
    for(loop=1;loop<N*2;loop++){
      if(K%2){	
        if(S[loop]=='W'){
          K++;
        }else{
          ans=(ans*K)%1000000007;
          K--;
          if(K<0){
            ans=0;
            break;
          }
        }
      }else{
        if(S[loop]=='B'){
          K++;
        }else{
          ans=(ans*K)%1000000007;
          K--;
          if(K<0){
            ans=0;
            break;
          }
        }
      }
    }
  }
  if(K){
    ans=0;
  }else{
    for(loop=N;loop>1;loop--){
      ans=(ans*loop)%1000000007;
    }
  }
  cout << ans << endl;
  return 0;
}
