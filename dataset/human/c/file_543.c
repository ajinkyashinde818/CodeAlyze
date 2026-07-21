#include<stdio.h>
#include<math.h>
    int main(){
      int n,i;
      scanf("%d",&n);
      double a[n];
      double sum=0,y=0;
      double min,x;
      scanf("%lf",&x);
      for(i=1;i<n;i++){
        scanf("%lf",&a[i]);
        sum+=a[i];
      }
      min=fabs(x-sum);
      for(i=1;i<n-1;i++){
        x+=a[i];
        sum-=a[i];
        if(fabs(x-sum)<min)
          min=fabs(x-sum);
      }
      printf("%.0lf\n",min);
	}
