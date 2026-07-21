#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n, min;
    long sum = 0;
    cin >> n;
    vector<int> a(n);
    int minus_group = 0;
    int current_minus_length = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a.at(i);
        if (a.at(i) < 0)
        { //0?
            current_minus_length++;
        }
        if (a.at(i) > 0 || i == n - 1)
        {
            if (current_minus_length % 2 != 0)
            {
                minus_group++;
            }
            current_minus_length = 0;
        }
        a.at(i) = abs(a.at(i));
        if (i == 0)
        {
            min = a.at(0);
        }
        if (min > a.at(i))
        {
            min = a.at(i);
        }
    }
    for (int i = 0; i < n; i++)
    {
        sum += a.at(i);
    }
    if (minus_group % 2 != 0)
    {
        sum -= min * 2;
    }
    cout << sum << endl;
    return 0;
}
