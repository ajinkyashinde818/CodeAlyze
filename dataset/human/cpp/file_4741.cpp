#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<climits>
#include<cmath>
#include<sstream>
#include<iomanip>
#include <map>
#include <stack>
 
const int64_t cc = pow( 10, 9 );
//std::cout<< std::fixed << std::setprecision(10) << ( double )( max ) / 2;
bool sort_pair( std::pair< std::string, int64_t > origin, std::pair< std::string, int64_t > another )
{
    return origin.second  > another.second;
}
 
int main()
{
    std::string word = "aa";
    int a,b,c,d,e;
    std::cin>> a;
    std::cin>> b;

    c = b + ( 10 - std::min( a , 10 ) ) * 100;

    std::cout<< c;
}
