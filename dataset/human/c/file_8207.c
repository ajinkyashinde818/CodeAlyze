#include <stdio.h>
#include<string.h>
int main()
{
long int a=0,b=0,c=0,d=0,w=0,i,str1=0,str2=0,flag,j,count=1;
char x[101];
scanf("%ld %ld %ld %ld",&a,&b,&c,&d);
if(a*b==c*d)
{
    printf("%ld",a*b);
}
else{
    if(a*b>c*d)
    {
        printf("%ld",a*b);
    }else{
        printf("%ld",d*c);
    }
}
    

 return 0;
}
