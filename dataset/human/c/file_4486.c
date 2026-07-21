#include<stdio.h>
int main(){
  
  int sum=0;
  int n=0,i,j;
  int flag=0;
  int a[200][10];
  int b=0,c=0;
  scanf("%d", &n);

  for(i=0;i<n;i++){
    scanf("%d %d", &b,&c);
    for(j=0;j<2;j++){
      if(j == 0){
        a[i][j] = b;
      }else{
        a[i][j] = c;
      }
    }
  }

  for(i=0;i<n-2;i++){
    if(a[i][0] == a[i][1] && a[i+1][0] == a[i+1][1] && a[i+2][0] == a[i+2][1]){
      flag++;
    }
  }
  
  if(flag>=1){
    printf("Yes");
  }else{
    printf("No");
  }
  
 return 0; 
}
