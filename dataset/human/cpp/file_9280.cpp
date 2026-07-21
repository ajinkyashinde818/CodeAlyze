#include<iostream>
#include<vector>
using namespace std;
int main(){
  int n,m; cin >> n >> m;
  vector<string> a,b;
  int cnt = 0;
  for(int i = 0; i < n; i++){
    string s; cin >> s;
    a.push_back(s);
  }
  for(int i = 0; i < m; i++){
    string s; cin >> s;
    b.push_back(s);
  }
  for(int x = 0; x < n; x++){
    for(int y = 0; y < n; y++){
      if(x + m - 1 >= n or y + m - 1 >= n) continue;
      
      bool match = true;
      for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
          if(a.at(x+i).at(y+j) != b.at(i).at(j)) match =false;
        }
      }
      if(match){
        cout << "Yes";
        return 0;
      }
      
    }
  }
  cout << "No";
}
