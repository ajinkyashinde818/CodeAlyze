#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;

int main()
{
  int N,M;
  cin>>N>>M;
  string ans="No";
  vector <string> A(N),B(M);
  for(int i=0;i<N;i++) cin>>A[i];
  for(int i=0;i<M;i++) cin>>B[i];
  for(int i=0;i<N-M+1;i++){
    for(int j=0;j<N-M+1;j++){
      bool flag = true;
      for(int k=0;k<M;k++){
        if (A[k+i].substr(j,M)!=B[k]) flag=false;
      }      
      if (flag) ans="Yes";
    }
  }
  cout<< ans <<endl;
}
