#include<stdio.h>
int main(void){
  int A=0,B=0,C=0,D=0;
  int s1=0,s2=0;
  scanf("%d%d%d%d",&A,&B,&C,&D);
  s1=A*B;
  s2=C*D;
  if (s1==s2){
    printf("%d\n",s1);
}
  if (s1>s2){
    printf("%d\n",s1);
}
  else if(s1<s2) {
    printf("%d\n",s2);
}


  return 0;
}
