#include <iostream>
#include <stdio.h>
using namespace std;
 
long long int zet(long long int x){
    if(x>0 || x==0){
        return x;
    }else{
        return -x;
    }
}

int main(){
    int N;
    scanf("%d",&N);
    long long int a[N];
    for(int i=0;i<N;i++){
        scanf("%lld",&a[i]);
    }    
    long long x=a[0];
    long long y=0;
    int i;
    for(i=1;i<N;i++){
        y=y+a[i];
    }
    long long int min=zet(x-y);
    long long int temp=0;
    for(i=1;i<N-1;i++){
        x=x+a[i];
        y=y-a[i];
        temp=zet(x-y);
        if(temp<min){
            min=temp;
        }
    }
    printf("%lld\n",min);

    return 0;
    
}
