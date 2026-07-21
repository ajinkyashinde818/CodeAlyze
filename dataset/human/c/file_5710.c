#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int gcd(int A,int B){
    if(B == 0){
        return A;
    }
    return gcd(B,A%B);
}

/*
2
1000000000
1
-999999999
*/
int main(){
    
    int n,min = (int)pow(10,10);
    int range = - min;
    scanf("%d",&n);

    for(int i = 0;i<n;i++){
        int buff;
        scanf("%d",&buff);

        if(range <= buff - min){
            range = buff - min;
        }

        if(buff < min){
            min = buff;
        }
        //printf(" %d %d\n",min,range);
    }

    printf("%d\n",range);



    
    

    return 0;
}
