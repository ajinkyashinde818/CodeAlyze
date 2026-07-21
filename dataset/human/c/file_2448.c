#include<stdio.h>
int main(){
  char s[3];
  int t[3]={0};
  scanf("%s",s);
  int i,j=0;
    for(i=0;i<3;i++){
      if(s[i]=='a') t[0]=1;
        else if(s[i]=='b') t[1]=1;
               else t[2]=1;
    }  
    if(t[0]==1 && t[1]==1 && t[2]==1) printf("Yes");
      else printf("No");    
  return 0;
}
