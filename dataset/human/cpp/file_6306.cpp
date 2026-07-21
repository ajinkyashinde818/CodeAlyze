#include <iostream>
#include <string>

using namespace std;

long long mod = 1e9+7;
long long N;
string s;

int main(){
    cin >> N;
    cin >> s;
    long long p = 1;
    long long n = 0;
    for(int i=0;i<N*2;i++){
        if(n == 0){
            if(s[i] == 'W'){
                cout << 0 << endl;
                return 0;
            }
            n++;
            continue;
        }
        if(s[i] == 'W'){
            if(n % 2==0){
                p *= n;
                n--;
                p %= mod;
            }else{
                n++;
                n %= mod;
            }
        }else{
            if(n % 2==1){
                p *= n;
                n--;
                p %= mod;
            }else{
                n++;
                n %= mod;
            }
        }
    }
    if(n != 0){
        cout << 0 << endl;
        return 0;
    }
    for(long long i=2;i<=N;i++){
        p *= i;
        p %= mod;
    }
    cout << p << endl;
    return 0;
}
