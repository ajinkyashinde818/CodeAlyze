#include<algorithm>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
#include<iomanip>
using namespace std;

int main()
{
    std::cout<<std::fixed<<std::setprecision(10);
    
    int N, R;
    cin >> N >> R;
    
    if (N >= 10) {
        cout << R;
    } else {
        cout << 100 * (10 - N) + R;
    }

    return 0;
}
