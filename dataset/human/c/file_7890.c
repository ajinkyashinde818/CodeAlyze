#include <stdio.h>

//素数列挙
//pには充分な要素数の配列のアドレス、返り値は個数
#include <stdbool.h>
#define n0 16000 //上限/2
#define n1 180    //sqrt(上限)/2

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
  int p[100005],n,a,b,z=0,l[100005]={},np,i,j,m,x=0;
  np=prime(&p);
  scanf("%d",&n);
  scanf("%d",&m);
  for(i=0;i<n;i++){
    scanf("%d",&a);
    a>>=1;
    for(j=0;j<np;j++){
      if(a==1) break;
      b=0;
      while(a%p[j]==0){
        a/=p[j];
        b++;
      }
      if(j==0){
        if(i==0){
          z=b;
        }else if(z!=b){
          z=-1;
          break;
        }
      }
      if(l[j]<b){
        l[j]=b;
      }
    }
    if(a!=1){
      p[np]=a;
      l[np]=1;
      np++;
    }
    if(z==-1) break;
  }
  if(z!=-1){
    x=1;
    for(i=0;i<np;i++){
      for(j=0;j<l[i];j++){
        if((long)x*p[i]>(long)m)break;
        x*=p[i];
      }
      if(j!=l[i]){
        x=0;
        break;
      }
    }
  }
  if(x!=0){
    printf("%d",((m+x)>>1)/x);
  }else{
    printf("0");
  }
  return(0);
}
