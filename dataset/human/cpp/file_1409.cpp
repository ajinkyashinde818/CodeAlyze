#include <bits/stdc++.h>
using namespace std;


signed main(){
    int n;
    cin >> n;
   double p = sqrt(2*n);
    int k = p +1;
    if(k*(k-1)!= n*2){
        cout << " No ";
    }else{
        int a[k][k];
        int t =1;
        for(int i =0;i<k;i++){
            for(int j =i+1;j<k;j++){
                a[i][j]=t;
                a[j][i]=t;
                t++;
            }
        }
        cout << " Yes " << endl;
        cout << k << endl;
        for(int i =0;i<k;i++){
            cout << k-1 << " ";
            for(int j =0;j<k;j++){
                if(i!=j){
                    cout << a[i][j]<< " ";
                }
            }
            cout << endl;
        }
    }

    return 0;
}
