#include<iostream>
#include<string>
//#include<vector>
using namespace std;

int main(){
  int n, m, pos, jdg=0;
  cin >> n >> m;
  string a[n], b[m];
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  for(int i=0;i<m;i++){
    cin >> b[i];
  }
  for(int i=0;i<n-m+1;i++){
    for(int j=0;j<m;j++){
      for(int k=0;k<n-m+1;k++){
        if(a[i+j].substr(k,m)==b[j]){
          jdg += 1;
          int o=j;
          for(int l=i+j+1;l<m+i+j;l++){
            o++;
            if(a[l].substr(k,m)!=b[o]){
              jdg = 0;
              break;
            }
            else{
              jdg += 1;
            }
          }
        }
        if(jdg==m)break;
      }
      if(j==0 && jdg==0)break;
      else if(jdg==m)break;
    }
    if(jdg==m)break;
  }
  if(jdg==m)cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
