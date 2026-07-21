#include<stdio.h>
#include<iostream>
#include<cstdlib>
using namespace std;

int N;
int main (){
    cin >> N;
    int a[N];
    long long int sum = 0;
    for(int i=0; i<N; i++){
        cin >> a[i];
        sum += a[i];
    }
    long long int x = 0;
    long long int ans = 9999999999;
    for(int i=0; i<N-1; i++){
        x += a[i];
        ans = min( abs(sum - x * 2), ans);
    }
    cout << ans << endl;
    return 0;
}
