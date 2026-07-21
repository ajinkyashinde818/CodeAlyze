#include<bits/stdc++.h>
using namespace std;

int main(){
    unsigned long N;
    cin >> N;
    vector<long> A(N), B(N);
    for(auto &i : A)cin >> i;
    transform(A.cbegin(), A.cend(), B.begin(), labs);
    cout << accumulate(B.cbegin(), B.cend(), 0L) -
            (1 & count_if(A.cbegin(), A.cend(), [](auto a){return a < 0;}) ? *min_element(B.cbegin(), B.cend()) * 2 : 0) << endl;
}
