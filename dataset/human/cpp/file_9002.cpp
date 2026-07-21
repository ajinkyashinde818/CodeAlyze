#include <iostream>
using namespace std;

bool includePic(string A[], string B[], int Ar, int Ac, int m){
  int B_row, B_column;
  for(B_row = 0; B_row < m; B_row++){
    for(B_column = 0; B_column < m; B_column++){
      if(B[B_row][B_column] != A[Ar+B_row][Ac+B_column]) return false;
    }
  }
  return true;
}

int main(void){
  int n, m, A_row, A_column, B_row;
  cin >> n >> m;
  string A[n] = {}, B[m] = {};
  for(A_row = 0; A_row < n; A_row++){
    cin >> A[A_row];
  }
  for(B_row = 0; B_row < m; B_row++){
    cin >> B[B_row];
  }

  for(A_row = 0; A_row < n-m+1; A_row++){
    for(A_column = 0; A_column < n-m+1; A_column++){
      if(includePic(A, B, A_row, A_column, m)){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
