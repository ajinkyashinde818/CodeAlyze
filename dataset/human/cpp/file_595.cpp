#include<iostream>
using namespace std;
int main()
{
    // 整数の入力
    int R, G, B, N;
    // スペース区切りの整数の入力
    cin >> R >> G >> B >> N;

    if(G < B)
        swap(G, B);
    if(R < G)
        swap(R, G);

    
    int num = 0;
    for(int r=0; r*R <= N; r++){
        if(r*R == N){
            num++;
            break;
        }

        for(int g=0; r*R + g*G <= N; g++){
            if(r*R + g*G == N){
                num++;
                break;
            }

            int temp = N - r*R - g*G;
            if(temp % B == 0){
                num++;
            }
        }
    }

    //cout << (a+b+c) << " " << s << endl;
    cout << num << endl;
    return 0;
}
