#include <stdio.h>
#include <stdlib.h>
typedef long long ll;
int main(void)
{
  int n,k,c;
  scanf("%d%d%d",&n,&k,&c);
  char str[n+1];
  int l[k],r[k],j=0;
  scanf("%s",str);
  for(int i=0;i<k;i++){
    while(str[j]=='x') j++;
    l[i]=j;
    j+=c+1;
  }
  j=n-1;
  for(int i=k-1;i>=0;i--){
    while(str[j]=='x') j--;
    r[i]=j;
    j-=c+1;
  }
  for(int i=0;i<k;i++)
    if(l[i]==r[i]) printf("%d\n",l[i]+1);

}
