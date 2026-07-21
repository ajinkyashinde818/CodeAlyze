#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <numeric>

using namespace std;

int main(int argc, char** argv){
    int N;
    cin >> N;
    vector<int> p;
    vector<int> n;
    int zeros = 0;
    long long sum = 0;
    for (int i=0; i<N; i++){
        int tmp;
        cin >> tmp;
        if (tmp > 0){
            p.push_back(tmp);
            sum += tmp;
        }
        if (tmp < 0){
            n.push_back(tmp);
            sum -= tmp;
        }
        if (tmp ==0) zeros++;
    }

    int M = n.size();

    if (M%2 == 1 && zeros == 0){
        sort(p.begin(), p.end());
        sort(n.begin(), n.end());
        if (!p.empty()){
            long long tmp = p[0] + n[M-1];
            if (tmp < 0) sum -= 2*p[0];
            else sum += 2*n[M-1];
        } else {
            sum += 2*n[M-1];
        }
    }

    cout << sum << "\n";

    return 0;
}
