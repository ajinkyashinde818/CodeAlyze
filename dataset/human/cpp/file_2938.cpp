#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    long long sum = 0;
    for(int i = 0; i < n; i++)
    cin >> a[i];
    sort(a.begin(),a.end());
    for(int i = 0; i < n - 1; i++){
        if(a[i] <= 0 && a[i + 1] <= 0){
            a[i] *= -1;
            a[i + 1] *= -1;
        }
        if(a[i] <= 0 && a[i + 1] >= 0){
            if(abs(a[i]) > abs(a[i + 1])){
                a[i] *= -1;
                a[i + 1] *= -1;
            }
        }

    }
    for(int i = 0; i < n; i++){
        sum += a[i];
    }
    cout << sum << endl;
}
