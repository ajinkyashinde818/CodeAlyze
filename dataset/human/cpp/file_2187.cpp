#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <utility>
using namespace std;

int main()
{
    int n,i,j;
    cin >> n;
    vector<long long> a(n);
    vector<long long> b(n);
    int x = 0,y = 0,z = 0;
    long long sum = 0;
    for(i = 0;i < n;++i){
        cin >> a.at(i);
        if(a.at(i) > 0){
            sum += a.at(i);
            b.at(i) = a.at(i);
            ++x;
        }else if(a.at(i) < 0){
            sum += (-1)*a.at(i);
            b.at(i) = (-1)*a.at(i);
            ++y;
        }else{
            b.at(i) = 0;
            ++z;
        }
    }
    if(z){
        cout << sum << endl;
    }else{
        if(y%2){
           int min = b.at(0);
           for(i = 0;i < n;++i){
               if(min > b.at(i)){
                   min = b.at(i);
                }
            }
            cout << sum-2*min << endl;
        }else{
            cout << sum << endl;
        }
    }
    return 0;
}
