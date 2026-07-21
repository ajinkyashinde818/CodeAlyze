#include<stdio.h>


main()
{
    int a,b,c,d,ar1,ar2;
    scanf("%d %d %d %d",&a,&b,&c,&d);

    ar1=a*b;
    ar2=c*d;

    if(ar1>ar2 || ar1==ar2)
        printf("%d",ar1);
    else if(ar1<ar2)
        printf("%d",ar2);

return 0;
}
