#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
typedef long long ll;
int main()
{
    ll N;
    int a=0,i,c,j;
    int l[8]={3,6,10,15,21,28,36,45};
    scanf("%lld",&N);
    for(i=2;i<1000001;i++){
        if(N%i) continue;
        c=0;
        while(N%i==0){
            c++;
            N/=i;
        }for(j=0;j<8;j++){
            if(l[j]>c) {
                a+=j+1;
                break;
            }
        }

    }
    if(N>1) a+=1;
    printf("%d",a);
}
