#include<stdio.h>

int main(){
    int n,sum=0;
    int a[21];
    int b[21];
    int c[20];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int j=0;j<n;j++){
        scanf("%d",&b[j]);
    }
    for(int k=0;k<n-1;k++){
        scanf("%d",&c[k]);
    }
    for(int l=0;l<n;l++){
        sum+=b[a[l]-1];
        if((a[l]+1==a[l+1])&&(l<n-1)){
            sum+=c[a[l]-1];
        }
    }
    printf("%d\n",sum);
    return 0;
}
