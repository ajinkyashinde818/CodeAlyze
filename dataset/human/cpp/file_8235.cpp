#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long> a(N);
  vector<long> s(N);
  
    for(int i=0;i<N;i++){
       cin>>a[i];
      if(i==0) s[0] = a[0];
       else s[i] =s[i-1]+a[i];
     }
  //cout<<s[0]<<endl;
  //cout<<s[N-1]<<endl;
  long m=99999999999999999;
    for(int i=0;i<N-1;i++){
      long sunuke = s[i];
      long arai= s[N-1]-s[i];
      long dif = abs(sunuke-arai);
      m =min(dif,m);
    }
cout<<m<<endl;

  }
