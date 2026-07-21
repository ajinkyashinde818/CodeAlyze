#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> ans[400005];

int main(void)
{
    cin >> n;
    
    int sum = 0, num;
    for(int i = 1; ; i++){
        sum += i;
        if(sum == n){
            num = i;
            break;
        }
        if(sum > n){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    
    if(num == 1){
        cout << 2 << endl;
        cout << 1 << " " << 1 << endl;
        cout << 1 << " " << 1 << endl;
        return 0;
    }
    
    
    
    int id = 4;
    ans[1].push_back(1);
    ans[1].push_back(2);
    ans[2].push_back(1);
    ans[2].push_back(3);
    ans[3].push_back(2);
    ans[3].push_back(3);
    for(int i = 3; i <= num; i++){
        for(int j = 1; j <=i; j++){
            ans[i+1].push_back(id);
            ans[j].push_back(id++);
        }
    }
    
    cout << num+1 << endl;
    for(int i = 1; i <= num+1; i++){
        cout << ans[i].size() << " ";
        for(int j = 0; j < ans[i].size(); j++) cout<< ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}
