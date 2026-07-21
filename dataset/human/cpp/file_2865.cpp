#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,minus=0;
    long long ans = 0;
    cin>>N;
    vector<int> A(N);

    for(int i=0; i<N; i++){
        cin>>A[i];
        if(A[i] < 0){
            A[i] *= -1;
            minus++;
        }
    }

    sort(A.begin(),A.end());

    for(int i=0; i<N; i++){
        if(i == 0 ){

            if(minus % 2 == 0) ans += A[i];
            else ans -= A[i];
        }
        
        else ans += A[i];
    }

    cout<<ans<<endl;

    return 0;
}
