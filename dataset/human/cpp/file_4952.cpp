#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>
#include <stdio.h>
#include <iomanip>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>

using namespace std;

typedef long long int ll; 
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;

void floatOutPutSetup(){
    cout << fixed;
    cout << setprecision(10);
}

int main(){
    int N,R;
    cin >> N>>R;
    if(N<10){
        cout<<R+100*(10-N);
    }else{
        cout<<R;
    }

    return 0;
}
