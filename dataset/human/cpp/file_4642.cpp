#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, R;
    cin >> N >> R;

    if (10 <= N){
        cout << R << "\n";
    }
    else {
        cout << (R + (100 * (10 - N))) << "\n";
    }


    return 0;
}
