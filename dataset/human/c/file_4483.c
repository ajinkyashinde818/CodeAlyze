#include<stdio.h>
#include<string.h>

int main(void){
  int n;
  int d1[101],d2[101];
  scanf("%d",&n);

  int flag = 0;
  for(int i = 0;i<n;i++){
   scanf("%d %d",&d1[i],&d2[i]); 
    if(d1[i]==d2[i]) flag++;
    else flag = 0;
    if(flag == 3){
     printf("Yes");
      return 0;
    }
  }
  
  printf("No");
  return 0;
}
