#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n,i;
    int d1[100];
    int d2[100];
    int flag = 0;
    int zorome = 0;
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        scanf("%d",&d1[i]);
        scanf("%d",&d2[i]);

        if(d1[i] == d2[i]) zorome++;
        else zorome = 0;

        if(zorome == 3) flag = 1;
   }
    if(flag == 1){
        printf("Yes");
    } else {
        printf("No");
    }

}
