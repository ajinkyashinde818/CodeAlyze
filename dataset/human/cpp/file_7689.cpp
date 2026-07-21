#include <iostream>
#include <cmath>

using namespace std;

long long N;
long long a[200000];

int main(){
    long long m;
    cin >> N;
    for(int i=0;i<N;i++) cin >> a[i];
    long long s = 0;
    for(int i=1;i<N;i++) s += a[i];
    long long t = a[0];
    m = abs(s-t);
    for(int i=1;i<N-1;i++){
        s -= a[i];
        t += a[i];
        m = min(m,abs(s-t));
    }
    cout << m << endl;
    return 0;
}
