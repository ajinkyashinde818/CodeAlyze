#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a,const void *b){
    if(*(int*)a>*(int*)b){return -1;}
    else if(*(int*)a<*(int*)b){return 1;}
    else {return 0;}
}


int main(void){
int n,a[101],b[101],c[101];
int sum=0;
scanf("%d",&n);

for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
}

for(int i=0;i<n;i++){
    scanf("%d",&b[i]);
}

for(int i=0;i<n-1;i++){
    scanf("%d",&c[i]);
}

sum=sum+b[a[0]-1];




for(int i=1;i<n;i++){
sum=sum+b[a[i]-1];
if(a[i]==a[i-1]+1){sum=sum+c[a[i-1]-1];}
//printf("%d\n",sum);
}
printf("%d",sum);




}
