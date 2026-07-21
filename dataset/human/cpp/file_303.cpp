#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    int c[3], n;
    cin >> c[0] >> c[1] >> c[2] >> n;
    int count = 0;

    vector<int> rgb;
    rgb.push_back(c[0]);
    rgb.push_back(c[1]);
    rgb.push_back(c[2]);
    sort(rgb.begin(),rgb.end());

    for(int i=0; i <= ((n-(n%rgb.at(2)))/rgb.at(2)); ++i){
        static int a;
        a = n - rgb.at(2) * i;
        for(int j=0; j <= ((a-(a%rgb.at(1)))/rgb.at(1)); ++j){
            static int b;
            // cout << j << endl;
            b = a - rgb.at(1) * j;
            // cout << a << endl;a
            if(b%rgb.at(0)==0) ++count;
        }
    }

    cout << count << endl;

    return 0;
}
