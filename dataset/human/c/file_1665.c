#include <stdio.h>

int main(){
  int n, soma = 0, x;
  int a[21], b[21], c[21];

  scanf("%d", &n);

  for(int i = 0; i < n; ++i){
    scanf("%d", &a[i]);
  }
  for(int i = 0; i < n; ++i){
    scanf("%d", &b[i]);
  }
  for(int i = 0; i < n-1; ++i){
    scanf("%d", &c[i]);
  }

  soma = b[a[0]-1];


  for(int i = 1; i < n; ++i){
    if(a[i] == a[i-1]+1){
      soma = soma+b[a[i]-1]+c[a[i-1]-1];
    }
    else{
      soma = soma + b[a[i]-1];
    }
  }

  printf("%d\n", soma);
  return 0;
}
