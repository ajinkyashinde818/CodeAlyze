#include<stdio.h>
int main(void)
{ char s[4]={0};
  int check[4]={0};
  scanf("%s\n",s);
  int i=0;int j;
  int count=0;
  for(i=0;i<4;i++)
  { if(s[i]=='a')j=0;
    if(s[i]=='b')j=1;
    if(s[i]=='c')j=2;
     if(check[j]==0)
     { count++;
       check[j]++;
     }
  }
  if(count==3){puts("Yes");}else{puts("No");}
 return 0;
}
