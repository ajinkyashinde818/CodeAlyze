#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <unordered_map>

using namespace std;
typedef long long ll;


int main(void)
{
    int n,r;
    cin >> n >> r;

    if ( n >= 10)
    {
        cout << r<<endl;
    }else
    {
        cout << r + 100*(10-n)<<endl;
    }
    

    return 0;
}
