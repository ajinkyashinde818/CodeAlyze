# include"stdio.h"
# include"stdlib.h"
//# include"math.h"
int main(){
    int n;
    scanf("%d",&n);
    long long int a[n],x=0,y=0;
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
        if(i==0)x=a[i];
        else y+=a[i];
    }
    long long int min=llabs(x-y);
    for(int i=0;i<n-1;i++){
        if(llabs(x-y)<min) min=llabs(x-y);
        if(llabs(x-y)==0) break;
        x+=a[i+1];
        y-=a[i+1];
    }
    printf("%lld\n",min);
}
