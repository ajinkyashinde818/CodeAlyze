//===========================================
// Contents    : AOJ ITP1_3_B
//               整数 x を読み込んでそのまま出力
// Constraints : 1 ≤ x ≤ 10,000
//               データセットの数は10,000以下
// Author      : 廣部智也
// LastUpdate  :
// Since       : 2020/05/23
//===========================================

#include <stdio.h>

int main(void){
    
    int i = 0;
    int j = 0;
    int x[10000] = {};
    
    // データの入力
    while( i < 10000 ){
        
        scanf("%d", &x[i]);
        
        if( x[i] < 0 || x[i] > 10000 ){             // if( x[i] < 1 || x[i] > 10000 ){
                                                    //  → x = 0 が入力終了を示す値なので、はじく範囲を x[i] < 0 に変更
            return 0;
        }
        
        // x = 0 で入力終了
        if( x[i] == 0){
            break;
        }
        
        i++;
        
    }
    
    // データの入力が1つも無い場合、ここで終了
    if( i == 0){
        return 0;
    }
    
    // データの出力
    for( j = 0 ; j < i ; j++ ){                     // for( j = 0 ; j < i + 1 ; j++ ){
                                                    //  → iがインクリメントされる前にwhile文を抜けるので、j < i に変更
        printf("Case %d: %d\n", j + 1, x[j]);
    }
    
    return 0;
}
