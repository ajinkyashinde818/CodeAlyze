#include<bits/stdc++.h>
using namespace std;

int main(){
    //input
    long long N;
    cin >> N;
    long long A[N],B[N];
    long long i;
    long long C[N+1], D[N+1];
    fill(C,C+N+1,0);
    fill(D,D+N+1,0);
    for(i=0; i<N; i++){
        cin >> A[i];
        C[A[i]]++;
    }
    for(i=0; i<N; i++){
        cin >> B[i];
        D[B[i]]++;
    }

    //calc
    for(i=1; i<=N; i++){
        C[i]+=C[i-1];
        D[i]+=D[i-1];
    }
    for(i=1; i<=N; i++){
        if(C[i]-C[i-1]+D[i]-D[i-1]>N){
            cout << "No" << endl;
            system("pause");
            return 0;
        }
    }
    cout << "Yes" << endl;
    long long x=0;
    for(i=1; i<=N; i++){
        x=max(x,C[i]-D[i-1]);
    }
    for(i=0; i<N-1; i++){
        cout << B[(i+(N-x))%N] << " ";
    }
    cout << B[(N-1+(N-x))%N] << endl;
    system("pause");
    return 0;
}
