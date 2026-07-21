#include<stdio.h>
int R=1,C=1,H[2000010],N[2000010];
//評価関数（いまはMIN）
int hyouka(int a,int b){
  if(C<b)return 1;
  if(C<a||b==0)return 0;
  return N[H[a]]<N[H[b]]?1:0;
}
//挿入関数
void hin(int a){
  int i=C++;
  for(N[H[0]=R]=a;hyouka(0,i/2);i/=2)H[i]=H[i/2];
  H[i]=R++;
}
//取り出す関数
int hout(){
  int rt=H[1],i,j=2,k=H[--C];
  for(i=1;hyouka(i,C);i=j)H[i]=H[j=i*2+1-hyouka(i*2,i*2+1)];
  H[j/2]=k;
  return rt;
}
int main(){
  int n,a,i,d[300010];
  long long s=0;
  scanf("%d",&n);
  for(i=0;i<3*n;i++){
    scanf("%d",&a);
    hin(a);
  }
  for(i=0;i<3*n;i++)d[i]=N[hout()];
  for(i=0;i<n;i++)s=s+d[i*2+n];
  printf("%lld\n",s);
  return 0;
}
