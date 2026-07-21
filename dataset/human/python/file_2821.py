import Foundation
// 第一引数に、素因数分解したい自然数を渡す
func prime_factorization(n:Int)->[[Int]]{
    // n = 1 なら素因数分解できないので空の二次元配列を返す
    if n == 1{
        return []
    }
    // 戻り値のなる二次元配列を初期化
    var arr:[[Int]] = []
    // nの値を変数に格納
    var temp = n
    // 計算するのは√nまでで十分
    for i in 2...Int(sqrt(Double(n)))+1{
        // 割り切れる -> その数を素因数に持つ
        if temp%i==0{
            var cnt=0
            // 素因数の字数を計算
            while temp%i==0{
                // 割り切れるなら次数を一つ増やす
                cnt+=1
                // tempをiで割る
                temp /= i
            }
            // 素因数とその次数をarrに追加
            arr.append([i,cnt])
        }
    }
    // temp ≠ 1ならtempは素因数なのでarrに追加
    if temp != 1{
        arr.append([temp, 1])
    }
    // arrが空なら n = (素数) なのでarrに追加
    if arr==[] {
        arr.append([n, 1])
    }
    // arrを返す
    return arr
}

// 標準入力の受け取り
let n = Int(readLine()!)!

// nを素因数分解
let factorization = prime_factorization(n:n)

// 答えを入れる変数の初期化
var ans = 0

// 各素因数についてループを回す
for i in factorization{

    // 計算に使う変数を初期化
    var num = i[1]
    var cnt = 1
    
    // もし以前の操作で選んだどの整数とも異なる整数を作れるなら ans += 1
    while num >= cnt{
        ans += 1
        num -= cnt
        cnt += 1
    }
}

// 答えを出力
print(ans)
