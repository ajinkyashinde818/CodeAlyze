#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin>>n;
  long long sum=0,sunuke=0,min=-1;
  int card[n];
  for(int i=0;i<n;i++){
    cin>>card[i];
    sum+=card[i];
  }
  for(int i=0;i<n-1;i++){
    sunuke+=card[i];
    if(min==-1 || min>abs(sunuke-(sum-sunuke))){
      min=abs(sunuke-(sum-sunuke));
    }
  } 
  cout<<min<<endl;
  return 0;
}
