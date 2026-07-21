#include<stdio.h>

int main(void){
  int n,flag,flag2;
  int d1[100],d2[100];
  flag = 0;
  flag2 = 0;
  scanf("%d", &n);
  for(int i = 0; i < n;i++){
    scanf("%d %d", &d1[i], &d2[i]);
    if(d1[i] == d2[i]){
      flag++;
    }
    else{
      flag = 0;
    }
    if(flag == 3){
      flag2 = 1;
    }
  }
  if(flag2 == 1)
    printf("Yes");
  else
    printf("No");
  
  return 0;
}
