#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;


int main(){
    int N;
    cin >> N;
    vector<long long> a(N);
    long long x=0,y=0,ans=1e12+1;
    for (int i=0; i<N; ++i) {
        cin >> a[i];
        x+=a[i];
    }
    for (int i=0; i<N; ++i) {
        y+=a[i];
        if (i+1<N) ans=min(ans,abs(x-y*2));
    }
    cout << ans << endl;
}
