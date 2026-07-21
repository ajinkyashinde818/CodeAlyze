#include <algorithm>
#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <vector>
using namespace std;

int main()
{
    int N, R;
    cin >> N >> R;
    
    int A;
    if (N < 10) {
        A = 100 * (10 - N);
    }
    
    
    cout << R + A << endl;

    return 0;   
}
