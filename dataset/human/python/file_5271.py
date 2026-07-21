from functools import reduce
from collections import defaultdict
from collections import deque
import math

def btf(i,d,N):
    q = deque()
    q.append(i)
    dist = [-1]*N
    dist[i] = 0
    i = 1
    while q:
        l = len(q)
        for j in range(l):
            next_node = q.popleft()
            for succ in d[next_node]:
                if dist[succ] == -1:
                    dist[succ] = i
                    q.append(succ)
        i +=1
    return dist

def main():
    # 文字列の2進数を数値にする
    # '101' → '5'
    # 文字列の頭に'0b'をつけてint()にわたす
    # binary = int('0b'+'101',0)

    # 2進数で立っているbitを数える
    # 101(0x5) → 2
    # cnt_bit = bin(5).count('1')
    
    # N! を求める
    # f = math.factorial(N)

    # N の逆元
    # N_inv = pow(N,MOD-2,MOD)

    # nCr
    # Nの階乗 * rの階乗の逆元 * n-rの階乗の逆元
    
    # 切り捨て
    # 4 // 3
    # 切り上げ
    #-(-4 // 3)
    
    # 初期値用:十分大きい数(100億)
    INF = float("inf")

    # 大きな素数
    MOD = 10**9+7
    
    # 1文字のみを読み込み
    # 入力:2
    # a = input().rstrip()
    # 変数:a='2'
    
    # スペース区切りで標準入力を配列として読み込み
    # 入力:2 4 5 7
    # a, b, c, d = (int(_) for _ in input().split())  
    # 変数:a=2 b=4 c=5 d =7
    
    # 1文字ずつ標準入力を配列として読み込み
    # 入力:2 4 5 7
    # a = list(int(_) for _ in input().split())
    # 変数:a = [2, 4, 5, 7]    

    # 1文字ずつ標準入力を配列として読み込み
    # 入力:2457
    # a = list(int(_) for _ in input())
    # 変数:a = [2, 4, 5, 7]    
    N,M = (int(_) for _ in input().split())
    d = defaultdict(list)
    
    for i in range(M):
        s1,s2 = (int(_) for _ in input().split())
        d[s1-1].append(s2-1)
        d[s2-1].append(s1-1)

    dist = btf(0,d,N)

    if dist[N-1] == 2:
        print('POSSIBLE')
    else:
        print('IMPOSSIBLE')
        
if __name__ == '__main__':
    main()
