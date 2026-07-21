#include <bits/stdc++.h>
using namespace std;


  
int main(){
  

  int64_t n;
  cin>>n;
  
  vector<int64_t> data(n);
  
  for (int64_t i=0;i<n;i++){
    cin>>data.at(i);
  }
  
  
  int64_t sum=0;
  
  vector<int64_t> sums(n);
  
  for (int64_t i=0;i<n;i++){
    sum+=data.at(i);
    sums.at(i)=sum;
  }
  
  vector<int64_t> difference(n-1);
  
  for (int64_t i=0;i<n-1;i++){
    int64_t tmp=abs(sums.at(n-1)-2*sums.at(i));
    difference.at(i)=tmp;
  }
  
  sort(difference.begin(),difference.end());
 
  cout<<difference.at(0)<<endl;
  
    
  
}
