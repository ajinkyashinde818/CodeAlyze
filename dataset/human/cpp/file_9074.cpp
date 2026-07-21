//Template Matching
#include <iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    string a[n];
    string b[m];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<m; i++){
        cin >> b[i];
    }
    int x=0;
    int y=0;
    int z=0;
    for(int i=0; i<(n-m+1); i++){
        for(int j=0; j<(n-m+1); j++){
            int t=i;
            int s=j;
            int x=0;
            int y=0;
            while(a[t][s]==b[x][y]){
                s++;
                y++;
                if(x==(m-1) && y==m){
                    cout << "Yes" << endl;
                
                    return 0;       
                }
                else if(y==m){
                    y=0;
                    x++;
                    t++;
                    s-=m;

                }
                
            }
        }
    }
        cout << "No" << endl;
    

    return 0;
}
