#include <bits/stdc++.h>
using namespace std;

long mod=1e9+7;

int main() {
int N;
string S;
cin>>N>>S;
N*=2;
string T=S;
if(S[0]=='B') T[0]='L';
else{
  cout<<0<<endl;
  return 0;
}
for(int i=0;i<N-1;i++){
  if(T[i]=='L'){
    if(S[i]=='B'&&S[i+1]=='B') T[i+1]='R';
    if(S[i]=='B'&&S[i+1]=='W') T[i+1]='L';
    if(S[i]=='W'&&S[i+1]=='B') T[i+1]='L';
    if(S[i]=='W'&&S[i+1]=='W') T[i+1]='R';
  }
  else if(T[i]=='R'){
    if(S[i]=='B'&&S[i+1]=='B') T[i+1]='L';
    if(S[i]=='B'&&S[i+1]=='W') T[i+1]='R';
    if(S[i]=='W'&&S[i+1]=='B') T[i+1]='R';
    if(S[i]=='W'&&S[i+1]=='W') T[i+1]='L';
  }
}

if(S[N-1]=='B'&&T[N-1]=='R') T[N-1]='R';
else{
  cout<<0<<endl;
  return 0;
}

int l=0,r=0;
for(int i=0;i<N;i++){
  if(T[i]=='L') l++;
  if(T[i]=='R') r++;
}

if(l==N/2&&r==N/2) r=0;
else{
  cout<<0<<endl;
  return 0;
}

long ans=1;
r=0;
for(int i=N-1;i>=0;i--){
  if(T[i]=='R') r++;
  if(T[i]=='L'){
    if(r>0) ans*=r,r--,ans%=mod;
    else{
      cout<<0<<endl;
      return 0;
    }
  }
}
for(int i=1;i<=N/2;i++){
  ans *=i;
  ans %= mod;
}
cout<<ans<<endl;
}
