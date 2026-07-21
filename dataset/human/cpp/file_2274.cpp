#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin>>N;
    vector<long> A(N);
    int cnt=0;
    for(int i=0; i<N; ++i){
        cin>>A[i];
        if(A[i]<0){
            A[i]*=-1;
            cnt++;
        }
    }
    sort(A.begin(), A.end());

    long sum=0;
    for(int i=1; i<N; i++){
        sum+=A[i];
    }

    if(cnt%2==1){
        cout<<sum - A[0]<<endl;
    }else{
        cout<<sum + A[0]<<endl;
    }

    return 0;
}
