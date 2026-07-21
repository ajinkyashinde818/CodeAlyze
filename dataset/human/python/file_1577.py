import math
import sys
from itertools import accumulate
from functools import reduce
import queue
from fractions import gcd

def lcm(a, b):
    return a * b // gcd(a, b)

def combination_count(n, r):
    return math.factorial(n) // (math.factorial(n - r) * math.factorial(r))

def permutations_count(n, r):
    return math.factorial(n) // math.factorial(n - r)

sys.setrecursionlimit(10000)

mod = 1000000007

"""
# 0埋め, 小数点出力桁指定時のときの出力
a = 100
b = 0.987654321
print("{0:06d}-{1:6f}".format(a,b))
000100-0.987654

# 文字列をリストに格納
char_list = list("abcd") # ["a","b","c","d"]

# 標準入力取得
## 文字列
    = sys.stdin.readline().rstrip()
    = list(sys.stdin.readline().rstrip())
    = [list(list(sys.stdin.readline().rstrip())) for i in range(h)] #文字列を分解して二次元配列入力

## 数値
    = int(sys.stdin.readline())
    = map(int, sys.stdin.readline().split())
    = list(map(int, sys.stdin.readline().split()))
    = [list(map(int,list(sys.stdin.readline().split()))) for i in range(h)]  # 二次元配列入力　二次元マップみたいな入力のとき
"""

if __name__ == "__main__":
    n,m = map(int, sys.stdin.readline().split())
    a=[input() for _ in range(n)]
    b=[input() for _ in range(m)]
    r = any([r[j:j+m] for r in a[i:i+m]]==b for i in range(n-m+1) for j in range(n-m+1)) #内包表記×多重ループ
    print("Yes" if r else "No")
