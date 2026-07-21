#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    int count = 0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(a[i] < 0){
            a[i] *= -1;
            count += 1;
        }
    }

    sort(a.begin(),a.end());
    
    long long int sum = 0;
    for(int i=0; i<n; i++){
        sum += a[i];
    }
    if(count % 2 == 1) sum -= 2 * a[0];
    cout << sum << endl;
    return 0;
}
