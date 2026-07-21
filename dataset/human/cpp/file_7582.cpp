#include <iostream>

using namespace std;


int main() {
    int N;
    cin >> N;
    long long a[N];
    long long sum[N];
    long long c = 0;
    for(int i=0;i<N;i++){
        cin >> a[i];
        c += a[i];
        //cout << c <<"\n";
        sum[i] = c;
    }
    long long x;
    long long min = 1000000000000000000LL;;
    for(int i=0;i<N-1;i++){
        long long p = sum[i];
        long long q = sum[N-1] - sum[i];
        if(p < q) x = q - p;
        else x = p - q;
        if(x<=min){
            min = x;
        }
        //cout << mini << " " << min <<"\n";
    }
    cout << min << "\n";
    return 0;
}
