#include<stdio.h>
int main(){
  char a[3]={0};
  
  scanf("%s %s %s",&a[0],&a[1],&a[2]);
  
  if(a[0]!=a[1]&&a[1]!=a[2]&&a[0]!=a[2]){
    printf("Yes");}
  else{
    printf("No");
  }
  return(0);
}
