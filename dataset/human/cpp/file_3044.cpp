#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    long long a, sm=0, mx=0;
    vector<long long> v;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a;
        sm += a;
        v.push_back(a);
    }
    mx = sm;
    sort(v.begin(), v.end());
    for(int i=0;i<n-1;i+=2){
        sm -= 2*v[i];
        sm -= 2*v[i+1];
        mx = max(mx, sm);
    }
    cout << mx << endl;
}
