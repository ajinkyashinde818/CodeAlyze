#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<char>>imaA(n,vector<char>(n));
  vector<vector<char>>imaB(m,vector<char>(m));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
      cin >> imaA.at(i).at(j);
  }
  for(int i=0;i<m;i++){
    for(int j=0;j<m;j++)
      cin >> imaB.at(i).at(j);
  }
  bool ans=false;
  for(int i=0,l=n-m+1;i<l;i++){
    for(int j=0;j<l;j++){
      if(imaA.at(i).at(j)==imaB.at(0).at(0)){
        bool br=false;
        for(int x=0;x<m;x++){
          for(int y=0;y<m;y++){
            if(imaA.at(i+x).at(j+y)!=imaB.at(x).at(y)){
              br=true;
              break;
            }
          }
          if(br)
            break;
        }
        if(!br){
          ans=true;
        }
      }
      if(ans)
        break;
    }
    if(ans)
      break;
  }
  cout << (ans ? "Yes":"No") << endl;
}
