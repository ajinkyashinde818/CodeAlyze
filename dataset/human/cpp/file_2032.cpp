#include<bits/stdc++.h>
using namespace std;

int ze(int);

int main(){
  long long sum;
  int N;
  int i;

  cin>>N;

  vector<int> a(N);

  for(i=0;i<N;i++)
  cin>>a.at(i);

  int cnt=0;
  for(i=0;i<N;i++){
    if(a.at(i)<0)
    cnt++;
  }

  sum=0;
  for(i=0;i<N;i++)
  sum+=ze(a.at(i));
  // cout<<sum<<endl;

  if(cnt%2!=0){
    // cout<<"syori"<<endl;
    int min=1000000000;
    int d;
    for(i=0;i<N;i++){
      d=ze(a.at(i));
      if(min>d)
      min=d;
    }
    sum-=min*2;
  }

  cout<<sum<<endl;

}

int ze(int a){
  if(a<0)
  a*=(-1);
  return a;
}
