#include <stdio.h>
int main(){
    int now=0;
    char a[10000];
    for(int i=0;i<10000;i++)a[i]='\0';
    scanf("%s",a);
    while(a[now]!='\0')now++;
    for(int i=0;i<now-8;i++)printf("%c",a[i]);
    printf("\n");
}
