#include <stdio.h>
#define MAX 1000000

int main(int argc, const char * argv[]) {
    int t[MAX],n,i,j,k,sum=0,count=0;
    for(i=0;i<MAX;i++){
        t[i]=1;
    }
    t[0]=t[1]=0;
    for(i=2;i*i<MAX;i++){
        if(t[i]==1){
            for(j=i*i;j<MAX;j+=i){
                t[j]=0;
            }
        }
    }
    while(1){
        scanf("%d",&n);
        if(n==0)
            break;
        for(k=2;k<MAX;k++){
            if(t[k]==1){
                sum+=k;
                count++;
            }
            if(count==n)
                break;
        }
        printf("%d\n",sum);
        sum=0;
        count=0;
    }
    return 0;
}
