#include<stdio.h>
int main(){
    int n,a[200000],next;

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    next=a[0]-1;
    if(a[0]==2){
        printf("1\n");
        return 0;
    }
    int bef=0,cnt=1;
    while(1){
        if(a[next]==2){
            printf("%d\n",cnt+1);
            return 0;
        }else{
            next=a[next]-1;
            cnt++;
        }
        if(cnt>=2*n)break;
    }
    printf("-1\n");
    return 0;
}
