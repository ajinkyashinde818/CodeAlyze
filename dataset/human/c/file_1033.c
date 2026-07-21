#include <stdio.h>
#include <stdlib.h>
#include <string.h> // 文字列処理の関数
#include <ctype.h> // 文字変換(大文字/小文字)の関数

int main() {
char buf[100];
scanf("%s",buf);
int i,j;
for (i=0;buf[i] != '\0';i++);
for (j=0;j<=i-9;j++) {
 printf("%c",buf[j]);
}
printf("\n");
return 0;
}
