#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <limits>
#include <numeric>
#include <type_traits>

using namespace std;

int main() {
    int i, j, n, p, q, temp;
    long long int t = 0;
    int flag = 0;
    int minidx;
    long long int minnum=1000000000;
    int count=0;
    string s;
    cin >> n;
    long long int a[n];
    for (i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for(i=0; i<n; ++i){
        if(a[i]<=0){++count;}
        if(abs(a[i])<minnum){minnum=abs(a[i]);minidx=i;}
    }
    if(count%2==0){
        for (i = 0; i < n; ++i) {t+=abs(a[i]);}
    }
    else{
        for (i = 0; i < n; ++i) {
            if(i==minidx){
                t-=abs(a[i]);
            }
            else{t+=abs(a[i]);}
        }
    }

    cout<<t;
    return 0;
}
