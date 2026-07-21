#include<stdio.h>
int f(char s[]){
  int n=0,i,k=1;
  for(i=0;s[i];i++){
    if(s[i]=='m')n+=k*1000;
    if(s[i]=='c')n+=k*100;
    if(s[i]=='x')n+=k*10;
    if(s[i]=='i')n+=k*1;
    if('0'<=s[i]&&s[i]<='9')k=s[i]-'0';
    else k=1;
  }
  return n;
}
int main(){
  int i,n,a;
  char s1[10],s2[10];
  scanf("%d",&n);
  while(n--){
    scanf("%s %s",s1,s2);
    a=f(s1)+f(s2);
    if(a/1000>1)printf("%d",a/1000);
    if(a/1000)  printf("m");
    a%=1000;
    if(a/100>1)printf("%d",a/100);
    if(a/100)  printf("c");
    a%=100;
    if(a/10>1)printf("%d",a/10);
    if(a/10)  printf("x");
    a%=10;
    if(a>1)printf("%d",a);
    if(a)  printf("i");
    printf("\n");
  }
  return 0;
}
