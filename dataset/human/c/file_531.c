#include<stdio.h>
#include<stdlib.h>
long int a[200000];
long int arai;
long int sunu;
long int ans;
long int temp;
int main(void){
    int n,i;
    arai=0;
    sunu=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%ld",&a[i]);
        if(i!=0){
            arai+=a[i];
        }
    }
    sunu=a[0];
    ans=labs(arai-sunu);
    for(i=1;i<n-1;i++){
        arai-=a[i];
        sunu+=a[i];
        temp=labs(arai-sunu);
        if(ans>temp){
            ans=temp;
        }
    }
    printf("%ld\n",ans);
    return 0;
}
