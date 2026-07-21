#include<stdio.h>

int main()
{
 int A,B,C,D;

 scanf("%d%d%d%d",&A,&B,&C,&D);

 if((A*B==C*D)||(A*B>C*D))printf("%d\n",A*B);
 else if(A*B<C*D)printf("%d\n",C*D);

 return 0;
}
