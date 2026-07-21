#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, displayed_rating;
    cin >> n >> displayed_rating;

    int modifier = (n < 10) ? 100 * (10 - n) : 0;
    cout << displayed_rating + modifier;
    return 0;
}

/*
file=a
g++ -W -Wall -pedantic --std=c++17 -ggdb3 -o ${file}.out ${file}.cpp && ./${file}.out

*/
