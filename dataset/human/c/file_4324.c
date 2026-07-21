#include<stdio.h>
#include<stdlib.h>

int main(void){
  int n,m;
  int i,j;

  scanf("%d%d",&n,&m);
  int a[m];
   long long int b[n];
  for(i=0;i<n;i++)
  b[i]=100;




  for(i=0;i<m;i++){
    scanf("%d",&a[i]);
    b[a[i]-1]=0;
    if(i>0&&(a[i]==a[i-1]+1)){
      printf("%d",0);
      return 0;
    }
  }


  //ここから先は二つ連続で穴が来ることはないから。

  if(b[0]==0)
  b[1]=1;
  else if(b[1]==0)
  b[0]=1;
  else{
    b[0]=1;
    b[1]=2;
  }

  for(i=2;i<n;i++){
    if(b[i]!=0)
    b[i]=b[i-1]+b[i-2];
    b[i]=b[i]%1000000007;
  }
  b[n-1]=b[n-1]%1000000007;
  //for(i=0;i<n;i++)
  //printf("%ddanme:%lld\n",i+1,b[i]);
  printf("%lld",b[n-1]);
  return 0;
}
