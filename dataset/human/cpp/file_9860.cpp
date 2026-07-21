#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <set>
#include <iomanip>
#include <stdio.h>
#include <sstream>
#include <string>
using namespace std;
int main(void){
  int n;
  string s;
  cin>>n>>s;
  sort(s.begin(),s.end());
  int eng[26]={};
  for (long long int i = 0; i < n; i++)
  {
    eng[s[i]-0x20-0x41]++;
  }
  
  long long int ans=1;
  for (long long int i = 0; i < 26; i++)
  {
    ans*=eng[i]+1;
    ans%=1000000007;
  }
  ans--;
  cout<<ans<<endl;
}
