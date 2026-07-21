#include <bits/stdc++.h>
using namespace std;

int main() {
    int R, G, B;
    cin >> R >> G >> B;
    int N;
    cin >> N;
    int count = 0;
    for (int i = 0; i * R <= N; i++) {
        for (int j = 0; j * G + i * R <= N; j++) {
            int sum = N - j * G - i * R;
            if (sum % B == 0) {
                count++;
            }
        }
    }
    cout << count << endl;
}
