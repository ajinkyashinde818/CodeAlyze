#include <bits/stdc++.h>
using namespace std;

int main(){
  long long int N;
  long long int mod = 1e9+7;
  cin >> N;
  string s;
  cin >> s;
  if(s[0] == 'W'||s[2*N-1]=='W'){
    cout << 0 << endl;
  }
  else{
    long long int l=1,r=0;//
    long long int sum = 1;
    char a = 'L';
    for(int i = 1; i < 2*N; i++){
      //cout << a << endl;
      if((s[i-1]=='B'&&s[i]=='W')||(s[i-1]=='W'&&s[i]=='B')){
        if(a=='R'){
          r++;
          sum *= l;
          sum = sum%mod;
          l--;
          a = 'R';
        }
        else{
          l++;
          a = 'L';
        }
      }
      else{
        if(a=='R'){
          l++;
          a = 'L';
        }
        else{
          r++;
          sum*=l;
          sum = sum%mod;
          l--;
          a = 'R';
        }
      }
      
    }
    //cout << a << endl;
    //cout << l << r << endl;
    if(l!=0 || r!=N){
      cout << 0 << endl;
    }
    else{
      long long int num = 1;
      for(int i = 1; i <= N; i++){
        num *= i;
        num = num%mod;
      }
      sum *= num;
      sum = sum%mod;
      cout << sum << endl;
    }
  }
}
