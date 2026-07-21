#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long a,b,c;
  cin>>a;
 b=0;
  c=0;
  vector<long long>vec(a);
  for(long long i=0;i<a;i++){
    cin>>vec.at(i);
    b+=vec.at(i);
  }
  b-=vec.at(a-1);
  c+=vec.at(a-1);
  long long e=abs(b-c);
  for(long long j=a-2;j>0;j--){
    b-=vec.at(j);
    c+=vec.at(j);
    long long f=abs(b-c);
    if(f<e){
      e=f;
    }
  }
    cout<<e<<endl;
}
