#include<stdio.h>
int MIN(int a,int b){return a<b?a:b;}
int main(){
  int n,m,a[20],b[20],i,j,c,ans=1e9,s,d;
  scanf("%d %d",&n,&m);
  for(i=0;i<n;i++)scanf("%d %d",&a[i],&b[i]);
  for(i=0;i<(1<<n);i++){
    s=m/100;
    for(j=c=0;j<n;j++){
      if(i&(1<<j)){
	s-=b[j]/100+a[j]*(j+1);
	c+=a[j];
      }
    }
    for(j=n;j;j--){
      if((i&(1<<(j-1)))||s<=0)continue;
      d=MIN((s-1)/j+1,a[j-1]);//printf("s%d %d\n",s,d);
      s-=d*j;
      c+=d;
    }
    if(s<=0)ans=MIN(ans,c);//printf("%d %d\n",c,i);
  }
  printf("%d\n",ans);
  return 0;
}
