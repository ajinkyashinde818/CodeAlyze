#include <stdio.h>
#include <string.h>
int main(void){
    int n;
    scanf("%d", &n);
    int cnt=0;
    for(int i=0; i<n; i++){
        int d1, d2;
        scanf("%d %d", &d1, &d2);
        if(d1==d2){
            cnt++;
            if(cnt>=3){
                printf("Yes\n");
                return 0;
            }
        }else cnt=0;
    }
    printf("No\n");
    return 0;
}
