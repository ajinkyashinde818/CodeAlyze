#include <iostream>

using namespace std;

int main(int argc, char** argv){
    int R, G, B, N;
    cin >> R >> G >> B >> N;

    int count = 0;
    for (int r=0; r<=3000; r++){
        if (r*R > N) break;
        for (int g=0; g<=3000; g++){
            if (r*R + g*G > N) break;
            if ((N - r*R - g*G) % B == 0){
                count++;
            }
        }
    }

    cout << count << "\n";

    return 0;
}
