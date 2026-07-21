#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    vector<int> av(N);
    int minus = 0;
    long long sum = 0;
    for(int i = 0; i < N; i++) {
        cin >> v[i];
        if(v[i] < 0) minus++;
        av[i] = abs(v[i]);
        sum += av[i];
    }
    sort(av.begin(), av.end());
    if(minus % 2 == 0) cout << sum << endl;
    else cout << sum - (2 * av[0]) << endl;
}
