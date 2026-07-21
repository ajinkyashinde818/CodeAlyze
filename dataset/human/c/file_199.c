#include <stdio.h>

int abs(int x){
  if(x >= 0) return x;
  else return -x;
}
/*
int min(int a,int b){
  if(a > b) return b;
  else return a;
}
*/

int main(){
  int n;
  scanf("%d\n",&n);
  int a[n];
  for(int i = 0; i < n; ++i) scanf("%d",&a[i]);
  long answer = 0;
  int numminus = 0;
  int flag = 0;
  int min = abs(a[0]);
  for(int i = 0; i < n; ++i){
    if(a[i] < 0){
      numminus++;
      a[i] = -a[i];
    }
    if(min > a[i]) min = a[i];
    answer += (long)a[i];
    if(a[i] == 0) flag = 1;
  }
  if((numminus % 2 == 1) && (flag == 0)){
    answer -= 2 * (long) min;
  }
  
  printf("%ld\n",answer);
  return 0;
}
