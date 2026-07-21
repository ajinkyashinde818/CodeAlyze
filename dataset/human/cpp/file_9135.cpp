#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cmath>
#include <iomanip>

int main()
{
    // std::cout << std::fixed << std::setprecision(5);
    int n, m;
    std::cin >> n >> m;
    std::string a[n], b[m];
    for(int i=0; i<n; i++) std::cin >> a[i];
    for(int i=0; i<m; i++) std::cin >> b[i];
    
    bool exist = false;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i+m-1>n || j+m-1>n) continue;

            bool match = true;
            for(int p = 0; p < m; p++)
            {
                for (int q = 0; q < m; q++)
                {
                    if(a[i+p][j+q]!=b[p][q]) match = false;
                }
            }
            if(match) exist = true;
        }
    }

    if(exist)
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;
    
    return 0;
}
