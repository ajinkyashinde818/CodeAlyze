#include <stdio.h>
#include <math.h>

int main() {

  double x1,y1,x,y;
  int w,h,n;
  int i,j,ki,l;
  double xs,ys;
  int s=0;
  scanf("%d %d %d",&w,&h,&n);


  scanf("%lf %lf",&x1,&y1);


  for(i = 0; i<n-1; i++) {

    scanf("%lf %lf" ,&x,&y);
    //     printf("x = %lf x1 = %lf \n",x , x1);

    xs = x1-x;
    ys = y1-y;
  
    //     printf("xs = %lf\n",xs);

    if(xs*ys > 0) {
      xs = xs * xs;
      ys = ys * ys;
      //    printf("xs = %lf\n",xs);
      xs = sqrt(xs);
      ys = pow(ys, 1.0/2);
      //   printf("xs = %lf\n ys = %lf\n",xs,ys);

      if(xs > ys) {
	s = s + xs;
	//	printf("s = %d\n",s);
      } else {
	s = s + ys;
      }
    } else {

      xs = xs * xs;
      ys = ys * ys;
      xs = pow(xs, 1.0/2);
      ys = pow(ys, 1.0/2);
      s = s + xs + ys;
    }

    x1 = x;
    y1 = y;

  }

  printf("%d\n",s);

  return 0;

}
