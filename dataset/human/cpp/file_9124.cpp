#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    char pic_a[n][n], pic_b[m][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> pic_a[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cin >> pic_b[i][j];
            }
    }

  //bool flag = true;
    for (int i = 0; i < n - m + 1; i++) {
      //bool flag = true;
        for (int j = 0; j < n - m + 1; j++) {
            bool flag = true;
            for (int k = 0; k < m; k++) {
                for (int u = 0; u < m; u++) {
                    if (pic_b[k][u] != pic_a[i + k][j + u]) {
                        flag = false;
                    }
                }
            }
        if (flag == true) {
            cout << "Yes" << endl;
            return 0;
            }
            }

    }

    cout << "No" << endl;


}
