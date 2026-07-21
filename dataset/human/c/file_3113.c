#include <stdio.h>
int main(void){
int a,b,c=0,w[1000000];
scanf("%d%d",&a,&b);
for(int i=0;i<b;i++){
    scanf("%d",&w[i]);
}
for(int j=0;j<b-1;j++){
    if(c<w[j+1]-w[j]){
        c=w[j+1]-w[j];
    }
}
if(c<a-w[b-1]+w[0]){
    c=a-w[b-1]+w[0];
}
printf("%d",a-c);
}
