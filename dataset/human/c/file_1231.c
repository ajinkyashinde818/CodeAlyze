#include<stdio.h>
#include <string.h>
int main(void){
  int i, j, tmp;
  char a[100], b[100];
  scanf("%s %s", a, b);
  for( i = 0; i < strlen(a); i++){
    for( j = i + 1 ; j < strlen(a); j++){
      if( a[i] > a[j]){
        tmp = a[j];
        a[j] = a[i];
        a[i] = tmp;
      }
    }
  }
  for( i = 0; i < strlen(b); i++){
    for( j = i + 1 ; j < strlen(b); j++){
      if( b[i] < b[j]){
        tmp = b[j];
        b[j] = b[i];
        b[i] = tmp;
      }
    }
  }
  if( strcmp( a, b) < 0 ){
    puts("Yes");
  }else{
    puts("No");
  }
  return 0;
}
