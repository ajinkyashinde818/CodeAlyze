#include<stdio.h>
int main(void){
  int d[3] = {0};
  int i;
  int h = 0;
  char S[3];
  scanf("%s",&S);
  for(i = 0;i < 3;i++){
 	 if(S[i] == 'a'){
       if(d[0] == 0){
         h += 1;
         d[0] = 1;
       }
     }
    else if(S[i] == 'b'){
       if(d[1] == 0){
         h += 1;
         d[1] = 1;
       }
     }
    else if(S[i] == 'c'){
       if(d[2] == 0){
         h += 1;
         d[2] = 1;
       }
     }
  }
  if(h == 3)printf("Yes");
  else printf("No");
  return 0;
}
