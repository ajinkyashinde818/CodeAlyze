#include <stdio.h>
#include <stdlib.h>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)

#define MMM -2000000000

int main(int argc, char *argv[]){
        int L;
        int n;
        int i;
        unsigned long *r;
        int MAX_r = MMM;
        int MIN_r;
        scanf("%d", &n);
        r = malloc(sizeof(unsigned long)*n);
        
        scanf("%d", &r[0]);
        MIN_r = r[0];
        for(i=1;i<n;i++){
                scanf("%d", &r[i]);
                //printf("max:%d min:%d\n", MAX_r, MIN_r);
                //printf("r[i]-MIN_r=%d-%d=%d\n", r[i], MIN_r, r[i]-MIN_r);
                L = r[i]-MIN_r;
                MAX_r = max(MAX_r,L);
                MIN_r = min(MIN_r, r[i]);
                //printf("max:%d min:%d\n", MAX_r, MIN_r);
                //printf("r[i]-MIN_r=%d-%d=%d\n", r[i], MIN_r, r[i]-MIN_r);
        }

        printf("%d\n", MAX_r);
        return 0;
}
