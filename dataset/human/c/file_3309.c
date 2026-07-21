#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int i,k=0,n=0,a[3000000]={},first=0,second=0,tmp=0;
    char token[3000000]={};
    fgets(token, sizeof(token), stdin);
    k=atoi(strtok(token, " "));n=atoi(strtok(NULL, " "));
    fgets(token, sizeof(token), stdin);
    a[1]=atoi(strtok(token, " "));
    for (i=2; i<n+1; i++) a[i]=atoi(strtok(NULL, " "));
    a[0]=0;a[n+1]=k;
    for (i=1; i<n; i++) if(tmp<a[i+1]-a[i]) tmp=a[i+1]-a[i];
    first=a[n]-a[1];second=k-tmp;
    if (second>a[n]-a[1]) second=a[n]-a[1];
    if (first>second) printf("%d",second);
    else printf("%d",first);
    return 0;
}
