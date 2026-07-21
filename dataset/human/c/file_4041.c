#include <stdio.h>
int main(void)

{
    int a,b,k,i,n;

    scanf("%d%d%d",&a,&b,&k);

    if((1<=a)&&(a<=100)&&(1<=b)&&(b<=100)&&(1<=k)){
       if(a<b) n = a;
       else    n = b;
       for(i=n;k>0;i--)
          if((a%i == 0)&&(b%i == 0)) k--;
          printf("%d\n",i+1);
    }
    return 0;
}
