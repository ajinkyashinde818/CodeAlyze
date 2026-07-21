#include "bits/stdc++.h"
using namespace std;

int main(){
    int N;
    long int ans=0;
    int c=0;
    cin >> N;
    vector<int> A(N,0);
    for(int i=0;i<N;i++){
        cin >> A[i];
        if(A[i]<0) c++;
    }
    if(c%2==0){
        for(int i=0;i<N;i++) ans+=abs(A[i]);
    }else{
        for(int i=0;i<N;i++) A[i]=abs(A[i]);
        sort(A.begin(),A.end());
        for(int i=1;i<N;i++) ans+=A[i];
        ans -= A[0];
    }
    cout << ans << endl;
    return 0;
}
