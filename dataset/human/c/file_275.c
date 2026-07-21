#include<stdio.h>
int main(void){
    double temp,ans=0,min=1000000001;
    int n,i,negcnt=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%lf",&temp);
        if(temp<0){
            temp=temp*-1;
            negcnt++;
        }
        if(temp<min){
            min=temp;
        }
        ans+=temp;
    }
    if(negcnt%2==1){
        ans-=min*2;
    }
    printf("%.0lf\n",ans);
    return 0;
}
