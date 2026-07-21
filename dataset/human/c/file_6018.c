#include <stdio.h>
#define NUM 200000

int main()
{
    int n,i,a[NUM],j,maxv,minv;
    
    scanf("%d",&n);
    for(i = 0;i < n;i++){
        scanf("%d",&a[i]);
    }
    maxv = a[1] - a[0];
    minv = a[0];
    for(j = 1;j < n;j++){
            if(maxv < (a[j] - minv)) maxv = a[j] - minv;
            if(minv > a[j]) minv = a[j];
    }
    
    printf("%d\n",maxv);
    
    return 0;
}
