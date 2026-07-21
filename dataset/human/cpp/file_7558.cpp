#include <iostream>
using namespace std;

int main(){
    int N;
    long long a_sum = 0;
    long long a_list[200010];
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> a_list[i];
        a_sum += a_list[i];
    }
    long long x = a_list[0];
    long long x_y;
    long long min = abs(2*x - a_sum);
    for(int i=1; i<N-1; i++){
        x += a_list[i];
        x_y = abs(2*x - a_sum);
        if(x_y <= min){
            min = x_y;
        }
    }
    cout << min;
    return EXIT_SUCCESS;
}
