#include <stdio.h>

int main(){
    int n, i;

    scanf("%d", &n);

    long a[n], cm=0, cz=0, max=0, min=1000000000, sum=0, ans=0;

    for(i=0; i<n; i++) {
        scanf("%ld", &a[i]);
    }


    for(i=0; i<n; i++) {
        if(a[i]<0) {
            cm += 1;
            sum += -1*a[i];
            if(min >-1*a[i]) {
                min = -1*a[i];
            }
        } else if (a[i]==0) {
            cz += 1;
        } else {
            sum += a[i];
            if(min >a[i]) {
                min = a[i];
            }
        }
    }


    if (cz>0 || (cm%2)==0) {
        ans = sum;
    } else if ((cm%2)==1) {
        ans = sum - min*2;
    }

    printf("%ld \n", ans);
}
