#include<stdio.h>
#include<math.h>
int main(){
  int n,m,a,b,c,d,x[100],y[100],r[100],f,ty,tx,ox,oy,i;
  double td,od,cd,px,py;
  while(scanf("%d",&n),n){
    for(i=0;i<n;i++)scanf("%d %d %d",&x[i],&y[i],&r[i]);
    scanf("%d",&m);
    while(m--){
      scanf("%d %d %d %d",&tx,&ty,&ox,&oy);
      for(i=f=0;i<n;i++){
	td=hypot(tx-x[i],ty-y[i]);
	od=hypot(ox-x[i],oy-y[i]);
	a=ox-tx;
	b=ty-oy;
	c=ty*a+tx*b;
	d=a*x[i]-b*y[i];
	cd=abs(a*y[i]+b*x[i]-c)/hypot(a,b);
	px=1.0*(b*c+a*d)/(a*a+b*b);
	py=1.0*(a*c-b*d)/(a*a+b*b);
	if(td<r[i]&&od<r[i])continue;
	if((tx<=px&&px<=ox||tx>=px&&px>=ox)&&(ty<=py&&py<=oy||ty>=py&&py>=oy)){
	  if((double)r[i]+0.000000001>cd)f=1;
	}
	if(td<r[i]&&r[i]<od)f=1;
	if(td>r[i]&&r[i]>od)f=1;//printf("%f %f %f %f %f\n",td,od,cd,px,py);
	if(f)break;
      }
      if(f)printf("Safe\n");
      else printf("Danger\n");
    }
  }
  return 0;
}
