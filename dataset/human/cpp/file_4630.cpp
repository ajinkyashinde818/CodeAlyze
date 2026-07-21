#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
int main(void){
    int k , r;
    cin >> k >> r;
    if(k >=10){
        cout << r << endl;
    }else{
        cout << r + 100 * (10 - k) << endl;
    }
    return 0;
}
