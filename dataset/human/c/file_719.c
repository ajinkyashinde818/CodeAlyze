#include <stdio.h>
int main(void){
    int d;
    scanf("%d",&d);
    int a[30];
    for(int i=0;i<30;i++)a[i]=0;
    char c[100005];
    scanf("%s",c);
    for(int i=0;i<d;i++){
        a[c[i]-'a']++;
    }
    long long p=1000000007;
    long long ans=1;
    for(int i=0;i<26;i++){
        ans*=a[i]+1;
        ans%=p;
    }
    printf("%lld\n",(ans-1+p)%p);
}
