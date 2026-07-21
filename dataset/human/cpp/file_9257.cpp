#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, M, a, b, f, f2;
  string A[100], B[100];
  cin>>N>>M;

  for(int i = 0; i < N; i++){
    cin>>A[i];
  }a = A[0].size();
  for(int i = 0; i < M; i++){
    cin>>B[i];
  }b = B[0].size();

  f2=0;
  for(int i = 0; i <= N-M; i++){
    for(int j = 0; j <= N-M; j++){
      f=0;
      for(int k = 0; k < M; k++){
	for(int l = 0; l < M; l++){// cout<<A[k][l];
	  if(A[i+k][j+l] != B[k][l]){f=1;break;}
	}//cout<<endl;
	 if(f)break;
      }
      //cout<<i<<" "<<j<<" "<<f<<endl;
      if(f==0)break;
    }
    if(f==0)break;
  }
  if(f)cout<<"No"<<endl;
  else cout<<"Yes"<<endl;
  return 0;
}
