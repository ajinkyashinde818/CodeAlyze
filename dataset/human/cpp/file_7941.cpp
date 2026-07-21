#include <bits/stdc++.h>
using namespace std;

long long int myabs(long long int input){
    if(input < 0){
        input *= -1;
    }
    return input;
}

int main() {

    int n;

    cin >> n;

    vector<long long int> v;

    for(int i=0; i<n; i++){
        long long int a;
        cin >> a;
        v.push_back(a);
    }

    vector<long long int> Cumulative_Sum;

    Cumulative_Sum.push_back(v[0]);

    for(int i=0; i<n-1 ;i++){
        Cumulative_Sum.push_back(Cumulative_Sum[i] + v[i+1]);
    }

    long long int ans = myabs(Cumulative_Sum[n-1] - Cumulative_Sum[0] - Cumulative_Sum[0]);

    for(int i=1; i<n-1; i++){
        ans = min(ans,myabs(Cumulative_Sum[n-1] - Cumulative_Sum[i] - Cumulative_Sum[i]));
    }

    cout << ans << endl;

    return 0;
}
