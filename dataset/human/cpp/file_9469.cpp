#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, m;
vector<string> A, B;

bool match_temp(int w, int h) {
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < m; j++) {
      if(A[h+i][w+j] != B[i][j]) {
        return false;
      }
    }
  }
  return true;
}

int main(){
  cin >> n >> m;
  
  for(int i = 0; i < n; i++){
    string tmp;
    cin >> tmp;
    A.push_back(tmp);
  }
  for(int i = 0; i < m; i++){
    string tmp;
    cin >> tmp;
    B.push_back(tmp);
  }

  bool flg = false;
  for(int h = 0; h < n-m+1; h++){ // vertical search
/*
    size_t Pos = A[h].find(B[h]);
    if(Pos == string::npos){
      cout << "npos: " << h << endl;
      continue;
    }
    */
    for(int w = 0; w < n-m+1; w++) { // horizontal search
      if(match_temp(w, h)) {
        flg = true;
      }
      if(flg) {
        break;
      }
    }
  }
  if(flg) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
