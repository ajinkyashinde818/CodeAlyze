#include <stdio.h>
    #include <string.h>
    #include <math.h>

    int main(void)
    {
        int i,maxv = 0,minv = 0;
        int n;

        scanf("%d",&n);

        int a[n];

        for(i=0;i<n;i++){scanf("%d",&a[i]);}

        maxv = a[1] - a[0];
        minv = a[0];
        for(i=1;i<n;i++){
            if(maxv < (a[i] - minv)){maxv = a[i] - minv;}
            if(minv > (a[i])){minv = a[i];}
        }
        printf("%d\n",maxv);
        return 0;
    }
