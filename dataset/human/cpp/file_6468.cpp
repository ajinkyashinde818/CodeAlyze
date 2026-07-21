#include <bits/stdc++.h>
using namespace std;
int main(){
  long n,i,k,p,ans;
  ans=0;
  bool roop=false;
  string str;
  cin>>n>>str;
  vector<char> vec(2*n);
  k=0;
  
  if(str.at(0)=='B'&&str.at(2*n-1)=='B'){
    roop=true;
    ans=1;
  }
  for(i=0; i<2*n; i++){
    if(i==0){
      vec.at(i)='R';
      k++;
      
      
      
    }
   
    else if(str.at(i)==str.at(i-1)){
      vec.at(i)='L';
      if(str.at(i)=='B'){
        str.at(i)='W';
      }
      else{
        str.at(i)='B';
      }
    }
    else{
      vec.at(i)='R';
      k++;
   
    }
  }
 
  while(roop){
   
    while(n==k){
      p=0;
      for(i=0; i<2*n; i++){
      
        
        if(vec.at(i)=='R'){
          p=p+1;
        }
        else{
        
          ans=ans*p%1000000007;
          p=p-1;
        }
      }
      break;
    }
    break;
  }
  for(i=1; i<n+1; i++){
    
    ans=ans*i%1000000007;
  }
  if(vec.at(2*n-1)=='R'){
    ans=0;
  }
  
 
  if(n==k){
  }
  else{
    ans=0;
  }
  
  
  
  cout<<ans;
}
