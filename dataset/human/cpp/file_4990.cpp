#include <iostream>
#include <numeric>
#include <vector>
#include <math.h>
#include <map>
#include <algorithm>
#include <stdio.h>
#include <set>
using namespace std; 

int main(){
    int n,r; cin >> n >> r;
    if (n<10) cout << r+100*(10-n) << "\n";
    else cout << r << "\n";
}
