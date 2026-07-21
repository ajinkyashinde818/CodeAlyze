#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long n,k,i,j,index,out[200001]={0},output;
    long long a[200001]={0};
    int flag=0,repeat=0;
    scanf("%lld %lld",&n,&k);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(i=1;i<=k;i++){
        if(i==1){
            output = a[1];
            out[i] = a[1];
            a[1] = -out[1];
            index = out[i];

        }
        else{
            output = a[index];
            out[i] = a[index];
            a[index] = -out[i];
            index = out[i];
        }
        if(output<0){
            for(j=1;j<i;j++){
                if((-out[i])==out[j]){
                    repeat = i-j;
                    flag = 1;
                    break;
                }
            }
        }
        if(flag==1){
            index = (k-j)%repeat;
            output = out[j+index];
            break;
        }
    }
    printf("%lld\n",output);
    return 0;
}
