#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int p=0,i=0,j,k,b=1;
  
  while(s[i]!='.') p=p*10+s[i]-'0',i++;
  i++;
  while(i<s.size()&&s[i]!='(') {
    b*=10;
    p=p*10+s[i]-'0';
    i++;
  }
  if(s[i]=='('){
    i++;j=0;k=0;
    while(s[i]!=')') {
      k=k*10+9;
      j=j*10+s[i]-'0';
      i++;
    }
    b*=k;
    p=p*k+j;
  }
  cout << p/__gcd(p,b) << "/" <<  b/__gcd(p,b) << endl;
  return 0;
}
