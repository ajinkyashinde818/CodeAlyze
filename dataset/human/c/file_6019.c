#include <stdio.h>
#include <stdlib.h>

long max(long a,long b);
long min(long a,long b);

int main(void){
    long retval=-10000000010;
    int n;
    scanf("%d",&n);
    long* R=(long*)malloc(sizeof(long)*n);
    for(int i=0;i<n;i++){
        scanf("%ld",&(R[i]));
    }
    long minimum=R[0];
    for(int i=1;i<n;i++){
        retval=max(R[i]-minimum,retval);
        minimum=min(minimum,R[i]);
    }
    printf("%ld\n",retval);
    return 0;
}

long max(long a,long b){
    if(a>b){return a;}
    else{return b;}
}
long min(long a,long b){
    if(a<b){return a;}
    else{return b;}
}
