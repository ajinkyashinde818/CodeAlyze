#include <stdio.h>
#define MAX 110000
int p[MAX];
int prime[13000];
int c;
void hurui(){
  int i,j;
  for(i=0;i<MAX;i++)p[i]=1;
  p[0]=0;p[1]=0;c=0;
  for(i=2;i<MAX;i++){
    //printf("%d\n",i);
    if(p[i]==1){
      prime[c++]=i;
      for(j=2*i;j<MAX;j+=i)p[j]=0;
    }
  }

}
int main(){
  int i,n;
  hurui();
  long long int s;
  while(1){
    s=0;
    scanf("%d",&n);
    if(n==0)break;
    for(i=0;i<n;i++)s+=prime[i];
    printf("%lld\n",s);
  }
  return 0;
}
