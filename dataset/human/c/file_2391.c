#include<stdio.h>
int main(void){
char s[3];
  int i;
  int judgea=0,judgeb=0,judgec=0;
  scanf("%s",s);
  for(i=0;i<3;i++){
  if(s[i]=='a'){
  judgea=1;
  }
  }
   for(i=0;i<3;i++){
  if(s[i]=='b'){
  judgeb=1;
  }
  }
   for(i=0;i<3;i++){
  if(s[i]=='c'){
  judgec=1;
  }
  }
  if(judgea==1&&judgeb==1&&judgec==1){
  printf("Yes");
  }else{
  printf("No");
  }
  return 0;
}
