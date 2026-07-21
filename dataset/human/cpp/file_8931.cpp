#include <iostream>
#include <vector>
using namespace std;
int main(){

    int n, m;
    cin >> n >> m;

    vector<string>a(n),b(m);

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    for(int i=0; i<m; i++){
        cin >> b[i];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(a[i][j]!=b[0][0])continue;
            bool f = 1;

            for(int k=0; k<m; k++){
                for(int l=0; l<m; l++){
                    if(i+k>=n || j+l>=n || a[i+k][j+l]!=b[k][l]){
                        f = 0;
                        break;
                    }
                }
            }

            if(f){
                puts("Yes");
                return 0;
            }

        }
    }

    puts("No");

    return 0;
}
