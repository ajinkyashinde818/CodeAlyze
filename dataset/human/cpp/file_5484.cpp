#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <deque>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <iomanip>
#include <cstring>
#include <climits>
#include <cstdio>

#define nl '\n'

using namespace std;

int n, r;

int main(){

    cin >> n >> r;

    if(n >= 10){
        cout << r;
    } else{
        cout << r + (100*(10-n));
    }





    
}
 
//g++ -std=c++14 comp.cpp -o c && c.exe
//g++ -std=c++14 comp.cpp -o c; ./c.exe
//g++ -std=c++14 comp.cpp && ./a.out


//Surely this is going to AC
