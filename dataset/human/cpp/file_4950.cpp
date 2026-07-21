#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cmath>
#include <utility>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    int n, r;
    cin >> n >> r;
    if (n >= 10)
        cout << r;
    else
        cout << r + 100 * (10 - n);
    //cin.close();
    //cout.close();
    return 0;
}
