#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    long long n, c, ans;
    cin >> n >> c;
    long long  x[n], v[n], avr[n+1], avl[n+1], maxr[n+1], maxl[n+1];
    for(int i =0; i<n; i++){
        cin >> x[i] >> v[i];
        avr[i] = i==0? v[i]
                     : avr[i-1] + v[i];
    }
    for(int i =0; i<n; i++){
        auto current = avr[i] - x[i];
        maxr[i] = i==0? current
                      : max(maxr[i-1], current);
    }
    maxr[n] = 0;
    
    for(int i = n-1; i>=0; i--){
        avl[i] = i==n-1? v[i]
                       : avl[i+1] + v[i]; 
    }
    for(int i = n-1; i>=0; i--){
        auto current = avl[i] - (c-x[i]);
        maxl[i] = i==n-1? current
                        : max(maxl[i+1], current);
    }
    maxl[n] = 0;
    
    ans = 0;
    for(int i=0; i<n; i++){
        auto r1 = avr[i]-x[i];
        auto r2 = avr[i]-2*x[i] + maxl[i+1];
        auto first_right = max(r1, r2);
        ans = max(ans, first_right);
        auto l1 = avl[i] - (c-x[i]);
        auto l2 = i==0? avl[i]-2*(c-x[i]) : avl[i]-2*(c-x[i]) + maxr[i-1];
        auto first_left = max(l1, l2);
        ans = max(ans, first_left);
    }
    cout << ans << endl;
    return 0;
}
