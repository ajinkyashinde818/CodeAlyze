#include <stdio.h>

int main()
{
    int i,j,n;
    char buf[10];
    fgets(buf,sizeof(buf),stdin);
    sscanf(buf,"%d",&n);
    int min,maxprofit;
    maxprofit = -1e10;
    for (i=0;i<n;i++){
        scanf("%d",&j);
        if (i==0) min = j;
        else{
            if (maxprofit < (j-min)) maxprofit = (j-min);
            if (j<min) min = j;
        }
    }
    printf("%d\n",maxprofit);

    return 0;
}
