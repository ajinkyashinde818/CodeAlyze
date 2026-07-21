#include <iostream>
using namespace std;

int main(){
    int n;
    long a[100010], b, c, m, s;
    cin >> n;
    m = 1e9;
    s = 0;
    c = 0;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
        b = abs(a[i]);
        s += b;
        if (a[i] < 0) c++;
        if (m > b) m = b;
    }
    cout << (s - 2*m*(c%2));
}
