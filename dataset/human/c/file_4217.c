#include<stdio.h>

int main(void){
    int n, m;
    scanf("%d %d",&n ,&m);
    int a[m];
    int b[n];
    int i, j, k=0;
    int flag;
    int ans;
    for(i=0;i<m;i++){
        scanf("%d",&a[i]);
    }

    // shokichi
    if(a[0] == 1 && a[1] == 2){
        printf("0");
        return 0;
    }
    if(a[0] == 2){
        b[0] = 1;
        b[1] = 0;
    }
    else if(a[0] == 1 && a[1] != 2){
        b[0] = 0;
        b[1] = 1;
    }
    else{
        b[0] = 1;
        b[1] = 2;
    }

    //keisan
    for(i=0;i<n-2;i++){
        b[i+2] = b[i+1] + b[i];
        for(j=k;j<m;j++){
            if(a[j] == i+3){
                flag++;
                k = j;
                break;
            }
        }
        if(flag == 1){
            b[i+2] = 0;
            flag--;
        }
        b[i+2] = b[i+2]%1000000007;
    }

    ans = b[n-1];
    printf("%d\n",ans);
    return 0;
    
}
