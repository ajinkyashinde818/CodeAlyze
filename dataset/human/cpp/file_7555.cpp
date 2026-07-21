#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
    long n;
    cin >> n;
    long a[200009] = {0};
    long sum = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        sum += a[i];
    }
    
    long x = a[0];
    long y = sum - a[0];
    long minDiff = abs(x - y);
    for(int i = 1; i < n - 1; ++i){
        x += a[i];
        y -= a[i];
        long diff = abs(x - y);
        if(minDiff > diff){
            minDiff = diff;
        }
    }

    cout << minDiff << endl;
}
