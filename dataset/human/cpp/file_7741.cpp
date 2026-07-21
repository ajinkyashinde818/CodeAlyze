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
   long long int n;
   cin>>n;
   long long int all=0;
   vector<long long int> hoge(n);
   for(long long int i=0; i<n; i++){
     cin>>hoge.at(i);
     all+=hoge.at(i);
   }

   long long int a=0;
   long long int b=all;
   long long int ans=pow(10,182);
   for(long long int i=0; i<n-1; i++){
     a+=hoge.at(i);
     b-=hoge.at(i);
     ans=min(ans, abs(a-b));
   }
   cout<<ans<<endl;
}
