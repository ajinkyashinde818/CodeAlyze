#include<stdio.h>
int main(){
  int n;
  scanf("%d", &n);
  int a[n],i,min=1000000000,minus=0,zero=0;
  long long int sum=0;
  for(i=0;i<n;i++){
    scanf("%d", &a[i]);
    if(a[i]<0){
      a[i]*=-1;
      minus++;
    }
    if(min>a[i]) min=a[i];
    if(a[i]==0) zero++;
    sum+=a[i];
  }
  int c=0;
  if(minus%2!=0) c=1;
  if(zero>0) c=0;
  if(c==1) sum-=min*2;
  printf("%lld", sum);
  return 0;
}
