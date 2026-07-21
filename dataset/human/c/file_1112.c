#include <stdio.h>
int read(char s[]){
  int i,tmp=1,ret=0;
  for(i=0;s[i];i++){
    if(s[i]=='m'){
      ret+=tmp*1000;
      tmp=1;
    }
    else if(s[i]=='c'){
      ret+=tmp*100;
      tmp=1;
    }
    else if(s[i]=='x'){
      ret+=tmp*10;
      tmp=1;
    }
    else if(s[i]=='i')
      ret+=tmp;
    else
      tmp=s[i]-'0';
  }
  return ret;
}
int main(void){
  int n,t1,t2,ans;
  char s1[9],s2[10];
  scanf("%d",&n);
  while(n--){
    scanf("%s",s1);scanf("%s",s2);
    ans=read(s1)+read(s2);
    if(ans/1000==1)
      printf("m");
    else if(ans/1000)
      printf("%dm",ans/1000);
    ans%=1000;
    if(ans/100==1)
      printf("c");
    else if(ans/100)
      printf("%dc",ans/100);
    ans%=100;
    if(ans/10==1)
      printf("x");
    else if(ans/10)
      printf("%dx",ans/10);
    ans%=10;
    if(ans==1)
      printf("i");
    else if(ans)
      printf("%di",ans);
    puts("");
  }
  return 0;
}
