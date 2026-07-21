#include <iostream>
#include <vector>
using namespace std;
int main(void){
    int n, k = 1;
    cin >> n;
    while(k*(k-1)/2 < n) k++;
    if(k*(k-1)/2 > n){
        puts("No");
        return 0;
    }
    vector< vector<int> > s(k, vector<int>());
    int a = 0, b = 1;
    for(int i=1;i<=n;i++){
        s[a].push_back(i);
        s[b].push_back(i);
        b++;
        if(b == k) b = ++a + 1;
    }
    puts("Yes");
    cout << k << endl;
    for(int i=0;i<k;i++){
        cout << k-1;
        for(int j=0;j<k-1;j++){
            cout << " " << s[i][j]; 
        }
        cout << endl;
    }
}
