#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
  char a[3];
  int i;
  scanf("%s",a);
  for(i=0;i<2;i++)
    if(a[i]=='9'){
      printf("Yes\n");
      return 0;
    }
  printf("No\n");
}
