#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,m;cin>>n>>m;
    vector<string> image(n);for(int i=0;i<n;i++){cin>>image[i];}
    vector<string> temp(m);for (int i=0;i<m;i++){cin>>temp[i];}


    bool all_match = false;
    for (int h_init=0;h_init<=n-m;h_init++){
        for (int w_init=0;w_init<=n-m;w_init++){
            bool broke = false;

            for (int h=0;h<m;h++){
                if (image[h_init + h].substr(w_init, m) != temp[h]){
                    broke = true;
                    break;
                }
            }
            if (!broke){
                all_match = true;
            }

        }
    }
    if (all_match){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
