#include <iostream>
#include <iomanip>
using namespace std;

void Main() {
    // input
    int N, R;
    cin >> N >> R;

    // translate
    int innerRating;
    if (N >= 10) {
        innerRating = R;
    } else {
        innerRating = R + 100 * (10 - N);
    }


    // output
    cout << innerRating << endl;

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
