#include <iostream>

using namespace std;

long long mypow(long long a) {
    long long ret = 1;
    for (int i=1; i<a; i++) {
        ret *= 3;
    }
    return ret;
}

bool check1(long long nokori, long long speed) {
    long long t = 0;
    t += mypow(++speed);
    while(speed > 2) {
        t += mypow(--speed);
    }
    return t <= nokori;
}

bool check2(long long nokori, long long speed) {
    long long t = 0;
    t += mypow(speed);
    while(speed > 2) {
        t += mypow(--speed);
    }
    return t <= nokori;
}

int main() {
    long long t;
    cin >> t;
    long long speed = 1;

    long long tt = t;

    if (t == 0) {
        cout << 0 << endl;
        return 0;
    }

    int ans = 1;
    t--;

    while(t) {
        ans++;
        // 加速しても大丈夫な場合
        if (check1(t, speed)) {
            speed++;
        }
        // 速度そのままでも大丈夫な場合
        else if (check2(t, speed)) {

        }
        // 速度を落とさないといけない場合
        else {
            speed--;
        }

        t -= mypow(speed);
        // cout << ans << " " << tt - t << endl;
    }

    cout << ans << endl;
}
