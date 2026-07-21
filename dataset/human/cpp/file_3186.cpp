#include<iostream>
#include<chrono>
#include<algorithm>
using namespace std;

int main(){
  int n;
  int minimum=1000000001;
  long sum=0;

  cin>>n;

  int tmp;
  int neg_cnt=0;
  for(int i=0;i<n;i++){
    cin>>tmp;
    if(tmp<0)neg_cnt++;

    sum+=abs(tmp);
    minimum=min(minimum,abs(tmp));
  }

  long ans=(neg_cnt%2)==0 ? sum : sum-(minimum*2);
  cout<< ans <<endl;
  return 0;
}
