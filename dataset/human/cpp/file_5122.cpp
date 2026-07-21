#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, r;
    cin >> n >> r;
    if(n < 10){
        cout << r + 100 * (10 - n) << endl;
    }
    else{
        cout << r << endl;
    }
}
