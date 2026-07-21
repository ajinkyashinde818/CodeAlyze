#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    string sm[51];
    string sn[51];
    int m,n;
    int x = 0;
    cin >> m >> n;
    for(int i=0;i<m;i++){
        cin >> sm[i];
    }
    for(int i=0;i<n;i++){
        cin >> sn[i];
    }
    for(int i=0;i<m-n+1;i++){
        for(int j=0;j<m-n+1;j++){
            if(sn[0] == sm[i].substr(j,n)){
                x += 1;
                if(x >= n) {
                    cout << "Yes" << endl;
                    return 0;
                }
                //cout << i << j << endl ;
                for(int k=1;k<n;k++){
                    if(sn[k] == sm[k+i].substr(j,n)){
                        x += 1;
                        //cout << k << endl;
                    }
                    else if(sn[k] != sm[k+i].substr(j,n)){
                        //cout << "hazure"<< endl;
                        k = 1;
                        x = 0;
                        break;
                    }
                    if(x >= n) {
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    //cout << "x=" <<x << endl;
    if(x == 0){
        cout << "No" << endl;
    }
    return 0;
}
