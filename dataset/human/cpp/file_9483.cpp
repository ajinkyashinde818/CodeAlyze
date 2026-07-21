#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
#include<string>
#include<string.h>
#include<unordered_set>

using namespace std;




vector<int> prime_sieve(int n)
{
    int* arr = new int[n+1];
    
    int i, p;
    for (i = 0; i <= n; ++i) {
        arr[i] = i;
    }
    for (i = 2; i <= n; ++i) {
        if (arr[i] != 0) {
            for (p = arr[i] * arr[i]; p <= n; p += arr[i]) {
                arr[p] = 0;
            }
        }
    }
    vector<int> primes;
    for (i = 2; i <= n; ++i) {
        if (arr[i] != 0) {
            primes.push_back(arr[i]);
        }
    }
    return primes;
}

int min(int a, int b)
{
    return a < b ? a : b;
}



int main()
{
    int n, m,flag=0;
    cin >> n >> m;
    vector<string> a(n), b(m);
    
    int i, j, k,l;
    for (i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (i = 0; i < m; ++i) {
        cin >> b[i];
    }

    for (k = 0; k < n; ++k) {
        for (l = 0; l < n; ++l) {
            if (k + m - 1 >= n || l + m - 1 >= n) {
                continue;
            }
            for (i = 0; i < m; ++i) {
                for (j = 0; j < m; ++j) {
                    if (b[i][j] != a[i + k][j + l]) {
                        flag = 1;
                    }
                }
            }
            if (flag == 0) {
                cout << "Yes";
                exit(0);
            }
            flag = 0;
        }
    }

    cout << "No";
    
    
}
