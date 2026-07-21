#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>

using namespace std;

int main(){
    int r, g, b, n;
    cin >> r >> g >> b >> n;
    int counter = 0;
    for (size_t i = 0; i <= n/r; i++)
    {
        for (size_t j = 0; j <= n/g; j++)
        {
            int z = (n-(i*r+j*g))/b;
            if(0<=z && z<=(n/b) && z*b+j*g+i*r==n) counter++;
        }
    }
    cout << counter << endl;
    return 0;
}
