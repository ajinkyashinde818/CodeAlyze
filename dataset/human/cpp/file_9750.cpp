#include <stdio.h>
#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
    int n;
    string s, u;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, s);
    unsigned long  res = 1;
    int count, tmp;
    for (size_t i = 0; i < 26; i++)
    {
        count = 0;
        tmp = 0;
        while (true)
        {
            tmp = s.find('a' + i, tmp);
            if (tmp == -1)
                break;
            tmp++;
            count++;
        }
        res *= (count + 1);
        res = res % ((unsigned long)pow(10, 9) + 7);
    }

    res--; 
    cout << res << "\n";
}
