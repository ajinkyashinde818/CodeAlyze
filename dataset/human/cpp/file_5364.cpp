#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;
typedef long long ll;
int main(){
  ll n,r;
  cin>>n>>r;
  if(n<10){
    r+=100*(10-n);
  }
  cout<<r<<endl;
}
