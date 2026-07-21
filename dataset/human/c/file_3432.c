#include<stdio.h>
#include<string.h>

int main()
{
  char s[100001];
  int i,l;
  scanf("%s",s);
  l=strlen(s);
  i=l-1;
  while(1){
    if(i==-1){
      printf("YES");
      return 0;
    }
    else if(i>=6 && s[i]=='r' && s[i-1]=='e' && s[i-2]=='m' && s[i-3]=='a' && s[i-4]=='e' && s[i-5]=='r' && s[i-6]=='d'){
      i-=7;
    }
    else if(i>=5 && s[i]=='r' && s[i-1]=='e' && s[i-2]=='s' && s[i-3]=='a' && s[i-4]=='r' && s[i-5]=='e'){
      i-=6;
    }
    else if(i>=4 && s[i]=='m' && s[i-1]=='a' && s[i-2]=='e' && s[i-3]=='r' && s[i-4]=='d'){
      i-=5;
    }
    else if(i>=4 && s[i]=='e' && s[i-1]=='s' && s[i-2]=='a' && s[i-3]=='r' && s[i-4]=='e'){
      i-=5;
    }
    else{
      printf("NO");
      return 0;
    }
  }
}
