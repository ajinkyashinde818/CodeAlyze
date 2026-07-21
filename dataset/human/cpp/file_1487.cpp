#include <bits/stdc++.h>
using namespace std;

vector<int> X[1003];

int main() {

    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int N;
    cin >> N;
    
    int ptr = 0;
    
    while(ptr * (ptr - 1) / 2 < N)
        ptr++;
    
    if(ptr * (ptr - 1) / 2 > N)
    {
        cout << "No\n";
        return 0;
    }
    
    cout << "Yes\n";
    
    int k = 0;
    cout << ptr << "\n";
    
    for(int i=1; i<=ptr; i++)
    {
        for(int j=i+1; j<=ptr; j++)
        {
            k++;
            X[i].push_back(k);
            X[j].push_back(k);
        }
    }
    
    for(int i=1; i<=ptr; i++)
    {
        cout << X[i].size() << " ";
        
        for(auto x : X[i])
            cout << x << " ";
        cout << "\n";
    }
    
    return 0;
}
