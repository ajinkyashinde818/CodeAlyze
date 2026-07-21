#include <iostream>
#include <vector>

using namespace std;

int main(){
    int R, G, B, N;
    cin >> R >> G >> B >> N;
    int ans = 0;
    vector<int> cnt;
    
    for(int i = 0; i <= N; i++){
        int sum = 0;
        if(i * R > N)   break;
        
        for(int j = 0; j <= N; j++){
            if(i * R + j * G > N)   break;
            
            sum = i * R;
            sum += j * G;
            cnt.push_back(sum);
            
        }
    }
    
    for(int i = 0; i < cnt.size(); i++){
        if((N - cnt[i]) % B == 0)       ans++;
    }
    
    cout << ans << endl;
}
