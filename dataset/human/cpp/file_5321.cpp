#include <iostream>
#include <algorithm>
#include <math.h> 
#include <string>
#include <iomanip>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <bitset>
using namespace std;
int main(){
    int n, r;
    cin >> n >> r;
    if(n >= 10) cout << r << endl;
    else cout << r+100*(10-n) << endl;
}
