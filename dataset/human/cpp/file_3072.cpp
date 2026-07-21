#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<long int> a(n);
    int sigc = 0;
    long absmin = LONG_MAX;
    for(auto& i : a){
        cin >> i;
    }
    long abssum = 0;
    for(auto i : a){
        long absa = abs(i);
        if(i < 0) sigc++;
        if(absa < absmin) absmin = absa;
        abssum += absa;
    }
    if(sigc%2 == 0) cout << abssum << endl;
    else cout << abssum - 2*absmin << endl;
    return 0;
}
