#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <deque>
using namespace std;

int main() {
    //input
    int r,g,b,n; cin >> r >> g >> b >> n;
    int counter = 0;

    //compute
    for(int i = 0;i < n / r + 1; i++) {
        for(int j = 0; j < n / g + 1 ; j++){
            bool p = ((n - r * i - g * j) >= 0 && (n - r * i - g * j) % b == 0);
            if(p) counter++;
        } 
    }

    //output
    cout << counter << endl;
}
