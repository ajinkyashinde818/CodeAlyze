#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    char large_square[n][n+1], small_square[m][m+1];
    
    for(int i=0; i<n; i++){
        cin >> large_square[i];
    }
    for(int i=0; i<m; i++){
        cin >> small_square[i];
    }
    int flag;
    for(int i=0; i<n-m+1; i++){
        for(int j=0; j<n-m+1; j++){
            flag=0;
            for(int k=0; k<m; k++){
                for(int l=0; l<m; l++){
                    if(large_square[i+k][j+l]!=small_square[k][l]){
                        flag=1;
                        break;
                    }
                }
            }
            if(flag==0){
                break;
            }
        }
        if(flag==0){
            break;
        }
    }
    if(flag==0){
        cout << "Yes";
    }else{
        cout << "No";
    }

    return 0;
}
