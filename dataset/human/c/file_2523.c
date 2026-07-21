#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 
int compare_int(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int main()
{
  int N;
  int number;
  char s[1]={};
  int  ans[3]={};
  int i;
//    int k=0;
for(i=0;i<3;i++){
  scanf("%c", s);
//  printf("%s\n",s);
//  scanf("%lld %lld",  &D, &X);
  if('a'==s[0]) ans[0]=1;
  else if('b'==s[0]) ans[1]=1;
  else if('c'==s[0]) ans[2]=1;
//printf("%d%d%d\n",ans[0],ans[1],ans[2]);
}
  if(ans[0]&&ans[1]&&ans[2])  printf("Yes\n");  
  else printf("No\n"); 
return 0;
}
