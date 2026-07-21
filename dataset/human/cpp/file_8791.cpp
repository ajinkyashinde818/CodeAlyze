#include <iostream>

using namespace std;


int main()
{
    int n, m;
    int flag = 0; // †‡Xx_悪魔的行為_xX‡†
    char a[55][55];
    char b[55][55];
    char dummy;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }



    for (int i = 0; i < n - m + 1 && !flag; i++) {
        for (int j = 0; j < n - m + 1 && !flag; j++) {

            int k, l;

            k = 0;
            l = m;
            while (l == m && k < m) {
                l = 0;
                while (a[i + k][j + l] == b[k][l] && l < m) {
                    l++;
                }
                k++;
            }

            if (k == m && l == m) {
                flag = 1;
            }
            
        }
    }

    cout << (flag ? "Yes" : "No");

    return 0;
}
