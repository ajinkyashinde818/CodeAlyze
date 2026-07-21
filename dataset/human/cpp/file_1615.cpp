#include<bits/stdc++.h>
using namespace std;
long long a[100009];
main(){
   int n;
   cin >> n;
   for(int k = 2; k <= 1000; k++){
        if(n == k* (k - 1) / 2){
            cout << "Yes\n" << k << endl;
            int cnt = 0;
            vector<vector<int> > v(k);
            for(int i = 0; i < k; i++){
                for(int j = i + 1; j < k; j++){
                    v[i].push_back(++cnt);
                    v[j].push_back(cnt);
                }
            }
            for(int i = 0; i < k; i++){
                cout<<v[i].size()<<" ";
                for(int j : v[i])
                    cout<<j<<" ";
                cout<<endl;
            }
            return 0;
        }
   }
   cout << "No"<<endl;
   return 0;
}
