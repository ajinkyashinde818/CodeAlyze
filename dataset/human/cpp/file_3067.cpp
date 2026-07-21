#include<bits/stdc++.h>
using namespace std;

int main() {
    long long int n,cnt,est,sum,atl;cin >> n;
    cnt = 0;
    sum = 0;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    est = abs(a[0]);
    for(int l=1;l<n;l++){
        if(abs(a[l])<est){
            est = abs(a[l]);
        }
    }

    for(int o=0;o<n;o++){
        sum += abs(a[o]);
    }



    for(int j=0;j<n;j++){
        if(a[j]<=0)cnt++;
    }

    atl = sum;
    atl -= abs(est);
    atl -= abs(est);

    if(cnt%2==0){
        cout << sum << endl;
    }else{
        cout << atl << endl;
    }
}
