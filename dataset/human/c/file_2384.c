#include <stdio.h>

int main(){
   
  int a=0,b=0,c=0,i;
  char str[4];
  
  scanf("%s",str);
  
  for(i=0;i<3;i++){
   if(str[i]=='a'){
     a=a+1;
  }
  }
  
    for(i=0;i<3;i++){
   if(str[i]=='b'){
     b=b+1;
  }
  }
  
   for(i=0;i<3;i++){
   if(str[i]=='c'){
     c=c+1;
  }
  }
  
    if(a==1&&b==1&&c==1){
      puts("Yes");
    }
    else {
       puts("No");
    }
  
  return 0;
}
