#include <iostream>
using namespace std;

char A[50][50],B[50][50];
int N,M;

bool check(int x,int y){
  for(int i=0;i<M;i++) for(int j=0;j<M;j++){
    if(A[i+x][j+y]!=B[i][j]) return false;
  }
  return true;
}

int main(){
  cin >> N >> M;
  for(int i=0;i<N;i++) for(int j=0;j<N;j++) cin >> A[i][j];
  for(int i=0;i<M;i++) for(int j=0;j<M;j++) cin >> B[i][j];
  for(int i=0;i<N-M+1;i++) for(int j=0;j<N-M+1;j++){
    if(check(i,j)){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
