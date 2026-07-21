#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
#include <cstdio>
#include <tuple>
#include <string>
#include <vector> 
#include <set>
#include <string.h>
#include <map>
#include <cmath>
#include <deque>
using ll = long long;
using Graph = vector<vector<int>>;
#include <queue>
#include <stack>

int main(){

    int n,r;
    cin >> n >> r;

    if(n < 10){
        r = r+100*(10 - n);
        cout << r << endl;
    }else{
        cout << r << endl;

    }

    return 0;
}
