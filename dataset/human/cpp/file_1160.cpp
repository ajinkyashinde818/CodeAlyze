#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main(int argc, char **argv) {
    int R, G, B, N;
    scanf("%d%d%d%d", &R, &G, &B, &N);
    int triples = 0;
    for (int r = 0; r * R <= N; ++r)
        for (int g = 0; g * G <= N; ++g) {
            int b = N - (r * R + g * G);
            if (b >= 0 && b % B == 0)
                ++triples;
        }
    printf("%d\n", triples);
    return 0;
}
