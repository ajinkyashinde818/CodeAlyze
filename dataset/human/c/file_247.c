#include<stdio.h>
//小さい順にソート
int c[100002];
void merge(int i,int j,long long *s){
  if(i!=j){
    merge(i,(i+j)/2,s);
    merge((i+j)/2+1,j,s);
    int a=i,b=(i+j)/2+1;
    int d;
    for(d=i;d<=j;d++){
      if((i+j)/2<a){
        c[d]=s[b];
        b++;
      }
      else if(j<b){
        c[d]=s[a];
        a++;
      }
      else if(s[a]<s[b]){
        c[d]=s[a];
        a++;
      }
      else{
        c[d]=s[b];
        b++;
      }
    }
    for(d=i;d<=j;d++)
      s[d]=c[d];
  }
}

int main(){
  int n,i,count=0;
  scanf("%d",&n);
  long long a[n+1],sum=0;
  for(i=0;i<n;i++){
    scanf("%lld",&a[i]);
    if(a[i]<0){
      a[i]=-a[i];
      count++;
    }
  }
  merge(0,n-1,a);
  if(count%2==0)
    sum+=a[0];
  else
    sum-=a[0];
  for(i=1;i<n;i++)
    sum+=a[i];
  printf("%lld\n",sum);
  return 0;
}
