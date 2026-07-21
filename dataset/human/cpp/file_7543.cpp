#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
  long a[200010],sum[200010],mina;
  int n;
  scanf("%d",&n);
  scanf("%ld",&sum[0]);
  for(int i=1;i<n;i++){
    scanf("%ld",&a[i]);
    sum[i]=sum[i-1]+a[i];
  }
  mina=labs(sum[n-1]-2*sum[0]);
  for(int i=1;i<n-1;i++)
    mina=min(mina,labs(sum[n-1]-2*sum[i]));
  printf("%ld\n",mina);
}
