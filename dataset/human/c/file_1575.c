#include<stdio.h>
int main(void){
    char s[10], S[10];
    int sI, SI;
    scanf("%c %c", &s[0], &S[0]);
    if ( s[0] == 'A') sI = 1;
    if ( s[0] == 'B') sI = 2;
    if ( s[0] == 'C') sI = 3;
    if ( s[0] == 'D') sI = 4;
    if ( s[0] == 'E') sI = 5;
    if ( s[0] == 'F') sI = 6;
    if ( S[0] == 'A') SI = 1;
    if ( S[0] == 'B') SI = 2;
    if ( S[0] == 'C') SI = 3;
    if ( S[0] == 'D') SI = 4;
    if ( S[0] == 'E') SI = 5;
    if ( S[0] == 'F') SI = 6;
    /*printf("%c %c\n%d %d\n",s[0], S[0], sI, SI);*/
    if ( sI < SI) printf("<\n", S);
    else if ( sI > SI)printf(">\n", s);
    else if ( sI = SI ) printf("=\n");
    return 0;
}
