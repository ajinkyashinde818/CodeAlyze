#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> RGB;

int count(int k,int n){
  if(k==2){
    if(n%RGB[k]==0) return 1;
    else return 0;
  }

  int r=0,i;
  for(i=0;i<=n/RGB[k];i++){
    r+=count(k+1,n-RGB[k]*i);
  }

  return r;
}
int main(){
  int r=0,n,i,j;
  for(i=0;i<3;i++){
    cin>>j;
    RGB.push_back(j);
  }
  sort(RGB.rbegin(),RGB.rend());

  cin>>n;
  
  r=count(0,n);

  cout<<r<<endl;
  return 0;
}
