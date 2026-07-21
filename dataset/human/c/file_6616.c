#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int list[n];
    int i,difference=0;
    for (i=0;i<n;i++){
        scanf("%d",&list[i]);
    }
    int min = list[0];
    int ans = list[1] - list[0];
    for (i=1;i<n;i++){
        if (min>list[i]){
            min = list[i];
        }else if (ans<list[i]-min){
            ans = list[i] - min;
        }
    }
    printf("%d\n",ans);
    return 0;
}
