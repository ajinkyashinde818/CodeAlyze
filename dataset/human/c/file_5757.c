#include <stdio.h>
#include <string.h> 

int max(int a,int b){
    if(a>=b){
        return a;
    }
    else{
        return b;
    }
}

long long int maxll(long long int c,long long int d){
    if(c>=d){
        return c;
    }
    else{
        return d;
    }
}

int min(int a,int b){
    if(a>=b){
        return b;
    }
    else{
        return a;
    }
}

long long int minll(long long int c,long long int d){
    if(c>=d){
        return d;
    }
    else{
        return c;
    }
}

int main(void){ 
    int N,i;
    long long int fmax=-1000000000000;
    long long int A[1000000];
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%lld",&A[i]);
    }
    long long int mina=A[0];
    for(i=1;i<N;i++){
        fmax=maxll(fmax,A[i]-mina);
        mina=minll(mina,A[i]);
    }
    printf("%lld\n",fmax);
    return 0;
}
