#include<stdio.h>
#include<math.h>

long long int gojohou(int A,int B)
{
    if(A==0)
    {
        return B;
    }
    if(B==0)
    {
        return A;
    }
    
    if(A<B)
    {
        return gojohou(A,B%A);
    }
    if(A>B)
    {
        return gojohou(A%B,B);
    }
}

int main()
{
    long long int A;
    scanf("%lld",&A);
    
    long long int B;
    scanf("%lld",&B);
    
    long long int RETURN=A*B/gojohou(A,B);
    
    printf("%lld",RETURN);
    
    return 0;
}
