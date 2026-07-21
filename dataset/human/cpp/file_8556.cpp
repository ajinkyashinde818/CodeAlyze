#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {

    int n, m;

    cin >> n >> m;

    vector<string> map1(n);
    vector<string> map2(m);

    for(int i = 0; i < n; ++i)
        cin >> map1[i];
    
    for(int j = 0; j < m; ++j)
        cin >> map2[j];


    bool isTrue = false;
    for(int i = 0; i < n - m + 1; ++i) {
        for(int j = 0; j < n - m + 1; ++j) {

            int k;
            for(k = 0; k < m; ++k) {
                
                string s = map1[i + k];
                if(map2[k] != s.substr(j, m))
                    break;

            }

            isTrue = k == m;

            if(isTrue)
                break;
        }

        if(isTrue)
            break;
    }

    if(isTrue)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;

}
