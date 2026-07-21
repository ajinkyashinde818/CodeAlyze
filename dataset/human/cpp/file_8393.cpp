#include<iostream>
#include<vector>
#include<string>
using namespace std;
int N, M;

bool is_fitting(
  vector<string> A,
  vector<string> B,
  int x, int y,
  char dir
){
  if(x+M > N || y+M > N){
    return false;
  }
  for(int i=0;i<M;++i){
    for(int j=0;j<M;++j){
      // printf("Are %c and %c same ?\n", A[i+x][j+y], B[i][j]);
      if(A[i+x][j+y] != B[i][j]){
        // printf("pixels are not match... \t");
        // printf("current cursor is (%d, %d)\n",x, y);
        switch (dir){
          case 'd':
            return is_fitting(A, B, x+1, y, 'h') ||
            is_fitting(A, B, x, y+1, 'v') ||
            is_fitting(A, B, x+1, y+1, 'd');
          case 'h':
            return is_fitting(A, B, x+1, y, 'h');
          case 'v':
            return is_fitting(A, B, x+1, y, 'v');
        }
      }
    }
  }
  // printf("current cursor is (%d, %d)\n",x, y);
  return true;
}

int main(void){
  cin >> N >> M;
  int tmp;
  vector<string> A = vector<string>(N);
  vector<string> B = vector<string>(M);

  for(int i=0;i<N;++i){
    cin >> A[i];
  }
  for(int i=0;i<M;++i){
    cin >> B[i];
  }
  if(is_fitting(A, B, 0, 0, 'd')){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}
