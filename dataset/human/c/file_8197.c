#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define LINE_BUF_SIZE 256

int main(){

    int i,j,k;
    long int A,B,C,D;
    char line[LINE_BUF_SIZE];

    fgets(line,sizeof(line),stdin);
    sscanf(line,"%ld %ld %ld %ld", &A,&B,&C,&D);

    if(A*B == C*D){
        printf("%ld",A*B);
        return 0;
    }

    if(A*B > C*D){
        printf("%ld",A*B);
        return 0;
    }

    else{
        printf("%ld",C*D);
        return 0;
    }

    return 0;

}
