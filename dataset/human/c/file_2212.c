#include <stdio.h>
#include <string.h>

int main(){
  char s[100001]={'\0'},left[200001]={'\0'},right[200001]={'\0'},input;
  int i,q,mode=0,flip=0,direct=0,len;
  int l_in=0,r_in=0;
  
  scanf("%s",s);  
  scanf("%d",&q);
  
  for(i=0;i<q;i++){
    scanf("%d",&mode);

    if(mode==1){
      flip=flip^1;
    } else if(mode==2){
      scanf("%d %c",&direct,&input);
      
      if((flip==0 && direct==1)||(flip==1 && direct==2)){
        left[l_in]=input;
        l_in++;
      } else if ((flip==0 && direct==2)||(flip==1 && direct==1)){
        right[r_in]=input;
        r_in++;
      }
    }
  }
  
  if(flip==0){
    for(i=l_in-1;i>=0;i--){
      printf("%c",left[i]);
    }
    printf("%s",s);
    printf("%s",right);
  } else {
    for(i=r_in-1;i>=0;i--){
      printf("%c",right[i]);
    }
    len=strlen(s);
    for(i=len-1;i>=0;i--){
      printf("%c",s[i]);
    }
    printf("%s",left);
  }
}
