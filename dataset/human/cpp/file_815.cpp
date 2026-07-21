#include <iostream>
#include <vector>
using namespace std;

void a()
{
    int k, n;
    cin >> n >> k;
    cout << n - k + 1;
}
void b()
{
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    int am = n / a;
    int bm = n / b;
    int cm = n / c;
    long long int num = 0;

    for (int i = 0; i <= am; i++)
    {
        if (a * i > n)
            break;
        for (int j = 0; j <= bm; j++)
        {
            if (a * i + b * j > n)
                break;
            if ((n - a * i - b * j) % c == 0)
                num++;
        }
    }
    cout << num;
}
int main(void)
{
    b();
    //a();
}
