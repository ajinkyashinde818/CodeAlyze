#include<stdio.h>
     
    int main(){
      int flag[3]={},i;
      char s[3];
      scanf("%s",s);
      for(i=0;i<3;i++){
        if(s[i]=='a') flag[0]=1;
        else if(s[i]=='b') flag[1]=1;
        else if(s[i]=='c') flag[2]=1;
      }
      if(flag[0]==1&&flag[1]==1&&flag[2]==1)
        printf("Yes\n");
      else
        printf("No\n");
    }
