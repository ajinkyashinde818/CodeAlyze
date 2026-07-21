#include <iostream>
#include <bits/stdc++.h>

int di(int a, int b, int n);

int main() {
    int r, g, b, n,cnt;
    cnt=0;
    std::cin >> r >> g >> b >> n;
    for(int i=0; i<=n/r;i++){
        for(int j=0;j<=(n-i*r)/g;j++){
            if((n-r*i-g*j)%b==0){
                cnt=cnt+1;
            }
        }
    }
    std::cout << cnt << std::endl;
    return 0;
}
