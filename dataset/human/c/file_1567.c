#include <stdio.h>
#include <stdlib.h>
#include <string.h> // 文字列処理の関数
#include <ctype.h> // 文字変換(大文字/小文字)の関数

int main() {
char buf1[1];
scanf("%s",buf1);
char buf2[1];
scanf("%s",buf2);
int i,j;
if (buf1[0]=='A') i=10;
if (buf1[0]=='B') i=11;
if (buf1[0]=='C') i=12;
if (buf1[0]=='D') i=13;
if (buf1[0]=='E') i=14;
if (buf1[0]=='F') i=15;
if (buf2[0]=='A') j=10;
if (buf2[0]=='B') j=11;
if (buf2[0]=='C') j=12;
if (buf2[0]=='D') j=13;
if (buf2[0]=='E') j=14;
if (buf2[0]=='F') j=15;
if (i<j) printf("<\n");
if (i>j) printf(">\n");
if (i==j) printf("=\n");
return 0;
}
