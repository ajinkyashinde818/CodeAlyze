#include<cstdio>
#include<algorithm>
using namespace std;

int main(void){
  long long s=0,t=0,ans=10000000000;
  int a[200001],n,i;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
    s+=a[i];
  }

  for(i=0;i<n-1;i++){
    t+=a[i];
    ans=min(ans,abs(s-2*t));
  }

  printf("%lld\n",ans);

  return 0;
}
