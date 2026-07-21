#include<stdio.h>
#include<iostream>
#include<cstdlib>
using namespace std;

int N;
long long int sum = 0,ans = 0;
int a[112345];
int main (){
    cin >> N;
    int cnt = 0;
    int zero = 0;
    int m = 1023456789;
    for(int i=0; i<N; i++) {
        cin >> a[i];
        int x = abs(a[i]);
        sum += x;
        if( a[i] < 0 ) cnt++;
        m = min( m,x);
    }
    cout << ( cnt % 2 ? sum - (m * 2) : sum) << endl;
    return 0;
}
