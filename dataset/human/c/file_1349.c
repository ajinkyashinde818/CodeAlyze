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
    int n,m;
    scanf("%d%d",&n,&m);
    int a[m],b[m];
    bool to[n],from[n];
    for (int i=0; i<n; i++){
        to[i]=false;
        from[i]=false;
    }
    for (int i=0; i<m; i++){
        scanf("%d%d",&a[i],&b[i]);
        if (a[i]==1){
            to[b[i]]=true;
        } else if (b[i]==n){
            from[a[i]]=true;
        }
    }
    for (int i=0; i<n; i++){
        if (to[i]==true && from[i]==true){
            printf("POSSIBLE\n");
            exit(0);        
        } 
    }
    printf("IMPOSSIBLE\n");
	return 0 ;
}
