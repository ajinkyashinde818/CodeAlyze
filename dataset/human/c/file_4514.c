#include <stdio.h>

int main() {
  long int n;
  int i;
  int flg = 0;
  int ans = 0;
  
  scanf("%ld", &n);
  
  long int d[n*2];
  
  for(i=0; i<(n*2); i++) {
    scanf("%ld", &d[i]);
  }

  for(i=0; i<(2*n); i=i+2){
    if(d[i]==d[i+1]) {
      ans = ans + 1;
    }
    if(ans==3) {
      flg = 1;
    }
    if(d[i]!=d[i+1]) {
      ans = 0;
    }
  }

  if(flg==1) {
    printf("Yes");
  } else {
    printf("No");
  }

  return 0;
}
