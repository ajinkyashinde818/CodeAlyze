#include <iostream>
#include <algorithm>

using namespace std ;

int Function1(int a,int N){
    if(!(N%a)){
        return 1;
    }
    else{
        return 0;
    }
}

int Function2(int b1,int b2,int N){
    int temp;
    if(b1<b2){
        temp=b1;
        b1=b2;
        b2=temp;
    }
    int n=N/b1;
    int sum=0;
    for(int i=0;i<n+1;i++){
        sum+=Function1(b2,N-b1*i);
    }
    return sum;
}

int Function3(int c1,int c2,int c3,int N){
    int temp;
    if(c1<c2){
        temp=c1;
        c1=c2;
        c2=temp;
    }
    if(c1<c3){
        temp=c1;
        c1=c3;
        c3=temp;
    }
    int n=N/c1;
    int sum=0;
    for(int i=0;i<n+1;i++){
        sum+=Function2(c2,c3,N-c1*i);
    }
    return sum;

}

int main(){
    int R,G,B,N;
    scanf("%d %d %d %d",&R,&G,&B,&N);
    printf ("%d",Function3(R,G,B,N));
    return 0;
}
