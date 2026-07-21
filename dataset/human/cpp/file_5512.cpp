#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
using LL = long long;

int main(){
    int n, r;
    cin >> n >> r;
    if(n>=10){
        cout << r << endl;
    }else{
        cout << r + 100*(10-n) << endl;
    }
}
