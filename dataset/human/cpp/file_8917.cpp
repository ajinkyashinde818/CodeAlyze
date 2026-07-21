#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n,m;
  cin >> n >> m;
  vector<string>data_a(n);
  vector<string>data_b(m);
  for(int i=0;i<n;i++){
    cin >> data_a.at(i);
  }
  for(int i=0;i<m;i++){
    cin >> data_b.at(i);
  }
  bool exist=false;
  for(int li=0;li<n;li++){
    for(int lj=0;lj<n;lj++){
      if(li+m-1>=n||lj+m-1>=n){
        continue;
      }
      bool judge=true;
      for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
          if(data_a.at(li+i).at(lj+j)!=data_b.at(i).at(j)){
            judge=false;
          }
        }
      }
      if(judge){
        exist=true;
      }
    }
  }
  if(exist){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}
