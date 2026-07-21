#include<stdio.h>
#include<stdlib.h>

int cmpnum(const void*n1,const void*n2)
{
  return *(int*)n2-*(int*)n1;
}

int main()
{
  int n;
  int i,j;
  long long a[300001];
  long long t,sum=0;
  scanf("%d",&n);
  for(i=0;i<3*n;i++){
    scanf("%lld",&a[i]);
  }
  /*for(i=0;i<3*n;i++){
    for(j=i+1;j<3*n;j++){
      t=a[i];
      if(a[i]<a[j]){
        a[i]=a[j];
        a[j]=t;
      }
    }
  }*/
  qsort(a,3*n,sizeof(long long),cmpnum);
  for(i=0;i<2*n;i++){
    if(i%2==1){
      sum+=a[i];
    }
  }
  printf("%lld",sum);
  return 0;
}
