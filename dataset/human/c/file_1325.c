#include<stdio.h>
int main()
{
int n,m,i;
  scanf("%d %d",&n,&m);
  int a[m],b[m],sw1[n+1],sw2[n+1],cc;
  
  for(i=0;i<n+1;++i)
  {
  sw1[i]=0;
  sw2[i]=0;
  }
  
  cc=0;
  
  for(i=0;i<m;++i)
  {
  scanf("%d %d",&a[i],&b[i]);
  if(a[i]==1) sw1[b[i]]++;
  if(b[i]==n) sw2[a[i]]++;
  }

  for(i=1;i<n+1;++i)
  {
  if(sw1[i]>0 && sw2[i]>0) cc++;
  }
  if(cc >0) printf("POSSIBLE");
  else printf("IMPOSSIBLE");

return 0;}
