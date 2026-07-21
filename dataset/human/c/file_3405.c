#include<stdio.h>
#include<string.h>
int main(){
  char s[100002];
  scanf("%s",s);
  int len=strlen(s);
  while(len>0){
    if(len>=6 && s[len-6]=='e' && s[len-5]=='r' && s[len-4]=='a' && s[len-3]=='s' && s[len-2]=='e' && s[len-1]=='r')
      len-=6;
    else if(len>=5 && s[len-5]=='e' && s[len-4]=='r' && s[len-3]=='a' && s[len-2]=='s' && s[len-1]=='e')
      len-=5;
    else if(len>=5 && s[len-5]=='d' && s[len-4]=='r' && s[len-3]=='e' && s[len-2]=='a' && s[len-1]=='m')
      len-=5;
    else if(len>=7 && s[len-7]=='d' && s[len-6]=='r' && s[len-5]=='e' && s[len-4]=='a' && s[len-3]=='m' && s[len-2]=='e' && s[len-1]=='r')
      len-=7;
    else{
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  return 0;
}
