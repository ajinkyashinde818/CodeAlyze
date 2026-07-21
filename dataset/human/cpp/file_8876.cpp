#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    string A[n];
    string B[m];

    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    for(int i = 0; i < m; i++){
        cin >> B[i];
    }

    bool exist = false;
    for(int y = 0; y <= n-m; y++){
        for(int x = 0; x <= n-m; x++){

            bool match = true;
            for(int i = 0; i < m; i++){
                for(int j = 0; j < m; j++){
                    if(A[y+i][x+j] == B[i][j]){
                        continue;
                    }
                    else{
                        match = false;
                        //break;
                    }
                }
            }

            if(match == true){
                exist = true;
                break;
            }

        }
    }

    if(exist == true){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }

    return 0;
}
