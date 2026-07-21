#include <string>
#include <iostream>
#include <vector>
using namespace std;

int n,m;
vector<string> A,B;

bool isMatch(int a, int b){
  for(int i=0;i<m;i++)
	  for(int j=0;j<m;j++){
        if(A[i+a][j+b]==B[i][j]) continue;
        else return false;
      }
  return true;
}

int main(){
  cin >> n >> m;
  for(int i=0;i<n;i++) {string s; cin >> s; A.push_back(s);}
  for(int i=0;i<m;i++) {string s; cin >> s; B.push_back(s);}
  for(int i=0;i<n-m+1;i++) for(int j=0;j<n-m+1;j++){
  	if(isMatch(i,j)){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;

}
