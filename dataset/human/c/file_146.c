#include<stdio.h>

int main(){
  int a[3],N,ans=0;
  scanf("%d%d%d%d",&a[0],&a[1],&a[2],&N);

  for (int i = 0; i < 2; i++)
  {
    int temp;
    if(a[i]>a[i+1]){
      temp=a[i];
      a[i]=a[i+1];
      a[i+1]=temp;
    }
  }

  if (a[0]==1&&a[1]==1&&a[2]==1)
  {
    ans=(N+1)*(N+2)/2;
  }else{
    for (int i = 0; i <= N/a[0]; i++){
      for (int j = 0; j <= (N-i*a[0])/a[1]; j++){
        for (int k = 0; k <= (N-i*a[0]-j*a[1])/a[2]; k++){
          if ((i*a[0]+j*a[1]+k*a[2])==N)
          {
            ans++;
          }
        }
      }
    }
  }

  printf("%d",ans);

  return 0;
}
