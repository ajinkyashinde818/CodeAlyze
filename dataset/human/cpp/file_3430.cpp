#include <iostream>

using namespace std;

int n;
int a[100000];
long long result;
int lowest_abs_val;

void enter()
{

    cin >> n;
    for (int i = 0 ; i < n ; i ++)
        cin >> a[i];

}

void process()
{

    for (int i = 0 ; i < n - 1; i ++)
    {
        if (a[i] < 0)
        {
            a[i] *= -1;
            a[i+1] *= -1;
        }
    }

    if (a[n-1] >= 0)
    {
        for (int i = 0 ; i < n ; i++)
            result += a[i];
    }
    else
    {
        lowest_abs_val = abs(a[0]);
        for (int i = 0 ; i < n ; i++)
            {
                result += abs(a[i]);
                lowest_abs_val = min(lowest_abs_val,abs(a[i]));
            }
        result -= 2*lowest_abs_val;
    }
}

void print()
{

    cout << result;

}

int main()
{

    enter();
    process();
    print();
    return 0;

}
