#include <iostream>
#include <algorithm>

using namespace std;

double solve(int T, int D, int TA, int TB, int DA, int DB)
{
    double res = 999999999999999.99;
    
    for(int i = 0; i <= D; i += DA)
    {
        for(int j = 0; i + j <= D; j += DB)
        {
            int Acal = TA * i;
            int Bcal = TB * j;
            
            double Temperature = (1.0 * (Acal + Bcal)) / (i + j);
            
            res = min(res, abs(Temperature - T));
        }
    }
    
    return res;
}

int a, b, c, d, e, f;

int main()
{
    cin >> a >> b >> c >> d >> e >>f;
    
    printf("%.999999f\n", solve(a, b, c, d, e, f));
    
    return 0;
}
