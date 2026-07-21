#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <cmath>
#include <cctype>

using namespace std;

int main()
{
    int n, r;
    cin >> n >> r;
    
    if(n >= 10) {
        cout << r << endl;
    }else {
        cout << r+100*(10-n) << endl;
    }

    return 0;
}
