#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long>csum(200100);
    int a;
    for(int i=0;i<N;i++){
        cin >> a;
        if(i==0) csum[i]=a;
        else csum[i]=csum[i-1]+a;
    }
    long long mi=1e10,dif;
    for(int i=0;i<N-1;i++){
        dif=abs(csum[i]-(csum[N-1]-csum[i]));
        mi=min(mi,dif);
    }
    cout << mi << endl;
}
