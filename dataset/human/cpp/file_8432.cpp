#include<iostream>
using namespace std;
int main(){
  char a[50][50];
  char b[50][50];
  int n,m;
  cin >> n >> m;
  int i,j;
  for(i = 0;i<n;i++){
    for(j = 0;j<n;j++){
    	cin >> a[i][j];
    }
  }

  for(i = 0;i<m;i++){
    for(j = 0;j<m;j++){
    	cin >> b[i][j];
    }
  }
  int flag = 0, k, l;
  for(i = 0;i<=n-m;i++){
    for(j = 0;j<=n-m;j++){
      flag = 0;
      for(k = i;k<i + m;k++){
        for(l = j;l<j + m;l++){
        	if(a[k][l] != b[k - i][l - j]){
              flag = 1;
            }
        }
      }
      if(flag == 0){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
    
  cout << "No" << endl;
  return 0;
}
