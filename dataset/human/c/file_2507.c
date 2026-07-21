#include<stdio.h>
int main(void){
char a[3]={};
int b[3]={};
int i;
int j=0;
if(scanf("%c",&a[0])==1);
if(scanf("%c",&a[1])==1);
if(scanf("%c",&a[2])==1);
for(i=0;i<3;i++){
        if(a[i]=='a')b[0]++;
        if(a[i]=='b')b[1]++;
        if(a[i]=='c')b[2]++;
}
for(i=0;i<3;i++){
        if(b[i]!=1)j=1;
}
        if(j==1)printf("No");
        else printf("Yes");
return 0;
}
