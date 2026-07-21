#include <bits/stdc++.h>
using namespace std;
int abs(int a){
  if(a<0) a = (-1)*a;
  return a;
}
int pow(int a,int b){
  int ans=1;
  for(int i=0; i<b; i++) ans *=a;
  return ans;
}
int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  int odd=0;//奇数の個数
  int absmin=pow(10,9);//絶対値が最小のもの
  int mini=0;
  for(int i=0; i<n; i++){
    int tmp;
    cin>>tmp;
    a.at(i)=abs(tmp);
    if(tmp<0) odd++;
    if(abs(tmp)<absmin){
      absmin=abs(tmp);
      mini=i;
    }
  }
  long long ans=0;
  for(int i=0; i<n; i++){
    if(i!=mini) ans += a.at(i);
    else if( odd%2==1) ans -= a.at(i);
    else ans += a.at(i);
  }
  cout<<ans<<endl;
}
