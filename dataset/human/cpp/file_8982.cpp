#include<iostream>
#include <regex>
using namespace std;
int main()
{
    int n, m, tmp, count;
    cin >> n >> m;
    // 文字列の入力
    string a[n], b[m], yes, no;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<m; i++){
        cin >> b[i];
    }
    // 出力
    yes = "Yes";
    no = "No";
    tmp = -1;
    count = 0;
    int i=0;
    for(int i=0; i<=n-m; i++){
        if(a[i].find(b[0])!=-1){
            tmp = a[i].find(b[0]);
            for(int j=0; j<=n-m; j++){
                if(a[i].substr(j, n).find(b[0])!=-1){
                    for(int k=0; k<m; k++){
                        if(a[i+k].substr(j, m).find(b[k])!=-1){
                            count++;
                            if(count>=m){
                                cout << yes << endl;
                                return 0;
                            }
                        }
                    }
                    count = 0;   
                }
            }
        }
    }
    cout << no << endl;
    return 0;
}
