#include<iostream>
#include<string>

using namespace std;

int main(){
    int N;
    string S;
    cin >> N;
    cin >> S;
    long divd = 1000000007;
    int d[2*N];
    d[0]=1;
    int ln = 1;
    for(int i =1 ; i < 2*N; i++){ 
        if(S[i]!=S[i-1]){
            if(d[i-1] > 0){
                ln++;
                d[i] =ln;
            }
            else{
                d[i] = -1;
            }
        }
        else{
            if(d[i-1] > 0){
                d[i] = -1;
            }
            else{
                ln++;
                d[i] = ln;
            }
        }
    }

    long ans=1;
    if(S[0] == 'W' || S[2*N-1] == 'W' || ln != N) cout << 0 << endl;
    else{
        for(int i = 0; i<2*N; i++){
            if(d[i] > 0){
                ans *= (2*N-1) - i - 2*(ln - d[i]);
                ans %=divd;
            }
        }
        for(int i=1;i<=N;i++){
        ans *=i;
        ans %=divd;

        }
        cout << ans <<endl;
    }
    return 0;
}
