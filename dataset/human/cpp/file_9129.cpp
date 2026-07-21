#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <set>
#include <iomanip>
#include <stdio.h>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;
int main(void){
  int n,m;
  cin>>n>>m;
  vector<string> a(n);
  vector<string> b(m);
  for(int i=0; i<n; i++){
    cin>>a.at(i);
  }
  for(int i=0; i<m; i++){
    cin>>b.at(i);
  }

bool ok=false;
  for(int i=0; i<=n-m; i++){
    for(int l=0; l<=n-m; l++){
      bool pre=true;
      for(int j=0; j<m; j++){
        for(int k=0; k<m; k++){
          if(b.at(j)[k]!=a.at(j+i)[k+l]){
            pre=false;
            break;
          }
        }//k
        if(pre==false){
          break;
        }
      }//j
    if(pre){
      ok=true;
      break;
    }
    }//l
  }//i

  if(ok){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}
