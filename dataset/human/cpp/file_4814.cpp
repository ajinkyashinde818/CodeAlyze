#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
#include<utility>
#include <numeric>
 
using namespace std;
typedef long long ll;
 
int main(){
ll n,r;
  cin>>n>>r;
  if(n>=10){
    cout<<r;
  }
  else{
    cout<<r+100*(10-n);
  }
  return 0;
 
}
