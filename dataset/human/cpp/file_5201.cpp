#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <math.h>
#include <string>
using namespace std;

int main() {
	cin.tie(0);
  ios::sync_with_stdio(false);
 
	int n,k,i,j,r;
  vector<int> v;
  cin>>n>>r;
  
  if(n>=10)
    cout<<r;
  else
    cout<<r+100*(10-n);


  return 0;
}
