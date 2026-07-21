#include <bits/stdc++.h>
#include<iostream>
using namespace std;

int main(void)
{
    int r,g,b,n;
    cin >> r >> g >> b >> n;

    int count =0;
    for(int i = 0; n >= r*i; i++) {
        if (r*i == n) {
            count++;
            continue;
        }
        for (int j = 0; n >= r*i + g*j; j++) {
                if (r*i + g*j == n) {
                    count++;
                } else {
                    int m = n - (r*i + g*j);
                    if (m % b == 0) count++;
                }
        }
    }

    cout << count << endl;
    return 0;
}
