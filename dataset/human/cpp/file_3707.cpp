#include<iostream>
#include<cmath>
#include<string>
using namespace std;
int main(){
    int N,i,j,k,minus=0,zero=0;
    long sums=0,min;
    cin >> N;
    long *A = new long[N];
    for(i=0;i<N;i++){
        cin >> A[i];
        if(A[i]<0) minus++;
        if(A[i]==0) zero++;
    }
    if(zero>0 || minus%2 == 0){
        for(i=0;i<N;i++) sums += labs(A[i]);
    }
    else{
        min = labs(A[0]);
        for(i=0;i<N;i++){
            sums += labs(A[i]);
            if(min>labs(A[i])) min = labs(A[i]);
        }
        sums = sums - 2*min;
    }
    cout << sums << endl;
}
