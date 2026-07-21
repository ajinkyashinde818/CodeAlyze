#include <iostream>
#include <cmath>

using namespace std;

int N;
long long a[100000];
long long b[100000];

int main(){
    cin >> N;
    bool f = false;
    for(int i=0;i<N;i++){
        cin >> a[i];
        b[i] = a[i];
        if(a[i] == 0) f = true;
    }
    long long aa=0,bb=0;
    for(int i=0;i<N-1;i++){
        if(a[i] < 0){
            a[i+1] *= -1;
        }
    }
    if(a[N-1] > 0) f = true;
    if(f){
        for(int i=0;i<N;i++) aa += abs(a[i]);
        cout << aa << endl;
        return 0;
    }
    bb = 1e9+7;
    for(int i=0;i<N;i++){
        aa += abs(a[i]);
        bb = min(bb,abs(a[i]));
    }
    cout << aa - 2 * bb << endl;
    return 0;
}
