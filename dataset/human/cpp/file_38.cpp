#include <iostream>

using namespace std;

int main()
{
    int inputR;
    int inputG;
    int inputB;
    int inputN;
    
    cin >> inputR >> inputG >> inputB >> inputN;
    
    if (3000 < inputR) {
        cout << "Invalid argument R = " << inputR << "¥n";
        return 1;
    }
    
    if (3000 < inputG) {
        cout << "Invalid argument G = " << inputG << "¥n";
        return 1;
    }
    
    if (3000 < inputB) {
        cout << "Invalid argument B = " << inputB << "¥n";
        return 1;
    }
    
    if (3000 < inputN) {
        cout << "Invalid argument N = " << inputN << "¥n";
        return 1;
    }
    
    int i = 0, j = 0, k = 0;
    int resolv_count = 0;
    for (i = 0; i <= inputN; i++) {
        int Rr = inputR * i;
        if (inputN < Rr) {
            break;
        }
        
        if (inputN == Rr) {
            resolv_count++;
            // これ以降は全てダメ
            break;
        }
        
        for (j = 0; j <= inputN; j++) {
            int Gg = inputG * j;
            if (inputN < Rr + Gg) {
                break;
            }
            
            if (inputN == Rr + Gg) {
                resolv_count++;
                break;
            }
            
            int a = inputN - ( Rr + Gg );
            
            if (a % inputB == 0) {
                resolv_count++;
            }
        }
    }
    
    cout << resolv_count;
}
