#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> input(n);
    for (int i = 0; i < n; i++)
        cin >> input[i];
    vector<long long> pref(n);
    pref[0] = input[0];
    for (int i = 1; i < n; i++)
        pref[i] = pref[i - 1] + input[i];
    long long answer = abs(pref[n - 1] - pref[0] - pref[0]);
    for (int i = 0; i < n - 1; i++){
        if (abs(pref[n - 1] - pref[i] - pref[i]) < answer)
            answer = abs(pref[n - 1] - pref[i] - pref[i]);
            //cout << pref[n - 1] - pref[i] << " " << pref[i] << endl;
    }
    cout << answer;
    return 0;
}
