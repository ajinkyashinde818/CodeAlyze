#include<stdio.h>
#include<string.h>
//20000桁のマージソート(1単語10文字以下)
char c[101];
int sort(int a,int b,char s[101]){
  if(a==b)
    return 0;
  sort(a,(a+b)/2,s);
  sort((a+b)/2+1,b,s);
  int i=a,j=(a+b)/2+1,k=a;
  while(k<=b){
    if(i<(a+b)/2+1 && j<b+1){
      if(s[i]<s[j]){
        c[k]=s[i];
        i++;
      }
      else{
        c[k]=s[j];
        j++;
      }
    }
    else if(j>b){
      c[k]=s[i];
      i++;
    }
    else{
      c[k]=s[j];
      j++;
    }
    k++;
  }
  for(i=a;i<=b;i++)
    s[i]=c[i];
  return 0;
}

int main(){
  char s[101],t[101];
  scanf("%s%*c%s",s,t);
  int slen=strlen(s);
  int tlen=strlen(t);
  int i;
  sort(0,slen-1,s);
  sort(0,tlen-1,t);
  for(i=0;i<slen;i++){
    if(s[i]<t[tlen-1-i]){
      puts("Yes");
      return 0;
    }
    else if(s[i]>t[tlen-1-i]){
      puts("No");
      return 0;
    }
  }
  if(slen==tlen)
    puts("No");
  else
    puts("Yes");
  return 0;
}
