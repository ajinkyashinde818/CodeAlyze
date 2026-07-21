#include <stdio.h>

int Euclid(int x, int y);

int main(void)
{
    long A,B; /*input var*/
    long lcm; /*least common multiple*/
    
    scanf("%ld %ld",&A,&B);
    lcm = A*B/Euclid(A,B);
    printf("%ld \n",lcm);
    return 0;
}

int Euclid(int x, int y)
{
    if(y==0)    return x;
    else    return Euclid(y,x%y);
}
