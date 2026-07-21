#include<bits/stdc++.h>

int main()
{
    int n,m;
    std::cin >> n >> m;
    std::vector<std::string> t(n), k(n);
    for(int i = 0; i < n; i++)std::cin >> t[i];
    for(int i = 0; i < m; i++)std::cin >> k[i];

    bool res = false;
    for(int i = 0; i <= n - m; i++){
        for(int j = 0; j <= n - m; j++){
            bool flag = true;
            for(int x = 0; x < m; x++){
                for(int y = 0; y < m; y++){
                    if(t[x + i][y + j] != k[x][y])flag = false;
                }
            }
            if(flag)res = true;
        }
    }
    std::cout << (res ? "Yes" : "No") << std::endl;


}
