#include<stdio.h>
#include <string.h>

int main()
{
  char S[100001],temp;
    scanf("%s",&S);
  char T[4][8]={"maerd","remaerd","esare","resare"};
  
  int s,i,j,a,k;
  
  
  s=strlen(S);
  
  for(i=0;i<s/2;i++)
  {
    temp=S[i];
    S[i]=S[s-i-1];
    S[s-i-1]=temp;
  }

  
  for(i=0;i<4 && strlen(S)>1;i++)
  {
    k=strlen(T[i]);
    s=strlen(S);

    a=strncmp(S,T[i],k);
    if(a==0)
    {
      for(j=0;j<s;j++)
      {
        S[j]=S[j+k];
      }
      i=-1;
    }
  }

  a=strlen(S);
  if(a==0)
  {
      printf("YES");
  }
  else
  {
      printf("NO");
  }


  return 0;
}
