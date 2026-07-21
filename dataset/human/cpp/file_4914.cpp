#include <iostream>
#include <string>
using namespace std;

void _150() {
    string s;
    cin >> s;

    if ((s == "AAA") || (s == "BBB"))
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
}

void _156() {
    int n, r;
    cin >> n >> r;

    if (n >= 10)
        cout << r << endl;
    else
        cout << r + 100 * (10 - n) << endl;
}


int main()
{
    // _150();
    _156();
    
    return 0;
}
