#include<bits/stdc++.h>
using namespace std;
//size_t f = string::npos
//make pair, tuple

int main(){
      int n,m;cin >> n >> m;
      char arrn[n + 5][n + 5];
      char arrm[m + 5][m + 5];
      for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                  cin >> arrn[i][j];
            }
      }
      for(int i = 0;i < m;i++){
            for(int j = 0;j < m;j++){
                  cin >> arrm[i][j];
            }
      }
      for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                  if(arrn[i][j] == arrm[0][0]){
                        int c = 0;
                        for(int k = i;k < i + m;k++){
                              if(k < n){
                                    for(int l = j;l < j + m;l++){
                                          if(l < n){
                                                if(arrn[k][l] == arrm[k - i][l - j])c++;
                                          }
                                    }
                              }
                        }
                        if(c == m * m)return cout << "Yes", 0;
                  }
            }
      }
      cout << "No";
}
