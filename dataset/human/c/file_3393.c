#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int main(void){
    char s[100020],t[100020],a[5]="maerd",b[7]="remaerd",c[5]="esare",d[6]="resare";
    scanf("%s",s);
    t[strlen(s)]='\0';
    for (int i=0; i<strlen(s); i++){
        t[i]=s[strlen(s)-i-1];
    }
    int count=0;
    while(count<strlen(s)){
        if (strncmp(t+count,a,5)==0){
            count+=5;
        } else if (strncmp(t+count,b,7)==0){
            count+=7;
        } else if (strncmp(t+count,c,5)==0){
            count+=5;
        } else if (strncmp(t+count,d,6)==0){
            count+=6;
        } else {
            printf("NO\n");
            exit(0);
        }
    }
    printf ("YES\n");
	return 0 ;
}
