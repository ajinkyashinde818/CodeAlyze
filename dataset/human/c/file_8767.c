#include<stdio.h>
#define MOD 1000000007
long int PROD(long int a,long int b){return (a+MOD)%MOD*((b+MOD)%MOD)%MOD;}//a*b
void quicksort(long int a[],int s,int t){
  if(s<t){
    long int i=s,j=t,p=a[(s+t)/2];
    while(1){
      while(a[i]>p)i++;
      while(p>a[j])j--;
      if(i>=j)break;
      a[i]^=a[j]^=a[i]^=a[j];
      i++;j--;
    }
    quicksort(a,s,i-1);quicksort(a,j+1,t);
  }
}
int main(){
  long int p[200001],m[200001],i,j,k,n,x=0,y=0,r=1;
  scanf("%ld%ld",&n,&k);
  for(i=0;i<n;i++){scanf("%ld",&j);if(j>0){p[x]=j;x++;}else{m[y]=-j;y++;}}
  quicksort(p,0,x-1);quicksort(m,0,y-1);
  if(x==0&&k%2){for(i=1;i<=k;i++)r=PROD(r,-m[y-i]);printf("%ld",r);return 0;}
  if(n==k){for(i=0;i<x;i++)r=PROD(r,p[i]);for(i=0;i<y;i++)r=PROD(r,-m[i]);printf("%ld",r);return 0;}
  j=k<y?k-k%2:y-y%2;
  while(j>1&&k-j+1<x&&p[k-j]*p[k-j+1]>m[j-1]*m[j-2])j-=2;
  for(i=0;i<k-j;i++)r=PROD(r,p[i]);
  for(i=0;i<j;i++)r=PROD(r,-m[i]);
  printf("%ld",r);
}
