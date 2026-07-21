//
//  main.cpp
//  Study
//
//  Created by 佐々木勇星 on 2020/03/12.
//  Copyright © 2020 佐々木勇星. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>
#include <iomanip>

using namespace std;


int main(int argc, const char * argv[]) {
    
    int n, r, ans;
    
    cin >> n >> r;
    
    ans = r;
    
    if(n < 10)
    {
        ans = r + 100 * (10 - n);
    }
    
    cout << ans << endl;
    
    return 0;
}
