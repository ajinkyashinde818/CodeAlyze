#include<stdio.h>

int main(){
    int N,i,count=0;
    int a[100001];
    scanf("%d",&N);
    for(i=1;i<=N;i++){
        scanf("%d",&a[i]);
    }

    for(i=1;count<100001;){
        if(i==2) break;
        i=a[i];
        count++;        
    }
    if(count==100001) printf("-1\n");
    else printf("%d\n",count);
    return 0;
}
