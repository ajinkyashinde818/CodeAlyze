#include<stdio.h>

int gcd(int n,int m){
  if(n<m)return gcd(m,n);
  if(m==0)return n;
  return gcd(m,n%m);
}

#define lcm(a,b) ((a)*(b)/gcd((a),(b)))

int main (void){
  int r,g,b,n;
  scanf("%d %d %d %d",&r,&g,&b,&n);

  int r_max,ans=0;
  r_max=n/r;

  int i,j,nn,del;
  del=gcd(g,b);
  g/=del; b/=del;
  nn=n+r;
  for(i=0;i<=r_max;i++){
    nn=n-r*i;
    if(nn%del) continue;
    nn/=del;
    j=0;
    while(nn%b){
      nn-=g;
    }
    if(nn>=0)    ans+=(nn/b/g+1);
    //    printf("i:%d %d\n",i, ans);
  }
    

  printf("%d",ans);
  return 0;
}
