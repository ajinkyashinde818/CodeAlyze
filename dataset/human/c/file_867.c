#include <stdio.h>
#include <stdbool.h>
#define n0 500000 //上限/2
#define n1 500    //sqrt(上限)/2

int prime(int *p){
  bool fp[n0]={};
  int i,j,np=1,s;
  for(i=0;i<n1;i++){
    if(fp[i]) continue;
    s=(i<<1)+3;
    for(j=(i+1)*3;j<n0;j+=s){
      fp[j]=1;
    }
  }
  p[0]=2;
  for(i=0;i<n0;i+=1){
    if(fp[i]^1){
      p[np]=(i<<1)+3;
      np++;
    }
  }
  return(np);
}

int main(){
  int i,j,p[200000],c,m=0,l[200000];
  long n;
  c=prime(&p);
  scanf("%ld",&n);
  for(i=0;i<c;i++){
    l[i]=0;
    while(n%p[i]==0){
      n/=p[i];
      l[i]++;
    }
  }
  if(n!=1){
    l[c]=1;
    c++;
  }
  for(i=0;i<c;i++){
    for(j=1;j<=l[i];j++){
      l[i]-=j;
      m++;
    }
  }
  printf("%d",m);
  return(0);
}
