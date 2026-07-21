#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;


int main(){
    int N;
    int Aodd = 0;
    ll A;
    ll Amin = 1000000000;
    ll ans = 0;

    //input
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> A;
        if(A < 0){
            Aodd++;
            A *= -1;
        }
        if(Amin > A){
            Amin = A;
        }
        ans += A;
    }

    if(Aodd % 2 == 0){
        cout << ans << endl;
    }else{
        cout << ans - (2 * Amin) << endl;
    }

    return 0;
}
