//
//  main.cpp
//  ProCon
//
//  Created by hashimotoryoma on 2017/08/20.
//  Copyright © 2017年 hashimotoryoma. All rights reserved.
//


#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

typedef long long ll;

int N;
ll C;
ll x[112345],v[112345];
ll vsum[112345];
ll ans;
ll f[112345];

int main() {
    // insert code here...    return 0;
  //////
    // input from txt
    /*
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
    std::ofstream out("output.txt");
    std::cout.rdbuf(out.rdbuf());
   ///////
     */
    cin >> N >> C;
    for(int i=1;i<=N;i++){
        cin >> x[i] >> v[i];
        vsum[i] = vsum[i-1] + v[i];
        f[i] = max(f[i-1],vsum[i]-x[i]);
    }
    x[N+1] = C;
    for(int i=N+1;i>=1;i--){
        ans = max(ans,(vsum[N]-vsum[i-1])-2*(C-x[i])+f[i-1]);
    }
    
    for(int i=N;i>=1;i--){
        f[i] = max(f[i+1],(vsum[N]-vsum[i-1])-(C-x[i]));
    }
    for(int i=0;i<=N;i++){
        ans = max(ans,vsum[i]-2*x[i]+f[i+1]);
    }
    cout << ans << endl;
    return 0;
}
