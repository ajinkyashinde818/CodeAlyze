#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int main(void){
    int N;
    long long C;
    cin >> N >> C;
    vector<long long> point = vector<long long>(N + 1);
    vector<long long> value = vector<long long>(N + 1);
    for(int i = 1; i <= N; i++){
        cin >> point[i] >> value[i];
    }

    vector<long long> dy = vector<long long>(N + 2);
    vector<long long> rev = vector<long long>(N + 2);
    vector<long long> bdy = vector<long long>(N + 2);
    vector<long long> brev = vector<long long>(N + 2);
    long long result = 0;

    for(int i = 1; i <= N; i++){
        dy[i] = dy[i - 1] + value[i] - (point[i] - point[i - 1]);
        bdy[i] = point[i];
        if(result < dy[i]) result = dy[i];
    }
    rev[N] = value[N] - (C - point[N]);
    brev[N] = (C - point[N]);
    for(int i = N - 1; i >= 1; i--){
        long long diff = point[i + 1] - point[i];
        rev[i] = rev[i + 1] + value[i] - diff;
        brev[i] = diff;
        if(result < rev[i]) result = rev[i];
    }

    for(int i = 2; i <= N; i++){
        if(dy[i] < dy[i - 1]) {
            dy[i] = dy[i - 1];
            bdy[i] = bdy[i - 1];
        }
    }
    for(int i = N - 1; i >= 1; i--){
        if(rev[i] < rev[i + 1]) {
            rev[i] = rev[i + 1];
            brev[i] = brev[i + 1];
        }
    }

    /*
    for(int i = 1; i <= N; i++){
        cout << dy[i] << ' ';
    }
    cout << endl;
    for(int i = 1; i <= N; i++){
        cout << rev[i] << ' ';
    }
    cout << endl;
    */

    long long t_result = 0;
    int st = 0;
    for(int i = 1; i <= N; i++){
        if(t_result < dy[i] + rev[i + 1] - point[i]) {
            t_result = dy[i] + rev[i + 1] - point[i];
        }
        if(t_result < dy[i - 1] + rev[i] - (C - point[i])) {
            t_result = dy[i - 1] + rev[i] - (C - point[i]);
        }
        if(t_result < dy[i]) t_result = dy[i];
        if(t_result < rev[N - i]) t_result = rev[N - i];
    }
    if(result < t_result) result = t_result;
    cout << result << endl;
    return 0;

    if(result <= 0) {
        cout << 0 << endl;
        return 0;
    }

    /*
    int st = 0;
    long long t_result = 0;
    int j = (N > 1) ? 2 : 1;
    for(int i = 1; i <= N; i++){
        if(i + j > N) break;
        //long long min = (C - point[N - j + 1] > point[i]) ? point[i] : C - point[N - j + 1];
        long long min = dy[i] + rev[j] - bdy[i];
        if(t_result < min) {
            t_result = min;
            //if(result < dy[i] + rev[j] - min) result = dy[i] + rev[j] - point[i];
            st = i;
        }
    }

    int i = st;
    for(int j = 1; j <= N; j++){
        if(i + j > N) break;
        long long min = (C - point[N - j + 1] > point[i]) ? point[i] : C - point[N - j + 1];
        //long long min = brev[j];
        if(result < dy[i] + rev[j] - min) {
            result = dy[i] + rev[j] - min;
            st = i;
        }
    }

    st = 0;
    i = (N > 1) ? 2 : 1;
    t_result = 0;
    for(int j = 1; j <= N; j++){
        if(i + j > N) break;
        //long long min = (C - point[N - j + 1] > point[i]) ? point[i] : C - point[N - j + 1];
        long long min = dy[i] + rev[j] - brev[j];
        if(t_result < min) {
            t_result = min;
            //if(result < dy[i] + rev[j] - min) result = dy[i] + rev[j] - min;
            st = j;
        }
    }

    for(int i = 1, j = st; i <= N; i++){
        if(i + j > N) break;
        long long min = (C - point[N - j + 1] > point[i]) ? point[i] : C - point[N - j + 1];
        if(result < dy[i] + rev[j] - min) {
            result = dy[i] + rev[j] - min;
            st = i;
        }
    }
    */

    /*
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(i + j > N) break;
            long long min = (C - point[N - j + 1] > point[i]) ? point[i] : C - point[N - j + 1];
            if(result < dy[i] + rev[j] - min) result = dy[i] + rev[j] - min;
        }
    }
    */

    cout << result << endl;
    return 0;
}
