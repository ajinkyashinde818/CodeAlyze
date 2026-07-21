#include <iostream>
#include <string>
#include <vector>

using namespace std;

using Image = vector<string>;

Image ReadImage(int size)
{
    Image image(size);
    for (auto &row : image) {
        getline(cin, row);
    }
    return image;
}

bool ContainsAt(const Image &big, int x, int y, const Image &small)
{
    int n = small.size();
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < n; j += 1) {
            if (small[i][j] != big[x + i][y + j]) {
                return false;
            }
        }
    }
    return true;
}

bool Contains(const Image &big, const Image &small)
{
    int n = big.size();
    int m = small.size();

    for (int i = 0; i + m <= n; i += 1) {
        for (int j = 0; j + m <= n; j += 1) {
            if (ContainsAt(big, i, j, small)) {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    cin.get();

    auto big = ReadImage(n);
    auto small = ReadImage(m);

    cout << (Contains(big, small) ? "Yes" : "No") << "\n";
    return 0;
}
