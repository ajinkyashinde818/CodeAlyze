#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;

int main(){
    int n;
    cin >> n;
    int as[n];
    for(int i = 0; i < n; i++){
        cin >> as[i];
    }
    int minus = 0;
    int m = abs(as[0]);
    long long s = 0;
    for(int i = 0; i < n; i++){
        s += abs(as[i]);
        m = min(m, abs(as[i]));
        if(as[i] <= 0){
            minus++;
        }
    }
    if(minus%2 == 0){
        cout << s << endl;
    }else{
        cout << s-m*2 << endl;
    }
    return 0;
}
