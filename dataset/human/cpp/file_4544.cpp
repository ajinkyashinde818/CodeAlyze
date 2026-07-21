#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <functional>
 
using namespace std;
 
int main(void) {
    unsigned long int n = 0, r = 0;
    
    cin >> n >> r;
    if(n < 10){
        cout << r + 100 * (10 - n) << endl;
    }else{
        cout << r << endl;
    }
    return 0;
}
