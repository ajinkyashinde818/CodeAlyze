#include<stdio.h>

int main()
{
  char S[4];
  int flag[3]={0,0,0};
  int i;
  scanf("%s",S);
  
  for(i=0;S[i]!='\0';i++){
    if(S[i]=='a'&&flag[0]!=1)
      flag[0]=1;
    else if(S[i]=='b'&&flag[1]!=1)
      flag[1]=1;
    else if(S[i]=='c'&&flag[2]!=1)
      flag[2]=1;
  }

  for(i=0;i<3;i++)
    if(flag[i]==0){
      printf("No");
      return 0;
    }
  printf("Yes");
  return 0;
}
