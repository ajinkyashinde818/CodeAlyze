#include <stdio.h>
#include <string.h>
int main(void){
    int n,next,ans=0,a[100001] ;
    scanf ("%d",&n) ;
    for (int i=0; i<n; i++) {
        scanf ("%d",&a[i]) ;
    }
    next = a[0] ;
    while (next!=2 && ans<n+1) {
        next=a[next-1] ;
        ans++ ;
    }
    if (ans>n) {
        printf ("-1\n") ;
    } else {
        printf ("%d\n",ans+1) ;
    }
    return 0 ;
}
