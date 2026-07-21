#include<stdio.h>
#include<string.h>

int main(){
  char s[100000],s5[6],s6[7],s7[8];
  int i,n,flag;
  scanf("%s",s);
  n=strlen(s);
  s7[7]=s6[6]=s5[5]='\0';
  for(i=n-1;i>=0;i-=flag){
    for(int j=0;j<7;j++){
      s7[j]=s[i-6+j];
      if(j>0)
        s6[j-1]=s[i-6+j];
      if(j>1)
        s5[j-2]=s[i-6+j];
    }
    if(strcmp(s7,"dreamer")==0)
      flag=7;
    else if(strcmp(s6,"eraser")==0)
      flag=6;
    else if(strcmp(s5,"dream")==0||strcmp(s5,"erase")==0)
      flag=5;
    else{
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
}
