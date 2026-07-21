#include<stdio.h>
int main(void)
{
  int e,y,a;
scanf("%d",&e);
scanf("%d",&y);
if(e==0){
  if(y>=1989){
    a=y-1988;
    printf("H%d\n",a);
  }
  else if(y>=1926){
    a=y-1925;
    printf("S%d\n",a);
  }
      else if(y>=1912){
    a=y-1911;
    printf("T%d\n",a);
  }
        else{
    a=y-1867;
    printf("M%d\n",a);
  }
}
else{
  switch(e){
    case 1:
      a=y+1867;
      break;
    case 2:
      a=y+1911;
      break;
    case 3:
      a=y+1925;
      break;
    case 4:
      a=y+1988;
      break;
  }
printf("%d\n",a);
}
return 0;
}
