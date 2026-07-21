#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){
    int n,m ;
    char a[55][55],b[55][55] ;
    scanf ("%d%d",&n,&m) ;
    for (int i=0; i<n; i++){
        scanf ("%s",a[i]) ;
    }
    for (int i=0; i<n; i++){
        scanf ("%s",b[i]) ;
    }
    for (int i=0; i<n-m+1; i++){
        for (int j=0; j<n-m+1; j++){
            for (int k=0; k<m; k++){
                if (strncmp(b[k],a[i+k]+j,m)!=0){
                    break ;
                } else if (k==m-1) {
                    printf ("Yes\n") ;
                    exit (0) ;
                }
            }
        }
    }
    printf ("No\n") ;
	return 0 ;
}
