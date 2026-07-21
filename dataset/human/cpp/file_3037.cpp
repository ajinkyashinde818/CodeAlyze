#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
    int n = 0;
    cin >> n;
    int tmp = 0;
    int countMinus = 0;
    unsigned long long sum = 0;
    int min = 1000000001;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if (tmp < 0)
        {
            countMinus++;
        }
        tmp = abs(tmp);
        sum += tmp;
        if(min > tmp) {
            min = tmp;
        }
    }


    if(countMinus & 1) {
        cout << sum - min * 2 << endl;
    }
    else {
        cout << sum << endl;
    }

    return 0;
}
