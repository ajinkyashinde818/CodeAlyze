#include <cstdio>
#include <cstring>
#include <utility>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n,m;
    cin >> n >>m;
    char s[n][n];
    char t[m][m];
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++)
        cin >> s[i][j];
    }
    for(int i=0;i<m;i++){
      for(int j=0;j<m;j++)
        cin >> t[i][j];
    }

    for(int i=0;i<=n-m;i++){
      for(int j=0;j<=n-m;j++){
        bool ans=true;
        for(int k=0;k<m;k++){
          for(int l=0;l<m;l++){
            if(s[i+k][j+l]!=t[k][l]){
              ans = false;
              break;
            }
          }
        if(!ans){
          break;
        }
      }
      if(ans){
        cout << "Yes"<<endl;
        return 0;
      }
    }
  }
    cout << "No"<<endl;
  return 0;
}
