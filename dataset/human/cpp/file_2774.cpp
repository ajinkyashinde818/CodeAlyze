#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
#include <queue>
#include <climits>
#include<cmath>
#include <sstream>
#include <iomanip>

bool sort_pair( std::pair< int64_t, std::string > origin, std::pair< int64_t, std::string > another )
{
    return origin.first < another.first;
}


int main()
{

    int64_t a;

    std::cin>> a;

    std::vector< int > b( a );
    std::priority_queue< int64_t > c;
    std::priority_queue< int, std::vector<int64_t>, std::greater<int64_t> > d;

    for( int i = 0; i < a; i++ )
    {
        std::cin>> b[i];

        d.push( abs( b[i] ) );

        if( b[i] < 0 )
        {
            c.push( b[i] );
        }
    }

    int64_t all = 0;
    
    if( c.size() % 2 != 0 )
    {
        all += d.top() * -1;
        d.pop();
    }

    while( !d.empty() )
    {
        all += abs( d.top() );
        d.pop();
    }
    
    std::cout<< all <<"\n";
}
