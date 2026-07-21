#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    int n,m;
    vector<string> img;
    vector<string> tmp;
    int cnt = 0;
    int flag = 0;

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        img.push_back(str);
    }
    for(int i = 0; i < m; i++){
        string str;
        cin >> str;
        tmp.push_back(str);
    }

    for(int i = 0; i < n - m + 1; i++){
        for(int j = 0; j < n - m + 1; j++){
            for(int k = 0; k < m; k++){
                for(int l = 0; l < m; l++){
                    if(img[i + k][j + l] == tmp[k][l]){
                        cnt++;
                        if(cnt == m * m){
                            flag = 1;
                        }
                    }
                    else{
                        cnt = 0;
                    }
                }
            }
        }
    }

    if(flag == 1){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }

    return 0;
}
