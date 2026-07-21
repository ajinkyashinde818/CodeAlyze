#include<stdio.h>
int main(){
 int c=1,d=0;
char a[3];
scanf ("%s",a);
  for (int i=0;i<3;i++){
  if (a[i]=='a'){
    d=d+1;
  }
  else if(a[i]=='b'){
  c=c*2;
  d=d+2;
  }
  else if(a[i]=='c'){
    c=c*3;
  d=d+3;
  }
  }
  if(c==6 & d==6){
    printf("Yes");
  }
  else{
  printf ("No");
  }
   return 0;
}
