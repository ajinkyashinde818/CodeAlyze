#include <bits/stdc++.h>
using namespace std;

int main() {

    long long n;
    cin >> n;
    priority_queue<long long, vector<long long>, greater<long long> > under;
    priority_queue<long long, vector<long long>, greater<long long> > over;
    for (long long i=0; i<n; i++) {
        long long a;
        cin >> a;
        if (a < 0) {
            under.push(a);
        }
        else {
            over.push(a);
        }
    }
    while (under.size() > 1) {
        long long f = under.top();
        under.pop();
        long long s = under.top();
        under.pop();
        over.push(-f); over.push(-s);
    }
    long long sm = 0;
    if (under.size() == 1) {
        long long alt = over.top();
        over.pop();
        long long ye = under.top();
        under.pop();
        if (abs(ye) > abs(alt)) {
            sm += -ye - alt;
        }
        else {
            sm += alt + ye;
        }
    }
    while (!over.empty()) {
        sm += over.top(); over.pop();
    }
    cout << sm;
}
