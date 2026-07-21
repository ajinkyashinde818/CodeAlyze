#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n,m,cnt = 0,flag = 1;
    cin >> n >> m;
    string a[n],b[m],s;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    for(int i = 0; i <= n - m; i++){
        for(int j = 0; j <= n - m; j++){
            for(int k = 0; k < m; k++){
                s = a[i+k].substr(j,m);
                if(b[k] == s) cnt++; 
            }
            if(cnt == m){
                flag = 0;
                break;
            }else cnt = 0;
        }
    }

    cout << (flag == 0 ? "Yes" : "No") << endl;

    return 0;
}
