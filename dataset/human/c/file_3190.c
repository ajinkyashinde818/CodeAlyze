#include <stdio.h>

int main(void){
    int n,k;
    scanf("%d %d",&k,&n);
    int a[n];
    int i;
    for(i=0;i<n;i++){
        scanf("%d", &a[i]);
    }

    int tokei,hantokei,min,tmp;

    tokei=a[1]-a[0];
    hantokei=k-(a[n-1]-a[0]);
    if(tokei>=hantokei){
        min=k-tokei;
    }else{
        min=k-hantokei;
    }
    /*長い方を引く*/

    for(i=1;i<n-1;i++){
        tokei=a[i+1]-a[i];
        hantokei=a[i]-a[i-1];

        if(tokei>=hantokei){
            tmp=k-tokei;
        }else{
            tmp=k-hantokei;
        }
        /*長い方を引く*/

        if(tmp<min){
            min=tmp;
        }
    }

    tokei=k-(a[n-1]-a[0]);
    hantokei=a[n-1]-a[n-2];
    if(tokei>=hantokei){
        tmp=k-tokei;
    }else{
        tmp=k-hantokei;
    }
    /*長い方を引く*/

    if(tmp<min){
        min=tmp;
    }

    printf("%d\n",min);
    return 0;
}
