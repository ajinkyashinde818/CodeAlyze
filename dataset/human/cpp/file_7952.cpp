#include<iostream>
#include<vector>
#include<numeric>
#include<cmath>
#include<climits>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long int> card(n);

    long long int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> card[i];
        sum += card[i];
    }

    long long int min = INT_MAX;
    long long int tmp = 0;
    for(int i = 0; i < n - 1; i++){
        tmp += card[i];
        long long int ans = fabs(tmp - (sum - tmp));
        if(min > ans){
            min = ans;
        }
    }

    cout << min << endl;

    return 0;
}
