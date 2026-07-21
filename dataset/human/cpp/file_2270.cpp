#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>

using namespace std;

int main(){
  long long int n;
  long long int i,j,c=0,m=0,ans=0;
  vector <long long int> v,w;
  
  cin>>n;
  
 for(i=0;i<n;i++){
   cin>>j;
   v.push_back(j);
   w.push_back(abs(j));
   if(j<0)
     m++;
 }
 sort(w.begin(),w.end());
  for(i=0;i<n;i++){
    ans=ans+w[i];
  }
  cout<<(m%2==0?ans:ans-2*w[0])<<endl;
  
  return 0;
}
