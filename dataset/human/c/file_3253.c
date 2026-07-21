#include<stdio.h>
#include<strings.h>

int main(void){
    int k,n;
    scanf("%d %d", &k,&n);
    int pos[n],dis[n];
    int i;
    for(i=0;i<n;i++){
        scanf("%d", &pos[i]); //0 to i-1
    }
    for(i=0;i<n-1;i++){
        dis[i] = pos[i+1] - pos[i];
    }
    dis[n-1] = k - pos[n-1] + pos[0];

    int maxd = 0;
    for(i=0;i<n;i++){
        if(maxd < dis[i]) maxd = dis[i];
    }

    printf("%d", k-maxd);
    return 0;
}
