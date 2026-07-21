#include <stdio.h>

int main(void)
{

  int a, b, k, i, s1, s2, j;
  scanf("%d%d%d",&a,&b,&k);
  j=0;
  for(i=100000;i>=0;i--){
        s1=a%i;
        s2=b%i;
        if((s1==0)&&(s2==0)){
                j++;
                if(j==k){
                        printf("%d\n",i);
                        return 0;
                }
        }
  }
  return 0;
}
