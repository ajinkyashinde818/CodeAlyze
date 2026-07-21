#include<stdio.h>
int gcd(int,int);
int main(){
    int a,b,k,g;
    scanf("%d %d %d",&a,&b,&k);

    g = gcd(a,b);
    int ans[30];
    int j=0;

    for(int i=g;i>0;i--){
        if(g%i==0){
            ans[j] = i;
            j++;
        }
    }        

    printf("%d",ans[k-1]);

    return 0;
}
int gcd(int a,int b){
    if(a>b){
        int tmp=0;
        tmp=a;
        a=b;
        b=tmp;
    }
    int c=b%a;
    while(1){
        c=b%a;
        if(c==0)
            break;
        b=a;
        a=c;
    }

    return a;
}
