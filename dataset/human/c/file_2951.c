#include<stdio.h>

int main()
{
  int  k, s, a=0, i, x, y, z;

  scanf("%d %d", &k, &s);

if(k > s) k=s;
while(k >= 0 ){
  x = k; if(x > s) x = s;
  y = x; if(x+y > s) y = s-x;
  z = y; if(x+y+z>s) z = s-x-y;

  if(x+y+z<s)break;
  while(1){
    if( x == y) if(y == z) a+=1; else a+=3;
    else if(y == z) a+=3; else a+=6;

    if(z+1 <= y-1){z++;y--;}else{break;}
  }
  k--;
}

  printf("%d\n", a);
  return 0;
}
