#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>

int main(){
    int n, m;
    std::cin>>n>>m;
    std::vector<std::string> a(n), b(m);
    for(int i = 0;i < n;i++){
        std::cin>>a[i];
    }
    for(int i = 0;i < m;i++){
        std::cin>>b[i];
    }
    std::string ans = "No";
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            int cnt = 0;
            for(int k = 0;k < m;k++){
                for(int l = 0;l < m;l++){
                    if(i+k >= n || j+l >= n){
                        continue;
                    }
                    if(a[i+k][j+l] == b[k][l]){
                        //std::cout<<i+k<<":"<<j+l<<std::endl;
                        ++cnt;
                    }
                }
            }
            if(cnt == (m * m)){
                ans = "Yes";
                break;
            }
        }
    }
    std::cout<<ans<<std::endl;
    return 0;
}
