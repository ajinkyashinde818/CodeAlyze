#include <iostream>
#include <vector>
using namespace std;

int main(){
  int m, n;
  cin >> n;
  bool trig=true;
  for(int i=0; i*i<=1+8*n; i++){
    if(i*i==1+8*n){
      m=(1+i)/2;
      trig=false;
      break;
    }
  }
  if(trig){
    cout << "No" << endl;
  }
  else {
    cout << "Yes" << endl;
    cout << m << endl;
    vector<vector<int>>ret(m);
    int inc=1;
    for(int i=0; i<m-1; i++){
      for(int j=i+1; j<m; j++){
        ret[i].push_back(inc);
        ret[j].push_back(inc);
        inc++;
      }
    }
    for(int i=0; i<m; i++){
      cout << m-1 << ' ';
      for(int r: ret[i])cout << r << ' ';
      cout << endl;
    }
  }
  return 0;
}
