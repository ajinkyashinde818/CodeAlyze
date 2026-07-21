#include<stdio.h>
int judge_abc(char *s,char a[4]){
  if(*s==a[0]){
    *s++;
    if(*s==a[1]){
      *s++;
      if(*s==a[2]){
        return 1;
      }
    }
  }
  return 0;
}
int main(void){
  char s[4];
  scanf("%s",s);
  while(
  judge_abc(s,"abc")||
  judge_abc(s,"acb")||
  judge_abc(s,"bac")||
  judge_abc(s,"bca")||
  judge_abc(s,"cab")||
  judge_abc(s,"cba")
  ){
    puts("Yes");
    return 0;
  }
  puts("No");
  return 0;
}
