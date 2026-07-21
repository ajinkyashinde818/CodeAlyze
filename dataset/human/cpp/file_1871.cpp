#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <climits>
#include <cfloat>
using namespace std;

int main()
{
    vector<int> decimal(7);
    decimal[6] = 5000000;
    for(int i=5; i>=0; --i)
        decimal[i] = decimal[i+1] / 2;

    int n;
    cin >> n;

    while(--n >= 0){
        string s;
        cin >> s;

        unsigned a = 0;
        for(int i=0; i<8; ++i){
            int b;
            if(isdigit(s[i]))
                b = s[i] - '0';
            else
                b = s[i] - 'a' + 10;
            a <<= 4;
            a += b;
        }

        bool sign = false;
        if(a & (1u<<31)){
            sign = true;
            a &= ~(1u<<31);
        }

        int x = 0;
        for(int i=0; i<7; ++i){
            if(a & 1)
                x += decimal[i];
            a >>= 1;
        }

        ostringstream oss;
        if(sign)
            oss << '-';
        oss << a << '.' << setfill('0') << setw(7) << x;

        string ret = oss.str();
        while(ret[ret.size()-2] != '.' && ret[ret.size()-1] == '0')
            ret.resize(ret.size() - 1);
        cout << ret << endl;
    }

    return 0;
}
