#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void){
    int n,d,k;
    int cho=0;
    int a[105];
    scanf("%d %d %d",&n,&d,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    for(int i=0;i<n;i++){
        for(int j=0;;j++){
            if(a[i]*j+1<=d){cho++;}
            else{break;}
        }
    }
cho=cho+k;
printf("%d",cho);


}
