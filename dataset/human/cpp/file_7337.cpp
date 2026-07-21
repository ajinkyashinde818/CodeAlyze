#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N;
    cin >> N;
    vector<long long>a(N);
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> a.at(i);
        sum += a.at(i);
    }
    
    vector<long long>count(N-1);
    vector<long long>dis(N-1);
    count.at(0) = a.at(0);
    dis.at(0) = abs((sum-count.at(0))-count.at(0));
    for (int i = 1; i < N-1; i++) {
        count.at(i) = count.at(i-1) + a.at(i);
        dis.at(i) = abs((sum-count.at(i))-count.at(i));
    }
    sort(dis.begin(), dis.end());
    cout << dis.at(0) << endl;
}
