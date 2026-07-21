#include <iostream>
using namespace std;

int main(){
  int m, n, i, j;
  int flag = 0;
  cin >> n >> m;
  char a[n][n];
  char b[m][m];
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      cin >> a[i][j];
    }
  }
  
  for(i = 0; i < m; i++){
    for(j = 0; j < m; j++){
      cin >> b[i][j];
    }
  }
  
  int h = 0;
  int w = 0;
  int num = 0;
  int mm = m * m;
  int sub = n - m;
  while(w <= sub){
    while(h <= sub){
      for(i =  h; i < m + h; i++){
	for(j = w; j < m + w; j++){
	  if(a[i][j] == b[i - h][j - w]) {
	    num++;
	  }
	}
      }
      if(num == mm){
	flag = 1;
	break;
      }
      num = 0;
      h++;
    }
    h = 0;
    w++;
  }
  
  if(flag) printf("Yes\n");
  else printf("No\n");
  return 0;
}
