#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

/*ソートの時に使う
int sort(const void *a, const void *b){
    return *(int*)a-*(int*)b ;
}
    qsort (data,sizeof(data),sizeof(int),sort); 
*/

int main(void){
    int n;
    scanf("%d",&n);
    long long a[n],sum[n];
    for (int i=0; i<n; i++){
        scanf("%lld",&a[i]);
        if (i==0){
            sum[i]=a[i];
        } else {
            sum[i]=a[i]+sum[i-1];
        }
    }
    long long ans;
    for (int i=0; i<n-1; i++){
        if (i==0){
            ans=llabs((sum[n-1]-sum[i])-sum[i]);
        } else if (ans>llabs((sum[n-1]-sum[i])-sum[i])){
            ans=llabs((sum[n-1]-sum[i])-sum[i]);
        }
    }
    printf("%lld\n",ans);
	return 0 ;
}
