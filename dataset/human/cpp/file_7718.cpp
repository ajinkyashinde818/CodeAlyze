#include<iostream>
using namespace std;
using lint=long long;
int main(){
  int N; cin>>N;
  lint a[200000];
  for(int i=0;i<N;i++)
    cin>>a[i];
  for(int i=1;i<N;i++)
    a[i]+=a[i-1];
  lint Min=abs(2*a[0]-a[N-1]);
  for(int i=1;i+1<N;i++)
    Min=min(Min,abs(2*a[i]-a[N-1]));
  cout<<Min<<endl;
  return 0;
}
