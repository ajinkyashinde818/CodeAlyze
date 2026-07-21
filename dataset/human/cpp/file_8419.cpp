#include <iostream>
using namespace std;
int main(){
    bool f;
    string a[50],b[50];
    int n,m,i,j,c,d;
    cin >> n >> m;
    for (i=0;i<n;i++)
        cin >> a[i];
    for (i=0;i<m;i++)
        cin >> b[i];
    for (i=0;i<n-m+1;i++){
        for (j=0;j<n-m+1;j++){
            f=true;
            for (c=0;c<m;c++){
                for (d=0;d<m;d++){
                    if (a[i+c][j+d]!=b[c][d])
                        f=false;
                }
            }
            if (f==true){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
