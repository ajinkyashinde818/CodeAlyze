#include <iostream>
using namespace std;
int main(){
long int n,sum=0,ct=0,sml;
cin>>n;
const int N=n;
long int a[N];
for(int i=0;i<N;i++){
  cin>>a[i];
  if(a[i]<0){
    ct++;
    a[i]*=-1;
}
if(sml>a[i]||i==0)sml=a[i];
sum+=a[i];
}
if(ct%2==1)sum-=sml*2;
cout<<sum<<endl;
  return 0;
}
