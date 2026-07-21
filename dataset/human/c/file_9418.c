#include<stdio.h>
int eat[200];
int main(void){
    int hum,day,final,i,j,temp,ans=0;
    scanf("%d",&hum);
    scanf("%d %d",&day,&final);
    for(i=0;i<200;i++){
        eat[i]=0;
    }
    for(i=0;i<hum;i++){
        scanf("%d",&temp);
        for(j=1;j<=day;j+=temp){
            eat[j]++;
        }
    }
    for(i=1;i<=day;i++){
        ans+=eat[i];
    }
    printf("%d\n",ans+final);
    return 0;
}
