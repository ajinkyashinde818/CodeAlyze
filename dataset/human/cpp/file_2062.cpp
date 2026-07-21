#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int numMinus = 0;
    int N;
    cin >> N;
    vector<long long> v(N);
    for(int i =0; i < N; i++){
        long long a;
        cin >> a;
        if(a<0){
            numMinus++;
            v[i] = -a;
        }
        else{
            v[i] = a;
        }
    }
    sort(v.begin(),v.end());
    long long ans = 0;
    for(int i =0; i < N; i++){
        ans+= v[i];
    }
    if(numMinus%2 == 1){
        ans -= 2*v[0];
    }
    cout << ans << endl;
}
