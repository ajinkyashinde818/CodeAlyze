#include<stdio.h>
int went[200000];
int way[200000];
int main(void){
    int i,n,fl,cnt;
    for(i=0;i<200000;i++){
        went[i]=0;
    }
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&way[i]);
    }
    fl=1;
    went[1]++;
    cnt=0;
    while(1){
        fl=way[fl];
        cnt++;
        went[fl]++;
        if(went[fl]>1){
            printf("-1\n");
            return 0;
        }
        if(fl==2){
            break;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
