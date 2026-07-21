#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,count=0,xmin=1000000000;
  int64_t sum=0;
  cin>>N;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin>>A.at(i);
    if(A.at(i)>=0){
      sum+=A.at(i);
      xmin=min(xmin,A.at(i));
      }
    else{
      sum+=-A.at(i);
      xmin=min(xmin,-A.at(i));
      count++;
      }
    }
  if(count%2==0)
    cout<<sum<<endl;
  else
    cout<<sum-2*xmin<<endl;
  }
