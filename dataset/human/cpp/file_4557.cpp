#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;

int main(){
  int n,r;cin>>n>>r;
  cout<<(n<10?100*(10-n)+r:r)<<endl;
}
