#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

ll pos_arr[100002];
ll neg_arr[100002];

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin>> N;

    ll num_of_neg = 0;
    ll num_of_zero = 0;
    ll num_of_pos = 0;

    ll temp;
    for(int i = 0; i< N; i++){
        cin >> temp;
        if (temp < 0)
            neg_arr[num_of_neg++] = temp;
        else if (temp == 0)
            num_of_zero++;
        else
            pos_arr[num_of_pos++] = temp;
    }

    ll sum = 0;
    if (num_of_zero != 0){ 
        for(int i = 0; i< num_of_neg;i++)
            sum += -neg_arr[i];
        for (int i = 0; i < num_of_pos; i++)
            sum += pos_arr[i];
    }
    else{
        if ((num_of_neg % 2) == 0){
            for(int i = 0; i< num_of_neg;i++)
                sum += -neg_arr[i];
            for (int i = 0; i < num_of_pos; i++)
                sum += pos_arr[i];
        }
        else{
            ll min_abs = 1000000001;
            for(int i = 0; i < num_of_neg; i++){
                sum += -neg_arr[i];
                min_abs = (min_abs > -neg_arr[i]) ? -neg_arr[i] : min_abs;
            }
            for(int i = 0; i < num_of_pos; i++){
                sum += pos_arr[i];
                min_abs = (min_abs > pos_arr[i]) ? pos_arr[i] : min_abs;
            }

            sum -= min_abs;
            sum -= min_abs;
        }
    }

    cout << sum;

}
