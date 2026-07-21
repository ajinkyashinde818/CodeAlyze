#include <stdio.h>
#include <stdlib.h>

int sort(const void *a, const void *b){
    return *(int*)b-*(int*)a ;
}

int main(void){
    int n;
    scanf("%d",&n);
    int a[n*3];
    for (int i=0; i<n*3; i++){
        scanf("%d",&a[i]);
    }
    long long ans=0;
    qsort (a,n*3,sizeof(int),sort);
    for (int i=0; i<n; i++){
        ans+=a[i*2+1];
    }
    printf ("%lld\n",ans);
	return 0 ;
}
