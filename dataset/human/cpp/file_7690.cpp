#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  long long a[N]={0};
  long long s[N]={0};
  long long dif=1000000009;
  long long sum=0;
  for (int i=0;i<N;i++){
    cin>>a[i];
    sum=sum+a[i];
    s[i]=sum;
  }
  if(N==2){
    cout<<abs(a[1]-a[0])<<endl;
    return 0;}
  
  for (int i=0;i<N;i++){
    if(i==N-1){
      break;
    }
    dif=min(dif,abs(s[i]-(sum-s[i])));
    //cout<<dif<<" "<<abs(s[i]-(sum-s[i]))<<endl;
  }
  //cout<<sum<<" "<<s[4]<<endl;
  cout<<dif<<endl;
 return 0;
}
