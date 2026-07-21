#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int &i : a){
        cin >> i;
    }

    for(int &i : b){
        cin >> i;
    }
    reverse(b.begin(), b.end());
    int c = -1;
    for(int i = 0; i < n; i++){
        if(a[i] == b[i]){
            c = b[i];
            break;
        }
    }
    int j = 0;
    for(int i = 0; i < n; i++){
        while(j < n && (b[j] == c || a[j] == c)){
            j++;
        }
        if(a[i] == b[i]){
            if(j == n){
                cout << "No";
                return 0;
            }
            int t = b[i];
            b[i] = b[j];
            b[j] = t;
        }
    }
    cout << "Yes\n";
    for(int i : b){
        cout << i << " ";
    }
    return 0;
}
