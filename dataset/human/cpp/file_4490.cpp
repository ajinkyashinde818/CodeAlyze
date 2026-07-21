#include<iostream>
using namespace std;

int main()
{
    int n, m;

    cin >> n >> m;

    if( n == 1 )
    {
        cout << 0 << endl;
        return 0;
    }

    if( n % 2 == 0 )
    {
        cout << 0;
        for( int i = 2; i < n / 2; i++ )
            cout << " " << 0;

        for( int i = n / 2 - 1; i < n; i++ )
            cout << " " << m;
    }
    else
    {
        cout << 0;
        for( int i = 1; i < n / 2; i++ )
            cout << " " << 0;

        for( int i = n / 2; i < n; i++ )
            cout << " " << m;
    }

    cout << endl;

    return 0;
}
