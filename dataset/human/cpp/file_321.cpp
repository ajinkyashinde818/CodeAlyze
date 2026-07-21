#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;

int main(){
    int r, g, b, n;
    cin >> r >> g >> b >> n;

    int count = 0;
    for(int i = 0; i <= n/r; i++){
        for(int j = 0; j <= n/g; j++){
            if((n-(r*i+j*g))/b >= 0 && (n-(r*i+j*g))%b == 0){
//                cerr << i << " " << j << " " << (n-(r*i+j*g))/b << endl;
                count++;
            }
        }
    }

    cout << count << endl;
    
    return 0;
}
