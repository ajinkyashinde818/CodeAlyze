#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <limits>
#include <map>
#include <set>
#include <iomanip>
#include <cmath>

using namespace std;

typedef long long int ll;
typedef std::numeric_limits<double> dbl;
const long long int LL_INF=1LL<<60;

vector<string> split(const string& input, char delimiter)
{
    stringstream stream(input);
    
    string field;
    vector<string> result;
    while (getline(stream, field, delimiter)) {
        result.push_back(field);
    }
    return result;
}

//#define DEBUG

ll A, B, M, N, D, K, Q, W, H, T, X, Y;

int main()
{
    cin >> N >> M;
    vector<string> sA(N), sB(M);
    for (auto& a : sA)
        cin >> a;
    for (auto& b : sB)
        cin >> b;

    for (int i = 0; i < N - M + 1; ++i) {
        for (int j = 0; j < N - M + 1; ++j) {
            bool match = true;
            for (int k = 0; k < M; ++k) {
                for (int l = 0; l < M; ++l) {
                    if (sB[k][l] != sA[i + k][j + l])
                        match = false;
                }
            }
            if (match) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;

    return 0;
}
