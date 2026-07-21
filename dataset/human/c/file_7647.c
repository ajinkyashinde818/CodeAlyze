#include <stdio.h>
int a[99999];
int main(void){
    int i,b;
    i=b=1;
    while(1){
        scanf("%d",&a[i]);
        if(a[i]==0) break;
        i++;
    }
    while(b<i){
        printf("Case %d: %d\n",b,a[b]);
        b++;
    }
	return 0;
}
