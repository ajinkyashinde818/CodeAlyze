#include<stdio.h>
#include<math.h>
int main(void){
  long long int n,m,x,c[13],a[13][13],i,j,b,d,k,ans,s[13],money;
  scanf("%lld %lld %lld",&n,&m,&x);
  for(i=0;i<n;i++){
    scanf("%lld",&c[i]);
    for(j=0;j<m;j++){
      scanf("%lld",&a[i][j]);
  }
  }
  ans=1000000000000;
  for(i=0;i<m;i++){
    s[i]=0;
  }
  b=pow(2,n);
  for(i=0;i<b;i++){ //2^n通り
    d=1;
    for(j=0;j<n;j++){ //全桁、つまり全参考書について買うか買わない変えを見る
      if(i&(1<<j)){ 
	money+=c[j]; //買うなら金額を足しておく
	for(k=0;k<m;k++){
	  s[k]+=a[j][k]; //各アルゴリズムの理解度を足す
	}
      }
    }
    for(k=0;k<m;k++){ //各アルゴリズムが全部x以上になっているか？
      if(s[k]<x){
	d=0;
	break;
      }
    }
    if(d==1){
      if(ans>money){
	ans=money;
      }
    }
    money=0;
    for(k=0;k<m;k++){
      s[k]=0;
    }
  }
  if(ans==1000000000000){
    printf("-1\n");
  }else{
    printf("%lld\n",ans);
  }
  return 0;
}
