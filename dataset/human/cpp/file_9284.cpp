#include <iostream>
#include <string>

using namespace std;
int main (){
    int n,m;
    cin >> n >> m;
    string tmp;
    bool a[n][n];
    bool b[m][m];
    for (int i = 0; i < n; i++){
        cin >> tmp;
        for (int j = 0; j < n; j++){
            if(tmp[j]=='#') a[i][j]=1;
            else            a[i][j]=0;
        }
    }
    for (int i = 0; i < m; i++){
        cin >> tmp;
        for (int j = 0; j < m; j++){
            if(tmp[j]=='#') b[i][j]=1;
            else            b[i][j]=0;
        }
    }

    int wdiff=n-m;
    int row,col,trow,tcol;
    bool jud,tjud;
    jud=true;
    for (int i = 0; i < wdiff*wdiff; i++){
        if(i==0) jud=false;
        row=i/wdiff;
        col=i%wdiff;
        tjud=true;
        for (int j = 0; j < m*m; j++){
            trow=j/m;
            tcol=j%m;
            if(b[trow][tcol]!=a[row+trow][col+tcol]) tjud=false;
        }
        if(tjud) jud=true;
    }
    if(jud) cout << "Yes\n";
    else    cout << "No\n";
}
