#include <stdio.h>
int main(void){
    int n,g,choko,i,a[100];
    scanf("%d%d%d",&n,&g,&choko);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    for(i=0;i<n;i++){
        choko+=g/a[i];
        if(g%a[i]!=0) choko++;
    }
    printf("%d",choko);
}
