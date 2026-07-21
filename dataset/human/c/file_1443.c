#include<stdio.h>
#include<iso646.h>
 
#include<stdio.h>
#include<string.h>
#include<iso646.h>
 
int main(){
  char N[2];
 
  scanf("%s",N);
 
  if(N[0] == '9' or N[1] == '9'){
    printf("Yes\n");
  }else{
    printf("No\n");
  }
 
return 0;
}
