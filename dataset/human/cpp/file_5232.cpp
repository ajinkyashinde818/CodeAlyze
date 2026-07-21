#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<set>
#include<map>
using namespace std;


int main() {
    int a, b;
    cin >> a >> b;
    if(a < 10){
        cout << b + 100*(10-a);
    }
    else
    {
        cout << b;
    }
    
    
    
    cout << endl;
}
