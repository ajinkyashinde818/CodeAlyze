#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

template<typename T> T find_first_positive(
    T const _b,
    T const _e)
    {
    auto b = _b, e = _e;
    if (*b>=0) return b;
    while(1) {
        size_t d = distance(b,e);
        if(d==2) {
            return b+1;
        }
        auto c = b+(d/2);
        if (*c>=0) {
            e = c+1;
        } else {
            b = c;
        }
    }
}

int main(int argc, char const *argv[])
{
    int n; cin >> n;
    vector<long long> a(n);
    for(auto itr=a.begin();n>0;--n) {
        cin >> *itr; ++itr;
    }
    sort(a.begin(), a.end());
    if (*a.begin()>=0LL) {
        cout << accumulate(a.begin(), a.end(), 0LL) << endl;
    } else {
        auto p_itr = find_first_positive(a.begin(), a.end());
        if((distance(a.begin(), p_itr)&1)) {
            cout << accumulate(a.begin(), p_itr-1, 0LL) * -1LL + accumulate(p_itr+1,a.end(),0LL) +
                    abs(*(p_itr-1) + *p_itr) << endl;
        } else {
            cout << accumulate(a.begin(), p_itr, 0LL) * -1LL + accumulate(p_itr,a.end(),0LL) << endl;
        }
    }


    return 0;
}
