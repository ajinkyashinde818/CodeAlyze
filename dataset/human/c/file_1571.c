#include <stdio.h>



int main (void){
    int i,j;
    char s1 = 0,s2 = 0; 
    int a,b; 
    int n;
   

    scanf("%c %c",&s1,&s2);

    if(s1 == 'A'){
        a = 10;
    }else if (s1 == 'B'){
        a = 11;
    }else if (s1 == 'C'){
        a = 12;
    }else if (s1 == 'D'){
        a = 13;
    }else if (s1 == 'E'){
        a = 14;
    }else if (s1 == 'F'){
        a = 15;
    }
    if(s2 == 'A'){
        b = 10;
    }else if (s2 == 'B'){
        b = 11;
    }else if (s2 == 'C'){
        b = 12;
    }else if (s2 == 'D'){
        b = 13;
    }else if (s2 == 'E'){
        b = 14;
    }else if (s2 == 'F'){
        b = 15;
    }
    if(a<b){
        printf("<\n");
    }else if (a > b){
        printf(">\n");
    }else{
        printf("=\n");
    }
    return 0;
}
