#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific
#include <string>//stoi/stol/stoul/stoll/stoull/stof/stod/stold/to_string/getline

using namespace std;

int main()
{
    size_t n, m;
    cin >> n >> m;
    string* a = new string[n];
    string* b = new string[m];
    for(size_t i = 0; i < n; ++i) { cin >> a[i]; }
    for(size_t i = 0; i < m; ++i) { cin >> b[i]; }

    bool found;
    for(size_t atop = 0; atop <= n-m; ++atop)
    {
        for(size_t alef = 0; alef <= n-m; ++alef)
        {
            found = true;
            for(size_t btop = 0; btop < m; ++btop)
            {
                for(size_t blef = 0; blef < m; ++blef)
                {
                    if (b[btop][blef] != a[atop+btop][alef+blef]) {found = false; goto nf;}
                }
            }
            nf:
            if (found) goto ff;
        }
    }
    ff:
    cout << (found ? "Yes" : "No") << endl;
    return 0;
}
