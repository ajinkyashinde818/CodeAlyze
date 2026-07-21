#include <stdio.h>

int main (){
    char l[1],r[1];
    scanf("%s",l);
    scanf("%s",r);
//    l[0]='A';
//    r[0]='A';
    if(l[0]>r[0])
    	printf(">\n");
    else if(l[0]<r[0])
    	printf("<\n");
    else
    	printf("=\n");
    return 0;
}
