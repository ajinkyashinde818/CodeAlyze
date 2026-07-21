#include<stdio.h>
double abso(double a,double b){
  if(a-b<0)
    return b-a;
  else
    return a-b;
}
int main(){
  int n,i;
  scanf("%d",&n);
  double a[n],sum=0,x,y=0,min;
  scanf("%lf",&x);
  for(i=1;i<n;i++){
    scanf("%lf",&a[i]);
    sum+=a[i];
  }
  min=abso(x,sum);
  for(i=1;i<n-1;i++){
    x+=a[i];
    sum-=a[i];
    if(abso(x,sum)<min)
      min=abso(x,sum);
  }
  printf("%.0lf\n",min);
}
