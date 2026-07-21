#include<stdlib.h>
#include<string.h>
#include<math.h>
#include <stdio.h>
int Min(int a,int b){
    return a<=b?a:b;
}
int main()
{   int ans,a,b,c;
    char s[10000];
    scanf("%d%d%d",&a,&b,&c);
    if(a+b+1>=c){
        ans=c+b;
       // printf("t");
    }else{
        ans=b+a+1+b;
        //printf("f");
    }
    printf("%d",ans);

    return 0;
}
