#include <bits/stdc++.h>
using  namespace std;
int main(){
    long long n;
    cin >> n;
    long long A[n],X[n],Y[n], minSum;
    for(int i=0;i<n;i++){
       cin >> A[i];
    }
    for(int i=0;i<n;i++){
        if(i==0){
            X[i]=A[i];
            Y[n-1-i]=A[n-1-i];
        }else{
            X[i]=X[i-1]+A[i];
            Y[n-1-i]=Y[n-i]+A[n-1-i];
        }
    }
    for(int i=0;i<n-1;i++){
        if(i==0){
            minSum = abs(X[i]-Y[i+1]);
        }else{
            minSum = min(minSum, abs(X[i]-Y[i+1]));
        }
    }
    cout << minSum << endl;
    return 0;
 
}
