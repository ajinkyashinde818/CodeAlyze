#include <stdio.h>
int main(){
    int n,now=1,a[10000];
    bool prime[1000000];
    a[0]=2;
    for(int i=3;i<1000000;i+=2){
        prime[i]=true;
    }
    for(int i=3;now<10000;i+=2){
        if(prime[i]){
            a[now]=i+a[now-1];
            now++;
            if((long long)i*i<1000000){
            for(int j=i*i;j<1000000;j+=i){
                prime[j]=false;
            }
            }
        }
    }
    while(1){
        scanf("%d",&n);
        if(n==0)return 0;
        printf("%d\n",a[n-1]);
    }
}
