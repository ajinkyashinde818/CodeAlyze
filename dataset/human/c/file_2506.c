#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define LINE_BUF_SIZE 256

int main(){

    int M,N,A,B,C;
    int i,j,k;
    char line[LINE_BUF_SIZE];

    fgets(line,sizeof(line),stdin);

    if(strncmp(line,"abc",3) == 0 || strncmp(line,"bac",3) == 0 || strncmp(line,"acb",3) == 0 || strncmp(line,"cab",3) == 0 || strncmp(line,"cba",3) == 0 || strncmp(line,"bca",3) == 0){
        printf("Yes");
    return 0;
        }

    printf("No");

    return 0;

}
