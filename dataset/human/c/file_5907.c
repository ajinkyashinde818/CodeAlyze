#include <stdio.h>

int main(){

    int t; //first line

    scanf("%d",&t);

    int r[t];
    int i = 0;
    int j;
    int p;


    while(i < t){
        scanf("%d",&r[i]);
        i++;
    }

    i = 0;
    p = r[1] - r[0];
    int minr = r[0];

    for(j=1; j<t; j++){
        
        if(minr > r[j-1]){
            minr = r[j-1];
        }
        
        if(p < (r[j] - minr)){
            p = r[j] - minr;
        }
    }


    printf("%d\n",p);

    return 0;

}
