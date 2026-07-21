#include <stdio.h>
int main(void){
    int a,b;
    char strx[1],stry[1];
    a=0;b=0;
    scanf("%s%s",strx,stry);
    if(strx[0]=='A'){
        a=1;
    }
    else if(strx[0]=='B'){
        a=2;
    }
    else if(strx[0]=='C'){
        a=3;
    }
    else if(strx[0]=='D'){
        a=4;
    }
    else if(strx[0]=='E'){
        a=5;
    }
    else{
        a=6;
    }

    if(stry[0]=='A'){
        b=1;
    }
    else if(stry[0]=='B'){
        b=2;
    }
    else if(stry[0]=='C'){
        b=3;
    }
    else if(stry[0]=='D'){
        b=4;
    }
    else if(stry[0]=='E'){
        b=5;
    }
    else{
        b=6;
    }
    if(a>b){
        printf(">\n");
    }
    else if (a<b){
        printf("<\n");
    }
    else {
        printf("=\n");
    }
    return 0;
}
