#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int a[21],b[21],c[20];
    int i;
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(i=1;i<=n;i++){
        scanf("%d",&b[i]);
    } 
    for(i=1;i<n;i++){
        scanf("%d",&c[i]);
    }
    int sati = 0;
    for(i=1;i<=n;i++){
        sati += b[i];
        if(i!=1 && a[i]-a[i-1]==1){
            sati += c[a[i-1]];
        }
    }
    printf("%d\n",sati);
    return 0;
}
