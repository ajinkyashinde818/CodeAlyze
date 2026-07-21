#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
using namespace std;

int main(){

    int n;
    cin >> n;

    vector<long long>v(n);
    cin >> v[0];
    for(int i = 1; i < n; i++){
        cin >> v[i];
        v[i] += v[i-1];
    }

    long long min = 99999999999;
    for(int i = 0; i < n-1; i++){
        long long temp = abs(v[n-1] - v[i] - v[i]) ;
        if(temp < min) min = temp;
    }


    cout << min << endl;

}
