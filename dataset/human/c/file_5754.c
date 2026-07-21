#include <stdio.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)

int main() {
    int n, A[200000+1];
    scanf("%d", &n);
    for (int i=0;i<n;i++) {
        scanf("%d", &A[i]);
    }
    int minv = A[0];//min{A[0],A[1],...,A[j-1]}

    //let p[k] be max profit when sell at time k
    int maxp = A[1]-A[0]; //max{p[1],p[2],...,p[j-1]}

    for (int j=1;j<n;j++){
        maxp = max(maxp, A[j]-minv);
        minv = min(minv, A[j]);
    }
    printf("%d\n", maxp);
    
        
    return 0;
}
