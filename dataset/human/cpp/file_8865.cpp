#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n, m;
string a[50], b[50];

bool match(int x, int y)
{
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            if(a[i+y][j+x] != b[i][j]) return false;
        }
    }

    return true;
}
int main()
{
    cin >> n >> m;

    int i;
    for(i=0; i<n; i++) cin >> a[i];
    for(i=0; i<m; i++) cin >> b[i];

    if(n-m < 1){
        cout << (a[0]==b[0] ? "Yes" : "No") << endl;
        return 0;
    }

    bool cont;
    int j;
    for(i=0; i<n-m; i++){
        for(j=0; j<n-m; j++){
            cont = match(i, j);
            if(cont){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;

    return 0;
}
