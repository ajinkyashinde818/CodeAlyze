#include <stdio.h>

int main(){
  int n,i,m,a[200005],b[200005],c=1,d[200005],e;
  long k;
  scanf("%d",&n);
  scanf("%ld",&k);
  for(i=0;i<n;i++){
    scanf("%d",&e);
    a[i]=e-1;
    d[i]=0;
  }
  b[0]=0;
  d[0]=1;
  for(i=a[0];d[i]==0;i=a[i]){
    b[c]=i;
    d[i]=1;
    c++;
  }
  e=1;
  m=i;
  d[0]=m;
  for(i=a[i];i!=m;i=a[i]){
    d[e]=i;
    e++;
  }
  if(k>=(long)c){
    printf("%d",d[(k-(long)c)%(long)e]+1);
  }else{
    printf("%d",b[k]+1);
  }
  return(0);
}
