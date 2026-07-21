#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    int n;
    cin >> n;
    
    std::vector<long long> v(n);
    int cnt = 0;
    long long min_element = LONG_MAX;
    long long sum = 0;
    for(int i=0; i<n; i++){
        long long c;
        cin >> c;
        sum += abs(c);
        min_element = min(min_element, abs(c));
        if (c < 0)cnt++;
    }

    if (cnt % 2 == 1){
        sum -= 2 * min_element;
    }
    
    cout << sum <<endl;
    
}
