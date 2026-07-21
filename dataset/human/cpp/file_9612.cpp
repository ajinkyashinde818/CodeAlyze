#include<iostream>

using namespace std;

int main(){
    int n, m;
    cin >>n >>m;
    char pic[n][n], tpic[m][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >>pic[i][j];
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            cin >>tpic[i][j];
        }
    }

    bool exist = false;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            //cout << "a" << endl;
            if(i + m - 1 >= n || j + m - 1 >= n) continue;

            bool match = true;
            //cout << "a" << endl;
            for(int k = 0; k < m; k++){
                for(int l = 0; l < m; l++){
                    //cout << pic[i + k][j + m] << ":" << tpic[k][l] << endl;
                    if(pic[i + k][j + l] != tpic[k][l]){
                        match = false;
                        //cout << "a" << endl;
                    }
                }
            }
            if(match) exist = true;
        }
    }

    if(exist){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
