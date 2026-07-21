#include <stdio.h>
int main(){

  int n,x1,y1,x2,y2,x,y,result=0,i;

  scanf("%d %d %d",&x1,&y1,&n);

  scanf("%d %d",&x1,&y1);

  for(i = 0; i < n-1; i++){

    scanf("%d %d",&x2,&y2);
    x=x2-x1;
    y=y2-y1;
    if(x < 0) x *= -1;
    if(y < 0) y *= -1;

    result += x;
    result += y;

    if((x2-x1)*(y2-y1) > 0){

      if(x > y) result -= y;
      else result -= x;

    }

    // printf("%d\n",result);                                                                                                                                                                  

    x1=x2;
    y1=y2;

  }

  printf("%d\n",result);

  return 0;

}
