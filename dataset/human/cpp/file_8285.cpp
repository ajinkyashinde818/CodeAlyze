#include <bits/stdc++.h> 

using namespace std; 

int main(){ 
  int n,m;
  cin>>n>>m;
  vector<vector<char>> data(n, vector<char>(n)); 

for (int i = 0; i <n ; i++) { 
  for (int j = 0; j < n; j++) { 

cin >> data.at(i).at(j); 

}
} 
  vector<vector<char>> data2(m, vector<char>(m)); 

for (int i = 0; i <m; i++) { 

for (int j = 0; j < m; j++) { 

cin >> data2.at(i).at(j); 

}
} 
  bool y=false;
  for(int i=0;i<n-m+1;i++){
    for(int j=0;j<n-m+1;j++){
      bool x=true;
      for(int a=0;a<m;a++){
        for(int b=0;b<m;b++){
          if(data.at(i+a).at(j+b)!=data2.at(a).at(b)){
            x=false;
            break;
          }
        }
        if(x==false){
          break;
        }
        }
      if(x==true){
        y=true;
        break;
      }
    }
    if(y==true){
      break;
    }
  }

  if(y==false) cout<<"No";
  else cout<<"Yes";
}
