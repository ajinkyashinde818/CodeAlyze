#include<stdio.h>
int main()
{
  const int NUM=20;
  int n,i;
  scanf("%d",&n);	// 数を取得
  int a[NUM];
  int b[NUM];
  int c[NUM];
  int point[NUM-1];	
  int pointnum=0;	// 追加ポイントの数
  
  for(i=0; i<n; i++)
  {
    scanf("%d",&a[i]);
    
    // a[i-1],a[i]が連続の場合は、a[i-1]を保持する
    if(i>0)
    {
      if(a[i]-a[i-1] == 1)
      {
        point[pointnum]=a[i-1];
        pointnum++;
      }
    }
  }

  int bsum=0;

  for(i=0; i<n; i++)
  {
    scanf("%d",&b[i]);
//    printf("%d ", b[i]);
    bsum += b[i];
  }
  int pointsum=0;
  for(i=0; i<n-1; i++)
  {
    scanf("%d",&c[i]);
//    printf("%d ", c[i]);
  }
  int csum=0;	// 追加ポイントのサム値
  for(i=0;i<pointnum;i++)
  {
//    printf("point[i]= %d\n",point[i]);
    csum += c[point[i]-1];
//    printf("%d unko\n", csum);
  }
  printf("%d",bsum+csum);
}
