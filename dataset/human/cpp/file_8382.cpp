#include <bits/stdc++.h>

using namespace std;

int N,M;
char A[55][55],B[55][55];

bool in(int a,int b){
  for(int i=a; i<a+M; i++){
    for(int j=b; j<b+M; j++){
      if(A[i][j]!=B[i-a][j-b]){
        return 0;
      }
    }
  }
  return 1;
}

int main(){

cin.tie(0);
ios::sync_with_stdio(false);

cin>>N>>M;

for(int i=0; i<N; i++){
  cin>>A[i];
}
for(int i=0; i<M; i++){
  cin>>B[i];
}

for(int i=0; i+M-1<N; i++){
  for(int j=0; j+M-1<N; j++){
    if(in(i,j)){
      cout<<"Yes"<<endl;
      return 0;
    }
  }
}

cout<<"No"<<endl;

}
