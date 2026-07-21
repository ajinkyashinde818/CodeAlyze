#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<string> Nmap(N);
    vector<string> Mmap(M);
    for(int i = 0; i < N ;i++)
    {
        string Nstr;
        cin >> Nstr;
        Nmap.at(i) = Nstr;
    }
    for(int i = 0; i < M ;i++)
    {
        string Mstr;
        cin >> Mstr;
        Mmap.at(i) = Mstr;
    }
    string answer = "No";
    bool matched = false;
    for(int i = 0; i <= N - M; i++){
        for(int j = 0; j <= N - M; j++){
            matched = true;
            for(int k = 0; k < M ; k++){
                for(int l = 0; l < M; l++){
                    if(Nmap.at(i + k)[j + l] != Mmap.at(k)[l]){
                        matched = false;
                        break;
                    }
                }
                if(!matched){
                    break;
                }
            }
            if(matched){
                answer ="Yes";
                break;
            }
        }
        if(matched){
            break;
        }
    }

    cout << answer << endl;
    return 0;
}
