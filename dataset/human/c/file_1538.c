#include<stdio.h>

int trnA(char a){
    int m;
    if(a=='A'){
        m=10;
    }
    if(a=='B'){
        m=11;
    }
    if(a=='C'){
        m=12;
    }
    if(a=='D'){
        m=13;
    }
    if(a=='E'){
        m=14;
    }
    if(a=='F'){
        m=15;
    }
    return m;
}
int trnB(char b){
    int n;
    if(b=='A'){
        n=10;
    }
    if(b=='B'){
        n=11;
    }
    if(b=='C'){
        n=12;
    }
    if(b=='D'){
        n=13;
    }
    if(b=='E'){
        n=14;
    }
    if(b=='F'){
        n=15;
    }
    return n;
}

int main(){
    char a,b;
    scanf("%c %c",&a,&b);
    if(trnA(a)>trnB(b)){
        printf(">\n");
    }
    else if(trnA(a)<trnB(b)){
        printf("<\n");
    }
    else{
        printf("=\n");
    }
    return 0;
}
