#include<iostream>
#include<string>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    char a[59][59], b[59][59];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cin >> b[i][j];
        }
    }
    bool ans=false;
    for(int i=0;i<n-m+1;i++){
        for(int j=0;j<n-m+1;j++){
            bool tmp=false;
            for(int k=0;k<m;k++){
                for(int l=0;l<m;l++){
                    if(a[i+k][j+l]!=b[k][l]){
                        tmp=true;
                    }
                    if(tmp)break;
                }
                if(tmp)break;
            }
            if(!tmp){
                ans=true;
                break;
            }
        }
        if(ans){
            break;
        }
    }
    if(ans){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}
