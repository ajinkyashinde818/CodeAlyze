//
//  main.cpp
//  AGC031 -a
//
//  Created by hiroaki on 2019/03/16.
//  Copyright © 2019年 hiroaki. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

int main() {
    long n;
    string s,S;
    cin >>n>>s;
    S=s;
    sort(s.begin(), s.end());
    decltype(s)::iterator result = std::unique(s.begin(), s.end());
    s.erase(result,s.end());
    long sum = 1;
    long l = s.size();
    for (int i=0; i<l; i++) {
        long e =count(S.begin(), S.end(), s[i]);
        sum *= (e+1);
        sum = sum % 1000000007;
    }
    cout<<sum-1<<endl;
    return 0;
}
